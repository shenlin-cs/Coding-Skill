// Matrix.h: interface for the CMatrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIX_H__C6991F56_9221_4165_B216_9417A8952DD7__INCLUDED_)
#define AFX_MATRIX_H__C6991F56_9221_4165_B216_9417A8952DD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Line.h"
#include "MyPoint.h"

class CMatrix  
{
public:

	double m_Matrix[3][3];
	CMyPoint point;

	CMatrix(double m00, double m01, double m02, double m10, double m11, double m12)
	{
		m_Matrix[0][0] = m00;
		m_Matrix[0][1] = m01;
		m_Matrix[0][2] = m02;
		m_Matrix[1][0] = m10;
		m_Matrix[1][1] = m11;
		m_Matrix[1][2] = m12;
		m_Matrix[2][0] = 0;
		m_Matrix[2][1] = 0;
		m_Matrix[2][2] = 1;
	}

	CMyPoint & operator* (const CMyPoint &oldPoint)
	{
		point.x = m_Matrix[0][0]*oldPoint.x + m_Matrix[0][1]*oldPoint.y + m_Matrix[0][2];
		point.y = m_Matrix[1][0]*oldPoint.x + m_Matrix[1][1]*oldPoint.y + m_Matrix[1][2];
		return this->point;
	}

	CMatrix();
	virtual ~CMatrix();
	
};

#endif // !defined(AFX_MATRIX_H__C6991F56_9221_4165_B216_9417A8952DD7__INCLUDED_)
