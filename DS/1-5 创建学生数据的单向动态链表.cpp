#include<iostream>
using namespace std;
 
struct student{
    int num;
    int score;
    struct student *next;
};

struct student *creat(void){
	int n;
	cout<<"please input number of students:"<<endl;
	cin>>n;

	struct student* p1,* p2;
	struct student* head;
	p1=p2=new struct student;
	head=p1;
	cout<<"please input student data:"<<endl;
	for(int i=0;i<n;i++){
		scanf("%d,%d",&p1->num,&p1->score);
		p1->next=new struct student;
		p2=p1;
		p1=p1->next;
	}
	p2->next=NULL;
	return head;
}


//StudybarCommentBegin
int main()
{
	struct student *ptr;
	int i=1;
	ptr=creat();
	printf("please output linklist data:\n");
	while(ptr!=NULL)
	{
		printf("student%d:num=%d,score=%d\n",i++,ptr->num,ptr->score);
		ptr=ptr->next;
	}
	return 0;
}
//StudybarCommentEnd
