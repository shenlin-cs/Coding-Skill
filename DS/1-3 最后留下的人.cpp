/*
13个人围成一圈，从第1个人开始顺序报号1、2、3，凡报到3者退出圈子。要求：
（1）求出退出圈子人的原始序号的顺序
（2）找出最后留在圈子中的人原始序号
（3）使用链表实现。
*/

//StudybarCommentBegin
#include <stdio.h>

struct person
{
	int number;
	int nextp;
}link[100];
//StudybarCommentEnd

int main(){
	int i,count,h,N;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		if(i==N)
			link[i].nextp=1;
		else
			link[i].nextp=i+1;
			link[i].number=i;
	}
	count=0;
	h=N;
	while(count<N-1){
		i=0;
		while(i!=3){
			h=link[h].nextp;
			if(link[h].number){
				i++;
			}
		}
		printf("%d ",link[h].number);
		link[h].number=0;
		count++;
	}
	for(i=1;i<=N;i++){
		if(link[i].number){
			printf("%d ",link[i].number);}
		}
		printf("\n");	
		return 0;
}
