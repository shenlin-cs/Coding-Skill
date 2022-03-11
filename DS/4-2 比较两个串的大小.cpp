#include<stdio.h>  
  
int Strcmp(char *s,char *t){
    int i=0;  
    for(i=0;s[i]==t[i];i++)  {  
        if(s[i]=='\0')  
        return 0;  
    }     
    if(s[i]<t[i])  
        return -1;  
    else  
        return 1;  
    }  
int main(){  
    char s[100];char t[100];
	scanf("%s",&s); 
    scanf("%s",&t); 
    printf("s:%s\n",s); 
    printf("t:%s\n",t); 
    Strcmp(s,t);  
    printf("Strcmp(s,t)=%d\n",Strcmp(s,t));  
    return 0;  
}
/*
#include<stdio.h> 
#define STRING_SIZE 255
typedef unsigned char SString[STRING_SIZE+1]; 
  
int Strcmp(char *s,char *t){
    int i=0;  
    for(i=0;s[i]==t[i];i++)  {  
        if(s[i]=='\0')  
        return 0;  
    }     
    if(s[i]<t[i])  
        return -1;  
    else  
        return 1;  
}

	int strCompare_SS(SString S,SString T){
		for(int i=1;i<=S[0]&&i<=T[0];++i)
			if(S[i]!=T[i]) return (S[i]-T[i]);
		return (S[0]-T[0]);
	}

    
int main(){  
    SString s,t;
	scanf("%s",&s); 
    scanf("%s",&t); 
    printf("s:%s\n",s); 
    printf("t:%s\n",t); 
    strCompare_SS(s,t);  
    printf("Strcmp(s,t)=%d\n",strCompare_SS(s,t));  
    return 0;  
}
*/
