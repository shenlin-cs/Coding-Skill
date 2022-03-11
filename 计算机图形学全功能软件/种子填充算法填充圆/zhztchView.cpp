// zhztchView.cpp : implementation of the CZhztchView class
//

#include "stdafx.h"
#include "zhztch.h"

#include "zhztchDoc.h"
#include "zhztchView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZhztchView

IMPLEMENT_DYNCREATE(CZhztchView, CView)

BEGIN_MESSAGE_MAP(CZhztchView, CView)
//{{AFX_MSG_MAP(CZhztchView)
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_Scanfill, OnScanfill)
ON_WM_CREATE()
	ON_COMMAND(ID_zhong, Onzhong)
	//}}AFX_MSG_MAP
// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhztchView construction/destruction

CZhztchView::CZhztchView()            //修改构造函数，当一个视类对象被调用时，构造函数被调用
{
	// TODO: add construction code here
	n=0;	t=TRUE;
	
}

CZhztchView::~CZhztchView()
{
}

BOOL CZhztchView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CZhztchView drawing

void CZhztchView::OnDraw(CDC* pDC)   //第二步，修改此函数，当一个视类对象被建立是调用
{
	CZhztchDoc* pDoc = GetDocument();      //定义了文档类的指针变量pDoc，同时调用成员函数GetDocument()获取文档类的指针赋给pDoc
	ASSERT_VALID(pDoc);      //有了公该指针便可以访问文档类中的有成员
	pDC->TextOut(1,65," 1.扫描算法就是内定自交四边形来填色");
	pDC->TextOut(1,80," 2.种子算法先用左击画圆(圆心+半径),再点击种子填充用于区域填充");
}

/////////////////////////////////////////////////////////////////////////////
// CZhztchView printing

BOOL CZhztchView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CZhztchView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CZhztchView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CZhztchView diagnostics

#ifdef _DEBUG
void CZhztchView::AssertValid() const
{
	CView::AssertValid();
}

