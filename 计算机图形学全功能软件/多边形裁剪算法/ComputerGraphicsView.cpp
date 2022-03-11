    // ComputerGraphicsView.cpp : implementation of the CComputerGraphicsView class
//

#include "stdafx.h"
#include "ComputerGraphics.h"

#include "ComputerGraphicsDoc.h"
#include "ComputerGraphicsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsView

IMPLEMENT_DYNCREATE(CComputerGraphicsView, CScrollView)

BEGIN_MESSAGE_MAP(CComputerGraphicsView, CScrollView)
	//{{AFX_MSG_MAP(CComputerGraphicsView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_VIEW_DEFINERECT, OnViewDefineRect)
	ON_COMMAND(ID_EDIT_DEFINEPOINT, OnEditDefinePoint)
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsView construction/destruction

CComputerGraphicsView::CComputerGraphicsView()
{
	// TODO: add construction code here
	m_bCaptured=false;
	m_bDefineRect=false;
	m_bDefinePointV=false;
}

CComputerGraphicsView::~CComputerGraphicsView()
{
}

BOOL CComputerGraphicsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsView drawing

void CComputerGraphicsView::OnDraw(CDC* pDC)
{
	CComputerGraphicsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int l,t,r,b;
	l=min(TopLeft.x,BottomRight.x);
	r=max(TopLeft.x,BottomRight.x);
	t=min(TopLeft.y,BottomRight.y);
	b=max(TopLeft.y,BottomRight.y);
	CRect rect(l,t,r,b);
	//定义裁减矩形区域，并赋值

	CPen penDot,penSolid;
	penDot.CreatePen(PS_DOT,1,RGB(0,0,0));
	pDC->SelectObject(penDot);
	pDC->Rectangle(rect);
	//用虚线画出裁减矩形区域

	penSolid.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(penSolid);
	pDC->TextOut(10,10,"鼠标左键点击“图像处理”->“自定义多边形点坐标”（鼠标左键定义点坐标（一个小圆形），右键结束）");
	pDC->TextOut(10,35,"鼠标左键点击“图像处理”->“自定义裁剪区域”（按住鼠标左键不放，移动鼠标，画出一个矩形框）");
	pDC->TextOut(10,60,"接下来可以选择“多边形填充”、“多边形裁剪”（下方五角星为一初始图形）");
	//屏幕上的提示信息

	if(PointArray.GetSize())
	{
		//当自定义多边形点坐标时，在各个点坐标处画一个小圆，以显示点的位置
		int i;
		for(i=0;i<PointArray.GetSize();i++)
		{
			pDC->MoveTo(PointArray.GetAt(i));
			CRect ellipseRect;
			ellipseRect.top = PointArray.GetAt(i).y - 5;
			ellipseRect.bottom = PointArray.GetAt(i).y + 5;
			ellipseRect.left = PointArray.GetAt(i).x - 5;
			ellipseRect.right = PointArray.GetAt(i).x + 5;
			pDC->Ellipse(ellipseRect);
		}
	}

	if(pDoc->bCutRect) 
	{
		//判断是否裁减，若是，则根据裁减区域进行裁减
		pDoc->m_grahics.CutRect(rect);
		pDoc->bCutRect=false;
	}
	pDoc->m_grahics.DrawPloyon(pDC);
	//画出多边形
	if(pDoc->bFillPloyon)
	{
		//判断是否填充，根据需要进行相应的操作
		pDoc->m_grahics.FillPloyon(pDC);
		pDoc->bFillPloyon=false;
	}
}

void CComputerGraphicsView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
	
	CComputerGraphicsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//设置初始的裁减区域
	int minX = pDoc->m_grahics.Point[0].x , minY = pDoc->m_grahics.Point[0].y;
	int maxX = pDoc->m_grahics.Point[0].x , maxY = pDoc->m_grahics.Point[0].y;
	for(int i=1;i<pDoc->m_grahics.PointCount;i++)
	{
		if(minX > pDoc->m_grahics.Point[i].x)
			minX = pDoc->m_grahics.Point[i].x;
		if(minY > pDoc->m_grahics.Point[i].y)
			minY = pDoc->m_grahics.Point[i].y;
		if(maxX < pDoc->m_grahics.Point[i].x)
			maxX = pDoc->m_grahics.Point[i].x;
		if(maxY < pDoc->m_grahics.Point[i].y)
			maxY = pDoc->m_grahics.Point[i].y;
	}
	TopLeft = CPoint(minX,minY);
	BottomRight = CPoint(maxX,maxY);
}

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsView diagnostics

