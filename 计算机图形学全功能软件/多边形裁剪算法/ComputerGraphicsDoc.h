// ComputerGraphicsDoc.h : interface of the CComputerGraphicsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPUTERGRAPHICSDOC_H__6C0A3F7F_4E0A_4117_A931_BFE5428F4322__INCLUDED_)
#define AFX_COMPUTERGRAPHICSDOC_H__6C0A3F7F_4E0A_4117_A931_BFE5428F4322__INCLUDED_

#include "Graphics.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CComputerGraphicsDoc : public CDocument
{
protected: // create from serialization only
	CComputerGraphicsDoc();
	DECLARE_DYNCREATE(CComputerGraphicsDoc)

// Attributes
public:
	CGraphics m_grahics;
	bool bFillPloyon;
	bool bCutRect;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComputerGraphicsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComputerGraphicsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CComputerGraphicsDoc)
	afx_msg void OnFillployon();
	afx_msg void OnUpdateFillployon(CCmdUI* pCmdUI);
	afx_msg void OnCutRect();
	afx_msg void OnUpdateCutRect(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPUTERGRAPHICSDOC_H__6C0A3F7F_4E0A_4117_A931_BFE5428F4322__INCLUDED_)
