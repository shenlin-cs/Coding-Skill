/*
13����Χ��һȦ���ӵ�1���˿�ʼ˳�򱨺�1��2��3��������3���˳�Ȧ�ӡ�Ҫ��
��1������˳�Ȧ���˵�ԭʼ��ŵ�˳��
��2���ҳ��������Ȧ���е���ԭʼ���
��3��ʹ������ʵ�֡�
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
