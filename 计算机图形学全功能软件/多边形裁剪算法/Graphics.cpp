#include "stdafx.h"
#include "Graphics.h"

//在指定的pDC设备中，画多边形
bool CGraphics::DrawPloyon(CDC* pDC)
{
	if(PointCount < 3)
		return false;
	//若多边形小于三个点则返回

	pDC->MoveTo(Point[0]);
	for(int i=1;i<PointCount;i++)
	{	
		pDC->LineTo(Point[i]);
	}
	pDC->LineTo(Point[0]);
	//在pDC中画出多边形

	return true;
}

//在指定的pDC设备中，填充多边形
bool CGraphics::FillPloyon(CDC* pDC)
{
	if(PointCount < 3)
		return false;
	//若多边形小于三个点则返回
	int minX = Point[0].x , minY = Point[0].y;
	int maxX = Point[0].x , maxY = Point[0].y;

	for(int i=1;i<PointCount;i++)
	{
		if(minX > Point[i].x)
			minX = Point[i].x;
		if(minY > Point[i].y)
			minY = Point[i].y;
		if(maxX < Point[i].x)
			maxX = Point[i].x;
		if(maxY < Point[i].y)
			maxY = Point[i].y;
	}
	//获取多边形中所有坐标点的最大值和最小值，作为扫描线循环的范围

	CUIntArray myArray;
	int x,y,i;
	for(y=minY;y<maxY;y++)
	{
		//扫描线从minY开始到maxY
		for(i=0;i<PointCount;i++)
		{
			//对每条边进行循环
			CPoint PointCross;
			int beforeI=BeforeIndex(i),afterI=AfterIndex(i);
			//判断是否跟线段相交
			if(InterCross(Point[beforeI],Point[i],CPoint(minX,y),CPoint(maxX,y),PointCross))
			{
				//若是存在交点，则进行相应的判断，即判断x的坐标取两次、一次还是不取
				if(PointCross==Point[i])
				{
					if((Point[beforeI].y > PointCross.y) && (Point[afterI].y > PointCross.y))
					{
						myArray.Add(PointCross.x);
						myArray.Add(PointCross.x);
						//边顶点的y值大于交点的y值，x坐标取两次
					}
					else
						if((Point[beforeI].y - PointCross.y) * (Point[afterI].y - PointCross.y) < 0)
							myArray.Add(PointCross.x);		//边顶点的y值在交点的y值之间，即一个顶点的y值大于交点的y值，而另一个小于，相应的x坐标取一次					
						else
							if(PointCross.y==Point[afterI].y)
								myArray.Add(PointCross.x);    
				}
				else 
					if(PointCross==Point[beforeI])
					{
						continue;
					}
					else
						myArray.Add(PointCross.x);//当交点不在线段的顶点时，x坐标只取一次
					
			}	
		}
		int *scanLineX,num=myArray.GetSize();
		scanLineX = new int[num];
		for(i=0;i<num;i++)
			scanLineX[i]=myArray.GetAt(i);//获取扫描线x值，以构成填充区间
		myArray.RemoveAll();
		SortArray(scanLineX,num);//对scanLine（扫描线x坐标进行排序）
		for(i=0;i<num;i=i+2)
		{
			if(i+1>=num)
				break;
			for(x=scanLineX[i];x<scanLineX[i+1];x++)//x值配对填充
				pDC->SetPixelV(CPoint(x,y),RGB(255,0,0));//将填充区间相应点的颜色设置成红色

		}
        Sleep(1);//CPU暂停1ms，以体现出多边形是以扫描线的方式，一条一条的填充的
		delete scanLineX;

		
	}
	
	return true;

}

bool CGraphics::CutRect(CRect rect)
{
	CPoint rectPoint[4];
	rectPoint[0].x = rect.left;
	rectPoint[0].y = rect.top;
	rectPoint[1].x = rect.right;
	rectPoint[1].y = rect.top;
	rectPoint[3].x = rect.left;
	rectPoint[3].y = rect.bottom;
	rectPoint[2].x = rect.right;
	rectPoint[2].y = rect.bottom;
	//获取裁减矩形的四个点的坐标，第一个点为左上，第二个点为右上，第三个点为右下，第四个点为左下
	int i;
	CArray<CPoint,CPoint&> myArray;//裁减后，保存的多边形的依次各点的坐标
	for(int rectNum=0;rectNum<4;rectNum++)
	{
		//对裁减矩形的四条边进行循环
		for(i=0;i<PointCount;i++)
		{
			//对每条边进行循环
			CPoint PointCross;
			int beforeI=BeforeIndex(i),afterI=AfterIndex(i);
			int afterrectNum = ((rectNum == 3)?0:rectNum+1);
			//判断是否跟线段相交
			if(InterCross(Point[beforeI],Point[i],rectPoint[rectNum],rectPoint[afterrectNum],PointCross))
			{
				if(PointCross==Point[i])
				{
					myArray.Add(Point[i]);//交点在线段上，直接添加点坐标在保存多边形的数组中
				}
				else 
					if(PointCross==Point[beforeI])
					{
						if(IsInSquareRgn(rect,Point[i],rectNum))
							myArray.Add(Point[i]);//判断是否可视，若是，则添加点坐标
					}
					else
					{
						myArray.Add(PointCross);//跟线段相交，但交点不在顶点上，添加交点坐标
						if(IsInSquareRgn(rect,Point[i],rectNum))
							myArray.Add(Point[i]);//判断是否可视，若是，则添加点坐标

					}
					
			}
			else
				if(IsInSquareRgn(rect,Point[i],rectNum))
					myArray.Add(Point[i]);//线段不相交，但需判断是否可视，若是，则添加点坐标
			
		}
		PointCount=myArray.GetSize();
		if(Point)
			delete Point;
		Point = new CPoint[PointCount];
		for(i=0;i<PointCount;i++)
			Point[i]=myArray.GetAt(i);//重新赋予点坐标的值
		myArray.RemoveAll();
	}
	return true;
}

