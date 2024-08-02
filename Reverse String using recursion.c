#include<stdio.h>
#include<string.h>
void reverseString(char s[],char revstr[],int i,int j){
	if(s[i]=='\0'){
		return;
	}
	revstr[j-1]=s[i];
	reverseString(s,revstr,i+1,j-1);
}

int main(){
	char s[100],revstr[100];
	printf("Enter a string : ");
	scanf("%s",s);
	int j=strlen(s);
	reverseString(s,revstr,0,j);
	printf("The reversed string is %s\n",revstr);
}
