
// MFC_0316View.cpp : CMFC_0316View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0316.h"
#endif

#include "MFC_0316Doc.h"
#include "MFC_0316View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0316View

IMPLEMENT_DYNCREATE(CMFC_0316View, CView)

BEGIN_MESSAGE_MAP(CMFC_0316View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC_0316View 构造/析构

CMFC_0316View::CMFC_0316View()
{
	// TODO: 在此处添加构造代码

}

CMFC_0316View::~CMFC_0316View()
{
}

BOOL CMFC_0316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0316View 绘制

void CMFC_0316View::OnDraw(CDC* /*pDC*/)
{
	CMFC_0316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0316View 诊断

#ifdef _DEBUG
void CMFC_0316View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0316Doc* CMFC_0316View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0316Doc)));
	return (CMFC_0316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0316View 消息处理程序


void CMFC_0316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	SetCapture();
	pDoc->A.left = point.x;
	pDoc->A.top = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC_0316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	ReleaseCapture();
	pDoc->A.right = point.x;
	pDoc->A.bottom = point.y;
	CClientDC dc(this);
	dc.Rectangle(pDoc->A.left,pDoc->A.top,pDoc->A.right,pDoc->A.bottom);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC_0316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC clientDC(this);
	CString s;
	s.Format(_T("X:%d  Y:%d"), point.x, point.y);
	clientDC.TextOutW(200, 20, s);
	CView::OnMouseMove(nFlags, point);
}
