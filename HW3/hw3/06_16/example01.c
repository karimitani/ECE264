#include <stdio.h>
#include <stdlib.h>


int outer = 3;

int foo(int x){

	int i;
	int outFor = 22;
	for(i=0;i<x;i++){
		int outFor = 2*i;
		outer += outFor;
	}
	printf("outFor is: %d\n",outFor);	
	return outFor;
}


int main(int argc, char ** argv)
{
	int i =3;
	return foo(i)+  outer;
		
	
}
