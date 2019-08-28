#include <stdio.h>
#include <stdlib.h>

void triangle(int n);
void arrow(int n);
void rectangle(int n);

int main(int argc, char *argv[]){
	char *a = argv[1];
	int n = atoi(a);
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n - i; j++)
			printf(" ");
		for(int j = 0; j < (2 * i) - 1; j++)
			printf("*");
		for(int j = 0; j < n - i; j++)
			printf(" ");
		printf("\n");
	}
	printf("\n");
	triangle(n);
	printf("\n");
	arrow(n);
	printf("\n");
	rectangle(n);
}

void triangle(int n){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}	
}

void arrow(int n){
	for(int i = 1; i <= (n + 1) / 2; i++){
		for(int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
	int m = n/ 2;
	for(int i = m; i > 0; i--){
		for(int j = i; j > 0; j--)
			printf("*");
		printf("\n");
	}
}

void rectangle(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("*");
		printf("\n");
	}
	

}
