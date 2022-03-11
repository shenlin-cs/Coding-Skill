// GraphView.cpp : implementation of the CGraphView class
//

#include "stdafx.h"
#include "Graph.h"

#include "GraphDoc.h"
#include "GraphView.h"

#include<fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphView

IMPLEMENT_DYNCREATE(CGraphView, CView)

BEGIN_MESSAGE_MAP(CGraphView, CView)
	//{{AFX_MSG_MAP(CGraphView)
	ON_COMMAND(IDC_CUT, OnCut)
	ON_COMMAND(IDC_FILL, OnFill)
	ON_COMMAND(IDC_IMAGE_H, OnImageH)
	ON_COMMAND(IDC_IMAGE_V, OnImageV)
	ON_COMMAND(IDC_MOVE_H, OnMoveH)
	ON_COMMAND(IDC_MOVE_V, OnMoveV)
	ON_COMMAND(IDC_RORATE, OnRorate)
	ON_COMMAND(IDC_SHEAR_H, OnShearH)
	ON_COMMAND(IDC_SHEAR_V, OnShearV)
	ON_COMMAND(IDC_ZOOM, OnZoom)
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDC_BACKUP, OnBackup)
	ON_COMMAND(IDC_CLEAR, OnClear)
	ON_EN_KILLFOCUS(IDC_CMD_EDIT, OnKillfocusCmdEdit)
	ON_COMMAND(IDC_COORD, OnCoord)
	ON_EN_SETFOCUS(IDC_CMD_EDIT, OnSetfocusCmdEdit)
	ON_COMMAND(IDC_MOVE_COORD, OnMoveCoord)
	ON_WM_CREATE()
	ON_COMMAND(IDC_READ, OnRead)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphView construction/destruction

CGraphView::CGraphView()
{
	// TODO: add construction code here
	m_CursorShape = 0;
	m_CtrlStatus = 0;
	m_nValue = 1;
	m_CoordX = 0;
	m_CoordY = 0;
	m_IsAltDown = FALSE;
	m_IsBtnDown = FALSE;
	ReadName ();
}

CGraphView::~CGraphView()
{
}

BOOL CGraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraphView drawing

