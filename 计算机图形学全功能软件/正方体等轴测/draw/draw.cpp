#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

// 使用 Bresenham 算法画任意斜率的直线（包括起始点，不包括终止点）
void Line_Bresenham(int x1, int y1, int x2, int y2, int color){
	int x = x1;
	int y = y1;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int s1 = x2 > x1 ? 1 : -1;
	int s2 = y2 > y1 ? 1 : -1;
	
	bool interchange = false;	// 默认不互换 dx、dy
	if (dy > dx){				// 当斜率大于 1 时，dx、dy 互换
		int temp = dx;
		dx = dy;
		dy = temp;
		interchange = true;
	}
	
	int p = 2 * dy - dx;
	for(int i = 0; i < dx; i++){
		putpixel(x, y, color);
		if (p >= 0){
			if (!interchange)		// 当斜率 < 1 时，选取上下象素点
				y += s2;
			else					// 当斜率 > 1 时，选取左右象素点
				x += s1;
			p -= 2 * dx;
		}
		if (!interchange)
			x += s1;				// 当斜率 < 1 时，选取 x 为步长
		else
			y += s2;				// 当斜率 > 1 时，选取 y 为步长
		p += 2 * dy;
	}
}

// 主函数
void main(){
	int n;
	printf("默认正方体一顶点在原点(0,0,0)，正方体所有顶点都在正半轴。\n请输入正方体边长（像素值如100）：");
	cin>>n;
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	
	// 测试画轴
	Line_Bresenham(320-n/2*1.732, 240+n/2, 0, 425, GREEN);
	Line_Bresenham(320, 240-n, 320, 0, GREEN);
	Line_Bresenham(320+n/2*1.732, 240+n/2, 640, 425, GREEN);
	
	// 测试画一个正方体的等轴侧
	Line_Bresenham(320, 240, 320-n/2*1.732, 240-n/2, BLACK);
	Line_Bresenham(320-n/2*1.732, 240-n/2, 320, 240-n, BLACK);
	Line_Bresenham(320, 240, 320+n/2*1.732, 240-n/2, BLACK);
	Line_Bresenham(320+n/2*1.732, 240-n/2, 320, 240-n, BLACK);
	Line_Bresenham(320-n/2*1.732, 240-n/2, 320-n/2*1.732, 240+n/2, BLACK);
	Line_Bresenham(320+n/2*1.732, 240-n/2, 320+n/2*1.732, 240+n/2, BLACK);
	Line_Bresenham(320, 240, 320, 240+n, BLACK);
	Line_Bresenham(320, 240+n, 320+n/2*1.732, 240+n/2, BLACK);
	Line_Bresenham(320, 240+n, 320-n/2*1.732, 240+n/2, BLACK);

	// 按任意键退出
	getch();
	closegraph();
}