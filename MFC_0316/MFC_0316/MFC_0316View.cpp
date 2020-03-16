
// MFC_0316View.cpp : CMFC_0316View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC_0316View ����/����

CMFC_0316View::CMFC_0316View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_0316View::~CMFC_0316View()
{
}

BOOL CMFC_0316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0316View ����

void CMFC_0316View::OnDraw(CDC* /*pDC*/)
{
	CMFC_0316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0316View ���

#ifdef _DEBUG
void CMFC_0316View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0316Doc* CMFC_0316View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0316Doc)));
	return (CMFC_0316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0316View ��Ϣ�������


void CMFC_0316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC clientDC(this);
	CString s;
	s.Format(_T("X:%d  Y:%d"), point.x, point.y);
	clientDC.TextOutW(200, 20, s);
	CView::OnMouseMove(nFlags, point);
}