void CGraphView::OnDraw(CDC* pDC)
{
	CGraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	DrawCoord (pDC);
	DrawName (pDC);
	if (m_CtrlStatus == FILL_MSG && m_IsBtnDown)
	{
		pDC->MoveTo (m_StartPoint);
		pDC->LineTo (m_EndPoint);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGraphView printing

BOOL CGraphView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraphView diagnostics

#ifdef _DEBUG
void CGraphView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphDoc* CGraphView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphDoc)));
	return (CGraphDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphView message handlers

void CGraphView::OnCut() 
{
	// TODO: Add your command handler code here
	m_CtrlStatus = CUT_MSG;
}

void CGraphView::OnFill() 
{
	// TODO: Add your command handler code here
	m_CtrlStatus = FILL_MSG;
}

void CGraphView::OnImageH() 
{
	// TODO: Add your command handler code here
	m_CtrlStatus = IMAGE_H_MSG;
}

void CGraphView::OnImageV() 
{
	// TODO: Add your command handler code here
	m_CtrlStatus = IMAGE_V_MSG;
}

void CGraphView::OnMoveH() 
{
	// TODO: Add your command handler code here
	m_wndEditBar.SetDlgItemText (IDC_CMD_EDIT, "请输入水平移动像素，例如：5");
	m_CtrlStatus = MOVE_H_MSG;
}

void CGraphView::OnMoveV() 
{
	// TODO: Add your command handler code here
	m_wndEditBar.SetDlgItemText (IDC_CMD_EDIT, "请输入垂直移动像素，例如：5");
	m_CtrlStatus = MOVE_V_MSG;
}

void CGraphView::OnRorate() 
{
	// TODO: Add your command handler code here
	m_wndEditBar.SetDlgItemText (IDC_CMD_EDIT, "请输入旋转角度（-360°~ 360°），例如：60");
	m_CtrlStatus = ROTATE_MSG;
}

void CGraphView::OnShearH() 
{
	// TODO: Add your command handler code here
	m_wndEditBar.SetDlgItemText (IDC_CMD_EDIT, "请输入水平错切系数，例如：2");
	m_CtrlStatus = SHEAR_H_MSG;
}

void CGraphView::OnShearV() 
{
	// TODO: Add your command handler code here
	m_wndEditBar.SetDlgItemText (IDC_CMD_EDIT, "请输入垂直错切系数，例如：2");
	m_CtrlStatus = SHEAR_V_MSG;
}

void CGraphView::OnZoom() 
{
	// TODO: Add your command handler code here
	m_wndEditBar.SetDlgItemText (IDC_CMD_EDIT, "请输入放大倍数，例如：1.5");
	m_CtrlStatus = ZOOM_MSG;
}

void CGraphView::OnBackup() 
{
	// TODO: Add your command handler code here
	m_CurGraph.GraphCopy (m_OrignalG);
	Invalidate ();
}

void CGraphView::OnClear() 
{
	// TODO: Add your command handler code here
	m_CurGraph.m_LineNum = 0;
	m_OrignalG.m_LineNum = 0;
	Invalidate ();
}

void CGraphView::OnCoord() 
{
	// TODO: Add your command handler code here
	if (IDOK == m_CoordDlg.DoModal ())
	{
		m_CoordX = m_CoordDlg.m_CoordX;
		m_CoordY = m_CoordDlg.m_CoordY;
		Invalidate ();
	}
}

void CGraphView::OnMoveCoord() 
{
	// TODO: Add your command handler code here
	m_CtrlStatus = MOVE_COORD_MSG;
	m_wndEditBar.SetDlgItemText (IDC_CMD_EDIT, "请将鼠标移到坐标轴原点附近，鼠标形状变为十字箭头后，再移动。");
}

void CGraphView::OnRead() 
{
	// TODO: Add your command handler code here
	if (m_OrignalG.m_LineNum)
		if (IDYES != MessageBox ("是否清除当前图形？", "读入提示", MB_YESNO))
			OnClear();
	ReadName ();
	Invalidate ();
}


BOOL CGraphView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default

	if (m_CursorShape)
	{
		if (m_CursorShape == IDI_CROSS)
		{
			SetCursor (AfxGetApp()->LoadStandardCursor (IDC_CROSS));
			return TRUE;
		}
		else if (m_CursorShape == IDI_COORD_HAND)
		{
			SetCursor(AfxGetApp()->LoadStandardCursor (IDC_SIZEALL)); 
			return TRUE;
		}
		else
		{
			HCURSOR m_hCursor = AfxGetApp()->LoadIcon(m_CursorShape);
			if (m_hCursor)
			{
				SetCursor(m_hCursor);
				return TRUE;
			}
		}
	}

	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CGraphView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect (&rect);
	CPoint centerPos((rect.left+rect.right)/2, (rect.top+rect.bottom)/2);
	
	switch (m_CtrlStatus)
	{
	case ZOOM_MSG:
			m_CursorShape = IDI_ZOOM_IN_ICON;
		break;
	case MOVE_H_MSG:
		if (point.x < centerPos.x)
			m_CursorShape = IDI_MOVE_LEFT_ICON;
		else
			m_CursorShape = IDI_MOVE_RIGHT_ICON;
		break;
	case MOVE_V_MSG:
		if (point.y < centerPos.y)
			m_CursorShape = IDI_MOVE_UP_ICON;
		else
			m_CursorShape = IDI_MOVE_DOWN_ICON;
		break;
	case SHEAR_H_MSG:
		if (point.x < centerPos.x)
			m_CursorShape = IDI_SHEAR_LEFT_ICON;
		else
			m_CursorShape = IDI_SHEAR_RIGHT_ICON;
		break;
	case SHEAR_V_MSG:
		if (point.y < centerPos.y)
			m_CursorShape = IDI_SHEAR_UP_ICON;
		else
			m_CursorShape = IDI_SHEAR_DOWN_ICON;
		break;
	case ROTATE_MSG:
		if (point.x < centerPos.x)
			m_CursorShape = IDI_RORATE_LEFT_ICON;
		else
			m_CursorShape = IDI_RORATE_RIGHT_ICON;
		break;
	case IMAGE_H_MSG:
		if (point.x < centerPos.x)
			m_CursorShape = IDI_IMAGE_LEFT_ICON;
		else
			m_CursorShape = IDI_IMAGE_RIGHT_ICON;
		break;
	case IMAGE_V_MSG:
		if (point.y < centerPos.y)
			m_CursorShape = IDI_IMAGE_UP_ICON;
		else
			m_CursorShape = IDI_IMAGE_DOWN_ICON;
		break;
	case CUT_MSG:
		m_CursorShape = IDI_CROSS;
		break;
	case FILL_MSG:
		m_CursorShape = IDI_CROSS;
		break;
	case MOVE_COORD_MSG:
		if (abs(point.x - m_CoordX) < 5 && abs(point.y - m_CoordY) < 5)
		{
			m_CursorShape = IDI_COORD_HAND;
		}
		else
			m_CursorShape = 0;
	default:
		break;
	}

	if (m_CtrlStatus == CUT_MSG && m_IsBtnDown)
	{
		CClientDC dc(this);

		dc.SetROP2(R2_NOT);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(CRect(startPoint,m_OldPoint)); 
		dc.Rectangle(CRect(startPoint,point));
		m_OldPoint = point;
	}

	if (m_CtrlStatus == FILL_MSG && m_IsBtnDown)
	{
		m_EndPoint = point;
		Invalidate ();
	}

	if (m_CtrlStatus == MOVE_COORD_MSG && m_IsBtnDown)
	{
		m_CoordX = point.x;
		m_CoordY = point.y;
		Invalidate ();
	}

	CView::OnMouseMove(nFlags, point);
}

