#if !defined(ComputerGraphicsClass)
#define ComputerGraphicsClass

class CGraphics
{
public:
	CGraphics():PointCount(10),Point(NULL)
	{
		//CGraphics��Ĺ��캯������ʼ��PointCount��Point
		Point = new CPoint[PointCount];
		Point[0] = CPoint(69,207);   Point[1] = CPoint(210,204);
		Point[2] = CPoint(250,86);   Point[3] = CPoint(292,206);
		Point[4] = CPoint(448,206);  Point[5] = CPoint(326,307);
		Point[6] = CPoint(378,468);  Point[7] = CPoint(253,365);
		Point[8] = CPoint(127,466);  Point[9] = CPoint(178,300);
		//10����Ϊ����ǵĶ�������

	}
	~CGraphics()
	{
		//����������ɾ����̬���ɵ�Pointָ��
		if(Point)
			delete [] Point;
	};
	bool DrawPloyon(CDC*);
	//��ָ���豸�У��������
	bool FillPloyon(CDC*);
	//�������
	bool InterCross(CPoint,CPoint,CPoint,CPoint,CPoint&);
	//�ж������߶��Ƿ��ཻ
	bool CutRect(CRect);
	//�Զ���ν��вü�
	bool IsInSquareRgn(CRect,CPoint,int);
	//�Զ���βü�ʱ���ж��߶ζ˵��Ƿ��ڿ���һ��
	int AfterIndex(int i)
	{
		return (i == PointCount-1)?0:i+1;
	}
	//��ȡ��һ�����������
	int BeforeIndex(int i)
	{
		return (i == 0 )? PointCount-1:i-1;
	}
	//��ȡǰһ�����������
	bool SortArray(int*,int);
	//ð������
public:
	CPoint *Point;
	//ָ��������ָ��
	int PointCount;
	//����ε�ĸ���
};



#endif