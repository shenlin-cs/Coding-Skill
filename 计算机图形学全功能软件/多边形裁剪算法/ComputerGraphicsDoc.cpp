// ComputerGraphicsDoc.cpp : implementation of the CComputerGraphicsDoc class
//

#include "stdafx.h"
#include "ComputerGraphics.h"

#include "ComputerGraphicsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsDoc

IMPLEMENT_DYNCREATE(CComputerGraphicsDoc, CDocument)

BEGIN_MESSAGE_MAP(CComputerGraphicsDoc, CDocument)
	//{{AFX_MSG_MAP(CComputerGraphicsDoc)
	ON_COMMAND(ID_FILLPLOYON, OnFillployon)
	ON_UPDATE_COMMAND_UI(ID_FILLPLOYON, OnUpdateFillployon)
	ON_COMMAND(ID_CUTRECT, OnCutRect)
	ON_UPDATE_COMMAND_UI(ID_CUTRECT, OnUpdateCutRect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsDoc construction/destruction

CComputerGraphicsDoc::CComputerGraphicsDoc()
{
	// TODO: add one-time construction code here
	bFillPloyon=false;
	bCutRect=false;
}

CComputerGraphicsDoc::~CComputerGraphicsDoc()
{
}

BOOL CComputerGraphicsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsDoc serialization

void CComputerGraphicsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsDoc diagnostics

#ifdef _DEBUG
void CComputerGraphicsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CComputerGraphicsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComputerGraphicsDoc commands

void CComputerGraphicsDoc::OnFillployon() 
{
	bFillPloyon=!bFillPloyon;
	UpdateAllViews(NULL);
}

void CComputerGraphicsDoc::OnUpdateFillployon(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bFillPloyon);	
}

void CComputerGraphicsDoc::OnCutRect() 
{
	bCutRect=!bCutRect;
	UpdateAllViews(NULL);
}

void CComputerGraphicsDoc::OnUpdateCutRect(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bCutRect);	
}
