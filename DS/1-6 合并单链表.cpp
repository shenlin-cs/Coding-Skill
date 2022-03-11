#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define LEN sizeof(struct student)
using namespace std;

struct student{
    int num;
    int score;
    struct student *next;
};
struct student lista,listb;
int n,sum=0;

struct student *creat(void){
	printf("input number & scores of student:\n");
	printf("if number is -1,stop inputing.\n");
	struct student* p1,* p2;
	struct student* head;
	n=0;
	p1=p2=(struct student*)malloc(LEN);
	scanf("%d %d",&p1->num,&p1->score);
	head=NULL;
		while(p1->num!=-1){
			n=n+1;
			if(n==1)
				head=p1;
			else 
				p2->next=p1;
			p2=p1;
		p1=(struct student* )malloc(LEN);
		scanf("%ld %d",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return head;
}
struct student *merge(struct student* ah,struct student * bh){
	struct student * pa1,* pa2,* pb1,* pb2;
	pa2=pa1=ah;
	pb2=pb1=bh;
	do{
	while((pb1->num > pa1->num) &&(pa1->next!=NULL)){
		pa2=pa1;
		pa1=pa1->next;
		} 
	if(pb1->num <= pa1->num){ 
		if(ah==pa1){ 
			ah=pb1;
			} 
		else{ 
			pa2->next=pb1;
			pb1=pb1->next;
			pb2->next=pa1;
			pa2=pb2;
			pb2=pb1;}
			} 
		}while((pa1->next!=NULL)||(pa1==NULL&& pb1!=NULL));
	if((pb1!=NULL) &&(pb1->num>pa1->num) &&(pa1->next==NULL))
		pa1->next=pb1;
	return ah;
}

void print(struct student *head){
	struct student* p;
	cout<<"There are "<<sum<<" records:\n";
	p=head;
	if(p!=NULL){
		do{
			printf("%d %d\n",p->num,p->score);
			p=p->next;
		}while(p!=NULL);
	}
}
//StudybarCommentBegin
int main()
{
	struct student *ahead,*bhead,*abh;
	printf("input list a:\n");
	ahead=creat();
	sum=sum+n;
	printf("input list b:\n");
	bhead=creat();
	sum=sum+n;
	abh=merge(ahead,bhead);
	print(abh);
	return 0;
}
//StudybarCommentEnd