void CZhztchView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZhztchDoc* CZhztchView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZhztchDoc)));
	return (CZhztchDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZhztchView message handlers

#include   <windows.h>       //   include   all   the   windows   headers   
#include   <windowsx.h>     //   include   useful   macros   
#include   <stdio.h>   
#include   <stdlib.h>
#include   <math.h>
#include	<graphics.h>
//   defines   for   windows  
typedef struct {
		int y, xLeft, xRight; 
	} Span;	
#define STACK_SIZE 100     		//开辟堆栈空间最大值为100
//#include"window.h"
	Span S[STACK_SIZE];
	int top = 0;
	void SetStackEmpty(){				//置堆栈为空
 		top = 0;
	}
	bool isStackEmpty(){				//检查堆栈状态
 		return top == 0;
	}
	bool PushStack(Span *pS){			//将区段压入堆栈
		if (top < STACK_SIZE){			//堆栈未满
  			S[top] = *pS;
  			top++;
  			return true;
 		}
 		else	return false;
	}
	bool PopStack(Span *pS){			//取栈顶区段
 		if (top > 0){
  			top--;
  			*pS = S[top];
  			return true;
 		}
 		else	return false;
	}
//	void CZhztchView::boundaryfill4(int x, int y, int boundarycolor, int newcolor){		//区域填充的扫描线算法
		
		
	void CZhztchView::boundaryfill4(int x, int y, int oldColor, int newColor)
	{
		int color;
		CClientDC dc(this);      //获取客户区设备描述表
		color=dc.GetPixel(x,y);

//void ScanLineFill4(int x, int y, int oldColor, int newColor){		//区域填充的扫描线算法
		Span span;
		span.y = y;
		span.xLeft = x; 
		while (dc.GetPixel(span.xLeft, span.y) == oldColor){
			dc.SetPixel(span.xLeft, span.y, newColor);
			span.xLeft--;
		}
		if (span.xLeft == x)//not a seed point actually
			return;
		else
			span.xLeft++;//compansate
		span.xRight = x + 1;
		while (dc.GetPixel(span.xRight, span.y) == oldColor){
			dc.SetPixel(span.xRight, span.y, newColor);
			span.xRight++;
		}
		if (span.xRight == x + 1)//cannot extend to right
			span.xRight = x;
		else
			span.xRight--;//compansate

		 SetStackEmpty();
		 PushStack(&span);

		while (!isStackEmpty()){
			PopStack(&span);
			Span S;//new span
			S.y = span.y + 1;
			S.xLeft = span.xLeft;
			bool xLeftNotSet = false;
			while (dc.GetPixel(S.xLeft, S.y) == oldColor){
				S.xLeft--;
			}
			if (S.xLeft == span.xLeft)//xLeft is not set
				xLeftNotSet = true;
			else
				S.xLeft++;//compansate
			int i = S.xLeft;
			while (i <= span.xRight){
				while (dc.GetPixel(i, S.y) == oldColor){
					if (xLeftNotSet){
						S.xLeft = i;
						xLeftNotSet = false;
					}
					dc.SetPixel(i, S.y, newColor);
					i++;
				}
				if (i > S.xLeft){
					S.xRight = i - 1;
					PushStack(&S);
					xLeftNotSet = true;
				}
				while (i <= span.xRight && dc.GetPixel(i, S.y) != oldColor){
					i++;
				}
			}
			S.y = span.y - 1;
			S.xLeft = span.xLeft;
			xLeftNotSet = false;
			while (dc.GetPixel(S.xLeft, S.y) == oldColor){
				S.xLeft--;
			}
			if (S.xLeft == span.xLeft)//xLeft is not set
				xLeftNotSet = true;
			else
				S.xLeft++;//compansate
			i = S.xLeft;
			while (i <= span.xRight){
				while (dc.GetPixel(i, S.y) == oldColor){
					if (xLeftNotSet){
						S.xLeft = i;
						xLeftNotSet = false;
					}
					dc.SetPixel(i, S.y, newColor);
					i++;
				}
				if (i > S.xLeft){
					S.xRight = i - 1;
					PushStack(&S);
					xLeftNotSet = true;
				}
				while (i <= span.xRight && dc.GetPixel(i, S.y) != oldColor){
					i++;
				}
			}
		}
	}
/*	if(color!=newcolor&&color!=boundarycolor)
	{
		dc.SetPixel(x,y,newcolor);
		boundaryfill4(x,y+1,boundarycolor,newcolor);
		boundaryfill4(x,y-1,boundarycolor,newcolor);
		boundaryfill4(x-1,y,boundarycolor,newcolor);
		boundaryfill4(x+1,y,boundarycolor,newcolor);
	} 
	*/



void CZhztchView::OnLButtonDown(UINT nFlags, CPoint point) //point表示鼠标在客户区中的当前点，当鼠标左键被按下时调用，并将鼠标当前
//坐标传给point
{
	// TODO: Add your message handler code here and/or call default
	//t、n分别为视类中的私有数据成员，
	if(t)                                     //当按下鼠标左键时，设置画线状态                
	{		
		n++;
		mp[n]=point;
		CClientDC dc(this);                            //获取客户区设备描述表，用当前的视图对象进行初始化
		CPen newpen(PS_SOLID,1,500);                   //画笔类，设计颜色画曲线
		dc.SelectObject(newpen);  
		if(n==2){							//选择画笔//
//		dc.MoveTo(mp[n]);                         //代表从第一个左击点连到第二个左击点，再到第三个......
//		dc.LineTo(mp[n-1]);
		dc.MoveTo(mp[n]);
		double r=(double)(sqrtf((mp[n-1].x-mp[n].x)*(mp[n-1].x-mp[n].x)+(mp[n-1].y-mp[n].y)*(mp[n-1].y-mp[n].y)));
		dc.Ellipse(mp[1].x-r,mp[1].y-r,mp[1].x+r,mp[1].y+r); 
		n=0;
		}
	}
	else//单击选取种子点后进行填充
	{
		boundaryfill4(point.x,point.y,RGB(255,255,255),RGB(0,0,0));	
	}	
}


void CZhztchView::OnRButtonDown(UINT nFlags, CPoint point) //闭合
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen newpen(PS_SOLID,1,500);          //设计闭合线颜色
	dc.SelectObject(newpen);
	dc.MoveTo(mp[n]);                     //从最后一个左击点连到第一个左击点
	dc.LineTo(mp[1]);
	dc.SetPixel(mp[1],500);                //画出第一个左击点，这样就得到了一个封闭区间
	
	CView::OnRButtonDown(nFlags, point);
}

