// MyButtun.cpp : implementation file
//

#include "stdafx.h"
#include "MyButtun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

CMyButtun::~CMyButtun()
{
}

BEGIN_MESSAGE_MAP(CMyButtun, CButton)
	//{{AFX_MSG_MAP(CMyButtun)
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_INITMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CMyButtun::Attach(const UINT nID,CWnd* pParent)
{
    if (!SubclassDlgItem(nID, pParent))
		return FALSE;
    return TRUE;
}
void CMyButtun::SetDownColor(COLORREF color)
{    //CMyButtun类的函数
    m_DownColor = color;
}
void CMyButtun::SetUpColor(COLORREF color)
{
    m_UpColor = color;
}
/////////////////////////////////////////////////////////////////////////////
// CMyButtun message handlers
//捕捉鼠标移动消息
void CMyButtun::OnMouseMove(UINT nFlags, CPoint point) 
{
// 	CString str;
// 	str.Format("没有发现");//很棒~~~~~~~~~~~~~~~~~~~~~~~
// 	AfxMessageBox(str);	
//SetDownColor(RGB(255,0,0));
// 	m_flag=true; 
// 	TRACKMOUSEEVENT tme; 
// 	tme.cbSize=sizeof(tme); 
// 	tme.dwFlags=TME_LEAVE; 
// 	tme.hwndTrack=this->m_hWnd; 
// 	::_TrackMouseEvent(&tme); 
// 	CButton::OnMouseMove(nFlags, point); 
// 	Invalidate();

	CButton::OnMouseMove(nFlags, point);
}

void CMyButtun::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
///////////////
	//版本三
	{
	   CDC dc;
	   dc.Attach(lpDrawItemStruct->hDC);//得到绘制的设备环境CDC
	   VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);
	   //得当Button上文字,这里的步骤是:1,先得到在资源里编辑的按钮的文字,
	   //然后将此文字重新绘制到按钮上,
	   //同时将此文字的背景色设为透明,这样,按钮上仅会显示文字
	   const int bufSize = 512;
	   TCHAR buffer[bufSize];
	   GetWindowText(buffer, bufSize);
	   int size=strlen(buffer);//得到长度
	   DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//绘制文字
	   SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//透明
	   if (lpDrawItemStruct->itemState&ODS_SELECTED)//当按下按钮时的处理
	   {////重绘整个控制
		   CBrush brush(m_DownColor);
		   dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//利用画刷brush，填充矩形框
		   //因为这里进行了重绘,所以文字也要重绘
		   DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
		   SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
	   }
	   else//当按钮不操作或者弹起时
	   {
		   CBrush brush(m_UpColor);
		   dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//
		   DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
		   SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
	   }
 	   if ((lpDrawItemStruct->itemState&ODS_SELECTED)&&(lpDrawItemStruct->itemAction &(ODA_SELECT|ODA_DRAWENTIRE)))
 	   {//选中了本控件,高亮边框
 		   COLORREF fc=RGB(255-GetRValue(m_UpColor),255-GetGValue(m_UpColor),255-GetBValue(m_UpColor));
 		   CBrush brush(fc);
 		   dc.FrameRect(&(lpDrawItemStruct->rcItem),&brush);//用画刷brush，填充矩形边框
 	   }
 	   if (!(lpDrawItemStruct->itemState &ODS_SELECTED) &&(lpDrawItemStruct->itemAction & ODA_SELECT))
 	   {
 		   CBrush brush(m_UpColor); //控制的选中状态结束,去掉边框
 		   dc.FrameRect(&lpDrawItemStruct->rcItem,&brush);//}
 		   dc.Detach();
 		}
	}
}
BOOL CMyButtun::OnEraseBkgnd(CDC* pDC) 
{
// 	CBrush   brush;
//     CRect   rect;
//     COLORREF   rgbBackGnd   =   RGB(210,210,210);
//     GetClientRect(&rect);
//     brush.CreateSolidBrush(rgbBackGnd);
//     pDC-> FillRect(rect,&brush);
    return   TRUE;	
//	return CButton::OnEraseBkgnd(pDC);
}

HBRUSH CMyButtun::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CButton::OnCtlColor(pDC, pWnd, nCtlColor);

	return My_Brush;
//	return hbr;
}

