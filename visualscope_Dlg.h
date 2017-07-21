// visualscope_Dlg.h : main header file for the VISUALSCOPE_DLG application
//

#if !defined(AFX_VISUALSCOPE_DLG_H__7F6D8968_A1CA_4803_B219_908A8E072EC2__INCLUDED_)
#define AFX_VISUALSCOPE_DLG_H__7F6D8968_A1CA_4803_B219_908A8E072EC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVisualscope_DlgApp:
// See visualscope_Dlg.cpp for the implementation of this class
//

class CVisualscope_DlgApp : public CWinApp
{
public:
	CVisualscope_DlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisualscope_DlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVisualscope_DlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISUALSCOPE_DLG_H__7F6D8968_A1CA_4803_B219_908A8E072EC2__INCLUDED_)
