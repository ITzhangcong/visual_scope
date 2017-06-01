// visualscope_DlgDlg.h : header file
//
#include "Serialport.h"
#include "MyButtun.h"
#if !defined(AFX_VISUALSCOPE_DLGDLG_H__41DAB474_9277_4B0A_9E85_A64239F59106__INCLUDED_)
#define AFX_VISUALSCOPE_DLGDLG_H__41DAB474_9277_4B0A_9E85_A64239F59106__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVisualscope_DlgDlg dialog
#define max_point_num 200000//最大点数
class CVisualscope_DlgDlg : public CDialog
{
// Construction
public:
	CVisualscope_DlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVisualscope_DlgDlg)
	enum { IDD = IDD_VISUALSCOPE_DLG_DIALOG };
	CButton	m_check_positive_only;
	CMyButtun	m_button_about_author;
	CMyButtun	m_buttun_Y_little;
	CMyButtun	m_buttun_Y_big;
	CMyButtun	m_buttun_x_little;
	CMyButtun	m_buttun_X_big;
	CButton	m_check_channel4;
	CButton	m_check_channel3;
	CButton	m_check_channel2;
	CButton	m_check_channel1;
	CButton	m_check_y_auto;
	CMyButtun m_buttun_clean_scope;
	CButton	m_check_x_follow;
	CStatic	m_receive_count;
	CStatic	m_static_disp_nothing;
	CComboBox	m_Combo_bandRate;
	CComboBox	m_combo_com_num;
	CMyButtun	m_open_serial_port;//rxh1.5
	CMyButtun	m_button_stop_scope;//rxh2.3
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisualscope_DlgDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	public:
		CSerialPort tCSerialPort;//定义串口类
		BOOL  m_bSerialPortOpened; //标志串口是否打开
		unsigned int m_BaudRate;//波特率
		unsigned char Com_Num;//串口号
		unsigned char *receive_buffer;
		signed short int (*scope_data)[4];
		long int MaxTotalBufNum;
		int ctTotalBufNum;
		//	int Str2Hex(CString str, char* data);
		//char HexChar(char );
		CRect m_rect;
		char disp_scope_flag;
		CButton m_button;//虚拟按钮
		CBrush m_DlgBackGroundColor;//对话框背景色
		int XDispScale,YDispScale;  // 显示比例尺，表示1米对应的像素数
		CRect tRect1;//矩形画图背景
		CFont m_font,n_font,x_font;//创建字体
		int scoll_position,max_scoll_position;//滚动条位置
		SCROLLINFO xSi;//滚动条结构体
		int point_num,point_num_temp,bad_num,point_num_old;
		char y_auto;//Y轴自适应标志位
		char positive_only_flag;
		char *disp_channl;
		CPoint mouse_point;
		bool Dragging;
		HCURSOR hCross;
		char disp_biaochi;
		bool disp_point_add_flag;
		int mouse_move_x;
		int mouse_right_down_x,mouse_right_up_x;
		char about_author_flag;
		char mouse_right_down_flag,mouse_right_up_flag;
		int select_left,select_right;//rxh3.0选中的坐标

	//	HBITMAP m_hBitmap;//rxh2.6位图句柄
	public:
		void OnDraw_000(CDC* pDC);
		void Display(CDC *pDC,signed short int(* buff_out)[4]);
		void close_port_all();
		void change_buttun_color();
		unsigned short CRC_CHECK(unsigned char *Buf, unsigned char CRC_CNT);
		void ReceiveDataDecode(unsigned char *buffer_in,	signed short int(* buff_out)[4]);
		void DispAboutAuthor(CDC *pDC,int X_basic,int Y_basic);
		void SaveSoftwareConfig();
		void OpenSoftwareConfig();
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVisualscope_DlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg LONG OnCommReceivedata(WPARAM ch, LPARAM port); //串口事件消息响应函数
	afx_msg void OnButtonOpenComFirst();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonCleanScope();
	afx_msg void OnButtonXBig();
	afx_msg void OnButtonXLittle();
	afx_msg void OnButtonYBig();
	afx_msg void OnButtonYLittle();
	afx_msg void OnSelendokComboBandrate();
	afx_msg void OnSelendokComboComNum();
	afx_msg void OnDropdownComboComNum();
	afx_msg void OnDestroy();
	afx_msg	void OnComErrorAndClose();//rxh1.5串口出错通知
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCheckXFollow();
	afx_msg void OnCheckYAuto();
	afx_msg void OnCheckChannel1();
	afx_msg void OnCheckChannel2();
	afx_msg void OnCheckChannel3();
	afx_msg void OnCheckChannel4();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam,LPARAM lParam);//rxh2.2手动添加鼠标响应函数
	afx_msg LRESULT OnMouseHover(WPARAM wParam,LPARAM lParam);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnButtonStopScope();
	afx_msg void OnButtonAboutAuthor();
	afx_msg void OnButtonSaveScope();
	afx_msg void OnButtonOpenDataFromFile();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCheckPositiveOnly();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISUALSCOPE_DLGDLG_H__41DAB474_9277_4B0A_9E85_A64239F59106__INCLUDED_)
