//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//存储结构
#define LIST_INIT_SIZE 20
#define LIST_INCREMENT 5
typedef struct
{
        ElemType *elem;
        int length;
        int listsize;
}SqList;
//StudybarCommentEnd

void Error(char *s){
	printf("%s\n",s);
	exit(1);
}

void InitList_Sq(SqList &L){ //初始化顺序表
	L.elem=new ElemType[LIST_INIT_SIZE];
	if(!L.elem) Error("Overflow!");
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
}

bool DestroyList_Sq(SqList &L){//销毁顺序表
	delete[] L.elem;
	L.length=0;
	L.listsize=0;
	return true;
}

int ListLength_Sq(SqList L){
	return L.length;
} 

void Increment(SqList &L){
	ElemType *newlist; 
	newlist=new ElemType[L.listsize+LIST_INCREMENT];
	if(!newlist) Error("Overflow");
	for(int i=0;i<L.length;i++)
	   newlist[i]=L.elem[i];
	delete []L.elem;
	L.elem=newlist;
	L.listsize+=LIST_INCREMENT;
}

void InsertElem_Sq(SqList &L,int i,ElemType e){//使用插入操作创建顺序表
	ElemType* p,*q;
	if((i<1)||(i>L.length+1))  Error("Position Error!");
	if(L.length>=LIST_INIT_SIZE)	Increment(L);
	q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p){
		*(p+1)=*p;
	}
	*q=e;
	++L.length;
}

void GetElem_Sq(SqList L,int i,ElemType &e){//求出第1个元素
	if((i<1)||(i>L.length))
		Error("Position Error!");
	e=L.elem[i-1];
}

int LocateElem_Sq(SqList L,ElemType e){//求出给定元素的位置
	int i=1;
	ElemType *p=L.elem;
	while((i<=L.length)&&(*p++!=e)) i++;
	if(i<=L.length) return i;
	else return 0;
}

bool PreElem_Sq(SqList L,ElemType cur_e,ElemType &pre_e){//求出给定元素的前驱元素
	for(int i=1;i<L.length;i++){
		if(L.elem[i]==cur_e){
			pre_e=L.elem[i-1];
			return 1;
		}
	}
	return 0;
}
bool NextElem_Sq(SqList L,ElemType cur_e,ElemType &next_e){//求出给定元素的后继元素
	for(int i=0;i<L.length-1;i++){
		if(L.elem[i]==cur_e){
			next_e=L.elem[i+1];
			return 1;
		}
	}
	return 0;
}

void DeleteElem_Sq(SqList &L,int i,ElemType &e){//删除第1个元素
	if((i<1)||(i>L.length)) Error("Position Error!");
	ElemType* p,*q;
	e=L.elem[i-1];
	p=&(L.elem[i-1]);
	q=L.elem+L.length-1;
	for(++p;p<=q;++p){
		*(p-1)=*p;
	}
	--L.length;
}

void TraverseList_Sq(SqList L){//输出删除第1个元素后的表元素
	for(int i=0;i<L.length;i++){
		printf("%d ",L.elem[i]);
	}
}

//StudybarCommentBegin
int main()
{
	SqList L;
	ElemType x,e,elem,i;

	InitList_Sq(L);
	printf("InitList_Sq success\n");

	printf("Create_List:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&elem);
		InsertElem_Sq(L,i+1,elem);
	}
	
	GetElem_Sq(L,1,e);
	printf("The first element is %d\n",e);

	printf("Enter the element you want to find:");
	scanf("%d",&x);
	if(!LocateElem_Sq(L,x))
		printf("Element %d is not exist\n",x);	
	else
	{
		printf("The %d at %d\n", x,LocateElem_Sq(L,x));
		if(PreElem_Sq(L,x,e))
			printf("The %d's previous element is %d\n",x,e);
		else 
			printf("The %d's previous element is not exist\n",x);	
		if(NextElem_Sq(L,x,e))
			printf("The %d's next element is %d\n",x,e);
		else
			printf("The %d's next element is not exist\n",x);	
	}

	DeleteElem_Sq(L,1,e);
	printf("After deleting the first element, List:");
	TraverseList_Sq(L);

	if(DestroyList_Sq(L))  printf("\nDestroyList_Sq success\n");	
	return 0;
}
//StudybarCommentEnd

/*
#define List_Size 100    // 线性表存储空间的初始分配量为100
typedef struct{ 
	ElemType  *elem;  // 向量data用于存放表结点 
	int        length;   // 当前的表长度 
} Sqlist; 
 //以上为定义表结构

void Invert_Sq( Sqlist &L){
	//逆置顺序表L
	n=L.length;   m=n/2;
	for ( i=0 ; i < m; i++){
		temp = L.elem[ i ];
		L .elem[ i ] = L.elem[ n - 1 - i ] ;
		L.elem[ n - 1 - i ] = temp ;  //交换数据逆置
	}  
}
//Invert_Sq
*/

/*
2.设顺序表L是一个递减有序表，试设计一个算法：将e插入到L中，并使L仍为一个有序表。

解答：
因已知顺序表L是递减有序表，所以只要从头找起找到第一个比它小(或相等)的结点数据，把e插入到这个数所在的位置就是了。算法如下：
void Insert_DecreaseList( Seqlist *L , ElemType e){
	if( L.length >= List_Size)
	Error(“Overflow!”);                         //L已满，给出相应信息
	for  ( i=L.length ; (i > 0) && (L.elem[ i-1] < e) ; i--) 
	L.elem[ i ]=L.elem[ i - 1 ];                    // 比较并移动元素
	L.elem[ i ] =e;                                  //插入e到L中
	L.length++;                                    //修正L的长度，令其增1
}
//Insert_DecreaseList
*/
