#include "stdafx.h"
#include "Graphics.h"

//��ָ����pDC�豸�У��������
bool CGraphics::DrawPloyon(CDC* pDC)
{
	if(PointCount < 3)
		return false;
	//�������С���������򷵻�

	pDC->MoveTo(Point[0]);
	for(int i=1;i<PointCount;i++)
	{	
		pDC->LineTo(Point[i]);
	}
	pDC->LineTo(Point[0]);
	//��pDC�л��������

	return true;
}

//��ָ����pDC�豸�У��������
bool CGraphics::FillPloyon(CDC* pDC)
{
	if(PointCount < 3)
		return false;
	//�������С���������򷵻�
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
	//��ȡ��������������������ֵ����Сֵ����Ϊɨ����ѭ���ķ�Χ

	CUIntArray myArray;
	int x,y,i;
	for(y=minY;y<maxY;y++)
	{
		//ɨ���ߴ�minY��ʼ��maxY
		for(i=0;i<PointCount;i++)
		{
			//��ÿ���߽���ѭ��
			CPoint PointCross;
			int beforeI=BeforeIndex(i),afterI=AfterIndex(i);
			//�ж��Ƿ���߶��ཻ
			if(InterCross(Point[beforeI],Point[i],CPoint(minX,y),CPoint(maxX,y),PointCross))
			{
				//���Ǵ��ڽ��㣬�������Ӧ���жϣ����ж�x������ȡ���Ρ�һ�λ��ǲ�ȡ
				if(PointCross==Point[i])
				{
					if((Point[beforeI].y > PointCross.y) && (Point[afterI].y > PointCross.y))
					{
						myArray.Add(PointCross.x);
						myArray.Add(PointCross.x);
						//�߶����yֵ���ڽ����yֵ��x����ȡ����
					}
					else
						if((Point[beforeI].y - PointCross.y) * (Point[afterI].y - PointCross.y) < 0)
							myArray.Add(PointCross.x);		//�߶����yֵ�ڽ����yֵ֮�䣬��һ�������yֵ���ڽ����yֵ������һ��С�ڣ���Ӧ��x����ȡһ��					
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
						myArray.Add(PointCross.x);//�����㲻���߶εĶ���ʱ��x����ֻȡһ��
					
			}	
		}
		int *scanLineX,num=myArray.GetSize();
		scanLineX = new int[num];
		for(i=0;i<num;i++)
			scanLineX[i]=myArray.GetAt(i);//��ȡɨ����xֵ���Թ����������
		myArray.RemoveAll();
		SortArray(scanLineX,num);//��scanLine��ɨ����x�����������
		for(i=0;i<num;i=i+2)
		{
			if(i+1>=num)
				break;
			for(x=scanLineX[i];x<scanLineX[i+1];x++)//xֵ������
				pDC->SetPixelV(CPoint(x,y),RGB(255,0,0));//�����������Ӧ�����ɫ���óɺ�ɫ

		}
        Sleep(1);//CPU��ͣ1ms�������ֳ����������ɨ���ߵķ�ʽ��һ��һ��������
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
	//��ȡ�ü����ε��ĸ�������꣬��һ����Ϊ���ϣ��ڶ�����Ϊ���ϣ���������Ϊ���£����ĸ���Ϊ����
	int i;
	CArray<CPoint,CPoint&> myArray;//�ü��󣬱���Ķ���ε����θ��������
	for(int rectNum=0;rectNum<4;rectNum++)
	{
		//�Բü����ε������߽���ѭ��
		for(i=0;i<PointCount;i++)
		{
			//��ÿ���߽���ѭ��
			CPoint PointCross;
			int beforeI=BeforeIndex(i),afterI=AfterIndex(i);
			int afterrectNum = ((rectNum == 3)?0:rectNum+1);
			//�ж��Ƿ���߶��ཻ
			if(InterCross(Point[beforeI],Point[i],rectPoint[rectNum],rectPoint[afterrectNum],PointCross))
			{
				if(PointCross==Point[i])
				{
					myArray.Add(Point[i]);//�������߶��ϣ�ֱ����ӵ������ڱ������ε�������
				}
				else 
					if(PointCross==Point[beforeI])
					{
						if(IsInSquareRgn(rect,Point[i],rectNum))
							myArray.Add(Point[i]);//�ж��Ƿ���ӣ����ǣ�����ӵ�����
					}
					else
					{
						myArray.Add(PointCross);//���߶��ཻ�������㲻�ڶ����ϣ���ӽ�������
						if(IsInSquareRgn(rect,Point[i],rectNum))
							myArray.Add(Point[i]);//�ж��Ƿ���ӣ����ǣ�����ӵ�����

					}
					
			}
			else
				if(IsInSquareRgn(rect,Point[i],rectNum))
					myArray.Add(Point[i]);//�߶β��ཻ�������ж��Ƿ���ӣ����ǣ�����ӵ�����
			
		}
		PointCount=myArray.GetSize();
		if(Point)
			delete Point;
		Point = new CPoint[PointCount];
		for(i=0;i<PointCount;i++)
			Point[i]=myArray.GetAt(i);//���¸���������ֵ
		myArray.RemoveAll();
	}
	return true;
}

bool CGraphics::InterCross(CPoint objectP1,CPoint objectP2,CPoint scanP1,CPoint scanP2,CPoint& coordinate)
{
	//objectP1��objectP2��һ���߶εĶ������꣬��scanP1��scanP2����һ���߶εĶ�������
	if(objectP1 == objectP2)
		return false;//��objectP1��objectP2��ȣ��򹹲����߶Σ��˳�
	if(scanP1 == scanP2)
		return false;//��scanP1��scanP2�ȣ��򹹲����߶Σ��˳�
	if( ( objectP1.y - objectP2.y ) * ( scanP1.x - scanP2.x )
		== ( scanP1.y - scanP2.y ) * ( objectP1.x - objectP2.x))
	{
		//��б����ȵ�����µĴ���
		if((objectP1.y-objectP2.y)*(scanP1.x-objectP1.x)==(objectP1.x-objectP2.x)*(scanP1.y-objectP1.y))
		{
			//�ж������߶��ǲ���ͬһ���߶�
			coordinate=objectP2;
			return true;
		}
		else
			return false;
	}
	if(objectP1.x == objectP2.x)
	{
		//����һ���߶�б�ʲ������ǵģ�����취
		double x,y;
		x = objectP1.x;
		y = (scanP1.y-scanP2.y)*1.0/(scanP1.x-scanP2.x)*(objectP1.x-scanP1.x)+scanP1.y;
		y = (float)((int)(y+0.5));
		if(((objectP1.y-y)*(y-objectP2.y)>=0) && ((objectP1.x-x)*(x-objectP2.x)>=0))
		{
			//�жϽ����ǲ����ڸ������߶���
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
			//���ڶ����߶�б�ʲ������ǵģ�����취
			double x,y;
			x = scanP1.x;
			y = (objectP1.y-objectP2.y)*1.0/(objectP1.x-objectP2.x)*(scanP1.x-objectP1.x)+objectP1.y;
			y = (float)((int)(y+0.5));
			if(((objectP1.y-y)*(y-objectP2.y)>=0) && ((objectP1.x-x)*(x-objectP2.x)>=0))
			{
				//�жϽ����ǲ����ڸ������߶���
				coordinate.x = scanP1.x;
				coordinate.y = (int)(y+0.5);
				return true;
			}
			return false;
		}
		else
		{
			//�����߶�б�ʶ�����ʱ�Ĵ���취
			double k1,k2;
			k1 = ( objectP1.y - objectP2.y ) * 1.0 / ( objectP1.x - objectP2.x);
			k2 = ( scanP1.y - scanP2.y ) * 1.0 / ( scanP1.x - scanP2.x );
			//k1,k2Ϊ��������߶ε�б��
			double x,y;
			x = (scanP1.y-objectP1.y-k2*scanP1.x+k1*objectP1.x)/(k1-k2);
			y = (k1*k2*scanP1.x-k1*k2*objectP1.x+k2*objectP1.y-k1*scanP1.y)/(k2-k1);
			x=(float)((int)(x+0.5));
			y = (float)((int)(y+0.5));

			if(((objectP1.y-y)*(y-objectP2.y)>=0) && ((objectP1.x-x)*(x-objectP2.x)>=0))
			{
				//�жϽ����ǲ����ڸ������߶���
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
	//ð������
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
	//�Զ���βü�ʱ���ж��߶ζ˵��Ƿ��ڿ���һ�࣬�жϾ���ֱ���жϵ�����Ĺ�ϵ
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