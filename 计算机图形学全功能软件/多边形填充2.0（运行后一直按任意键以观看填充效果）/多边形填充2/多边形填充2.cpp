// 多边形填充2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <windows.h>
using namespace std;
struct XET
{
	float xmin,ymax,ymin,dx;
}pNET[1024];
//N个顶点的坐标
struct node
{
	float x,y;
}point[1024];
//画图
void drawColor(float a,float b,int y)
{
	int x;
	for(x=a+0.5;x<=b+0.5;x++)
	putpixel(x,y,RED);
	//可以把下面这句取消注释，按回车看画线过程。
	system("pause");
} 
//优先队列保存某条扫描线上的x值
priority_queue<float,vector<float>,greater<float> >s;
int main()
{
	//i,j为for循环用到的，t为pNET[]数组的下标
	int i,j,t=0,N;
	//min_y为所有顶点y坐标的最小值，max_y为所有顶点y坐标的最大值
	int min_y=0x3fffffff,max_y=-1;
	printf("请输入顶点数N=:");
	scanf("%d",&N);
	printf("请按逆时针输入N个顶点的坐标（用空格分开）\n");
//	MOUSEMSG m;
//	m=GetMouseMsg();

	for(i=0;i<N;i++)
	{
		scanf("%f %f",&point[i].x,&point[i].y);
/*		if(m.uMsg==WM_LBUTTONDOWN){
		//选中方框时输出相应的flag
			point[i].x=m.x;
			point[i].y=m.y;
		}*/
		//查找所有顶点y坐标的最值
		if(point[i].y>max_y)
			max_y=point[i].y;
		if(point[i].y<min_y)
			min_y=point[i].y;
	}
	for(i=min_y;i<=max_y;i++)
	{
		for(j=0;j<N;j++)
		{
			if(point[j].y==i)
			{
				//按逆时针，某顶点的前一个顶点
				if(point[(j-1+N)%N].y>point[j].y)
				{
					struct XET p;
					p.xmin=point[j].x;
					p.ymax=point[(j-1+N)%N].y;
					p.ymin=point[j].y;
					p.dx=(point[(j-1+N)%N].x-point[j].x)/(point[(j-1+N)%N].y-point[j].y);
					//判断是否为局部最值
					if(point[(j+1+N)%N].y<=point[j].y)
						p.ymin++;
					pNET[t++]=p;
				}
				//按逆时针，某顶点的后一个顶点
				if(point[(j+1+N)%N].y>point[j].y)
				{
					struct XET p;
					p.xmin=point[j].x;
					p.ymax=point[(j+1+N)%N].y;
					p.ymin=point[j].y;
					p.dx=(point[(j+1+N)%N].x-point[j].x)/(point[(j+1+N)%N].y-point[j].y);
					//判断是否为局部最值
					if(point[(j-1+N)%N].y<=point[j].y)
						p.ymin++;
					pNET[t++]=p;
				}
			}
		}
	}


	initgraph(480,480);
	HWND hwnd=GetHWnd();//获取窗口句柄
	SetWindowText(hwnd,_T("多边形填充"));
	for(int x=1024;x>0;x--)
	{
		setlinecolor(RGB(255,255,255));
		line(x,0,x,600);
	}


	//所有扫描线进行扫描
	for(i=min_y;i<=max_y;i++)
	{
		for(j=0;j<t;j++)
		{
			//当前扫描线在某条边之间
			if(pNET[j].ymin<=i&&pNET[j].ymax>=i)
			{
				s.push(pNET[j].xmin);
				//更新xmin坐标
				pNET[j].xmin+=pNET[j].dx;
			}
		}
		while(!s.empty())
		{	//每两个一对,a,b均为扫描线上的x坐标
			float a=s.top();s.pop();
			float b=s.top();s.pop();
			drawColor(a,b,i);
		}
	}
	getch();
	closegraph();
	return 0;
}