bool CGraphics::InterCross(CPoint objectP1,CPoint objectP2,CPoint scanP1,CPoint scanP2,CPoint& coordinate)
{
	//objectP1、objectP2是一条线段的顶点坐标，而scanP1、scanP2是另一条线段的顶点坐标
	if(objectP1 == objectP2)
		return false;//若objectP1、objectP2相等，则构不成线段，退出
	if(scanP1 == scanP2)
		return false;//若scanP1、scanP2等，则构不成线段，退出
	if( ( objectP1.y - objectP2.y ) * ( scanP1.x - scanP2.x )
		== ( scanP1.y - scanP2.y ) * ( objectP1.x - objectP2.x))
	{
		//对斜率相等的情况下的处理
		if((objectP1.y-objectP2.y)*(scanP1.x-objectP1.x)==(objectP1.x-objectP2.x)*(scanP1.y-objectP1.y))
		{
			//判断两条线段是不是同一条线段
			coordinate=objectP2;
			return true;
		}
		else
			return false;
	}
	if(objectP1.x == objectP2.x)
	{
		//当第一条线段斜率不存在是的，处理办法
		double x,y;
		x = objectP1.x;
		y = (scanP1.y-scanP2.y)*1.0/(scanP1.x-scanP2.x)*(objectP1.x-scanP1.x)+scanP1.y;
		y = (float)((int)(y+0.5));
		if(((objectP1.y-y)*(y-objectP2.y)>=0) && ((objectP1.x-x)*(x-objectP2.x)>=0))
		{
			//判断交点是不是在该两条线段上
			coordinate.x = objectP1.x;
			coordinate.y = (int)(y+0.5);
			return true;
		}
		return false;
	}
	else
	{
		if(scanP1.x == scanP2.x)
		{
			//当第二条线段斜率不存在是的，处理办法
			double x,y;
			x = scanP1.x;
			y = (objectP1.y-objectP2.y)*1.0/(objectP1.x-objectP2.x)*(scanP1.x-objectP1.x)+objectP1.y;
			y = (float)((int)(y+0.5));
			if(((objectP1.y-y)*(y-objectP2.y)>=0) && ((objectP1.x-x)*(x-objectP2.x)>=0))
			{
				//判断交点是不是在该两条线段上
				coordinate.x = scanP1.x;
				coordinate.y = (int)(y+0.5);
				return true;
			}
			return false;
		}
		else
		{
			//两条线段斜率都存在时的处理办法
			double k1,k2;
			k1 = ( objectP1.y - objectP2.y ) * 1.0 / ( objectP1.x - objectP2.x);
			k2 = ( scanP1.y - scanP2.y ) * 1.0 / ( scanP1.x - scanP2.x );
			//k1,k2为计算的两线段的斜率
			double x,y;
			x = (scanP1.y-objectP1.y-k2*scanP1.x+k1*objectP1.x)/(k1-k2);
			y = (k1*k2*scanP1.x-k1*k2*objectP1.x+k2*objectP1.y-k1*scanP1.y)/(k2-k1);
			x=(float)((int)(x+0.5));
			y = (float)((int)(y+0.5));

			if(((objectP1.y-y)*(y-objectP2.y)>=0) && ((objectP1.x-x)*(x-objectP2.x)>=0))
			{
				//判断交点是不是在该两条线段上
				coordinate.x = (int)(x+0.5);
				coordinate.y = (int)(y+0.5);
				return true;
			}
			return false;
		}
	}
	return true;
}

bool CGraphics::SortArray(int* iArray,int iLength)
{
	//冒泡排序
	int i,j,iTemp;
	bool bFlag;
	for(i=0;i<iLength;i++)
	{
		bFlag=true;
		for(j=0;j<iLength-i-1;j++)
		{
			if(iArray[j] > iArray[j+1])
			{
				iTemp=iArray[j];
				iArray[j]=iArray[j+1];
				iArray[j+1]=iTemp;
				bFlag=false;
			}
		}
		if(bFlag)
			break;
	}
	return true;
}

bool CGraphics::IsInSquareRgn(CRect rect,CPoint Point,int flag)
{
	//对多边形裁减时，判断线段端点是否在可视一侧，判断就是直接判断点坐标的关系
	switch(flag) {
	case 0:
		if(Point.y > rect.top)
			return true;
		else 
			return false;
		break;
	case 1:
		if(Point.x < rect.right)
			return true;
		else 
			return false;
		break;
	case 2:
		if(Point.y < rect.bottom)
			return true;
		else 
			return false;
		break;
	case 3:
		if(Point.x > rect.left)
			return true;
		else 
			return false;
		break;
	default:
		break;
	}
	return true;
}