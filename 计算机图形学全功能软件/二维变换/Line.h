// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__7FA3A4E1_276D_421F_A612_8336E2D6CBD3__INCLUDED_)
#define AFX_LINE_H__7FA3A4E1_276D_421F_A612_8336E2D6CBD3__INCLUDED_

#include "MyPoint.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLine
{
public:
	int m_LineNum;
	CMyPoint m_StartPoint;
	CMyPoint m_EndPoint;
	CLine();
	virtual ~CLine();

};

#endif // !defined(AFX_LINE_H__7FA3A4E1_276D_421F_A612_8336E2D6CBD3__INCLUDED_)
