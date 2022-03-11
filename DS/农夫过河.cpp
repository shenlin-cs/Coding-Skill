#include<iostream>
#include<stdio.h>
using namespace std;
#define MAXNUM 20  
typedef struct //顺序队列类型定义 
{ 
	int f, r; //f表示头，r 表示尾
	int q[MAXNUM];//顺序队
}SeqQueue ,*PSeqQueue;

PSeqQueue createEmptyQueue_seq( ) //创建队列
{
	 PSeqQueue paqu = new SeqQueue; 
	 if (paqu == NULL) 
		 cout<<"Out of space!"<<endl; 
	 else
		 paqu->f=paqu->r=0; 
	 return (paqu);
} 
int isEmptyQueue_seq( PSeqQueue paqu ) //判断 paqu 所指是否是空队列
{ 
	return paqu->f==paqu->r;
 } 
void enQueue_seq(PSeqQueue paqu,int x) //在队列中插入一元素 x
{
	if ((paqu->r+1)%MAXNUM==paqu->f) 
		cout<<"队列已满."<<endl;
	else 
	{
		paqu->q[paqu->r]=x;
		paqu->r=(paqu->r+1)%MAXNUM;
	}
}
 void deQueue_seq(PSeqQueue paqu) //删除队列头部元素 
{
	 if( paqu->f==paqu->r) 
		 cout<<"队列为空"<<endl;
	 else 
		 paqu->f=(paqu->f+1)%MAXNUM; 
}
int frontQueue_seq( PSeqQueue paqu ) //对非空队列,求队列头部元素
 {
	return (paqu->q[paqu->f]);
 }
int farmer(int location) //判断农夫位置对0做与运算，还是原来的数字，用来判断位置
{
	return 0 != (location & 0x08);
 } 
int wolf(int location) //判断狼位置
{ 
	return 0 != (location & 0x04);
 }
int cabbage(int location) //判断白菜位置 
{ 
	return 0 != (location & 0x02);
 } 
int goat(int location) //判断羊的位置
{
	return 0 !=(location & 0x01);
 } 
int safe(int location) // 若状态安全则返回 true 
{ 
	if ((goat(location) == cabbage(location)) && (goat(location) != farmer(location)) ) 
		return 0; 
	if ((goat(location) == wolf(location)) && (goat(location) != farmer(location))) 
		return 0;
	return 1; //其他状态是安全的 
	 
}
 void farmerProblem( ) 
 { 
	 int movers, i, location, newlocation; 
	 int route[16]; //记录已考虑的状态路径
	 int print[MAXNUM];
     PSeqQueue moveTo; 
     moveTo = createEmptyQueue_seq( );//新的队列判断路径
     enQueue_seq(moveTo, 0x00); //初始状态为0
     for (i = 0; i < 16; i++) 
		 route[i] = -1; //-1表示没有记录过路径
	 route[0]=0; 
	 while (!isEmptyQueue_seq(moveTo)&&(route[15] == -1))//队列不为空，路径未满时循环
	 {
		 location = frontQueue_seq(moveTo); //从队头出队
		 deQueue_seq(moveTo);
    	 for (movers = 1; movers <= 8; movers<<= 1) 
		 { 
    		 if ((0 != (location & 0x08)) == (0 != (location & movers)))
			 { 
	    		 newlocation = location^(0x08|movers);//或运算
	    		 if (safe(newlocation) && (route[newlocation] == -1))//判断是否安全，以及路径是否可用

				 {
	    			 route[newlocation] = location; 
		    		 enQueue_seq(moveTo, newlocation);

				 } 

			 }

		 }

	 }
	 /* 打印出路径 */ 
	 if(route[15] != -1)
	 { 
		 cout<<"过河步骤是 : "<<endl; 
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
	    			 cout<<"农夫带羊过南岸";			 
				 if(temp[i][2]!=temp[i-1][2])
					 cout<<"农夫带白菜过南岸";	
				 if(temp[i][1]!=temp[i-1][1])
					 cout<<"农夫带狼过南岸";
				 if(temp[i][3]==temp[i-1][3]&&temp[i][2]==temp[i-1][2]&&temp[i][1]==temp[i-1][1])
					 cout<<"农夫自己过南岸";
						 }
			 else if(i%2==0)
			 {
		    	if(temp[i][3]!=temp[i-1][3])
	    			 cout<<"农夫带羊回北岸";			 
				 if(temp[i][2]!=temp[i-1][2])
					 cout<<"农夫带白菜回北岸";	
				 if(temp[i][1]!=temp[i-1][1])
					 cout<<"农夫带狼回北岸";
				 if(temp[i][3]==temp[i-1][3]&&temp[i][2]==temp[i-1][2]&&temp[i][1]==temp[i-1][1])
					 cout<<"农夫自己回北岸";
			 }
			 cout<<endl;
		 }
	 }
	 

	 else
		 cout<<"No solution."<<endl; 
 }
 int main() /*主函数*/ 
 {
	farmerProblem(); 
	
	 return 0;
 }
