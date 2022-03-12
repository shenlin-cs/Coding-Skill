#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

// ʹ�� Bresenham �㷨������б�ʵ�ֱ�ߣ�������ʼ�㣬��������ֹ�㣩
void Line_Bresenham(int x1, int y1, int x2, int y2, int color){
	int x = x1;
	int y = y1;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int s1 = x2 > x1 ? 1 : -1;
	int s2 = y2 > y1 ? 1 : -1;
	
	bool interchange = false;	// Ĭ�ϲ����� dx��dy
	if (dy > dx){				// ��б�ʴ��� 1 ʱ��dx��dy ����
		int temp = dx;
		dx = dy;
		dy = temp;
		interchange = true;
	}
	
	int p = 2 * dy - dx;
	for(int i = 0; i < dx; i++){
		putpixel(x, y, color);
		if (p >= 0){
			if (!interchange)		// ��б�� < 1 ʱ��ѡȡ�������ص�
				y += s2;
			else					// ��б�� > 1 ʱ��ѡȡ�������ص�
				x += s1;
			p -= 2 * dx;
		}
		if (!interchange)
			x += s1;				// ��б�� < 1 ʱ��ѡȡ x Ϊ����
		else
			y += s2;				// ��б�� > 1 ʱ��ѡȡ y Ϊ����
		p += 2 * dy;
	}
}

// ������
void main(){
	int n;
	printf("Ĭ��������һ������ԭ��(0,0,0)�����������ж��㶼�������ᡣ\n������������߳�������ֵ��100����");
	cin>>n;
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	
	// ���Ի���
	Line_Bresenham(320-n/2*1.732, 240+n/2, 0, 425, GREEN);
	Line_Bresenham(320, 240-n, 320, 0, GREEN);
	Line_Bresenham(320+n/2*1.732, 240+n/2, 640, 425, GREEN);
	
	// ���Ի�һ��������ĵ����
	Line_Bresenham(320, 240, 320-n/2*1.732, 240-n/2, BLACK);
	Line_Bresenham(320-n/2*1.732, 240-n/2, 320, 240-n, BLACK);
	Line_Bresenham(320, 240, 320+n/2*1.732, 240-n/2, BLACK);
	Line_Bresenham(320+n/2*1.732, 240-n/2, 320, 240-n, BLACK);
	Line_Bresenham(320-n/2*1.732, 240-n/2, 320-n/2*1.732, 240+n/2, BLACK);
	Line_Bresenham(320+n/2*1.732, 240-n/2, 320+n/2*1.732, 240+n/2, BLACK);
	Line_Bresenham(320, 240, 320, 240+n, BLACK);
	Line_Bresenham(320, 240+n, 320+n/2*1.732, 240+n/2, BLACK);
	Line_Bresenham(320, 240+n, 320-n/2*1.732, 240+n/2, BLACK);

	// ��������˳�
	getch();
	closegraph();
}