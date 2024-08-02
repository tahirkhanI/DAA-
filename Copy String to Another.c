#include<stdio.h>

void copy(char s1[], char s2[],int i){
	if(s1[i]=='\0'){
		return;
	}
	s2[i]=s1[i];
	copy(s1,s2,i+1);
}

int main(){
	char s[100],scpy[100];
	printf("Enter a string : ");
	scanf("%s",s);
	copy(s,scpy,0);
	printf("The original string is : %s\n",s);
	printf("The copied string is : %s\n",scpy);
	return 0;
}
