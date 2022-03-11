#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define N 100
using namespace std;
typedef char* *huffmancode; //动态分配数组存放哈弗曼编码表
typedef struct{
	char index;
	int weight;
	int lchild;
	int rchild;
	int parent;
}*huffmantree,thcode; //动态分配数组存放哈夫曼树
void Select(huffmantree &HT,int m,int *s1,int *s2) //查找权最小的两个数
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
void buildhuffmantree(huffmantree &HT,char *c,int *w,int n) //建立赫夫曼树,w存放n个字符权值
{
	int i=1,s1,s2;
	if(n<1)
	return;
 	int m=2*n-1; //m为创建哈夫曼树所需总结点个数
 	HT=(huffmantree)malloc((m+1)*sizeof(thcode)); //创建存储空间
 	huffmantree p=HT;
 	for(;i<=n;i++,w++,c++) //往树中输入数据
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
 	for(i=n+1;i<=m;i++) //构建赫夫曼树
 	{ 
	 	Select(HT,i-1,&s1,&s2); //在HT[1...i-1]选择parent为0且weight最小的两个节点，其序号分别为s1和s2.
	 	HT[s1].parent=i;
	 	HT[s2].parent=i;
	 	HT[i].lchild=s1;
	 	HT[i].rchild=s2;
	 	HT[i].weight=HT[s1].weight+HT[s2].weight;
 	}
}
void huffmancoding(huffmantree &HT,huffmancode &HC,int *w,int n) //赫夫曼代码函数
{
	char *cd;
	int f,c,i,start;
	HC=(huffmancode)malloc((n+1)*sizeof(char*)); //数组指针存放赫夫曼代码，分配n个字符编码的头指针向量
	cd=(char*)malloc(n*sizeof(char)); //暂时存放赫夫曼代码，分配求编码的工作空间
	cd[n-1]='\0'; //编码结束标志
	if(n==1) //当n为1是的编码
	{
 		HC[1]="0";return ;
 	}
	 for(i=1;i<=n;i++) //逐个字符求哈弗曼编码
	 {
		 start=n-1; //编码结束符标志
		 for(c=i,f=HT[i].parent ;f!=0;c=f,f=HT[f].parent ) //从叶子节点到根逆向求编码
		 if(HT[f].lchild ==c)
		 cd[--start]='0';
		 else
		 cd[--start]='1';
		 HC[i]=(char *)malloc((n-start)*sizeof(char)); //第i个字符分配空间
		 strcpy(HC[i],&cd[start]); //从cd复制到编码(串)到HC
		 }
		 free(cd); //释放空间
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
 	int n; //n为不同字符数
 	huffmantree HT; //huffmantree
 	huffmancode HC; //huffmancode
 	cout<<"Create a HuffmanTree."<<endl;
 	int a[N]; //存放字符频率(权值)B数组中权值对应A ，字符数组b对应a
 	char b[N]; //存放字符(原始数据)a数组中字符不重复 ，A数组中字符重复
 	Initindex(a,b,n); //数据输入(一段句子即可)
 	buildhuffmantree(HT,b,a,n); //建立赫夫曼树
 	cout<<"\nHuffmanTree created successfully."<<endl;
 	huffmancoding(HT,HC,a,n); //编码
 	print(HT,HC,n); //输出结果(打印) 
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

