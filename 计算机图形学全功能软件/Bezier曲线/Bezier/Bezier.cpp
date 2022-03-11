#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "GL/glut.h"

//������Ƶ���Ŀ�����ֵ
#define MAX_CPTX 30 
int ncpts=0;//ʵ�ʿ��Ƶ����
static int width=1024,height=640;//���ڴ�С

typedef struct{
	GLfloat x,y;
} ppoint;
ppoint cpts[MAX_CPTX];//�洢���Ƶ�����

//��׳�
int JieCheng(int n){
	if(n==1||n==0)
		return 1;
	else
		return n*JieCheng(n-1);
}
//���������
double C(int n,int i){
	return ((double)JieCheng(n))/((double)(JieCheng(i)*JieCheng(n-i)));
}
//��һ������N�η�
double N(double u,int n){
	double sum=1.0;
	if (n==0)
		return 1;
	for(int i=0;i<n;i++)
		sum*=u;
	return sum;
}

//����bezier����
void drawBezier(ppoint *p){    
	void display();
	if(ncpts<=0) return;
	int n=ncpts-1;
	while(n){
		glBegin(GL_LINES); ///������2����֮�仭һ������  
		glVertex2f(cpts[n].x,cpts[n].y);  
		glVertex2f(cpts[n-1].x,cpts[n-1].y);
		glEnd(); //���� 
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

//�����µĿ��Ƶ�
static void mouse(int button, int state,int x,int y){
	void display();
	float wx,wy;
	//���δ���������������Ӧ
	if(state!=GLUT_DOWN)
		return;
	else{
		if(button==GLUT_LEFT_BUTTON){
			//ת������
			wx=(2.0*x)/(float)(width-1)-1.0;
			wy=(2.0*(height-1-y))/(float)(height-1)-1.0;
			//�жϿ��Ƶ���Ŀ�Ƿ񳬹����ֵ
			if(ncpts==MAX_CPTX)
				return;
			//�洢���Ƶ�
			cpts[ncpts].x=wx;
			cpts[ncpts].y=wy;
			int n=ncpts;
			while(n){
				glEnable(GL_LINE_STIPPLE);//��������ģʽ��ʹ��glDisable(GL_LINE_STIPPLE)���Թر�  
				glLineStipple(2,0x0F0F);//�������ߵ���ʽ  
				glLineWidth(1.0f);//ָ���߿�
				glBegin(GL_LINES); ///������2����֮�仭һ������  
				glVertex2f(cpts[n].x,cpts[n].y);  
				glVertex2f(cpts[n-1].x,cpts[n-1].y);
				glEnd(); //���� 
				n--;
			}
			ncpts++;
			//���ƿ��Ƶ�
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

//�ػ溯��
void reshape(int w,int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,w,h);//�����ӿ�
	width=w;
	height=h;
}

int main(int argc, char **argv){
	//��ʼ��
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(width,height);
	glutCreateWindow("Bezier-���֣�����������ƶ��㣬�����Ҽ��������ߣ�����������");

	//ע��ص�����
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glutMainLoop();
}