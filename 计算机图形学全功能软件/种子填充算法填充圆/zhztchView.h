// zhztchView.h : interface of the CZhztchView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZHZTCHVIEW_H__AB74EEAB_BCA4_419E_B5C4_2225A05B2328__INCLUDED_)
#define AFX_ZHZTCHVIEW_H__AB74EEAB_BCA4_419E_B5C4_2225A05B2328__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct       //建立边表结构
{
    int num, ymin,ymax;
    float xmin,xmax,dx;
}  Edge;

class CZhztchView : public CView
{
protected: // create from serialization only
	CZhztchView();
	DECLARE_DYNCREATE(CZhztchView)

// Attributes
public:
	CZhztchDoc* GetDocument();
	CPoint spt[8];
	Edge edge[7],edgel[7],newedge[1];

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhztchView)
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
	BOOL t;
	int n;
	CPoint mp[100];
	void boundaryfill4(int,int,int boundarycolor,int newcolor);
	virtual ~CZhztchView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZhztchView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnScanfill();
	afx_msg void Onzhong();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in zhztchView.cpp
inline CZhztchDoc* CZhztchView::GetDocument()
   { return (CZhztchDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHZTCHVIEW_H__AB74EEAB_BCA4_419E_B5C4_2225A05B2328__INCLUDED_)
