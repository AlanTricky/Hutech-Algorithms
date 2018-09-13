#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void inputN(int &n){
	do{
		printf("\nInput n: ");
		scanf("%d",&n);
		
		if(n<0 || n>100){
			printf("\nInput wrong.In put again!!!!");
		}
	}while(n<0 || n>100);
}

void inputArray(int a[],int n){
	for(int i=0;i<n;i++){
		a[i] = rand()%100;
	}
}
void outputArray(int a[],int n){
	for(int i=0;i<n;i++){
		printf("\na[%d] = %d",i,a[i]);
	}
}
int Swap(int &h,int &k){
	int t;
	t=h;h=k;k=t;
}

void bubbleSort(int a[],int n){
	printf("\nBubble sort: ");
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--)
		{
			if(a[j-1] > a[j]){
				Swap(a[j-1],a[j]);
			}
		}
	}
	outputArray(a,n);
}

void interchangeSort(int a[],int n){
	printf("\nInterchange Sort: ");
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] > a[j]){
				Swap(a[i],a[j]);
			}
		}
	}
	outputArray(a,n);
}
void selectionSort(int a[],int n){
	int min;
	printf("\nSelection Sort: ");
	for(int i=0;i<n;i++){
		min = a[i];
		for(int j=i+1;j<n;j++){
			if(a[j] < a[i]){
				Swap(a[j],a[i]);
			}
		}
	}
	outputArray(a,n);	
}

void insertionSort(int a[],int n){
	int pos,x;
	printf("\nInsertion Sort: ");
	for(int i=0;i<n;i++){
		x = a[i]; pos = i-1;
		while(pos >=0 && a[pos] > x){
			a[pos +1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
	outputArray(a,n);
} 

void quickSort(int a[], int l,int r){
	int i,j,x;
	i = l; j = r;
	x = a[(l+r)/2];
	
	do{
		while(a[i] < x) i++;
		while(a[j] > x) j++;
		if(i <= j){
			Swap(a[i],a[j]);
			i++;
			j++;
		}
	}while(i<j);
	
	if(l < j) 	quickSort(a,l,j);
	if(r > i) 	quickSort(a,i,r);
}
int main(){
	int n;
	inputN(n);
	
	int a[MAX];
	inputArray(a,n);
	outputArray(a,n);
	
	
	quickSort(a,0,n-1);
	outputArray(a,n);
	
	
	/*int chon;
	do{
		clrscr();
		printf("\n1.Bubble Sort: ");
		printf("\n2.Interchange Sort: ");
		printf("\n3.Selection Sort: ");
		printf("\n4.Inserttion Sort: ");
		printf("\n5.Shell Sort: ");
		printf()
	}*/
	return 0;
}
