//创建一个n个整数的单向动态链表。
#include<iostream>
using namespace std;

struct num{
	int data;
	struct num* next;
};
struct num *creat(void){
	int n;
	cout<<"please input number of data:";
	cin>>n;
	struct num* p1,* p2;
	struct num* head;
	p1=p2=new struct num;
	head=p1;
	
	cout<<"please input "<<n<<" number:"<<endl;
	for(int i=0;i<n;i++){
		scanf("%d ",&p1->data);
		p1->next=new struct num;
		p2=p1;
		p1=p1->next;
	}
	p2->next=NULL;
	return head;
}
int main()
{
	struct num *ptr;
	ptr=creat();
	while(ptr!=NULL)
	{
		cout<<"The value is:"<<ptr->data<<endl;
		ptr=ptr->next;
	}
	return 0;
}
