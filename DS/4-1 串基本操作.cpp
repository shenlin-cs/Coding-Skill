#include <iostream>
#define STRING_SIZE 255
typedef unsigned char SString[STRING_SIZE+1];

void StrAssign_SS(SString &S,char chars[]){//��ֵ 
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
        if(chars_len>STRING_SIZE){//�ض� 
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

void StrConnect_SS(SString &T,SString S1,SString S2){//����b�ϲ�����a�ϣ�������ϲ���Ĵ�a�ͳ���
    if(S1[0]+S2[0]<=STRING_SIZE){
        int j=1,k=1;
        while(j<=S1[0])
			T[k++]=S1[j++];
        j=1;
        while(j<=S2[0]) 
			T[k++]=S2[j++];
        T[0]=S1[0]+S2[0];//��ȷ���� 
    }
    else if(S1[0]<STRING_SIZE){
    	int j=1,k=1;
    	while(j<=S1[0])
    		T[k++]=S1[j++];
		j=1;
		while(k<=STRING_SIZE) 
			T[k++]=S2[j++];
        T[0]=STRING_SIZE;//�ض�S2 
	}
	else if(S1[0]==STRING_SIZE){
    	int j=1,k=1;
    	while(j<=S1[0])
    		T[k++]=S1[j++];
        T[0]=STRING_SIZE;//�ض�S2 
	}
    else{
        int j=1,k=1;
        while(j<STRING_SIZE) 
			T[k++]=S1[j++];
        T[0]=STRING_SIZE;//�ض�S1
    }
}

void StrInsert_SS(SString &S1,SString S2,int pos){//����c���뵽��a�ĵ�i��λ���ϣ�����������Ĵ�a�ͳ���
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

void StrReplace_SS(SString &S1,SString S2,int pos,int num){//�ô�d�滻��a�ӵ�i��λ�ÿ�ʼ����len���ַ���������滻��Ĵ�a�ͳ���
    S1[0]=pos+S2[0]-1;
    if(pos+num<=STRING_SIZE){
        for(int i=pos,j=1;j<=S2[0];i++,j++)
            S1[i]=S2[j];
    }
    else
    	printf("Overflow");
}

void SubString_SS(SString &Sub,SString S,int pos,int len){
	//��Sub���ض���˳��S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ���
	if((pos<1)||(pos>S[0])||(len<0)||(len>S[0]-pos+1)) printf("Position Error");
	for(int i=1;i<len;i++) Sub[i]=S[pos+i-1];
	Sub[0]=len; 
}
/*
int StrIndex(SString S,SString T,int pos){
	//���ڴ�S�е�pos���ַ�����ҵ���һ����T��ȵ��Ӵ�����������S�е�λ�ã�
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
    printf("��aΪ��\n");
    ShowString(a);
    printf("��a�ĳ���Ϊ��%d\n",StrLength(a));
    printf("��bΪ��\n");
    ShowString(b);
    printf("��b�ĳ���Ϊ��%d\n",StrLength(b));
    printf("��cΪ��\n");
    ShowString(c);
    printf("��c�ĳ���Ϊ��%d\n",StrLength(c));
    printf("��dΪ��\n");
    ShowString(d);
    printf("��d�ĳ���Ϊ��%d\n",StrLength(d));
    printf("\n");
    
    StrConnect_SS(a, a, b);
    printf("ִ�кϲ���b������Ĵ�aΪ��\n");
    ShowString(a);
    printf("��a�ĳ���Ϊ��%d\n",StrLength(a));
    printf("\n");
    
    int i;
    scanf("%d",&i);
    printf("ִ���ڴ�a�ĵ�%d��λ���ϲ��봮c��Ĵ�aΪ��\n",i);
    StrInsert_SS(a,c,i);
    ShowString(a);
    printf("��a�ĳ���Ϊ��%d\n",StrLength(a));
    printf("\n");
    
    int pos,num;
    scanf("%d%d",&pos,&num);
    printf("ִ���ڴ�a�ĵ�%d��λ�����ô�d�滻%d���ַ��󣬴�aΪ��\n",pos,num);
    StrReplace_SS(a,d,pos,num);
    ShowString(a);
   	printf("��a�ĳ���Ϊ��%d\n",StrLength(a));
    return 0;
}

void Translation_SS(SString &S,char ch1,char ch2){
	//������˳��S��������ֵΪch1���ַ�����ch2���ַ� 
	for(int i=1;i<=S[0];i++){
		if(S[i]==ch1) S[i]=ch2;
	}
}

void Invert_SS(SString &S){//���� 
	for(int i=1;i<(S[0]/2);i++){
		char temp=S[i];
		S[i]=S[S[0]-i+1];
		S[S[0]-i+1]=temp;
	}
}

void DeleteChar_SS(SString &S,char ch){
	//ɾ��ֵΪch�������ַ� 
	for(int i=1;i<=(S[0]);i++){
		if(S[i]==ch){
			for(int j=i;j<(S[0]);j++) S[j]=S[j+1];
			S[0]=S[0]-1;
		}
	}
}
