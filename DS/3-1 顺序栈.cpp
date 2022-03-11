//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//存储结构
#define STACK_INIT_SIZE 20
#define STACK_INCREMENT 5
typedef struct
{
	ElemType *elem;		//栈尾指针
	int top;		//栈顶指针
	int stacksize;		//栈的大小
}SqStack;
//StudybarCommentEnd

void Error(char *s){
	printf("%s\n",s);
	exit(1);
}

void InitStack_Sq(SqStack &S){//初始化顺序栈
	S.elem=new ElemType(STACK_INIT_SIZE);
	if(!S.elem) Error("Overflow!"); 
	S.top=-1;
	S.stacksize=STACK_INIT_SIZE;
}

void Increment(SqStack &S){
	ElemType *newstack=new ElemType(S.stacksize+STACK_INCREMENT);
	int i;
	if(!newstack) Error("Overflow!"); 
	for(i=0;i<=S.top;i++){
		newstack[i]=S.elem[i];
	}
	delete []S.elem;
	S.elem=newstack;
	S.stacksize+=STACK_INCREMENT;
}

void Push_Sq(SqStack &S,ElemType e){//使用压栈操作创建顺序栈
	if(S.top==(S.stacksize-1)){
		Increment(S);
	}
	S.elem[++S.top]=e;
}

void GetTop_Sq(SqStack S,ElemType &e){//取出栈顶元素
	if(S.top==-1) Error("Stack Empty!");
	e=S.elem[S.top];
}

void Pop_Sq(SqStack &S,ElemType &e){//删除栈顶元素
	if(S.top==-1) Error("Stack Empty!");
	e=S.elem[S.top--];
}

void TraverseStack_Sq(SqStack S){//输出删除栈顶元素后的顺序栈
	for(int i=0;i<=S.top;i++){
		printf("%d ",S.elem[i]);
	}
}

int StackLength_Sq(SqStack S){
	return(S.top+1);
}
bool DestroyStack_Sq(SqStack S){//销毁顺序栈
	delete []S.elem;
	S.top=-1;
	S.stacksize=0;
	return (S.elem); 
}


//StudybarCommentBegin
int main()
{
	SqStack S;
	ElemType e,elem;
	int i;

	InitStack_Sq(S);
	printf("InitStack_Sq success\n");

	printf("Create_Stack:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&elem);
		Push_Sq(S,elem);
	}

	GetTop_Sq(S,e);
	printf("Top element is %d\n",e);

	Pop_Sq(S,e);
	printf("After deleting Stack top element, List:");
	TraverseStack_Sq(S);
	
	if(DestroyStack_Sq(S))  printf("\nDestroyStack_Sq success\n");
	return 0;
}
//StudybarCommentEnd


/*
void Conversion(){//十进制转D进制 
	InitStack_Sq(S);
	cin>>N;
	cin>>D;
	while(N){
		Push_Sq(S,N%D);
		N/=D;
	}
	while(!(S.top==1)){
		Pop_Sq(S,e);
		cout<<e;
	}
}
*/
/*
bool matching(){//括号是否正确嵌套 
	InitStack_Sq(S);
	Push_Sq(S,'#');
	ch=getchar();
	state=1;
	while((ch!='\n')&&state){
		if(ch=='(') Push_Sq(S,ch);
		if(ch==')'){
			GetTop_Sq(S,e);
			if(e=='#') state=0;
			else Pop_Sq(S,e);
		}
		ch=getchar();
	}
	GetTop_Sq(S,e);
	if(e!='#') state=0;
	if(state) return 1;
	else return 0;
}
*/
