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

CZhztchView::CZhztchView()            //�޸Ĺ��캯������һ��������󱻵���ʱ�����캯��������
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

void CZhztchView::OnDraw(CDC* pDC)   //�ڶ������޸Ĵ˺�������һ��������󱻽����ǵ���
{
	CZhztchDoc* pDoc = GetDocument();      //�������ĵ����ָ�����pDoc��ͬʱ���ó�Ա����GetDocument()��ȡ�ĵ����ָ�븳��pDoc
	ASSERT_VALID(pDoc);      //���˹���ָ�����Է����ĵ����е��г�Ա
	pDC->TextOut(1,65," 1.ɨ���㷨�����ڶ��Խ��ı�������ɫ");
	pDC->TextOut(1,80," 2.�����㷨���������Բ(Բ��+�뾶),�ٵ��������������������");
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
#define STACK_SIZE 100     		//���ٶ�ջ�ռ����ֵΪ100
//#include"window.h"
	Span S[STACK_SIZE];
	int top = 0;
	void SetStackEmpty(){				//�ö�ջΪ��
 		top = 0;
	}
	bool isStackEmpty(){				//����ջ״̬
 		return top == 0;
	}
	bool PushStack(Span *pS){			//������ѹ���ջ
		if (top < STACK_SIZE){			//��ջδ��
  			S[top] = *pS;
  			top++;
  			return true;
 		}
 		else	return false;
	}
	bool PopStack(Span *pS){			//ȡջ������
 		if (top > 0){
  			top--;
  			*pS = S[top];
  			return true;
 		}
 		else	return false;
	}
//	void CZhztchView::boundaryfill4(int x, int y, int boundarycolor, int newcolor){		//��������ɨ�����㷨
		
		
	void CZhztchView::boundaryfill4(int x, int y, int oldColor, int newColor)
	{
		int color;
		CClientDC dc(this);      //��ȡ�ͻ����豸������
		color=dc.GetPixel(x,y);

//void ScanLineFill4(int x, int y, int oldColor, int newColor){		//��������ɨ�����㷨
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



void CZhztchView::OnLButtonDown(UINT nFlags, CPoint point) //point��ʾ����ڿͻ����еĵ�ǰ�㣬��������������ʱ���ã�������굱ǰ
//���괫��point
{
	// TODO: Add your message handler code here and/or call default
	//t��n�ֱ�Ϊ�����е�˽�����ݳ�Ա��
	if(t)                                     //������������ʱ�����û���״̬                
	{		
		n++;
		mp[n]=point;
		CClientDC dc(this);                            //��ȡ�ͻ����豸�������õ�ǰ����ͼ������г�ʼ��
		CPen newpen(PS_SOLID,1,500);                   //�����࣬�����ɫ������
		dc.SelectObject(newpen);  
		if(n==2){							//ѡ�񻭱�//
//		dc.MoveTo(mp[n]);                         //����ӵ�һ������������ڶ�������㣬�ٵ�������......
//		dc.LineTo(mp[n-1]);
		dc.MoveTo(mp[n]);
		double r=(double)(sqrtf((mp[n-1].x-mp[n].x)*(mp[n-1].x-mp[n].x)+(mp[n-1].y-mp[n].y)*(mp[n-1].y-mp[n].y)));
		dc.Ellipse(mp[1].x-r,mp[1].y-r,mp[1].x+r,mp[1].y+r); 
		n=0;
		}
	}
	else//����ѡȡ���ӵ��������
	{
		boundaryfill4(point.x,point.y,RGB(255,255,255),RGB(0,0,0));	
	}	
}


void CZhztchView::OnRButtonDown(UINT nFlags, CPoint point) //�պ�
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen newpen(PS_SOLID,1,500);          //��Ʊպ�����ɫ
	dc.SelectObject(newpen);
	dc.MoveTo(mp[n]);                     //�����һ�������������һ�������
	dc.LineTo(mp[1]);
	dc.SetPixel(mp[1],500);                //������һ������㣬�����͵õ���һ���������
	
	CView::OnRButtonDown(nFlags, point);
}

void CZhztchView::OnScanfill() 
{
	RedrawWindow();
	CDC* pDC=GetDC();
	CPen newpen(PS_SOLID,3,RGB(255,0,0));
	CPen *old=pDC->SelectObject(&newpen);

	spt[0]=CPoint(200,200);    //���ƶ��������
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
	int p[5];  //ÿ��ɨ���߽���
	int pmin = 0,pmax = 0;
	for(int i=0;i<=6;i++)//�����߱�
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
	for(int r=1;r<=6;r++)	//����edge(yUpper��xIntersect)�����Ϊ�Ӵ�С
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
			if((scan>edge[j].ymin)&&(scan<=edge[j].ymax))//�ж����߶��ཻ
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
	MessageBox("�뵥��ѡȡ���ӵ�")	;
}

