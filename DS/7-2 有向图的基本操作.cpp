//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MaxVertexNum 20
typedef char VertexType;

typedef int ElemType;

typedef struct node {
	int adjvex;	
	struct node *next;
}EdgeNode, *EdgeLink;

typedef struct vnode {
	VertexType vertex;
	EdgeNode *firstedge;
}VertexNode;

typedef struct {
	VertexNode adjlist[MaxVertexNum];
	int n,e;		
}ALGraph;
//StudybarCommentEnd
typedef int ElemType;
//存储结构
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;	//队头指针
	QueuePtr rear;	//队尾指针
}LinkQueue;

void Error(char *s){
	printf("%s\n",s);
	exit(1);
}

void InitQueue_L(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	Q.front=Q.rear=NULL;
}

void EnQueue_L(LinkQueue &Q, ElemType e){
	QNode *p=new QNode;
	p->data=e;
	p->next=NULL;
	if(Q.front==Q.rear&&Q.front==NULL){
		Q.front=p;
		Q.rear=p;
	} 
	Q.rear->next=p;
	Q.rear=p;
}


void GetHead_L(LinkQueue Q, ElemType &e){
	if(Q.front->next==NULL) Error("Queue Empty!");
	e=Q.front->data;
}

void DeQueue_L(LinkQueue &Q, ElemType &e){
	QNode *p=new QNode;
	p=Q.front;
	e=Q.front->data;
	Q.front=Q.front->next;
	if(Q.rear==p) Q.rear=Q.front;
	delete p;
}

int locate(ALGraph G,int n){
	for(int k=0;k<G.n;k++){
		if(char(n+'0') == G.adjlist[k].vertex)
			return k;
	}
	return -1;
}

void CreateALGraph(ALGraph& G){
	int a,b,i;
	char t[20];
	printf("请输入顶点数和弧数：");
	scanf("%d %d",&G.n,&G.e);
	getchar();
	printf("请输入顶点信息：");
	gets(t);
	for(i=0;i<G.e;i++){
		G.adjlist[i].vertex=t[i];
		G.adjlist[i].firstedge=NULL;
	}
	for(i=1;i<=G.e;i++){
		printf("请输入第%d弧的起点和终点：",i);
		scanf("%d %d",&a,&b);
		a=locate(G,a);
		b=locate(G,b);
		EdgeNode* p=new EdgeNode;
		p->adjvex=b;
		p->next=G.adjlist[a].firstedge;
		G.adjlist[a].firstedge=p;
	}
}

void PrintALGraph(ALGraph G){
	printf("\n有向图的邻接表为：\n");
	for(int i=0;i<G.n;i++){
		printf("%d:",i);
		EdgeNode*p;
		printf("%c",G.adjlist[i].vertex);
		p=G.adjlist[i].firstedge;
		while(p){
			printf("->%d",p->adjvex);
			p=p->next;
		}
		printf("\n");
	}
	return;
}
void DFS_ALG(ALGraph G, int x, int visited[]){
	printf("%c ",G.adjlist[x].vertex);
	visited[x]=1;
	EdgeNode* p;
	for (p=G.adjlist[x].firstedge;p;p=p->next) {
		if(!visited[p->adjvex])
			DFS_ALG(G,p->adjvex,visited);
	}
}
void DFSTraverse(ALGraph G){
	int i,j;
	int visited[10];
	for (i=0;i<G.n;i++) {
		visited[i]=0;
	}
	for (i=0;i<G.n;i++) {
		if (!visited[i])
			DFS_ALG(G,i,visited);
	}
}

void BFSTraverse(ALGraph G) {
	int i,j;
	int visited[10];
	for(i=0;i<G.n;i++){
		visited[i]=0;
	}
	LinkQueue Q;
	InitQueue_L(Q);
	for(i=0;i<G.n;i++){
		if(visited[i]==0){
			printf("%c ",G.adjlist[i].vertex);
			visited[i]=1;
			EnQueue_L(Q,i);
			while(Q.front){
				int u;
				DeQueue_L(Q,u);
				u=locate(G,u);
				EdgeNode* p;
				for(p=G.adjlist[u].firstedge;p;p=p->next){
					if(!visited[p->adjvex]){
						printf("%c ",G.adjlist[p->adjvex].vertex);
						visited[p->adjvex]=1;
						EnQueue_L(Q,p->adjvex);
					}
				}
			}
		}
	}
}
//StudybarCommentBegin
int main()
{
	ALGraph G;
	CreateALGraph(G);
	PrintALGraph(G);
    printf("\n深度优先遍历：");
	DFSTraverse(G);
	printf("\n广度优先遍历：");
	BFSTraverse(G);
	printf("\n");
	return 0;
}
//StudybarCommentEnd