void CZhztchView::OnScanfill() 
{
	RedrawWindow();
	CDC* pDC=GetDC();
	CPen newpen(PS_SOLID,3,RGB(255,0,0));
	CPen *old=pDC->SelectObject(&newpen);

	spt[0]=CPoint(200,200);    //绘制多边形区域
	spt[1]=CPoint(400,400);
	spt[2]=CPoint(200,400);
	spt[3]=CPoint(400,200);
	spt[4]=CPoint(200,200);
    pDC->Polyline(spt,5);
	//pDC->SelectObject(old);
	//ReleaseDC(pDC);
	// TODO: Add your command handler code here
	//CDC* pDC=GetDC();
	CPen newpen2(PS_SOLID,1,RGB(0,255,0));
	CPen *old2=pDC->SelectObject(&newpen2);
	int j,k,s = 0;
	int p[5];  //每根扫描线交点
	int pmin = 0,pmax = 0;
	for(int i=0;i<=6;i++)//建立边表
	{
		edge[i].dx=(float)(spt[i+1].x-spt[i].x)/(spt[i+1].y-spt[i].y);
		if(spt[i].y<=spt[i+1].y){
			edge[i].num=i;
			edge[i].ymin=spt[i].y;
			edge[i].ymax=spt[i+1].y;
			edge[i].xmin=(float)spt[i].x;
			edge[i].xmax=(float)spt[i+1].x;
			if(spt[i+1].y > pmax)
				pmax = spt[i+1].y;
			if(spt[i].y < pmin)
				pmin = spt[i].y;
		}
		else{
			edge[i].num=i;
			edge[i].ymin=spt[i+1].y;
			edge[i].ymax=spt[i].y;
			edge[i].xmax=(float)spt[i].x;
			edge[i].xmin=(float)spt[i+1].x;
			if(spt[i].y > pmax)
				pmax = spt[i].y;
			if(spt[i+1].y < pmin)
				pmin = spt[i+1].y;
		}
	}
	for(int r=1;r<=6;r++)	//排序edge(yUpper，xIntersect)，结果为从大到小
	{
		for(int q=0;q<=6-r;q++)
		{
			if(edge[q].ymin<edge[q+1].ymin)
			{
				newedge[0]=edge[q];	edge[q]=edge[q+1];
				edge[q+1]=newedge[0];
			}				
		}
	}
	for(int scan=pmax-1;scan>=pmin+1;scan--)
	{
		int b=0;
		k=s;
		for(j=k;j<=6;j++)
		{	
			if((scan>edge[j].ymin)&&(scan<=edge[j].ymax))//判断与线段相交
			{
				if(scan==edge[j].ymax)
				{
					if(spt[edge[j].num+1].y<edge[j].ymax)
					{
						b++;
						p[b]=(int)edge[j].xmax;
					}
					else if(spt[edge[j].num-1].y<edge[j].ymax)
					{
						b++;		
						p[b]=(int)edge[j].xmax;
					}			
				}			
				if((scan>edge[j].ymin)&&(scan<edge[j].ymax))
				{
					b++;
					p[b]=(int)(edge[j].xmax+edge[j].dx*(scan-edge[j].ymax));
				}
			}
			//pDC->LineTo(spt[edge[0].num].x,spt[edge[0].num].y);
			if(scan<=edge[j].ymin)//
				s=j;
		}		
		if(b>1)
		{					
			for(int u=1;u<b;u++)
			{
				pDC->MoveTo(p[u]-1,scan);
				u++;
				pDC->LineTo(p[u],scan);
			}
		}		
	}
	pDC->SelectObject(old);
	pDC->SelectObject(old2);
}

void CZhztchView::Onzhong() 
{
	// TODO: Add your command handler code here
	t=FALSE;
	MessageBox("请单击选取种子点")	;
}

