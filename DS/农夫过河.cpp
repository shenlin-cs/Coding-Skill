#include<iostream>
#include<stdio.h>
using namespace std;
#define MAXNUM 20  
typedef struct //˳��������Ͷ��� 
{ 
	int f, r; //f��ʾͷ��r ��ʾβ
	int q[MAXNUM];//˳���
}SeqQueue ,*PSeqQueue;

PSeqQueue createEmptyQueue_seq( ) //��������
{
	 PSeqQueue paqu = new SeqQueue; 
	 if (paqu == NULL) 
		 cout<<"Out of space!"<<endl; 
	 else
		 paqu->f=paqu->r=0; 
	 return (paqu);
} 
int isEmptyQueue_seq( PSeqQueue paqu ) //�ж� paqu ��ָ�Ƿ��ǿն���
{ 
	return paqu->f==paqu->r;
 } 
void enQueue_seq(PSeqQueue paqu,int x) //�ڶ����в���һԪ�� x
{
	if ((paqu->r+1)%MAXNUM==paqu->f) 
		cout<<"��������."<<endl;
	else 
	{
		paqu->q[paqu->r]=x;
		paqu->r=(paqu->r+1)%MAXNUM;
	}
}
 void deQueue_seq(PSeqQueue paqu) //ɾ������ͷ��Ԫ�� 
{
	 if( paqu->f==paqu->r) 
		 cout<<"����Ϊ��"<<endl;
	 else 
		 paqu->f=(paqu->f+1)%MAXNUM; 
}
int frontQueue_seq( PSeqQueue paqu ) //�Էǿն���,�����ͷ��Ԫ��
 {
	return (paqu->q[paqu->f]);
 }
int farmer(int location) //�ж�ũ��λ�ö�0�������㣬����ԭ�������֣������ж�λ��
{
	return 0 != (location & 0x08);
 } 
int wolf(int location) //�ж���λ��
{ 
	return 0 != (location & 0x04);
 }
int cabbage(int location) //�жϰײ�λ�� 
{ 
	return 0 != (location & 0x02);
 } 
int goat(int location) //�ж����λ��
{
	return 0 !=(location & 0x01);
 } 
int safe(int location) // ��״̬��ȫ�򷵻� true 
{ 
	if ((goat(location) == cabbage(location)) && (goat(location) != farmer(location)) ) 
		return 0; 
	if ((goat(location) == wolf(location)) && (goat(location) != farmer(location))) 
		return 0;
	return 1; //����״̬�ǰ�ȫ�� 
	 
}
 void farmerProblem( ) 
 { 
	 int movers, i, location, newlocation; 
	 int route[16]; //��¼�ѿ��ǵ�״̬·��
	 int print[MAXNUM];
     PSeqQueue moveTo; 
     moveTo = createEmptyQueue_seq( );//�µĶ����ж�·��
     enQueue_seq(moveTo, 0x00); //��ʼ״̬Ϊ0
     for (i = 0; i < 16; i++) 
		 route[i] = -1; //-1��ʾû�м�¼��·��
	 route[0]=0; 
	 while (!isEmptyQueue_seq(moveTo)&&(route[15] == -1))//���в�Ϊ�գ�·��δ��ʱѭ��
	 {
		 location = frontQueue_seq(moveTo); //�Ӷ�ͷ����
		 deQueue_seq(moveTo);
    	 for (movers = 1; movers <= 8; movers<<= 1) 
		 { 
    		 if ((0 != (location & 0x08)) == (0 != (location & movers)))
			 { 
	    		 newlocation = location^(0x08|movers);//������
	    		 if (safe(newlocation) && (route[newlocation] == -1))//�ж��Ƿ�ȫ���Լ�·���Ƿ����

				 {
	    			 route[newlocation] = location; 
		    		 enQueue_seq(moveTo, newlocation);

				 } 

			 }

		 }

	 }
	 /* ��ӡ��·�� */ 
	 if(route[15] != -1)
	 { 
		 cout<<"���Ӳ����� : "<<endl; 
		 i=0;
		 for(location = 15; location >= 0; location = route[location]) 
		 { 
			 print[i]=location;
			 i++;
			 if (location == 0) 
				 break;
		 } 
		 int num=i-1;
	     int temp[20][4];       
		 int j;
		 for(i=num;i>=0;i--)
		 {
			 for(j=3;j>=0;j--)
			 {
				 temp[num-i][j]=print[i]%2;
				 print[i]/=2;
				 temp[0][j]=0;
				 temp[num+1][j]=1;
			 }
		 }
		 for(i=1;i<=num;i++)
		 {
			 cout<<"\t\t\tNO . "<<i<<"\t";
			 if(i%2==1)
			 {
				 if(temp[i][3]!=temp[i-1][3])
	    			 cout<<"ũ�������ϰ�";			 
				 if(temp[i][2]!=temp[i-1][2])
					 cout<<"ũ����ײ˹��ϰ�";	
				 if(temp[i][1]!=temp[i-1][1])
					 cout<<"ũ����ǹ��ϰ�";
				 if(temp[i][3]==temp[i-1][3]&&temp[i][2]==temp[i-1][2]&&temp[i][1]==temp[i-1][1])
					 cout<<"ũ���Լ����ϰ�";
						 }
			 else if(i%2==0)
			 {
		    	if(temp[i][3]!=temp[i-1][3])
	    			 cout<<"ũ�����ر���";			 
				 if(temp[i][2]!=temp[i-1][2])
					 cout<<"ũ����ײ˻ر���";	
				 if(temp[i][1]!=temp[i-1][1])
					 cout<<"ũ����ǻر���";
				 if(temp[i][3]==temp[i-1][3]&&temp[i][2]==temp[i-1][2]&&temp[i][1]==temp[i-1][1])
					 cout<<"ũ���Լ��ر���";
			 }
			 cout<<endl;
		 }
	 }
	 

	 else
		 cout<<"No solution."<<endl; 
 }
 int main() /*������*/ 
 {
	farmerProblem(); 
	
	 return 0;
 }
