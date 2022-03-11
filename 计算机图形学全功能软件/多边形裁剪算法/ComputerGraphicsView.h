// ComputerGraphicsView.h : interface of the CComputerGraphicsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPUTERGRAPHICSVIEW_H__E7A9FFE9_E3A9_4AA4_8950_247DEF22EC89__INCLUDED_)
#define AFX_COMPUTERGRAPHICSVIEW_H__E7A9FFE9_E3A9_4AA4_8950_247DEF22EC89__INCLUDED_

#include "Graphics.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CComputerGraphicsView : public CScrollView
{
protected: // create from serialization only
	CComputerGraphicsView();
	DECLARE_DYNCREATE(CComputerGraphicsView)

// Attributes
public:
	CComputerGraphicsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComputerGraphicsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_bCaptured;
	bool m_bDefineRect;
	bool m_bDefinePointV;
	CPoint TopLeft;
	CPoint BottomRight;
	CArray<CPoint,CPoint&> PointArray;
	virtual ~CComputerGraphicsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CComputerGraphicsView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnViewDefineRect();
	afx_msg void OnEditDefinePoint();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ComputerGraphicsView.cpp
inline CComputerGraphicsDoc* CComputerGraphicsView::GetDocument()
   { return (CComputerGraphicsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPUTERGRAPHICSVIEW_H__E7A9FFE9_E3A9_4AA4_8950_247DEF22EC89__INCLUDED_)
