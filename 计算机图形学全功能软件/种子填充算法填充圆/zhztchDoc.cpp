// zhztchDoc.cpp : implementation of the CZhztchDoc class
//

#include "stdafx.h"
#include "zhztch.h"

#include "zhztchDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZhztchDoc

IMPLEMENT_DYNCREATE(CZhztchDoc, CDocument)

BEGIN_MESSAGE_MAP(CZhztchDoc, CDocument)
	//{{AFX_MSG_MAP(CZhztchDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhztchDoc construction/destruction

CZhztchDoc::CZhztchDoc()
{
	// TODO: add one-time construction code here

}

CZhztchDoc::~CZhztchDoc()
{
}

BOOL CZhztchDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CZhztchDoc serialization

void CZhztchDoc::Serialize(CArchive& ar)
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
// CZhztchDoc diagnostics

#ifdef _DEBUG
void CZhztchDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZhztchDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZhztchDoc commands
