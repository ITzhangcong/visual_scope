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
{    //CMyButtun��ĺ���
    m_DownColor = color;
}
void CMyButtun::SetUpColor(COLORREF color)
{
    m_UpColor = color;
}
/////////////////////////////////////////////////////////////////////////////
// CMyButtun message handlers
//��׽����ƶ���Ϣ
void CMyButtun::OnMouseMove(UINT nFlags, CPoint point) 
{
// 	CString str;
// 	str.Format("û�з���");//�ܰ�~~~~~~~~~~~~~~~~~~~~~~~
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
	//�汾��
	{
	   CDC dc;
	   dc.Attach(lpDrawItemStruct->hDC);//�õ����Ƶ��豸����CDC
	   VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);
	   //�õ�Button������,����Ĳ�����:1,�ȵõ�����Դ��༭�İ�ť������,
	   //Ȼ�󽫴��������»��Ƶ���ť��,
	   //ͬʱ�������ֵı���ɫ��Ϊ͸��,����,��ť�Ͻ�����ʾ����
	   const int bufSize = 512;
	   TCHAR buffer[bufSize];
	   GetWindowText(buffer, bufSize);
	   int size=strlen(buffer);//�õ�����
	   DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//��������
	   SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//͸��
	   if (lpDrawItemStruct->itemState&ODS_SELECTED)//�����°�ťʱ�Ĵ���
	   {////�ػ���������
		   CBrush brush(m_DownColor);
		   dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//���û�ˢbrush�������ο�
		   //��Ϊ����������ػ�,��������ҲҪ�ػ�
		   DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
		   SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
	   }
	   else//����ť���������ߵ���ʱ
	   {
		   CBrush brush(m_UpColor);
		   dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//
		   DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
		   SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
	   }
 	   if ((lpDrawItemStruct->itemState&ODS_SELECTED)&&(lpDrawItemStruct->itemAction &(ODA_SELECT|ODA_DRAWENTIRE)))
 	   {//ѡ���˱��ؼ�,�����߿�
 		   COLORREF fc=RGB(255-GetRValue(m_UpColor),255-GetGValue(m_UpColor),255-GetBValue(m_UpColor));
 		   CBrush brush(fc);
 		   dc.FrameRect(&(lpDrawItemStruct->rcItem),&brush);//�û�ˢbrush�������α߿�
 	   }
 	   if (!(lpDrawItemStruct->itemState &ODS_SELECTED) &&(lpDrawItemStruct->itemAction & ODA_SELECT))
 	   {
 		   CBrush brush(m_UpColor); //���Ƶ�ѡ��״̬����,ȥ���߿�
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

