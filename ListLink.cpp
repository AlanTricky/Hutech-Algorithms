#include<stdio.h>
#include<conio.h>

struct Node{
	int Data;	
	struct Node *pNext;
};
typedef struct Node NODE;

struct List{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

void inputN(int &n){
	
	printf("How many Node do you want to input: \n");
	scanf("%d",&n);
}

//khoi tao danh sach lien ket don,"CHU Y: nho goi no truo khi nhap du lieu vao data"
void Init(LIST &l){
	
	l.pHead = l.pTail = NULL;
}

//tao danh sach Node
NODE* GetNode(int x){
	
	//Cap phat 1 Node
	NODE *p = new NODE;
	
	if (p == NULL){
		return NULL;
	}
	
	p->Data = x;// luu x vao data
	p->pNext = NULL;// khoi tao bien dem, co the hieu la soi day gan ket voi node tiep theo
	return p;
}

// Them Node ( Them dau va them cuoi)

//Them Node vao dau
void AddHead(LIST &l,NODE *p){
	
	if( l.pHead == NULL){
		
		l.pHead = l.pTail = p;
	}
	else{
		
		p->pNext = l.pHead;  
		l.pHead = p;
	}
}

//Them Node vao cuoi
void AddTail(LIST &l,NODE *p){
	
	if( l.pHead == NULL){
		
		l.pHead = l.pTail = p;
	}
	else{
		
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

int InputDataIntoNode(int &x)
{
	printf("Nhap vao data: \n");
	scanf("%d", &x);
	return x;
}
//Nhap du lieu cho danh sach
void Input(LIST &l,int n){
		
	Init(l);//Khoi tao
	
	for(int i=0;i<n;i++){

		int x = InputDataIntoNode(x);
		NODE *p = GetNode(x); // Them data vao Node p, tao ra Node p
		AddTail(l,p); //Them cuoi
	}
}

void Output(LIST l){
	for(NODE *p = l.pHead;p != NULL;p = p->pNext){
		
		printf("%4d",p->Data);
	}
	printf("\n");
}

//Giai phog
void free(LIST &l){
	NODE *p;
	while(p == NULL){
		
		p = l.pHead; //p tro den head
		l.pHead = l.pHead->pNext; // head chay qua thang ke tiep
		delete p;
	}
}

int findMaxValue(LIST l){
	
	int max = l.pHead->Data;
	for(NODE *p = l.pHead->pNext;p!=NULL;p=p->pNext){
		if(p->Data > max){
			max = p->Data;
		}
	}
	return max;
}

void Swap(int &a,int &b){
	int t=a;a=b;b=t;
}

void interchangeSort(LIST l){
	
	for(NODE *p = l.pHead;p != l.pTail;p = p->pNext){
		for(NODE *q = p->pNext;q != NULL;q = q->pNext){
			if(p->Data > q->Data)
				Swap(p->Data,q->Data);
		}
	}
}

int sum(LIST l){
	int s=0;
	
	for(NODE *p = l.pHead;p!=NULL;p = p->pNext){
		
		s += p->Data;
	}
	return s;
}

double average(LIST l,int n){
	int s = sum(l);
	return 	s/n;
}

//Them 1 Node q vao sau Node p
void addElement(LIST &l,NODE *p,NODE *q){
	
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		
		if(k->Data == p->Data){
			
			NODE* g  = k->pNext;
			k->pNext = q;
			q->pNext = g;
			return;
		}
	}
	
}

void deleteFisrtEle(LIST &l){
	
	NODE *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}

void deleteLastEle(LIST &l){
	
	NODE* p;
	for(NODE* k=l.pHead;k!=NULL;k=k->pNext){
		
		if(k == l.pTail){
			
			l.pTail=p;
			l.pTail->pNext = NULL;
			delete k;
			return;
		}
		p=k;
	}
}

void deleteBehindEle(LIST &l,NODE* p){
	
	NODE* g;	
	for(NODE* k=l.pHead;k!=NULL;k=k->pNext){
		
		if(k->Data == p->Data){
			
			g = k->pNext;	
			k->pNext = g->pNext;
			delete g;
			return;
		}
	}
}

void deleteAnyEle(LIST &l,NODE* p){
	
	NODE *h;
	for(NODE* k=l.pHead;k!=NULL;k=k->pNext){
		
		if(k->Data == p->Data){
			deleteBehindEle(l,h);
			return;
		}
		h=k;
	}
}
int main(){
	
	int n,x;
	inputN(n);
	
	LIST l;
	Input(l,n);
	printf("Arrays: \n");
	Output(l);
	
	/*int m = findMaxValue(l);
	printf("Max value is: %d \n",m);*/
	
	/*interchangeSort(l);
	printf("Arrays after Sort: \n");
	Output(l);*/
	
	/*double a=average(l,n);
	printf("Average of array = %.4lf\n",a);*/

	/*int p;
	printf("Nhap p: \n");
	scanf("%d", &p);
	
	NODE* P= GetNode(p);
	
	int q;
	printf("Nhap q: \n");
	scanf("%d", &q);
	
	NODE* Q= GetNode(q);
	
	addElement(l,P,Q);
	printf("List after ADD Element: \n");
	Output(l);
	
	/*printf("Array after delete element P: \n");
	deleteAnyEle(l,P);
	Output(l);*/
	
	deleteFisrtEle(l);
	Output(l);
	free(l);
	return 0;
}
