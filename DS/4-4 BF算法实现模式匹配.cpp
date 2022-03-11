#include <iostream>
#define STRING_SIZE 255
typedef unsigned char SString[STRING_SIZE+1];

void StrAssign_SS(SString &S,char chars[])
{
    int i=0;
    int chars_len=0;
    while(chars[i]!='\0')
	{
        ++chars_len;
        ++i;
    }
    if(!chars_len)
		S[0]=0;
    else
	{
        int j=0;
        int k=1;
        if(chars_len>STRING_SIZE)
		{
            while(k<STRING_SIZE)
                S[k++]=chars[j++];
            S[0]=STRING_SIZE;
        }
        else
		{
            while(k<STRING_SIZE)
                S[k++]=chars[j++];
            S[0]=chars_len;
        }
    }
}

int StrLength(SString &S)
{
    return S[0];
}

int StrIndex_BF(SString S,SString T)
{
	int i=0,j=0,start;
	printf("输入起始位置："); 
	scanf("%d",&start);
	while(i<=S[0]&&j<=T[0]){
		if(S[i]==T[j]){
			i++;
			j++;
		}
		else{
			start++;
			i=start;
			j=1;
		}
	}
	if(j>T[0]) return start;
	else return 0;
}

int main()
{
    char ch[255];
    SString s,t;
    printf("输入主串字符：");
    gets(ch);
    StrAssign_SS(s,ch);
    printf("输入模式字符："); 
    gets(ch);
    StrAssign_SS(t,ch);
	int c=StrIndex_BF(s,t);
	printf("\n模式匹配结果：%d\n",c); 
    return 0;
}