void CGraphView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CRect rect;
	GetClientRect (&rect);
	CPoint centerPos((rect.left+rect.right)/2, (rect.top+rect.bottom)/2);
	
	switch (m_CtrlStatus)
	{
	case ZOOM_MSG:
		{
			CMyPoint oPoint(0, 0);
			m_CurGraph.GraphZoom (m_nValue, oPoint);
			Invalidate ();
		}
		break;
	case MOVE_H_MSG:
		if (point.x < centerPos.x)
		{
			CMyPoint movePoint(-5, 0);
			m_CurGraph.GraphMove (movePoint);
		}
		else
		{
			CMyPoint movePoint(5, 0);
			m_CurGraph.GraphMove (movePoint);
		}
		Invalidate ();
		break;
	case MOVE_V_MSG:
		if (point.y < centerPos.y)
		{
			CMyPoint movePoint(0, -5);
			m_CurGraph.GraphMove (movePoint);
		}
		else
		{
			CMyPoint movePoint(0, 5);
			m_CurGraph.GraphMove (movePoint);
		}
		Invalidate ();
		break;
	case ROTATE_MSG:
		if (point.x < centerPos.x)
		{
			CMyPoint oPoint(0, 0);
			m_CurGraph.GraphRotate (-m_nValue, oPoint);
		}
		else
		{
			CMyPoint oPoint(0, 0);
			m_CurGraph.GraphRotate (m_nValue, oPoint);
		}
		Invalidate ();
		break;
	case SHEAR_H_MSG:
		if (point.x < centerPos.x)
		{
			CMyPoint oPoint(m_CoordX, m_CoordY);
			m_CurGraph.GraphShear (m_nValue, 0, 0, 0, oPoint);
		}
		else
		{
			CMyPoint oPoint(m_CoordX, m_CoordY);
			m_CurGraph.GraphShear (-m_nValue, 0, 0, 0, oPoint);
		}
		Invalidate ();
		break;
	case SHEAR_V_MSG:
		if (point.y < centerPos.y)
		{
			CMyPoint oPoint(m_CoordX, m_CoordY);
			m_CurGraph.GraphShear (0, 0, -1, 0, oPoint);
		}
		else
		{
			CMyPoint oPoint(m_CoordX, m_CoordY);
			m_CurGraph.GraphShear (0, 0, 1, 0, oPoint);
		}
		Invalidate ();
		break;
	case IMAGE_H_MSG:
		{
			CMyPoint imagePoint(-1, 1);
			CMyPoint oPoint(m_CoordX, m_CoordY);
			m_CurGraph.GraphImage (imagePoint, oPoint);
			Invalidate ();
		}
		break;
	case IMAGE_V_MSG:
		{
			CMyPoint imagePoint(1, -1);
			CMyPoint oPoint(m_CoordX, m_CoordY);
			m_CurGraph.GraphImage (imagePoint, oPoint);
			Invalidate ();
		}
		break;
	case CUT_MSG:
		m_IsBtnDown = TRUE;
		m_StartPoint = point;
		startPoint = point;
		m_OldPoint = point;
		break;
	case FILL_MSG:
		m_IsBtnDown = TRUE;
		m_StartPoint = point;
		startPoint = point;
		break;
	case MOVE_COORD_MSG:
		m_IsBtnDown = TRUE;
	default:
		break;
	}

	CView::OnLButtonDown(nFlags, point);
}

