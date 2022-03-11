// Matrix.cpp: implementation of the CMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Graph.h"
#include "Matrix.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMatrix::CMatrix()
{
	m_Matrix[0][0] = 0;
	m_Matrix[0][1] = 0;
	m_Matrix[0][2] = 0;
	m_Matrix[1][0] = 0;
	m_Matrix[1][1] = 0;
	m_Matrix[2][0] = 0;
	m_Matrix[2][1] = 0;
	m_Matrix[2][2] = 1;
}

CMatrix::~CMatrix()
{

}
