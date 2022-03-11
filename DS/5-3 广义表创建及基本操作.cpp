#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef char SString[255]; 
typedef struct GLNode{
	int tag;	//标志域
	union{		//值域或子表的表头指针域
		char data;
		struct{
			struct GLNode *hp,*tp;
		}ptr;
	};
}GLNode;
typedef GLNode *GList;	

void Error(char *s){  
    printf(s);
    exit(1);  
}

void InitGList(GList &GL){ 
	GL=NULL;
}

void CopyGList(GList &GT,GList GL){
	if(!GL)
		GT=NULL;
	else{
		GT=(GList)malloc(sizeof(GLNode)); 
		if(!GT)
			Error("CopyGList False!");
		GT->tag=GL->tag;
		if(GL->tag==0)
			GT->data=GL->data;
		else{
			CopyGList((GT->ptr.hp), GL->ptr.hp);
			CopyGList((GT->ptr.tp), GL->ptr.tp);
		}
	}
}

int LengthGList(GList GL){
	if(GL!=NULL)
		return(1 + LengthGList(GL->ptr.tp));
	else
		return(0);
}

int depGList(GList GL){
	if(!GL) return 1;
	if(GL->tag==0)  return 0;
	GList p=GL;
	int max,dep;
	for(max=0,p=GL;p;p=p->ptr.tp){
		dep=depGList(p->ptr.hp);
		if(dep>max) max=dep;
	}
	return (max+1);
}

bool GListEmpty(GList GL){
	return (!GL);
}

void TraverseGList(GList GL){
	if(!GL)
		printf("()");
	else{
		if(GL->tag==0)
			printf("%c",GL->data);
		else{
			cout<<"(";
			GList p=GL;
			while(p){
				TraverseGList(p->ptr.hp);
				p=p->ptr.tp;
				if(p)
					cout<<",";
			}
			cout<<")";
		}
	}
}

void GetHead(GList GL){
	if(!GL)
		Error("空表不能取表头！");
	GLNode *head=GL->ptr.hp;
	if(head->tag==0)
		cout<<head->data<<endl;
	else{
		TraverseGList(head);
		cout<<endl;
	}
}

void GetTail(GList GL){
	if(!GL)
		Error("空表不能取表尾！");
	GLNode *tail=GL->ptr.tp;
	TraverseGList(tail);
	cout<<endl;
}

void InsertFirst_GL(GList &GL,GList e){
	GList p=new GLNode;
	if(!p)
		Error("Overflow!");
	p->tag =1;
	p->ptr.hp = e;
	p->ptr.tp = GL;
	GL = p;
}

void StrAssign(SString T,char *chars){ 
	T[0] = strlen(chars);
	for(int i = 1; i <= T[0]; i++)
		T[i] = *(chars + i - 1);
}

void strcpy(SString T, SString S){
	for(int i = 0; i <= S[0]; i++)
		T[i] = S[i];
}

bool StrEmpty(SString S){
	return (!S[0]);
}

int strcmp(SString S,SString T){
	for(int i = 1; i <= S[0] && i <= T[0]; ++i)
		if(S[i] != T[i])
			return S[i] - T[i];
	return S[0]-T[0];
}

int strlen(SString S){
	return S[0];
}

void ClearString(SString S){
	S[0] = 0;
}

void SubString(SString Sub,SString S,int pos,int len){
	if(pos < 1 || pos >S[0] || len < 0 || len > S[0]-pos+1)
		Error("SubString False"); 
	for(int i = 1; i <= len; i++)
		Sub[i]=S[pos+i-1];
	Sub[0] = len;
}

void Decompose(SString &str,SString &hstr) {
	int n=strlen(str),i=1,k=0;  
	SString ch="",c1,c2,c3;
	StrAssign(c1,",");
	StrAssign(c2,"(");
	StrAssign(c3,")");
	SubString(ch,str,1,1);
	for(i=1,k=0;(i<=n) && (strcmp(ch,c1))||(k!=0); ++i){ 
		SubString(ch, str, i, 1);
		if(!strcmp(ch, c2))
			++k;
		else if(!strcmp(ch,c3))
			--k;
	}
	if(i<=n){
		SubString(hstr,str,1,i-2);
		SubString(str,str,i,n-i+1);
	}
	else{
		strcpy(hstr,str);
		ClearString(str);
	}
}

void CreateGList(GList &GL,SString S){
	SString sub,Hsub,es;
	GList p,q;
	StrAssign(es,"()");
	if(!strcmp(S, es))
		GL = NULL;
	else{
		GL = new GLNode;
		if(!GL)
			Error("Overflow!");
		if(strlen(S) == 1){
			GL->tag = 0;
			GL->data = S[1];
		}
		else{
			GL->tag = 1;
			p = GL;
			SubString(sub, S, 2, strlen(S)-2);
			do{
				Decompose(sub, Hsub);
				CreateGList(p->ptr.hp,Hsub);
				q = p;
				if(!StrEmpty(sub)){
					p =new GLNode;
					if(!p)
						Error("Overflow!");
					p->tag = 1;
					q->ptr.tp = p;
				}
			}while(!StrEmpty(sub));
			q->ptr.tp = NULL;
		}
	}
}
int main(){
    char p[100],p1[100],p2[100];
    printf("请输入字符序列：");
    gets(p);
    SString t,s1,s2;
    GList L,m,L1,L2;
    InitGList(L);
    InitGList(m);
    StrAssign(t,p);
    CreateGList(L,t);
    printf("构建的广义表为：");
    TraverseGList(L);
    printf("\n广义表的长度为：%d\n",LengthGList(L));
    printf("广义表的深度为：%d\n",depGList(L));
    printf("广义表的表头为："); 
    GetHead(L);
    printf("广义表的表尾为：");
    GetTail(L);
    
    printf("\n请输入字符序列作为广义表的表头：");
    gets(p1);
    InitGList(L1);
    StrAssign(s1, p1);
    CreateGList(L1,s1);

    printf("请输入字符序列作为广义表的表尾：");
    gets(p2);
    InitGList(L2);
    StrAssign(s2,p2);
    CreateGList(L2,s2);
    InsertFirst_GL(L2,L1);
    printf("广义表表头和表尾生成的广义表为：");
	TraverseGList(L2);
	
    return 0;
}

