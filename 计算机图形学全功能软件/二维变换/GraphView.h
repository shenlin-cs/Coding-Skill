// GraphView.h : interface of the CGraphView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHVIEW_H__A172EEEF_4598_40F8_B4F3_EE5942189FC7__INCLUDED_)
#define AFX_GRAPHVIEW_H__A172EEEF_4598_40F8_B4F3_EE5942189FC7__INCLUDED_

#include "Line.h"	// Added by ClassView
#include "MyGraph.h"	// Added by ClassView
#include "Coordinate.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define ZOOM_MSG		1011
#define MOVE_H_MSG		1021
#define MOVE_V_MSG		1031
#define ROTATE_MSG		1041
#define SHEAR_H_MSG		1051
#define SHEAR_V_MSG		1061
#define IMAGE_H_MSG		1071
#define IMAGE_V_MSG		1081
#define CUT_MSG			1091
#define FILL_MSG		1101
#define IDI_CROSS		1111
#define MOVE_COORD_MSG	1112
#define IDI_COORD_HAND	1113

#define LEFT			1901
#define BOTTOM			1911
#define RIGHT			1921
#define TOP				1931
#define CENTER			1941

class CGraphView : public CView
{
protected: // create from serialization only
	CGraphView();
	DECLARE_DYNCREATE(CGraphView)

// Attributes
public:
	CGraphDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CCoordinate m_CoordDlg;
	int m_CoordY;
	int m_CoordX;
	void DrawCoord(CDC *pDC);
	double m_nValue;
	void GetEditValue (CString &str);
	CMyPoint m_MyEPoint;
	CMyPoint m_MySPoint;
	CMyGraph m_CurGraph;
	CMyGraph m_OrignalG;
	double m_LineSlope;
	CPoint m_StartPoint;
	CPoint m_EndPoint;
	CPoint m_OldPoint;
	BOOL m_IsBtnDown;
	CPoint startPoint;
	void ReadName ();
	void DrawName(CDC *pDC);
	BOOL m_IsAltDown;
	int m_CtrlStatus;
	int m_CursorShape;
	virtual ~CGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphView)
	afx_msg void OnCut();
	afx_msg void OnFill();
	afx_msg void OnImageH();
	afx_msg void OnImageV();
	afx_msg void OnMoveH();
	afx_msg void OnMoveV();
	afx_msg void OnRorate();
	afx_msg void OnShearH();
	afx_msg void OnShearV();
	afx_msg void OnZoom();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBackup();
	afx_msg void OnClear();
	afx_msg void OnKillfocusCmdEdit();
	afx_msg void OnCoord();
	afx_msg void OnSetfocusCmdEdit();
	afx_msg void OnMoveCoord();
	afx_msg void OnRead();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GraphView.cpp
inline CGraphDoc* CGraphView::GetDocument()
   { return (CGraphDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHVIEW_H__A172EEEF_4598_40F8_B4F3_EE5942189FC7__INCLUDED_)
