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


void StrAssign_HS(HString &S,char chars[])//��ֵ 
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

void StrConcat_HS(HString &S1,HString S2)	//���� 
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


void StrCon_HS(HString &S1,HString S2,int pos)	//���� 
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

void SubString_HS(HString &S1,HString S2,int pos,int len)	//�Ӵ��滻	
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
	
	cout<<"��aΪ��"<<endl;
	StrPrint_HS(a);
	cout<<"��a�ĳ���Ϊ��"<<StrLength_HS(a)<<endl;
	
	cout<<"��bΪ��"<<endl;
	StrPrint_HS(b);
	cout<<"��b�ĳ���Ϊ��"<<StrLength_HS(b)<<endl;
	
	cout<<"��cΪ��"<<endl;
	StrPrint_HS(c);
	cout<<"��c�ĳ���Ϊ��"<<StrLength_HS(c)<<endl;
	
	cout<<"��dΪ��"<<endl;
	StrPrint_HS(d);
	cout<<"��d�ĳ���Ϊ��"<<StrLength_HS(d)<<endl;
	
	cout<<endl;
	
	cout<<"ִ�кϲ���b������Ĵ�aΪ��"<<endl;
	StrConcat_HS(a,b);
	StrPrint_HS(a);
	cout<<"��a�ĳ���Ϊ��"<<StrLength_HS(a)<<endl;
	
	cout<<endl;
	
	cin>>pos;
	cout<<"ִ���ڴ�a�ĵ�"<<pos<<"��λ���ϲ��봮c��Ĵ�aΪ��"<<endl;
	StrCon_HS(a,c,pos);
	StrPrint_HS(a);
	cout<<"��a�ĳ���Ϊ��"<<StrLength_HS(a)<<endl;
	
	cout<<endl;
	
	cin>>pos>>len;
	cout<<"ִ���ڴ�a�ĵ�"<<pos<<"��λ�����ô�d�滻"<<len<<"���ַ��󣬴�aΪ��"<<endl;
	SubString_HS(a,d,pos,len);
	StrPrint_HS(a);
	cout<<"��a�ĳ���Ϊ��"<<StrLength_HS(a); 
	
	
	DestroyString_HS(a);
	DestroyString_HS(b);
	DestroyString_HS(b);
	DestroyString_HS(b);
	
	return 0;
}
/*
void SubString_HS(HString &Sub,HString S,int pos,int len)		//���Ӵ�����sub 
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
void MAxSubString_HS(HString S,int &index,int &length){//��һ����ظ��Ӵ����±�ͳ��� 
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
