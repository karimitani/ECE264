#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "answer07.h"
char * * explode(const char * str, const char * delims, int * arrLen);


BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode * head = NULL;
  head = malloc(sizeof(BusinessNode));
  head->name = name;
  head->stars = stars;
  head->address = address;
  head->left = NULL;
  head->right = NULL;
  
  return head;
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  
  if(root == NULL)
  {
    return node;
  }
  
  if(strcmp(root->name, node->name) > 0 || strcmp(root->name, node->name) == 0)
  {
    root->left =  tree_insert(node, root->left);
  }
  else if(strcmp(root->name, node->name) < 0)
  {
    root->right =  tree_insert(node, root->right);
  }
  
  return root;
}


BusinessNode * load_tree_from_file(char * filename)
{
  BusinessNode * node = NULL;
  FILE * fp = fopen(filename, "r");
  char alph;
  char currLine[2000];
  int posn = 0;
  char ** explodedLine;
  int x; //not used
  BusinessNode * root = NULL;
  
  if(fp == NULL)
  {
    return NULL;
  }
  
  while(!feof(fp))
  {
   alph = fgetc(fp);
   
   if(alph != EOF && alph != '\n')
   {
     currLine[posn] = alph;
     posn++;
   }
   else if(alph!= EOF && alph == '\n')
   {
     currLine[posn] = '\0';   
     explodedLine = explode((const char *)currLine, "\t", &x);
    // printf("%s", explodedLine[2]);
     node = create_node(explodedLine[0], explodedLine[1], explodedLine[2]);
 
     free(explodedLine);
     
     root = tree_insert(node, root);
     
     posn = 0;
     
     
   }
  }
  
  fclose(fp);
  
  return root;
}
   
   
   

BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
 if (root == NULL)
 {
   return NULL;
 }
 
 if(strcmp(root->name, name) == 0)
 {
   return root;
 }
 else if(strcmp(root->name, name) > 0)
 {
   return tree_search_name(name, root->left);
 }
 else if(strcmp(root->name, name) < 0)
 {
   return tree_search_name(name, root->right);
 }
 
 return root;
}


void destroy_tree(BusinessNode * root)
{
  if(root != NULL)
  {
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root->name);
    free(root->address);
    free(root->stars);
    free(root);
  }
}


char * * explode(const char * str, const char * delims, int * arrLen)
{
	int x;
	int count = 0;
	int len = strlen(str);
	for(x = 0; x < len; x++)
	{
	if(strchr(delims, str[x]) != NULL)
	{
	count++;
	}
	}
	*arrLen = count + 1;
	char** strArr = malloc((count+1) * sizeof(char *));
	int arrInd = 0; 
	int last = 0;
	count = 0;
	while(arrInd < len)
	{
       	if(strchr(delims, str[arrInd]) != NULL)
       	{
       	strArr[count] = malloc(((arrInd - last) + 1) * sizeof(char));
       	memcpy(strArr[count], str + last, (arrInd-last) + 1);
      	strArr[count][arrInd-last] = '\0';
       	count++;
       	last = arrInd + 1;
	}

	if(arrInd == len - 1)
	{
       	strArr[count] = malloc(((arrInd - last) + 2) * sizeof(char));
       	memcpy(strArr[count], str + last, (arrInd-last) + 1);
       	strArr[count][arrInd-last + 1] = '\0';
       	count++;
       	last = arrInd + 1;
	}
	arrInd++;
	}


	return strArr;

}


  
  


