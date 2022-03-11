// Coordinate.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "Coordinate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE 
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordinate dialog


CCoordinate::CCoordinate(CWnd* pParent /*=NULL*/)
	: CDialog(CCoordinate::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCoordinate)
	m_CoordX = 0;
	m_CoordY = 0;
	//}}AFX_DATA_INIT
}


void CCoordinate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCoordinate)
	DDX_Text(pDX, IDC_EDIT1, m_CoordX);
	DDX_Text(pDX, IDC_EDIT2, m_CoordY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCoordinate, CDialog)
	//{{AFX_MSG_MAP(CCoordinate)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordinate message handlers
