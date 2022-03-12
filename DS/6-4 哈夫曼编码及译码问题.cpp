#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define N 100
using namespace std;
typedef char* *huffmancode; //��̬���������Ź����������
typedef struct{
	char index;
	int weight;
	int lchild;
	int rchild;
	int parent;
}*huffmantree,thcode; //��̬���������Ź�������
void Select(huffmantree &HT,int m,int *s1,int *s2) //����Ȩ��С��������
{
	int i;
	for(i=1;;i++){
 		if(HT[i].parent==0){
 			*s1=i;
 			i++;
 			break;
 		}
 	}
 	for(;;i++){
 		if(HT[i].parent==0){
 			*s2=i;
 			i++;
 			break;
 		}
 	}
 	for(;i<=m;i++){
 		if(HT[i].parent==0)
 			if(HT[i].weight<HT[*s1].weight){
 				if(HT[*s1].weight<HT[*s2].weight)
 					*s2=*s1;
 					*s1=i;
 				}
 			else if(HT[i].weight<HT[*s2].weight)
 				*s2=i;
 	}
}
void buildhuffmantree(huffmantree &HT,char *c,int *w,int n) //�����շ�����,w���n���ַ�Ȩֵ
{
	int i=1,s1,s2;
	if(n<1)
	return;
 	int m=2*n-1; //mΪ�����������������ܽ�����
 	HT=(huffmantree)malloc((m+1)*sizeof(thcode)); //�����洢�ռ�
 	huffmantree p=HT;
 	for(;i<=n;i++,w++,c++) //��������������
 	{
 		p[i].index =*c;
	 	p[i].weight =*w;
	 	p[i].parent =0;
	 	p[i].lchild =0;
	 	p[i].rchild =0;
 	}
 	for(;i<=m;i++){
		p[i].index ='0';
	 	p[i].lchild =0;
	 	p[i].parent =0;
	 	p[i].rchild =0;
	 	p[i].weight =0;
 	}	
 	for(i=n+1;i<=m;i++) //�����շ�����
 	{ 
	 	Select(HT,i-1,&s1,&s2); //��HT[1...i-1]ѡ��parentΪ0��weight��С�������ڵ㣬����ŷֱ�Ϊs1��s2.
	 	HT[s1].parent=i;
	 	HT[s2].parent=i;
	 	HT[i].lchild=s1;
	 	HT[i].rchild=s2;
	 	HT[i].weight=HT[s1].weight+HT[s2].weight;
 	}
}
void huffmancoding(huffmantree &HT,huffmancode &HC,int *w,int n) //�շ������뺯��
{
	char *cd;
	int f,c,i,start;
	HC=(huffmancode)malloc((n+1)*sizeof(char*)); //����ָ���źշ������룬����n���ַ������ͷָ������
	cd=(char*)malloc(n*sizeof(char)); //��ʱ��źշ������룬���������Ĺ����ռ�
	cd[n-1]='\0'; //���������־
	if(n==1) //��nΪ1�ǵı���
	{
 		HC[1]="0";return ;
 	}
	 for(i=1;i<=n;i++) //����ַ������������
	 {
		 start=n-1; //�����������־
		 for(c=i,f=HT[i].parent ;f!=0;c=f,f=HT[f].parent ) //��Ҷ�ӽڵ㵽�����������
		 if(HT[f].lchild ==c)
		 cd[--start]='0';
		 else
		 cd[--start]='1';
		 HC[i]=(char *)malloc((n-start)*sizeof(char)); //��i���ַ�����ռ�
		 strcpy(HC[i],&cd[start]); //��cd���Ƶ�����(��)��HC
		 }
		 free(cd); //�ͷſռ�
	}
void print(huffmantree HT,huffmancode HC,int n){
 	int i;
 	cout<<endl;
 	cout<<"Please print the Prefix Code made by infomation:"<<endl;
 	for(i=1;i<=n;i++){
 	cout<<"\""<<HT[i].index<<"\""<<" "<<HC[i]<<endl;
 	}
}
void Initindex(int *a,char *b,int &n){
 	int i;
 	cout<<"Please input the number of characters you want to enter:";
 	scanf("%d",&n);
 	getchar();
 	cout<<"Please enter your "<<n<<" characters:";
 	gets(b);
 	cout<<"Please enter the weights of your characters in order:";
 	for(i=0;i<n;i++){
 		scanf("%d",&a[i]);
 	}
}

int main(){
 	int n; //nΪ��ͬ�ַ���
 	huffmantree HT; //huffmantree
 	huffmancode HC; //huffmancode
 	cout<<"Create a HuffmanTree."<<endl;
 	int a[N]; //����ַ�Ƶ��(Ȩֵ)B������Ȩֵ��ӦA ���ַ�����b��Ӧa
 	char b[N]; //����ַ�(ԭʼ����)a�������ַ����ظ� ��A�������ַ��ظ�
 	Initindex(a,b,n); //��������(һ�ξ��Ӽ���)
 	buildhuffmantree(HT,b,a,n); //�����շ�����
 	cout<<"\nHuffmanTree created successfully."<<endl;
 	huffmancoding(HT,HC,a,n); //����
 	print(HT,HC,n); //������(��ӡ) 
 	cout<<"\nPlease input a sentence to be translated:"<<endl;
 	char ch2[10];cin>>ch2;
	string str("MY GOD.");
	cout<<"MY GOD."<<endl;
	int length=str.copy(ch2, 9);
	ch2[length] = '\0';
	cout<<"\nDecode the sentence you just entered and print.\nCode:";
	int count=0; 
	for(int d=0;d<strlen(ch2);d++){
		for(int h=0;h<=n;h++){
			if(ch2[d]==HT[h].index){
				cout<<HC[h];
				count++;
			}
		}
	}
	return 0;
}

