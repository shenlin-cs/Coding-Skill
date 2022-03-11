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
	//����ü��������򣬲���ֵ

	CPen penDot,penSolid;
	penDot.CreatePen(PS_DOT,1,RGB(0,0,0));
	pDC->SelectObject(penDot);
	pDC->Rectangle(rect);
	//�����߻����ü���������

	penSolid.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(penSolid);
	pDC->TextOut(10,10,"�����������ͼ����->���Զ������ε����ꡱ����������������꣨һ��СԲ�Σ����Ҽ�������");
	pDC->TextOut(10,35,"�����������ͼ����->���Զ���ü����򡱣���ס���������ţ��ƶ���꣬����һ�����ο�");
	pDC->TextOut(10,60,"����������ѡ�񡰶������䡱��������βü������·������Ϊһ��ʼͼ�Σ�");
	//��Ļ�ϵ���ʾ��Ϣ

	if(PointArray.GetSize())
	{
		//���Զ������ε�����ʱ���ڸ��������괦��һ��СԲ������ʾ���λ��
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
		//�ж��Ƿ�ü������ǣ�����ݲü�������вü�
		pDoc->m_grahics.CutRect(rect);
		pDoc->bCutRect=false;
	}
	pDoc->m_grahics.DrawPloyon(pDC);
	//���������
	if(pDoc->bFillPloyon)
	{
		//�ж��Ƿ���䣬������Ҫ������Ӧ�Ĳ���
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
	//���ó�ʼ�Ĳü�����
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
	//����갴���������Ӧ
	CScrollView::OnLButtonDown(nFlags, point);
	if(m_bDefineRect)
    {	
		//������Զ���ü�������Ĳ���
		SetCapture();//�������
		m_bCaptured = TRUE;
		CDC *dc=GetDC();
		CRect rect(TopLeft,BottomRight);
		dc->SelectStockObject(WHITE_PEN);

		
		dc->Rectangle(rect);
		InvalidateRect(rect,false);
		TopLeft = point;

		::SetCursor(::LoadCursor(NULL, IDC_CROSS));//�����������Ϊʮ���ε�
	}
	if(m_bDefinePointV)
	{
		//������Զ��������Ĳ���
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
	//������ƶ�ʱ����Ӧ
	if (m_bCaptured) 
	{
		//������Ӧ�ľ��βü��߿�
		CDC *dc=GetDC();
		CRect rect(TopLeft,BottomRight);
		dc->SelectStockObject(WHITE_PEN);

		
		dc->Rectangle(rect);//�ð�ɫ����ԭ�ȵľ��α߿�
		InvalidateRect(rect,false);
		BottomRight=point;
		
		CRect newrect(TopLeft,BottomRight);
		CPen pen;
		pen.CreatePen(PS_DOT,1,RGB(0,0,0));
		dc->SelectObject(pen);
		dc->Rectangle(newrect);//�����߻����µľ��α߿�
    }

	
}

void CComputerGraphicsView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CScrollView::OnLButtonUp(nFlags, point);
	//�����ſ��������Ӧ
    if (m_bCaptured) 
	{
		::ReleaseCapture();
        m_bCaptured = false;
		m_bDefineRect = false;
	}
}

void CComputerGraphicsView::OnViewDefineRect() 
{
	//�����Ƿ��Զ���ü�����
	m_bDefineRect = true;
}

void CComputerGraphicsView::OnEditDefinePoint() 
{
	//�����Ƿ��Զ���������
	m_bDefinePointV = true;
}

void CComputerGraphicsView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	////�����ſ��Ҽ�����Ӧ
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
			pDoc->m_grahics.Point[i]=PointArray.GetAt(i);//��Point���������¸�ֵ
		PointArray.RemoveAll();
		m_bDefinePointV=false;
		CRect rect;
		this->GetClientRect(rect);
		InvalidateRect(rect);
		
		//��ȡ�µĳ�ʼ�ü����η�Χ
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