void CGraphView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch (m_CtrlStatus)
	{
	case CUT_MSG:
		{
			m_IsBtnDown = FALSE;
			m_EndPoint = point;
		} 
		break;
	case FILL_MSG:
		{
			m_IsBtnDown = FALSE;
			m_EndPoint = point;

			m_MySPoint = m_StartPoint;
			m_MyEPoint = point;

			m_OrignalG.AddLine (&m_MySPoint, &m_MyEPoint);
			m_CurGraph.AddLine (&m_MySPoint, &m_MyEPoint);
		}
		break;
	case MOVE_COORD_MSG:
			m_IsBtnDown = FALSE;
			break;
	default: break;
	}

	CView::OnLButtonUp(nFlags, point);
}

void CGraphView::DrawName(CDC *pDC)
{
	if (m_CurGraph.m_LineNum <= 0)
		return;

	CPoint startPoint;
	CPoint endPoint;

	for (int i=0; i<m_CurGraph.m_LineNum; i++)
	{
		startPoint.x = (int)m_CurGraph.m_Line[i].m_StartPoint.x;
		startPoint.y = (int)m_CurGraph.m_Line[i].m_StartPoint.y;

		endPoint.x = (int)m_CurGraph.m_Line[i].m_EndPoint.x;
		endPoint.y = (int)m_CurGraph.m_Line[i].m_EndPoint.y;

		pDC->MoveTo (startPoint);
		pDC->LineTo (endPoint);
	}
}

void CGraphView::ReadName()
{
	ifstream fin("Graph.txt", ios::in);
	if (!fin )
		return ;

	while(!fin.eof())
	{
		CMyPoint startPoint, endPoint;
		fin >> startPoint.x >> startPoint.y;
		fin >> endPoint.x >> endPoint.y;
		m_OrignalG.AddLine (&startPoint, &endPoint);
		m_CurGraph.AddLine (&startPoint, &endPoint);
	}
	fin.close();
}

void CGraphView::OnKillfocusCmdEdit() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_wndEditBar.GetDlgItemText (IDC_CMD_EDIT, str);
	GetEditValue (str);
}

void CGraphView::OnSetfocusCmdEdit() 
{
	// TODO: Add your control notification handler code here
	m_wndEditBar.SetDlgItemText (IDC_CMD_EDIT, "");
}


void CGraphView::GetEditValue(CString &str)
{
	if (str.GetLength () > 5)
	{
		m_nValue = 1;
		return ;
	}
	char tmp[10] = ""; 
	sprintf(tmp, "%s", str);
	m_nValue = atof(tmp);
}

void CGraphView::DrawCoord(CDC *pDC)
{
	CRect rect;
	GetClientRect (&rect);
	
	pDC->MoveTo (rect.left, m_CoordY);
	pDC->LineTo (rect.right, m_CoordY);
	pDC->MoveTo (m_CoordX, rect.top);
	pDC->LineTo (m_CoordX, rect.bottom);
}