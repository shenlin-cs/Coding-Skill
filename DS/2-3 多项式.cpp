/*
题目（Description）：
顺序栈应用实例：对一个合法的中缀表达式求值。假设表达式只包含+、-、×、÷ 四个双目运算符，且运算符本身不具有二义性。只能进行整数的四则运算，支持小括号。对不能整除的将按两个整数除法规则进行取整。
要求：
（1）正确解释表达式；
（2）符合四则运算规则；
（3）输出计算过程和最后计算结果。
*/


#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define  LEN  sizeof(LNode)
typedef struct LNode   {
	//用单链表存储多项式的结点结构
	int coef;  //多项式的系数
	int exp;   //指数
	struct LNode *next; //指向下一个元素的指针 
}LNode;
typedef LNode polynomial;

polynomial *create(void) { 
	//用尾插法建立一元多项式的链表的函数
	polynomial *h,*r,*s;
	int c,e;
	h=(polynomial*)malloc(LEN);  //建立多项式的头结点，为头结点分配存储空间
	r=h; //r指针始终动态指向链表的当前表尾，以便于做尾插入，其初值指向头结点
	scanf("%d",&c); //输入系数
	scanf("%d",&e); //输入指针
	while(c!=0){ //输入系数为0时，表示多项式的输入结束
		s=(polynomial *)malloc(LEN); //申请新结点
		s->coef=c;
		s->exp=e;   //申请新结点后赋值
		r->next=s; //做尾插，插入新结点
		r=s;  //r始终指向单链表的表尾
		scanf("%d",&c);
		scanf("%d",&e);
	}
	r->next=NULL; //将表的最后一个结点的next置NULL，以示表结束
	return(h);
}
void Addpolyn(polynomial *pa, polynomial *pb){
	//一元多项式相加函数，用于将两个多项式相加，然后将和多项式存放在多项式polya中，并将多项式ployb删除
	polynomial *p,*q,*pre,*temp;
	p=pa->next;//令p和q分别指向polya和polyb多项式链表中的第一个结点
	q=pb->next;
	pre=p;    //位置指针，指向和多项式polya
	while(p&&q){ //当两个多项式均未扫描结束时，执行以下操作
		if(p->exp<q->exp){           //若p指向的多项式指数小于q指的指数
			pre=p;      //将p结点加入到和多项式中
			p=p->next;
		}
		else if(p->exp==q->exp){    //若指数相等，则相应的系数相加
			p->coef=p->coef+q->coef;
			if(p->coef!=0){
				pre=p;
				p=pre->next;
				temp=q;
				q=q->next;
				delete temp;
			}
			else {    //如果系数和为零，则删除结点p与q，并将指针指向下一个结点
				pre->next=p->next;
				delete p;
			}
		}
		else{                      //若p指数大于q指数*
			temp=q->next;
			q->next=p;
			pre->next=q;
			pre=q;
			q=temp;
		}
	}
	if(q)  //多项式B中还有剩余，则将剩余的结点加入到和多项式中
		pre->next=q;
	delete pb;
}
void print(polynomial *p){ //输出函数，打印出一元多项式
	while(p->next!=NULL){
		p=p->next;
		printf("     %d*x^%d",p->coef,p->exp);
	}
}
int main(){       //主函数
	polynomial *polya,*polyb;
	printf("\nPlease input the ploya include coef && exp:\n");
	polya=create();  //调用建立链表函数，创建多项式A
	print(polya);
	printf("\nPlease input the ployb include coef && exp:\n");
	polyb=create();  //同理，创建B
	print(polyb);
	printf("\nSum of the poly is:\n");
	Addpolyn(polya,polyb);    //调用一元多项式相加函数
	print(polya);            //调用输出函数，打印结果*
	printf("\n");
} 


//分析两个多项式相加算法的时间复杂度 
/*
两个多项式的“项数和”（设多项式A有n项，多项式B有m项）
算法执行时间主要花费在while循环的基本操作上，执行次数最多为（n+m）
因此该算法的时间复杂度为O(n+m)
*/
