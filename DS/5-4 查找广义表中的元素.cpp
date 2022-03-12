#include<stdio.h>
#include<stdlib.h>

//�����Ĵ洢�ṹ
struct GNode
{
	int tag;	//��־��
	union{		//ֵ����ӱ�ı�ͷָ����
		char data;
		struct GNode *sublist;
	};
	struct GNode *next;	//ָ���̽���ָ����
};

void CreateGList(struct GNode **GL);//���������Ĵ洢�ṹ
void PrintGList(struct GNode *GL);	//��ӡ��������
int SearchGList(struct GNode *GL, char e);//���ҵ��ڸ����ַ��ĵ�Ԫ�ؽ�㣬���ҳɹ��򷵻�1�����򷵻�0

int main()
{
	struct GNode *GL;//����ͷ���ӽ��
	printf("�������ַ����У�\n");
	CreateGList(&GL);
	printf("�´����Ĺ����");
	PrintGList(GL);
	printf("\n");
	printf("\n���������Ԫ�أ�\n");
	char d;
	scanf("%c",&d);
	if(SearchGList(GL, d)==0)
		printf("%c�ڹ�����в����ڣ�",d);
	else
		printf("%c�ڹ�����д��ڣ�",d);
}

//���������Ĵ洢�ṹ
void CreateGList(struct GNode **GL)
{
	char ch;
	scanf("%c", &ch);
	if(ch=='#')//������Ϊ�ո����ñ�ͷָ��Ϊ��
		*GL = NULL;
	if(ch=='(')//������Ϊ������������*GL��ָ����ӱ��㲢�ݹ鹹���ӱ�
	{
		*GL = new GNode;
		(*GL)->tag = 1;
		CreateGList(&((*GL)->sublist));
	}
	else{	//������Ϊ�ַ�������*GL��ָ��ĵ�Ԫ�ؽ��
		*GL = new GNode;
		(*GL)->tag = 0;
		(*GL)->data = ch;
	}
	scanf("%c", &ch);//�˴�������ַ���Ϊ���š������Ż�ֺ�
	if(*GL==NULL);	//��*GLΪ�գ���ʲô������
	else if(ch==',')//�����붺����ݹ鹹���̱�
		CreateGList(&((*GL)->next));
	else if((ch==')') || (ch=='\n'))//������Ϊ����������*GL�ĺ��ָ����Ϊ��
		(*GL)->next = NULL;
}

//��ӡ��������
void PrintGList(struct GNode *GL)
{
	//���ڱ���Ĵ������
	if(GL->tag==1){	//�����ӱ�����������ţ���Ϊ��ʼ����
		printf("(");
		if(GL->sublist==NULL)//���ӱ�Ϊ���������#���ַ�
			printf("#");
		else//���ӱ�ǿգ���ݹ�����ӱ�
			PrintGList(GL->sublist);
		printf(")");//��һ���ӱ����������Ӧ���һ����������ֹ��
	}
	else//���ڵ�Ԫ�ؽ�㣬������ý���ֵ
		printf("%c", GL->data);
	if(GL->next!=NULL)//������ĺ�̱�
	{
		printf(",");//��������ŷָ���
		PrintGList(GL->next);//�ٵݹ������̱�
	}
}

//���ҵ��ڸ����ַ��ĵ�Ԫ�ؽ�㣬���ҳɹ��򷵻�1�����򷵻�0
int SearchGList(struct GNode *GL, char e)
{
	int n=0;
	while(GL!=NULL){
		if(GL->tag == 1)
		{
			if(SearchGList(GL->sublist, e))
				return 1;
		}
		else
		{
			if(GL->data == e)
				return 1;
		}
		GL = GL->next;//ʹGLָ��ͬһ�����һ�����
	}
	return 0;
}
