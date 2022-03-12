//StudybarCommentBegin
#include <stdio.h>

#define Vertex_Max 100					
typedef char ElemType;					
typedef int VRType;						
typedef struct {
	ElemType vexs[Vertex_Max];			
	VRType edges[Vertex_Max][Vertex_Max];
	int vexnum,edgenum;					
}MGraph;

int main(){
	void CreateMGraph(MGraph *G);
	void PrintMGraph(MGraph *G);
	MGraph G;
	CreateMGraph(&G);
	PrintMGraph(&G);
	return 0;
}
//StudybarCommentEnd

void CreateMGraph(MGraph *G){
	int a,b;
	int i,j,k;
	printf("�����붥�����ͱ�����");
	scanf("%d %d",&G->vexnum,&G->edgenum);
	printf("�������붥����Ϣ��");
	scanf("%s",G->vexs);
	for(i=0;i<G->vexnum;i++){
		for(j=0;j<G->vexnum;j++){
			G->edges[i][j]=0;
		}
	}
	for(k=0;k<G->edgenum;k++){
		printf("�������%d�ߵ������յ㣺",k+1);
		scanf("%d %d",&a,&b);
		G->edges[a][b]=G->edges[b][a]=1;
	}
}
void PrintMGraph(MGraph *G){
	int i,j;
	printf("\n����ͼ�Ķ�����ϢΪ��\n");
	for(i=0;i<G->vexnum-1;i++){
		printf("%c ",G->vexs[i]);
	}
	printf("%c",G->vexs[G->vexnum-1]);
	printf("\n");
	printf("����ͼ���ڽӾ���Ϊ��\n");
	for(i=0;i<G->vexnum;i++){
		for(j=0;j<G->vexnum-1;j++){
			printf("%d\t",G->edges[i][j]);
		}
		printf("%d",G->edges[i][G->vexnum-1]);
		printf("\n");
	}
}
