#include<iostream>
#include<stdio.h>
using namespace std;
#define MAXNUM 20  
typedef struct //顺序队列类型定义 
{ 
	ElemType *base;
	int b1,b2;
}Array;

void InitArray(Array &A,int m,int n){
	A.base=new ElemType[n*m];
	if(!A.elem) Error("Overflow!");
	A.b1=m;
	A.b2=n;
}

void DestroyArray(Array &A){
	delete[]A.base;
	A.b1=A.b2=0;
}

void ValueArray(Array A,ElemType &e,int i,int j){
	if((0<=i)&&(i<A.b1)&&(0<=j)&&(j<A.b2)){
		off=A.b2*i+j;
		e=A.base[off];
	}
	else Error("Suffix Error!");
}

void AssignArray(Array &A,ElemType e,int i,int j){
	if((0<=i)&&(i<A.b1)&&(0<=j)&&(j<A.b2)){
		off=A.b2*i+j;
		A.base[off]=e;
	}
	else Error("Suffix Error!");
}
