#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct Book {
	char MS[10];
	char TS[40];
	long Gia;
};

void inputN(int &n){
	do{
		printf("\nInput n: ");
		scanf("%d",&n);
		
		if(n<0 || n>100){
			printf("\nInput wrong.In put again!!!!");
		}
	}while(n<0 || n>100);
}
void input1Element(Book &p){
	fflush(stdin);
	printf("\nInput book code: ");
	gets(p.MS);
	printf("\nIput book title: ");
	gets(p.TS);
	printf("\nIput cost: ");
	scanf("%ld", &p.Gia);
}

void output1Element(Book &p){
	printf("\nBook code: ");
	puts(p.MS);
	printf("\nBook title: ");
	puts(p.TS);
	printf("\nCost: %ld", p.Gia);
}

void inputArray(Book a[],int n){
	for(int i=0;i<n;i++){
		printf("\nInput information a[%d] ",i+1);
		input1Element(a[i]);
	}
}
void outputArray(Book a[],int n){
	printf("\n____Output infor about %d books____: ",n);
	for(int i=0;i<n;i++){
		printf("\n******Book Number %d******",i+1);
		output1Element(a[i]);
	}
}

int findSequentially(Book a[],int n,Book x){
	int m;
	for(int i=0;i<n;i++){
		m = strcmp(a[i].MS,x.MS);
		if(m == 0){
			return i;
		}
	}
	return -1;
}

Book Swap(Book &h,Book &k){
	Book t;
	t=h;h=k;k=t;
}

void sortUpAscending(Book a[],int n){
	int m;
	for(int i=0; i<n-1; i++){
		for(int j=i+1;j<n;j++){
			m = strcmp(a[i].MS,a[j].TS);
			if(m > 0){
				Swap(a[i],a[j]);
			}
		}
	}
}
int binarySearch(Book a[],int n,Book x){
	int left = 0, right=n-1;
	int mid;
	mid = (left + right)/2;
	int m;
	while(left < right){
		m = strcmp(a[mid].TS,x.TS);
		if (m == 0){
			return mid + 1;
		}
		if (m < 0){
			right = mid - 1;
		}
		if (m > 0){
			left = mid + 1;
		}
	}
	return -1;
}

int main(){
	int n;
	inputN(n);
	
	Book a[MAX];
	inputArray(a,n);
	outputArray(a,n);
	
	Book x;
	printf("\n******Input element x:********");
	input1Element(x);
	
	/*int locationX = findSequentially(a,n,x);
	if(locationX >= 0){
		printf("\nLocation X is: %d",locationX + 1);
		output1Element(a[locationX]);
	}
	else{
		printf("\nNot found!!!!");
	}*/
	
	int loXBi = binarySearch(a,n,x);
	if(loXBi >= 0){
		printf("\nLocation X is: %d",loXBi + 1);
		output1Element(a[loXBi]);
	}
	else{
		printf("\nNot found!!!!");
	}
 	return 0;
}
