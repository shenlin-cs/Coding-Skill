// MyGraph.h: interface for the CMyGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYGRAPH_H__CB5C501F_5108_4618_9D52_FF69543FB6C3__INCLUDED_)
#define AFX_MYGRAPH_H__CB5C501F_5108_4618_9D52_FF69543FB6C3__INCLUDED_

#include "Line.h"	// Added by ClassView
#include "Matrix.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyGraph  
{
public:
	void GraphImage(CMyPoint imagePoint, CMyPoint oPoint);
	void GraphShear(double shx, double refx, double shy, double refy, CMyPoint oPoint);
	void GraphCopy(CMyGraph orignalG);
	void Graph_M_x_P (CMatrix &matrix, CMyPoint move);
	void GraphRotate(double angle, CMyPoint oPoint);
	void GraphMove(CMyPoint movePoint);
	void GetGraphCenter();
	void GraphZoom(double zm, CMyPoint oPoint);
	void AddLine(CMyPoint *lpStartPoint, CMyPoint *lpEndPoint);
	int m_LineNum;
	CMyPoint m_GCenter;
	CLine m_Line[100];
	CMyGraph();
	virtual ~CMyGraph();
};

#endif // !defined(AFX_MYGRAPH_H__CB5C501F_5108_4618_9D52_FF69543FB6C3__INCLUDED_)
