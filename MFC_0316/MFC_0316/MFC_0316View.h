
// MFC_0316View.h : CMFC_0316View ��Ľӿ�
//

#pragma once


class CMFC_0316View : public CView
{
protected: // �������л�����
	CMFC_0316View();
	DECLARE_DYNCREATE(CMFC_0316View)

// ����
public:
	CMFC_0316Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC_0316View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_0316View.cpp �еĵ��԰汾
inline CMFC_0316Doc* CMFC_0316View::GetDocument() const
   { return reinterpret_cast<CMFC_0316Doc*>(m_pDocument); }
#endif

