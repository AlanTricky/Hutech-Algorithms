#include<stdio.h>
#include<conio.h>
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
		printf("Input a[%d] ",i);
		scanf("%d",&a[i]);
	}
}
void outputArray(int a[],int n){
	for(int i=0;i<n;i++){
		printf("\na[%d] = %d",i,a[i]);
	}
}

void inputX(int &x){
	printf("\nInput X: ");
	scanf("%d",&x);
}
int findSequentially(int a[],int n,int x){
	for(int i=0;i<n;i++){
		if(a[i] == x){
			return i+1;
		}
	}
	return -1;
}

int Swap(int &h,int &k){
	int t;
	t=h;h=k;k=t;
}

void sortUpAscending(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] > a[j]){
				Swap(a[i],a[j]);
			}
		}
	}
}
int binarySearch(int a[],int n,int x){
	int left = 0, right=n-1;
	int mid;
	mid = (left + right)/2;
	
	while(left <= right){
		if (a[mid] == x){
			return mid + 1;
		}
		if (a[mid] < x){
			right = mid - 1;
		}
		if (a[mid] > x){
			left = mid + 1;
		}
	}
	return -1;
}
int main(){
	int n;
	inputN(n);
	
	int a[MAX];
	inputArray(a,n);
	outputArray(a,n);
	
	int x;
	inputX(x);
	
	/*int locationX = findSequentially(a,n,x);
	if(locationX >= 0)
		printf("\nLocation X is: %d",locationX);
	else{
		printf("\nNot found!!!!");
	}*/
	
	int loXBi = binarySearch(a,n,x);
	if(loXBi >= 0)
		printf("\nLocation X binary is: %d",loXBi);
	else{
		printf("\nNot found!!!!");
	}	
 	return 0;
}
