
// Paint.h : main header file for the PROJECT_NAME application
//
#if !defined(AFX_DLG_H__A7561E47_8B22_413E_8611_6D285DD57136__INCLUDED_)
#define AFX_DLG_H__A7561E47_8B22_413E_8611_6D285DD57136__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPaintApp:
// See Paint.cpp for the implementation of this class
//

class CPaintApp : public CWinApp
{
public:
	CPaintApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPaintApp theApp;

#endif