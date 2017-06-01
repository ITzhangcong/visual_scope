// visualscope_Dlg.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "visualscope_Dlg.h"
#include "visualscope_DlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVisualscope_DlgApp

BEGIN_MESSAGE_MAP(CVisualscope_DlgApp, CWinApp)
	//{{AFX_MSG_MAP(CVisualscope_DlgApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisualscope_DlgApp construction

CVisualscope_DlgApp::CVisualscope_DlgApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVisualscope_DlgApp object

CVisualscope_DlgApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVisualscope_DlgApp initialization

BOOL CVisualscope_DlgApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CVisualscope_DlgDlg dlg;
	m_pMainWnd = &dlg;
	//rxh1.4改变对话框背景色和文本颜色
	SetDialogBkColor(RGB(0,128,255),RGB(255,0,0));
	//显示非模态对话框
	int nResponse = dlg.DoModal();
	


	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
