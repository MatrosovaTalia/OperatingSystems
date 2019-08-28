#include <string.h>
#include <stdio.h>

int main(){
	char str[1024];
	int len = 0;
	printf("Enter a string: \n");
	fgets(str, sizeof(str), stdin);
	
	while(str[len] != '\0')
		len++;
	int end = len - 1;
	for(int i = 0; i < len/2; i++){
		int temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		end--;		
	}
	printf("%s", str);

}
