#include <iostream>
#define STRING_SIZE 255
typedef unsigned char SString[STRING_SIZE+1];

void StrAssign_SS(SString &S,char chars[]){//赋值 
    int i=0;
    int chars_len=0;
    while(chars[i]!='\0'){
        ++chars_len;
        ++i;
    }
    if(!chars_len){
    	S[0]=0;
	}
    else{
        int j=0;
        int k=1;
        if(chars_len>STRING_SIZE){//截断 
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

void StrConnect_SS(SString &T,SString S1,SString S2){//将串b合并到串a上，并输出合并后的串a和长度
    if(S1[0]+S2[0]<=STRING_SIZE){
        int j=1,k=1;
        while(j<=S1[0])
			T[k++]=S1[j++];
        j=1;
        while(j<=S2[0]) 
			T[k++]=S2[j++];
        T[0]=S1[0]+S2[0];//正确连接 
    }
    else if(S1[0]<STRING_SIZE){
    	int j=1,k=1;
    	while(j<=S1[0])
    		T[k++]=S1[j++];
		j=1;
		while(k<=STRING_SIZE) 
			T[k++]=S2[j++];
        T[0]=STRING_SIZE;//截断S2 
	}
	else if(S1[0]==STRING_SIZE){
    	int j=1,k=1;
    	while(j<=S1[0])
    		T[k++]=S1[j++];
        T[0]=STRING_SIZE;//截断S2 
	}
    else{
        int j=1,k=1;
        while(j<STRING_SIZE) 
			T[k++]=S1[j++];
        T[0]=STRING_SIZE;//截断S1
    }
}

void StrInsert_SS(SString &S1,SString S2,int pos){//将串c插入到串a的第i个位置上，并输出插入后的串a和长度
    SString T;
    if(S1[0]+S2[0]<=STRING_SIZE){
        int j=1,k=1;
        while(j<pos) 
			T[k++]=S1[j++];
        j=1;
        while(j<=S2[0]) 
			T[k++]=S2[j++];
        j=pos;
        while(j<=S1[0])
			T[k++]=S1[j++];
        T[0]=S1[0]+S2[0];
    }
    else{
        if(pos+S1[0]<=STRING_SIZE){
            T[0]=0;
            int j=1,k=1;
            while(j<=pos){
                T[k++]=S1[j++];
                T[0]++;
            }
            j=1;
            while(j<=S2[0]){
                T[k++]=S2[j++];
                T[0]++;
            }
            j=pos+1;
            while(j<=STRING_SIZE){
                T[k++]=S1[j++];
                T[0]++;
            }
        }
        else{
            int j=1,k=1;
            while(j<=pos) 
				T[k++]=S1[j++];
            j=1;
            while(j<=STRING_SIZE) 
				T[k++]=S2[j++];
            T[0]=pos+STRING_SIZE;
        }
    }
    int i;
    for(i=0;i<=T[0];i++)
        S1[i]=T[i];
}

void StrReplace_SS(SString &S1,SString S2,int pos,int num){//用串d替换串a从第i个位置开始连续len个字符，并输出替换后的串a和长度
    S1[0]=pos+S2[0]-1;
    if(pos+num<=STRING_SIZE){
        for(int i=pos,j=1;j<=S2[0];i++,j++)
            S1[i]=S2[j];
    }
    else
    	printf("Overflow");
}

void SubString_SS(SString &Sub,SString S,int pos,int len){
	//用Sub返回定长顺序串S的第pos个字符起长度为len的子串；
	if((pos<1)||(pos>S[0])||(len<0)||(len>S[0]-pos+1)) printf("Position Error");
	for(int i=1;i<len;i++) Sub[i]=S[pos+i-1];
	Sub[0]=len; 
}
/*
int StrIndex(SString S,SString T,int pos){
	//若在串S中第pos个字符后查找到第一个与T相等的子串，返回其在S中的位置；
	if(pos>1){
		int s_len=StrLength(S);
		int t_len=StrLength(T);
		int i=pos;
		while(i<=(s_len-t_len+1)){
			SubString_SS(Sub,S,i,t_len);
			if(StrCompare(Sub,T)!=0) ++i;
			else return i;
		}
	}
	return -1; 
}
*/

void ShowString(SString S){
    for(int i=1;i<=S[0];i++)
        printf("%c",(char)S[i]);
    printf("\n");
}

int main()
{
    char ch[255];
    SString a,b,c,d;
    gets(ch);
    StrAssign_SS(a,ch);
    gets(ch);
    StrAssign_SS(b,ch);
    gets(ch);
    StrAssign_SS(c,ch);
    gets(ch);
    StrAssign_SS(d,ch);
    printf("\n");
    printf("串a为：\n");
    ShowString(a);
    printf("串a的长度为：%d\n",StrLength(a));
    printf("串b为：\n");
    ShowString(b);
    printf("串b的长度为：%d\n",StrLength(b));
    printf("串c为：\n");
    ShowString(c);
    printf("串c的长度为：%d\n",StrLength(c));
    printf("串d为：\n");
    ShowString(d);
    printf("串d的长度为：%d\n",StrLength(d));
    printf("\n");
    
    StrConnect_SS(a, a, b);
    printf("执行合并串b操作后的串a为：\n");
    ShowString(a);
    printf("串a的长度为：%d\n",StrLength(a));
    printf("\n");
    
    int i;
    scanf("%d",&i);
    printf("执行在串a的第%d个位置上插入串c后的串a为：\n",i);
    StrInsert_SS(a,c,i);
    ShowString(a);
    printf("串a的长度为：%d\n",StrLength(a));
    printf("\n");
    
    int pos,num;
    scanf("%d%d",&pos,&num);
    printf("执行在串a的第%d个位置上用串d替换%d个字符后，串a为：\n",pos,num);
    StrReplace_SS(a,d,pos,num);
    ShowString(a);
   	printf("串a的长度为：%d\n",StrLength(a));
    return 0;
}

void Translation_SS(SString &S,char ch1,char ch2){
	//将定长顺序串S中所有其值为ch1的字符换成ch2的字符 
	for(int i=1;i<=S[0];i++){
		if(S[i]==ch1) S[i]=ch2;
	}
}

void Invert_SS(SString &S){//反序 
	for(int i=1;i<(S[0]/2);i++){
		char temp=S[i];
		S[i]=S[S[0]-i+1];
		S[S[0]-i+1]=temp;
	}
}

void DeleteChar_SS(SString &S,char ch){
	//删除值为ch的所有字符 
	for(int i=1;i<=(S[0]);i++){
		if(S[i]==ch){
			for(int j=i;j<(S[0]);j++) S[j]=S[j+1];
			S[0]=S[0]-1;
		}
	}
}
