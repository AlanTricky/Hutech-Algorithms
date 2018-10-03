#include<stdio.h>
#include<conio.h>

struct NODE{
	int Data;
	struct NODE *pNext;
};

struct LIST{
	NODE *pHead;
	NODE *pTail;
};

void Init(LIST &l){
	
	l.pHead = l.pTail = NULL;
}

NODE* GetNode(int x){
	NODE *p = new NODE;
	
	if(p == NULL){
		return NULL;
	}
	
	p->Data = x; //luu x vao data
	p->pNext = NULL; // luu bien chay giong nhu luu i = 0
	return p;
}
void AddHead(LIST &l, NODE *p){
	
	if(l.pHead == NULL){
		
		l.pHead = l.pTail = p;
	}
	else{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST &l, NODE *p){
	
	if(l.pHead == NULL){
		
		l.pHead = l.pTail = p;
	}
	else{
		l.pTail->pNext = p;
		l.pTail = p ;
	}
}

void Input(LIST &l)
{
	int n;
	printf("How many Node do you want input: \n");
	scanf("%d",&n);

	Init(l);
		
	for(int i=0; i <n;i++)
	{
		int x;
		printf("Input into data: \n");
		scanf("%d",&x);
		
		NODE *p = GetNode(x);
		AddTail(l,p);
	}
}

void Output(LIST l)
{
	for(NODE* p = l.pHead; p!= NULL ;p= p->pNext){
		printf("%4d", p->Data);
	}
}
int main(){
	LIST l;
	Input(l);
	Output(l);
	return 0;
}









