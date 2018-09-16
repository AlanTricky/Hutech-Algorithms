#include<stdio.h>
#include<conio.h>
#define MAX 100
struct SV {
	int 	stuNum;
	char 	name[40];
	float 	aM;
};
void inputN(int &n){
	do{
		printf("Input N: \n");
		scanf("%d",&n);
		
		if(n<0 || n>100){
			printf("Input errors.Input again. Please!!!!\n");
		}
	}while(n<0 || n>100);
}
void input1Ele(SV &h) {
	fflush(stdin);
	printf("Input Student Numbers: \n");
	scanf("%d",&h.stuNum);
	printf("Input Full Name \n");
	gets(h.name);
	gets(h.name);
	printf("Input average mark: \n");
	scanf("%f",&h.aM);
}

void output1Ele(SV h){
	printf("Student Numbers: %d\n",h.stuNum);
	printf("Full Name: %s\n",h.name);
	printf("Input average mark: %f\n",h.aM);

}
 void inputArray(SV a[],int n) {
 	for(int i=0;i<n;i++){
 		printf("Infor About Student %d\n",i+1);
 		input1Ele(a[i]);
	 }
 }
void outputArray(SV a[],int n) {
 	for(int i=0;i<n;i++){
 		printf("Student %d\n",i+1);
 		output1Ele(a[i]);
	 }
 }
 
 int main(){
 	int n;
 	inputN(n);
 	SV a[MAX];
 	inputArray(a,n);
 	outputArray(a,n);
 }
 
 
 
 
