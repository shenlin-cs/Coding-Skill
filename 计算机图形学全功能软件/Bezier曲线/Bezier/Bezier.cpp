#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "GL/glut.h"

//定义控制点数目的最大值
#define MAX_CPTX 30 
int ncpts=0;//实际控制点个数
static int width=1024,height=640;//窗口大小

typedef struct{
	GLfloat x,y;
} ppoint;
ppoint cpts[MAX_CPTX];//存储控制点坐标

//求阶乘
int JieCheng(int n){
	if(n==1||n==0)
		return 1;
	else
		return n*JieCheng(n-1);
}
//求组合排列
double C(int n,int i){
	return ((double)JieCheng(n))/((double)(JieCheng(i)*JieCheng(n-i)));
}
//求一个数的N次方
double N(double u,int n){
	double sum=1.0;
	if (n==0)
		return 1;
	for(int i=0;i<n;i++)
		sum*=u;
	return sum;
}

//绘制bezier曲线
void drawBezier(ppoint *p){    
	void display();
	if(ncpts<=0) return;
	int n=ncpts-1;
	while(n){
		glBegin(GL_LINES); ///在下面2个点之间画一条虚线  
		glVertex2f(cpts[n].x,cpts[n].y);  
		glVertex2f(cpts[n-1].x,cpts[n-1].y);
		glEnd(); //结束 
		n--;
	}
	ppoint *p1;
	p1=new ppoint[1000];
	GLfloat u=0,x,y;
	int i,num=1;
	p1[0]=p[0];
	for(u=0;u<=1;u=u+0.001){   
		x=0;
		y=0;
		for(i=0;i<ncpts;i++){	
	      x+=C(ncpts-1,i)*N(u,i)*N((1-u),(ncpts-1-i))*p[i].x;
	      y+=C(ncpts-1,i)*N(u,i)*N((1-u),(ncpts-1-i))*p[i].y;
		}
		p1[num].x=x;
		p1[num].y=y;
		num++;
	}	
	    glPointSize(4.0);
	    glColor3f(0.0,0.0,0.0);
		glDisable(GL_LINE_STIPPLE);
	    glBegin(GL_LINE_STRIP);
	    for(int k=0;k<1000;k++)
		  glVertex2f(p1[k].x,p1[k].y);
	    glEnd();
	    glFlush();
		return;
}

//输入新的控制点
static void mouse(int button, int state,int x,int y){
	void display();
	float wx,wy;
	//鼠标未按下左键，不做响应
	if(state!=GLUT_DOWN)
		return;
	else{
		if(button==GLUT_LEFT_BUTTON){
			//转换坐标
			wx=(2.0*x)/(float)(width-1)-1.0;
			wy=(2.0*(height-1-y))/(float)(height-1)-1.0;
			//判断控制点数目是否超过最大值
			if(ncpts==MAX_CPTX)
				return;
			//存储控制点
			cpts[ncpts].x=wx;
			cpts[ncpts].y=wy;
			int n=ncpts;
			while(n){
				glEnable(GL_LINE_STIPPLE);//启动虚线模式，使用glDisable(GL_LINE_STIPPLE)可以关闭  
				glLineStipple(2,0x0F0F);//设置虚线的样式  
				glLineWidth(1.0f);//指定线宽
				glBegin(GL_LINES); ///在下面2个点之间画一条虚线  
				glVertex2f(cpts[n].x,cpts[n].y);  
				glVertex2f(cpts[n-1].x,cpts[n-1].y);
				glEnd(); //结束 
				n--;
			}
			ncpts++;
			//绘制控制点
			glColor3f(0.0,0.0,0.0);
			glPointSize(5.0);
			glBegin(GL_POINTS);
			glVertex2f(wx,wy);
			glEnd();
			glFlush();
		}
		if(button==GLUT_RIGHT_BUTTON){
			display();
			drawBezier(cpts);
		}
	}
}

void display(void){
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	for (i=0;i<ncpts;i++)
		glVertex2f(cpts[i].x,cpts[i].y);
	glEnd();
	glFlush();
}

//重绘函数
void reshape(int w,int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,w,h);//调整视口
	width=w;
	height=h;
}

int main(int argc, char **argv){
	//初始化
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(width,height);
	glutCreateWindow("Bezier-申林：单击左键绘制顶点，单击右键绘制曲线，可连续操作");

	//注册回调函数
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glutMainLoop();
}