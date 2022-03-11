#include<stdio.h>

struct data{
	int row,col;
	int e;
};

struct Matrix{
	data data[100];
	int mu,nu,tu;
};

void InitSMatrix_TSM(Matrix &M){
	printf("请输入稀疏矩阵的行数、列数、非零元个数：\n");
	scanf("%d %d %d",&M.mu,&M.nu,&M.tu);
	printf("请按照行优先顺序输入稀疏矩阵的非零元值：\n"); 
	for(int i=1;i<=M.tu;i++){
		scanf("%d %d %d",&M.data[i].row,&M.data[i].col,&M.data[i].e);
	}
}

void PrintSMatrix(Matrix M){
 	for(int i=1;i<=M.tu;i++)
 	printf("%d %d %d\n",M.data[i].row,M.data[i].col,M.data[i].e);
}

//直接取——顺序存 
void TransSMatrix_TSM(Matrix M,Matrix &T){
	T.mu=M.nu;
	T.nu=M.mu;
	T.tu=M.tu;
	if(T.tu){
		int pt=1;
		for(int i=0;i<M.nu;++i){
			for(int pm=1;pm<=M.tu;++pm){
				if(M.data[pm].col==i){
					T.data[pt].row=M.data[pm].col;
					T.data[pt].col=M.data[pm].row;
					T.data[pt].e=M.data[pm].e;
					++pt;
				}
			}
		}
	}
}

//顺序取——直接存 
void FastTransSMatrix_TSM(Matrix M,Matrix &T){
	T.mu=M.nu;
	T.nu=M.mu;
	T.tu=M.tu;
	int copt[100];
	int num[100];
	if(T.tu){
		int i;
		for(i=0;i<M.nu;++i)
			num[i]=0;
		for(i=1;i<=M.tu;++i)
			++num[M.data[i].col];
		copt[0]=1;
		for(i=1;i<M.nu;++i)
			copt[i]=copt[i-1]+num[i-1];
		for(i=1;i<=M.tu;++i){
			int j=M.data[i].col;
			int k=copt[j];
			T.data[k].row=M.data[i].col;
			T.data[k].col=M.data[i].row;
			T.data[k].e=M.data[i].e;
			++copt[j];
		}
	} 
}

int main(){
	Matrix m,t1,t2;
	InitSMatrix_TSM(m);
	printf("源三元组顺序表如下：\n");
	PrintSMatrix(m);
	TransSMatrix_TSM(m,t1);
	printf("使用直接取、顺序存转置算法转置后的三元组顺序表如下：\n");
	PrintSMatrix(t1);
	FastTransSMatrix_TSM(m,t2);
	printf("使用顺序取、直接存转置算法转置后的三元组顺序表如下：\n");
	PrintSMatrix(t2);
	return 0;
}
