#include<stdio.h>
struct matrix{
	int data[100];
	int size;
};

int main(){
	printf("请输入对称矩阵的行数（即列数）：");
	int n,i,j,k,a,b;matrix A,B;
	scanf("%d",&n);
	A.size=n*(n+1)/2;
	B.size=n*(n+1)/2;
	printf("请输入对称矩阵A的下三角元素，共%d个：",A.size);
	for(i=0;i<A.size;i++){
		scanf("%d",&A.data[i]);
	}
	printf("请输入对称矩阵B的下三角元素，共%d个：",B.size);
	for(i=0;i<B.size;i++){
		scanf("%d",&B.data[i]);
	}
	printf("\nA的下三角元素为：");
	for(i=0;i<A.size;i++){
		printf("%d ",A.data[i]);	
	}
	printf("\nB的下三角元素为：");
	for(i=0;i<B.size;i++){
		printf("%d ",B.data[i]);
	}
	printf("\n");
	
	int matrixA[100]={0};
	int matrixB[100]={0};
	int matrixC[100]={0};
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i>=j){
				a=i;
				b=j;
			}
			else{
				a=j;
				b=i;
			}
			matrixA[i*n+j]=A.data[a*(a+1)/2+b];
			matrixB[i*n+j]=B.data[a*(a+1)/2+b];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				matrixC[i*n+j]+=matrixA[i*n+k]*matrixB[k*n+j];
			}
		}
	}
	printf("\n矩阵A*B的结果为：\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		    printf("%8d",matrixC[i*n+j]);
		}
		printf("\n");
	}
}
