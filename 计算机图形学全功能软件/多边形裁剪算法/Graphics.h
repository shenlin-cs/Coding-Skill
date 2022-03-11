#if !defined(ComputerGraphicsClass)
#define ComputerGraphicsClass

class CGraphics
{
public:
	CGraphics():PointCount(10),Point(NULL)
	{
		//CGraphics类的构造函数，初始化PointCount和Point
		Point = new CPoint[PointCount];
		Point[0] = CPoint(69,207);   Point[1] = CPoint(210,204);
		Point[2] = CPoint(250,86);   Point[3] = CPoint(292,206);
		Point[4] = CPoint(448,206);  Point[5] = CPoint(326,307);
		Point[6] = CPoint(378,468);  Point[7] = CPoint(253,365);
		Point[8] = CPoint(127,466);  Point[9] = CPoint(178,300);
		//10个点为五角星的顶点坐标

	}
	~CGraphics()
	{
		//析构函数，删除动态生成的Point指针
		if(Point)
			delete [] Point;
	};
	bool DrawPloyon(CDC*);
	//在指定设备中，画多边形
	bool FillPloyon(CDC*);
	//填充多边形
	bool InterCross(CPoint,CPoint,CPoint,CPoint,CPoint&);
	//判断两条线段是否相交
	bool CutRect(CRect);
	//对多边形进行裁减
	bool IsInSquareRgn(CRect,CPoint,int);
	//对多边形裁减时，判断线段端点是否在可视一侧
	int AfterIndex(int i)
	{
		return (i == PointCount-1)?0:i+1;
	}
	//获取下一个点的索引号
	int BeforeIndex(int i)
	{
		return (i == 0 )? PointCount-1:i-1;
	}
	//获取前一个点的索引号
	bool SortArray(int*,int);
	//冒泡排序
public:
	CPoint *Point;
	//指向点坐标的指针
	int PointCount;
	//多边形点的个数
};



#endif