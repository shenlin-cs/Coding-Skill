// MyGraph.cpp: implementation of the CMyGraph class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Graph.h"
#include "MyGraph.h"

#include <math.h>
#define PI 3.1415926

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyGraph::CMyGraph() 
{
	m_LineNum = 0;
	memset (m_Line, 0, sizeof (m_Line));
}

CMyGraph::~CMyGraph()
{

}

void CMyGraph::AddLine(CMyPoint *lpStartPoint, CMyPoint *lpEndPoint)
{
	m_Line[m_LineNum].m_StartPoint.x = lpStartPoint->x;
	m_Line[m_LineNum].m_StartPoint.y = lpStartPoint->y;
	m_Line[m_LineNum].m_EndPoint.x = lpEndPoint->x;
	m_Line[m_LineNum].m_EndPoint.y = lpEndPoint->y;
	m_LineNum ++;
}

void CMyGraph::GetGraphCenter()
{
	double minX = m_Line[0].m_StartPoint.x;
	double maxX = m_Line[0].m_StartPoint.x;
	double minY = m_Line[0].m_StartPoint.y;
	double maxY = m_Line[0].m_StartPoint.y;

	for (int i=1; i<m_LineNum; i++)
	{
		if (minX > m_Line[i].m_StartPoint.x)
			minX = m_Line[i].m_StartPoint.x;

		if (maxX < m_Line[i].m_StartPoint.x)
			maxX = m_Line[i].m_StartPoint.x;

		if (minY > m_Line[i].m_StartPoint.y)
			minY = m_Line[i].m_StartPoint.y;

		if (maxY < m_Line[i].m_StartPoint.y)
			maxY = m_Line[i].m_StartPoint.y;
	}

	m_GCenter.x = (minX+maxX)/2;
	m_GCenter.y = (minY+maxY)/2;
}

void CMyGraph::GraphZoom(double zm, CMyPoint oPoint) //·Å´ó
{
	GetGraphCenter ();
	CMyPoint move = m_GCenter - oPoint;
	CMatrix matrix(zm, 0, 0, 0, zm, 0);
	Graph_M_x_P (matrix, move);
}

void CMyGraph::GraphMove(CMyPoint movePoint) //Æ½ÒÆ
{
	CMatrix matrix(1, 0, movePoint.x, 0, 1, movePoint.y);
	
	for (int i=0; i<m_LineNum; i++)
	{
		m_Line[i].m_StartPoint = matrix*m_Line[i].m_StartPoint;
		m_Line[i].m_EndPoint = matrix*m_Line[i].m_EndPoint;
	}
}

void CMyGraph::GraphRotate(double angle, CMyPoint oPoint)
{
	GetGraphCenter ();
	CMyPoint move = m_GCenter - oPoint;
	CMatrix matrix(cos ((angle/180)*PI), -sin ((angle/180)*PI), 0, sin ((angle/180)*PI), cos ((angle/180)*PI), 0);
	Graph_M_x_P (matrix, move);
}

void CMyGraph::Graph_M_x_P(CMatrix &matrix, CMyPoint move)
{
	for (int i=0; i<m_LineNum; i++)
	{
		m_Line[i].m_StartPoint = matrix*(m_Line[i].m_StartPoint - move);
		m_Line[i].m_EndPoint = matrix*(m_Line[i].m_EndPoint - move);

		m_Line[i].m_StartPoint = m_Line[i].m_StartPoint + move;
		m_Line[i].m_EndPoint = m_Line[i].m_EndPoint + move;
	}
}

void CMyGraph::GraphCopy(CMyGraph orignalG)
{
	for (int i=0; i<orignalG.m_LineNum; i++)
	{
		m_Line[i].m_StartPoint = orignalG.m_Line[i].m_StartPoint;
		m_Line[i].m_EndPoint = orignalG.m_Line[i].m_EndPoint;
	}
	m_LineNum = orignalG.m_LineNum;
	m_GCenter = orignalG.m_GCenter;
}

void CMyGraph::GraphShear(double shx, double refx, double shy, double refy, CMyPoint oPoint)
{
	CMatrix matrix(1, shx, -shx*refy, shy, 1, -shy*refy);
	Graph_M_x_P (matrix, oPoint);
}

void CMyGraph::GraphImage(CMyPoint imagePoint, CMyPoint oPoint)
{
	CMatrix matrix(imagePoint.x, 0, 0, 0, imagePoint.y, 0);
	Graph_M_x_P (matrix, oPoint);
}
