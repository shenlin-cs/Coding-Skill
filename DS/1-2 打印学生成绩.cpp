//���루Input����ÿ��ѧ����ѧ�š����������ſγ̳ɼ�
//�����Output����5��ѧ�������ݼ�¼
#include <iostream>
using namespace std;  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Student{  
    char NO[10];  
    char name[20];  
    int score[3];  
};
  
int main(){  
	struct Student stu[5],*p=stu;
    void input(struct Student stu[]);
    void print(struct Student stu[]);
    input(p);
    print(p);
    return 0;  
}  
void input(struct Student stu[]){
	int i;
	for(i=0;i<5;i++){
		cout<<"input score of student "<<i+1<<":"<<endl;
		cout<<"NO.:" ;cin>>stu[i].NO;
		cout<<"name:";cin>>stu[i].name;
		cout<<"score 1:";cin>>stu[i].score[0];
		cout<<"score 2:";cin>>stu[i].score[1];
		cout<<"score 3:";cin>>stu[i].score[2];
		cout<<endl;
		
	} 
}
void print(struct Student stu[]){
	int i;
	cout<<"NO.        name              score1     score2     score3        "<<endl;
	for(i=0;i<5;i++){
		printf("%-10s %-10s %10d %10d %10d\n",stu[i].NO,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
	} 
}
