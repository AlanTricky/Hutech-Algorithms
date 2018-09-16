#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100

void inputN(int &n){
	do{
		printf("Input n: \n");
		scanf("%d",&n);
		
		if(n<0 || n>100){
			printf("Input wrong. Please check again.\n");
		}
	}while(n<0 || n>100);
}

void random(int arr[],int n){

	for(int i=0;i<n;i++){
		arr[i] = rand()%100;
	}
}

void outputArray(int arr[],int n){
	
	printf("Array random is: \n");
	for(int i=0;i<n;i++){
		printf("%10d",arr[i]);
	}
}

void Swap(int &h,int &k){
	int t;
	t=h;h=k;k=t;
}

int partition(int arr[],int low,int high){
	int pivot = arr[high];
	int i = low-1;
	
	for(int j=low;j<=high-1;j++){
		if(arr[j] <= pivot){
			i++;
			Swap(arr[i],arr[j]);
		}
	}
	Swap(arr[i+1],arr[high]);
	return i+1;
}

void quickSort(int arr[],int low,int high){
	if(low < high){
		int pi = partition(arr,low,high);
		
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}

int main(){
	int n;
	inputN(n);
	
	clock_t star,end;
	double time;
	
	int arr[MAX];
	random(arr,n);
	outputArray(arr,n);
	
	quickSort(arr,0,n-1);
	printf("\n");
	outputArray(arr,n);
	
	return 0;
}
