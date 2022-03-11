//设计一个算法，实现求解串S中出现的第一个最长的连续相同字符构成的平台。
#include <iostream>
#define STRING_SIZE 255
typedef unsigned char SString[STRING_SIZE+1];

void StrAssign_SS(SString &S,char chars[]){
    int i=0;
    int chars_len=0;
    while(chars[i]!='\0'){
        ++chars_len;
        ++i;
    }
    if(!chars_len)
		S[0]=0;
    else{
        int j=0;
        int k=1;
        if(chars_len>STRING_SIZE){
            while(k<STRING_SIZE)
                S[k++]=chars[j++];
            S[0]=STRING_SIZE;
        }
        else{
            while(k<STRING_SIZE)
                S[k++]=chars[j++];
            S[0]=chars_len;
        }
    }
}

int StrLength(SString &S){
    return S[0];
}

void GetEqualStr(SString &t,SString s){
	int pos=0,len=1,i=1;
	for(i=1;i<s[0];i++){
		if(s[i]==s[i+1]){
			int temp=1; 
			while((s[i]==s[i+1])&&(i<s[0])){
				temp++;
				i++;
			}
			if(temp>len){
				len=temp;
				pos=i-temp+1;
			}
		}
	}
	t[0]=len;
	for(i=0;i<t[0];i++){
		t[i+1]=s[pos+i];
	}
}
void Showstr(SString s){
	for(int i=1;i<=s[0];i++)
        printf("%c",s[i]);
} 
int main(){
    char ch[255];
    SString s,t;
    gets(ch);
    StrAssign_SS(s,ch);
    printf("输入串是：");
	Showstr(s);
    GetEqualStr(t,s);
    printf("\n最长平台：");
    Showstr(t);
    return 0;
}