#ifdef _DEBUG
void CComputerGraphicsView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CComputerGraphicsView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CComputerGraphicsDoc* CComputerGraphicsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComputerGraphicsDoc)));
	return (CComputerGraphicsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsView message handlers

void CComputerGraphicsView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//对鼠标按下左键的相应
	CScrollView::OnLButtonDown(nFlags, point);
	if(m_bDefineRect)
    {	
		//如果是自定义裁减的区域的操作
		SetCapture();//捕获鼠标
		m_bCaptured = TRUE;
		CDC *dc=GetDC();
		CRect rect(TopLeft,BottomRight);
		dc->SelectStockObject(WHITE_PEN);

		
		dc->Rectangle(rect);
		InvalidateRect(rect,false);
		TopLeft = point;

		::SetCursor(::LoadCursor(NULL, IDC_CROSS));//设置鼠标样子为十字形的
	}
	if(m_bDefinePointV)
	{
		//如果是自定义点坐标的操作
		PointArray.Add(point);
		CRect ellipseRect;
		ellipseRect.top = point.y - 5;
		ellipseRect.bottom = point.y + 5;
		ellipseRect.left = point.x - 5;
		ellipseRect.right = point.x + 5;
		InvalidateRect(ellipseRect,true);
	}
}

void CComputerGraphicsView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CScrollView::OnMouseMove(nFlags, point);
	//对鼠标移动时的相应
	if (m_bCaptured) 
	{
		//画出相应的矩形裁减边框
		CDC *dc=GetDC();
		CRect rect(TopLeft,BottomRight);
		dc->SelectStockObject(WHITE_PEN);

		
		dc->Rectangle(rect);//用白色擦除原先的矩形边框
		InvalidateRect(rect,false);
		BottomRight=point;
		
		CRect newrect(TopLeft,BottomRight);
		CPen pen;
		pen.CreatePen(PS_DOT,1,RGB(0,0,0));
		dc->SelectObject(pen);
		dc->Rectangle(newrect);//用虚线画出新的矩形边框
    }

	
}

void CComputerGraphicsView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CScrollView::OnLButtonUp(nFlags, point);
	//对鼠标放开左键的相应
    if (m_bCaptured) 
	{
		::ReleaseCapture();
        m_bCaptured = false;
		m_bDefineRect = false;
	}
}

void CComputerGraphicsView::OnViewDefineRect() 
{
	//设置是否自定义裁减区域
	m_bDefineRect = true;
}

void CComputerGraphicsView::OnEditDefinePoint() 
{
	//设置是否自定义点的坐标
	m_bDefinePointV = true;
}

void CComputerGraphicsView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	////对鼠标放开右键的相应
	CScrollView::OnRButtonUp(nFlags, point);
	int i;
	if(m_bDefinePointV)
	{
		CComputerGraphicsDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->m_grahics.PointCount=PointArray.GetSize();
		if(pDoc->m_grahics.Point)
			delete pDoc->m_grahics.Point;
		pDoc->m_grahics.Point = new CPoint[pDoc->m_grahics.PointCount];
		for(int i=0;i<pDoc->m_grahics.PointCount;i++)
			pDoc->m_grahics.Point[i]=PointArray.GetAt(i);//对Point点坐标重新赋值
		PointArray.RemoveAll();
		m_bDefinePointV=false;
		CRect rect;
		this->GetClientRect(rect);
		InvalidateRect(rect);
		
		//获取新的初始裁减矩形范围
		int minX = pDoc->m_grahics.Point[0].x , minY = pDoc->m_grahics.Point[0].y;
		int maxX = pDoc->m_grahics.Point[0].x , maxY = pDoc->m_grahics.Point[0].y;
		for(i=1;i<pDoc->m_grahics.PointCount;i++)
		{
			if(minX > pDoc->m_grahics.Point[i].x)
				minX = pDoc->m_grahics.Point[i].x;
			if(minY > pDoc->m_grahics.Point[i].y)
				minY = pDoc->m_grahics.Point[i].y;
			if(maxX < pDoc->m_grahics.Point[i].x)
				maxX = pDoc->m_grahics.Point[i].x;
			if(maxY < pDoc->m_grahics.Point[i].y)
				maxY = pDoc->m_grahics.Point[i].y;
		}
		TopLeft = CPoint(minX,minY);
		BottomRight = CPoint(maxX,maxY);
	}
}
