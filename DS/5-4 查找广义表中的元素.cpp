#include<stdio.h>
#include<stdlib.h>

//广义表的存储结构
struct GNode
{
	int tag;	//标志域
	union{		//值域或子表的表头指针域
		char data;
		struct GNode *sublist;
	};
	struct GNode *next;	//指向后继结点的指针域
};

void CreateGList(struct GNode **GL);//建立广义表的存储结构
void PrintGList(struct GNode *GL);	//打印输出广义表
int SearchGList(struct GNode *GL, char e);//查找等于给定字符的单元素结点，查找成功则返回1，否则返回0

int main()
{
	struct GNode *GL;//带表头附加结点
	printf("请输入字符序列：\n");
	CreateGList(&GL);
	printf("新创建的广义表：");
	PrintGList(GL);
	printf("\n");
	printf("\n请输入待查元素：\n");
	char d;
	scanf("%c",&d);
	if(SearchGList(GL, d)==0)
		printf("%c在广义表中不存在！",d);
	else
		printf("%c在广义表中存在！",d);
}

//建立广义表的存储结构
void CreateGList(struct GNode **GL)
{
	char ch;
	scanf("%c", &ch);
	if(ch=='#')//若输入为空格，则置表头指针为空
		*GL = NULL;
	if(ch=='(')//若输入为左括号则建立由*GL所指向的子表结点并递归构造子表
	{
		*GL = new GNode;
		(*GL)->tag = 1;
		CreateGList(&((*GL)->sublist));
	}
	else{	//若输入为字符则建立由*GL所指向的单元素结点
		*GL = new GNode;
		(*GL)->tag = 0;
		(*GL)->data = ch;
	}
	scanf("%c", &ch);//此处读入的字符必为逗号、右括号或分号
	if(*GL==NULL);	//若*GL为空，则什么都不做
	else if(ch==',')//若输入逗号则递归构造后继表
		CreateGList(&((*GL)->next));
	else if((ch==')') || (ch=='\n'))//若输入为右括号则置*GL的后继指针域为空
		(*GL)->next = NULL;
}

//打印输出广义表
void PrintGList(struct GNode *GL)
{
	//对于表结点的处理情况
	if(GL->tag==1){	//存在子表，则输出左括号，作为开始符号
		printf("(");
		if(GL->sublist==NULL)//若子表为空则输出‘#’字符
			printf("#");
		else//若子表非空，则递归输出子表
			PrintGList(GL->sublist);
		printf(")");//当一个子表输出结束后，应输出一个右括号终止符
	}
	else//对于单元素结点，则输出该结点的值
		printf("%c", GL->data);
	if(GL->next!=NULL)//输出结点的后继表
	{
		printf(",");//先输出逗号分隔符
		PrintGList(GL->next);//再递归输出后继表
	}
}

//查找等于给定字符的单元素结点，查找成功则返回1，否则返回0
int SearchGList(struct GNode *GL, char e)
{
	int n=0;
	while(GL!=NULL){
		if(GL->tag == 1)
		{
			if(SearchGList(GL->sublist, e))
				return 1;
		}
		else
		{
			if(GL->data == e)
				return 1;
		}
		GL = GL->next;//使GL指向同一层的下一个结点
	}
	return 0;
}
