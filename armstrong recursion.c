#include<stdio.h>
#include<math.h>
int armstrong(int n){
	if(n>0){
		return (pow(n%10,3) + armstrong(n/10));
	}	
}

int main(){
	int n,i;
	printf("Enter a number : ");
	scanf("%d",&n);
	if(n==armstrong(n)){
		printf("Armstrong number");
	}
	else{
		printf("Not an armstrong number");
	}
	return 0;
}
