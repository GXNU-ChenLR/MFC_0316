
// MFC_0316.h : MFC_0316 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_0316App:
// �йش����ʵ�֣������ MFC_0316.cpp
//

class CMFC_0316App : public CWinApp
{
public:
	CMFC_0316App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_0316App theApp;
