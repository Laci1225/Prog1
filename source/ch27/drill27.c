#include <stdio.h>
#include <stdlib.h>

void funct(const char* p, const int x){
	printf("p is %s and x is %d\n",p,x);
}

int main(){

	printf("Hello world\n");

	const char* ch1 = "Hello";
	const char* ch2 = "world";
	printf("%s %s\n",ch1,ch2);
	funct("alma",5);
	funct("Béla",55);
	funct("asztal",12);
	funct("kóla",49);
}