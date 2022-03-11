// MyPoint.h: interface for the CMyPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPOINT_H__2FDFD700_E93D_4DCF_B3A4_88462881880B__INCLUDED_)
#define AFX_MYPOINT_H__2FDFD700_E93D_4DCF_B3A4_88462881880B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyPoint  
{
public:
	double x;
	double y;

	CMyPoint();
	CMyPoint(double x, double y) {this->x = x; this->y = y;}
	virtual ~CMyPoint();

	CMyPoint& operator= (const CMyPoint &point)
	{
		x = point.x;
		y = point.y;
		return *this;
	}

	CMyPoint& operator= (const CPoint &point)
	{
		x = (double)point.x;
		y = (double)point.y;
		return *this;
	}

	CMyPoint& operator+ (const CMyPoint &point)
	{
		x += point.x;
		y += point.y;
		return *this;
	}

	CMyPoint& operator- (const CMyPoint &point)
	{
		x -= point.x;
		y -= point.y;
		return *this;
	}

};

#endif // !defined(AFX_MYPOINT_H__2FDFD700_E93D_4DCF_B3A4_88462881880B__INCLUDED_)
