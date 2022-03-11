#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct
{
	char *ch;
	int length;
}HString;


void Error(char *s)
{
	cout<<s<<endl;
	exit(0);
}

void InitHString(HString &S)
{
	S.ch=NULL;
	S.length=0;	
} 


void StrAssign_HS(HString &S,char chars[])//赋值 
{
	int i=0,j=0,k=0;
	int chars_len=0;
	while(chars[i]!='\0')
	{
		++chars_len;
		++i;
	}
	if(S.ch)
	{
		delete S.ch;
	}
	if(!chars_len)
	{
		S.ch=NULL;
		S.length=0;
	}
	else
	{
		S.ch=new char[chars_len];
		if(!S.ch)
		{
			Error("Overflow");
		}
		while(k<chars_len)
		{
			S.ch[k++]=chars[j++];	
		}
		S.length=chars_len;
	}
}

void StrPrint_HS(HString &S)
{
	int i=0;
	while(i<S.length)
	{
		cout<<S.ch[i++];
	}
	cout<<endl;
}

void DestroyString_HS(HString &S)
{
	delete []S.ch;
	S.length=0;
}

int StrLength_HS(HString S)
{
	return S.length;
}

void StrConcat_HS(HString &S1,HString S2)	//连接 
{
	HString temp;
	temp.length=S1.length+S2.length;
	temp.ch=new char[temp.length];
	if(!temp.ch)
	{
		Error("Overflow!");
	}
	int i=0,j=0;
	while(j<S1.length)
	{
		temp.ch[i++]=S1.ch[j++];
	}
	j=0;
	while(j<S2.length)
	{
		temp.ch[i++]=S2.ch[j++];
	}
	delete []S1.ch;
	S1.ch=temp.ch;
	S1.length=temp.length;
}


void StrCon_HS(HString &S1,HString S2,int pos)	//插入 
{
	if( (pos<1) || (pos>S1.length) )
	{
		Error("Position Error!");
	}
	int i=0,j=0,k=0;
	HString temp;
	temp.ch=new char[S1.length+S2.length];
	temp.length=S1.length+S2.length;
	while(i<pos-1)
	{
		temp.ch[i++]=S1.ch[j++];
	}
	while(k<S2.length)
	{
		temp.ch[i++]=S2.ch[k++];
	}
	while(i<temp.length)
	{
		temp.ch[i++]=S1.ch[j++];
	}
	delete []S1.ch;
	S1.ch=temp.ch;
	S1.length=temp.length;
}

void SubString_HS(HString &S1,HString S2,int pos,int len)	//子串替换	
{
	if( (pos<1) || (pos>S1.length) || (len<0) || (len>(S1.length-pos+1)))
	{
		Error("Position Error!");
	}
	int i=0,j=0,k=0;
	HString temp;
	temp.length=S1.length-len+S2.length;
	temp.ch=new char[temp.length];
	while(i<pos-1)
	{
		temp.ch[i++]=S1.ch[j++];
	}
	j=j+len;
	while(k<S2.length)
	{
		temp.ch[i++]=S2.ch[k++];	
	}
	while(i<temp.length)
	{
		temp.ch[i++]=S1.ch[j++];
	}
	delete[] S1.ch;
	S1.ch=temp.ch;
	S1.length=temp.length;
}

int main(int argc, char** argv) 
{
	int pos=0,len=0;
	HString a,b,c,d;
	
	InitHString(a);
	InitHString(b);
	InitHString(c);
	InitHString(d);
	
	char s1[100],s2[100],s3[100],s4[100];
	
	gets(s1);
	gets(s2);
	gets(s3);
	gets(s4);

	StrAssign_HS(a,s1);
	StrAssign_HS(b,s2);
	StrAssign_HS(c,s3);
	StrAssign_HS(d,s4);
	
	cout<<endl;
	
	cout<<"串a为："<<endl;
	StrPrint_HS(a);
	cout<<"串a的长度为："<<StrLength_HS(a)<<endl;
	
	cout<<"串b为："<<endl;
	StrPrint_HS(b);
	cout<<"串b的长度为："<<StrLength_HS(b)<<endl;
	
	cout<<"串c为："<<endl;
	StrPrint_HS(c);
	cout<<"串c的长度为："<<StrLength_HS(c)<<endl;
	
	cout<<"串d为："<<endl;
	StrPrint_HS(d);
	cout<<"串d的长度为："<<StrLength_HS(d)<<endl;
	
	cout<<endl;
	
	cout<<"执行合并串b操作后的串a为："<<endl;
	StrConcat_HS(a,b);
	StrPrint_HS(a);
	cout<<"串a的长度为："<<StrLength_HS(a)<<endl;
	
	cout<<endl;
	
	cin>>pos;
	cout<<"执行在串a的第"<<pos<<"个位置上插入串c后的串a为："<<endl;
	StrCon_HS(a,c,pos);
	StrPrint_HS(a);
	cout<<"串a的长度为："<<StrLength_HS(a)<<endl;
	
	cout<<endl;
	
	cin>>pos>>len;
	cout<<"执行在串a的第"<<pos<<"个位置上用串d替换"<<len<<"个字符后，串a为："<<endl;
	SubString_HS(a,d,pos,len);
	StrPrint_HS(a);
	cout<<"串a的长度为："<<StrLength_HS(a); 
	
	
	DestroyString_HS(a);
	DestroyString_HS(b);
	DestroyString_HS(b);
	DestroyString_HS(b);
	
	return 0;
}
/*
void SubString_HS(HString &Sub,HString S,int pos,int len)		//求子串返回sub 
{
	if( (pos<1) || (pos>S.length) || (len<0) || (len>(S.length-pos+1)))
		Error("Position Error!");
	if(Sub.ch) delete Sub.ch;
	if(!len){
		Sub.ch=NULL;
		Sub.length=0;
	}
	else{
		Sub.ch=new char[len];
		if(!Sub.ch) Error("Overflow!");
		for(int i=0;i<len;i++)
			Sub.ch[i]=S.ch[pos+i-1];
		Sub.length=len;
	}
}

int StrCompare_HS(HString S,HString T){
	for(int i=0;(i<S.length)&&(i<T.length);++i)
		if(S.ch[i]!=T.ch[i]) return(S.ch[i]-T.ch[i]);
	return (S.length-T.length);
}
*/

/*
void MAxSubString_HS(HString S,int &index,int &length){//第一个最长重复子串的下标和长度 
	index=0;length=0;
	i=0;
	while(i<(S.length-1)){
		j=i+1;
		while(j<S.length){
			if(S.ch[i]==S.ch[j]){
				length1=1;
				for(k=1;S.ch[i+k]==S.ch[i+k];k++)
					length++;
				if(length1>length){
					index=i;
					length=length1;
				}
				j+=length1;
			}
			else j++;
		}i++
	}
}
*/
