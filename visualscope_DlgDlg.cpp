// visualscope_DlgDlg.cpp : implementation file
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
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisualscope_DlgDlg dialog

CVisualscope_DlgDlg::CVisualscope_DlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVisualscope_DlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVisualscope_DlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CVisualscope_DlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVisualscope_DlgDlg)
	DDX_Control(pDX, IDC_CHECK_POSITIVE_ONLY, m_check_positive_only);
	DDX_Control(pDX, IDC_CHECK_CHANNEL4, m_check_channel4);
	DDX_Control(pDX, IDC_CHECK_CHANNEL3, m_check_channel3);
	DDX_Control(pDX, IDC_CHECK_CHANNEL2, m_check_channel2);
	DDX_Control(pDX, IDC_CHECK_CHANNEL1, m_check_channel1);
	DDX_Control(pDX, IDC_CHECK_Y_AUTO, m_check_y_auto);
	DDX_Control(pDX, IDC_CHECK_X_FOLLOW, m_check_x_follow);
	DDX_Control(pDX, IDC_STATIC_RECEIVE_COUNT, m_receive_count);
	DDX_Control(pDX, IDC_STATIC_DISP_NOTHING, m_static_disp_nothing);
	DDX_Control(pDX, IDC_COMBO_BANDRATE, m_Combo_bandRate);
	DDX_Control(pDX, IDC_COMBO_COM_NUM, m_combo_com_num);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVisualscope_DlgDlg, CDialog)
	//{{AFX_MSG_MAP(CVisualscope_DlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommReceivedata) //串口消息处理，只需添加这一行
	ON_BN_CLICKED(IDC_BUTTON_OPEN_COM_FIRST, OnButtonOpenComFirst)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_CLEAN_SCOPE, OnButtonCleanScope)
	ON_BN_CLICKED(IDC_BUTTON_X_BIG, OnButtonXBig)
	ON_BN_CLICKED(IDC_BUTTON_X_LITTLE, OnButtonXLittle)
	ON_BN_CLICKED(IDC_BUTTON_Y_BIG, OnButtonYBig)
	ON_BN_CLICKED(IDC_BUTTON_Y_LITTLE, OnButtonYLittle)
	ON_CBN_SELENDOK(IDC_COMBO_BANDRATE, OnSelendokComboBandrate)
	ON_CBN_SELENDOK(IDC_COMBO_COM_NUM, OnSelendokComboComNum)
	ON_CBN_DROPDOWN(IDC_COMBO_COM_NUM, OnDropdownComboComNum)
	ON_WM_DESTROY()
	ON_MESSAGE(WM_COMM_CLOSE_PORT, OnComErrorAndClose) //rxh2.8
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHECK_X_FOLLOW, OnCheckXFollow)
	ON_BN_CLICKED(IDC_CHECK_Y_AUTO, OnCheckYAuto)
	ON_BN_CLICKED(IDC_CHECK_CHANNEL1, OnCheckChannel1)
	ON_BN_CLICKED(IDC_CHECK_CHANNEL2, OnCheckChannel2)
	ON_BN_CLICKED(IDC_CHECK_CHANNEL3, OnCheckChannel3)
	ON_BN_CLICKED(IDC_CHECK_CHANNEL4, OnCheckChannel4)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_MESSAGE(WM_MOUSELEAVE,OnMouseLeave)//rxh2.2手动添加
	ON_MESSAGE(WM_MOUSEHOVER,OnMouseHover)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUTTON_STOP_SCOPE, OnButtonStopScope)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT_AUTHOR, OnButtonAboutAuthor)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_SCOPE, OnButtonSaveScope)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_DATA_FROM_FILE, OnButtonOpenDataFromFile)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_BN_CLICKED(IDC_CHECK_POSITIVE_ONLY, OnCheckPositiveOnly)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisualscope_DlgDlg message handlers

BOOL CVisualscope_DlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
	m_bSerialPortOpened=FALSE;
	m_BaudRate=115200;
	//rxh2.7曾加接收缓冲区
	receive_buffer=new unsigned char[1024*10];;
	MaxTotalBufNum=1024*10;//总的字节数
	memset(receive_buffer,0,sizeof(unsigned char)*MaxTotalBufNum);//rxh2.9.1
	ctTotalBufNum=0;
	tCSerialPort.Hkey2ComboBox(m_combo_com_num);//遍历串口//rxh2.0
	Com_Num=m_nComArray[0];//在遍历函数中从注册表中读取的串口号存储到m_nComArray[]数组中
	m_Combo_bandRate.SetCurSel(11);//波特率默认115200
	//获取控件大小//rxh2.2
	CRect tRect;
	GetClientRect(&tRect);//获取当前客户区的大小
	tRect1.left=tRect.left;
	tRect1.top=tRect.top+40;
	tRect1.right=tRect.right;
	tRect1.bottom=tRect.bottom;
	disp_scope_flag=0;	
	SetTimer(1,100,NULL);//设置定时器
	SetTimer(2,2000,NULL);//设置定时器
	//	CreatePointFont(90, "宋体");
	m_DlgBackGroundColor.CreateSolidBrush(RGB(100,155,100));//自定义一个画刷,颜色与双缓冲颜色相同
	// 显示比例尺
	XDispScale=10;
	YDispScale=10; 
	//改变字体
	m_font.CreatePointFont(100,"新宋体");
	n_font.CreatePointFont(109,"宋体");
	x_font.CreatePointFont(120,"宋体");
	//修改按钮颜色//rxh1.5
	change_buttun_color();
	//m_open_serial_port.SetFont(&m_font);//改变按钮字体
	//滚动条设置//rxh2.4
	xSi.cbSize = sizeof (xSi);
	xSi.fMask  = SIF_ALL;
	xSi.nMin = 0; //最小滚动位置
	xSi.nMax = 200000;//最大滚动位置
	xSi.nPage = 10;//
	xSi.nPos = 0;
	xSi.nTrackPos = 0;
	SetScrollInfo(SB_HORZ,&xSi);
	max_scoll_position=xSi.nMax-xSi.nMin+1-xSi.nPage;//滚动条最大位置=nMax-nMin+1-nPage
	scoll_position=max_scoll_position;//初始化滚动条位置
	SetScrollPos(SB_HORZ, max_scoll_position);  
	m_check_x_follow.SetCheck(1);//初始化跟随
	//波形存储数组
	scope_data=new short int[max_point_num][4];
	memset(scope_data,0,sizeof(short int)*max_point_num*4);
	point_num=0;
	point_num_temp=0;
	point_num_old=0;
	bad_num=0;
	y_auto=1;//Y自适应
	positive_only_flag=0;//纯正数显示
	m_check_positive_only.SetCheck(0);
	m_check_y_auto.SetCheck(1);//默认Y轴自动适应//rxh2.7
	disp_channl=new char[4];//控制多通道显示
	memset(disp_channl,1,sizeof(char)*4);
	m_check_channel1.SetCheck(1);//默认选中通道
	m_check_channel2.SetCheck(1);
	m_check_channel3.SetCheck(1);
	m_check_channel4.SetCheck(1);
	Dragging=false;//初始化拖拽
	hCross=AfxGetApp()->LoadStandardCursor(IDC_SIZENESW);//获得十字光标句柄
	mouse_move_x=0;
	mouse_right_down_x=0;
	mouse_right_up_x=0;
	disp_biaochi=1;//是否显示数据值和标示线
	disp_point_add_flag=true;//波形不暂停
	about_author_flag=0;
	mouse_right_down_flag=0;
	mouse_right_up_flag=0;//右键抬起标志
	select_left=0;//矩形框选择的左坐标
	select_right=0;
	OpenSoftwareConfig();//读取上次软件的设置
// 	m_hBitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),//rxh2.6位图
//             "1.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CVisualscope_DlgDlg::change_buttun_color()
{	int ID_array[6]={IDC_BUTTON_OPEN_COM_FIRST,IDC_BUTTON_CLEAN_SCOPE};//rxh2.0
	COLORREF color[4]={RGB(0,255,0),RGB(0,245,255),RGB(10,100,255)};
// 	CMyButtun my_button[6];
// 	my_button[0]=m_open_serial_port;
	GetDlgItem(IDC_BUTTON_OPEN_COM_FIRST)->ModifyStyle(0,BS_OWNERDRAW,0);//打开串口	
	m_open_serial_port.Attach(IDC_BUTTON_OPEN_COM_FIRST,this);
    m_open_serial_port.SetDownColor(color[0]);
    m_open_serial_port.SetUpColor(color[1]);
	GetDlgItem(IDC_BUTTON_CLEAN_SCOPE)->ModifyStyle(0,BS_OWNERDRAW,0);//清除波形
	m_buttun_clean_scope.Attach(IDC_BUTTON_CLEAN_SCOPE,this);
    m_buttun_clean_scope.SetDownColor(RGB(255,255,200));
    m_buttun_clean_scope.SetUpColor(color[2]);
	GetDlgItem(IDC_BUTTON_STOP_SCOPE)->ModifyStyle(0,BS_OWNERDRAW,0);//暂停波形
	m_button_stop_scope.Attach(IDC_BUTTON_STOP_SCOPE,this);
    m_button_stop_scope.SetDownColor(color[0]);
    m_button_stop_scope.SetUpColor(color[0]);
	GetDlgItem(IDC_BUTTON_SAVE_SCOPE)->ModifyStyle(0,BS_OWNERDRAW,0);//保存
	m_buttun_X_big.Attach(IDC_BUTTON_SAVE_SCOPE,this);
    m_buttun_X_big.SetDownColor(color[0]);
    m_buttun_X_big.SetUpColor(color[1]);
	GetDlgItem(IDC_BUTTON_OPEN_DATA_FROM_FILE)->ModifyStyle(0,BS_OWNERDRAW,0);	//打开波形
	m_buttun_x_little.Attach(IDC_BUTTON_OPEN_DATA_FROM_FILE,this);
    m_buttun_x_little.SetDownColor(color[0]);
    m_buttun_x_little.SetUpColor(color[2]);
	GetDlgItem(IDC_BUTTON_ABOUT_AUTHOR)->ModifyStyle(0,BS_OWNERDRAW,0);	//关于
	m_button_about_author.Attach(IDC_BUTTON_ABOUT_AUTHOR,this);
    m_button_about_author.SetDownColor(color[2]);
    m_button_about_author.SetUpColor(color[1]);
}
void CVisualscope_DlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.\

//打开串口
void CVisualscope_DlgDlg::OnButtonOpenComFirst() 
{
	m_bSerialPortOpened=!m_bSerialPortOpened;//取反标志位
	if(m_bSerialPortOpened)//打开串口
	{
		if(tCSerialPort.InitPort(this->m_hWnd, Com_Num,m_BaudRate,'N',8,1,EV_RXFLAG | EV_RXCHAR,512))//初始化函数如果成功就返回TRUE，可以用来判断
		{
			tCSerialPort.StartMonitoring();///启用串口通信监测线程函数
			m_bSerialPortOpened=TRUE;//
			scoll_position=max_scoll_position;//打开串口时继续跟踪
			SetScrollPos(SB_HORZ, max_scoll_position);
			m_check_x_follow.SetCheck(1);//初始化跟随rxh2.9.3
			disp_point_add_flag=TRUE;
			m_open_serial_port.SetUpColor(RGB(255,255,0));//设置背景颜色
			m_open_serial_port.SetWindowText("关闭串口");//在按钮上显示字符串
		}
		else
		{
			m_bSerialPortOpened=FALSE;//标志位取反
			CString str;
			str.Format("COM%d 没有发现或被其它设备占用",Com_Num);//很棒~~~~~~~~~~~~~~~~~~~~~~~
			AfxMessageBox(str);
		}
	}
	else//关闭串口
	close_port_all();
}
//串口接收到数据
//ch->接收到的字符数据，port->串口号##########################################
LONG CVisualscope_DlgDlg::OnCommReceivedata(WPARAM ch, LPARAM port)
{	
	receive_buffer[ctTotalBufNum]=ch;//存入缓冲区
	if(ctTotalBufNum<MaxTotalBufNum)
	ctTotalBufNum++;//rxh2.7缓冲区指针+1
	else ctTotalBufNum=0;
	disp_scope_flag=1;//收到数据显示波形
	// 	//传入参数ch就是传进来的字符型数据，可以使用的数据*******************#########
	return 0;
}
void CVisualscope_DlgDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//显示调用
		//////////////////////////////////////////////////////
		CPaintDC dc(this); // device context for painting
		OnDraw_000(&dc);//rxh1.4
		CDialog::OnPaint();
// 		if(m_hBitmap)//rxh2.6
//         {
//             CPaintDC dc(this); // device context for painting
//             CRect rc;
//             GetClientRect(rc);
//             CDC memDC;
//             memDC.CreateCompatibleDC(&dc);
//             HBITMAP old=(HBITMAP)memDC.SelectObject(m_hBitmap);
//             dc.BitBlt(0,0,rc.Width(),rc.Height(),&memDC,0,0,SRCCOPY);
//             memDC.SelectObject(old);
//         }
	}
}
void CVisualscope_DlgDlg::OnDraw_000(CDC* pDC)
{
	//引入双缓冲绘图，防止闪烁
	////////////////////////////////////////////////
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);  //pDC	
	RECT rcRect;
	::GetClientRect(this->m_hWnd, &rcRect);
	int rcWidth = rcRect.right - rcRect.left;
	int rcHeight = rcRect.bottom - rcRect.top;	
	CBitmap MemBmp;
	MemBmp.CreateCompatibleBitmap(pDC, rcWidth, rcHeight);	
	CBitmap* pOldBmp = MemDC.SelectObject(&MemBmp);
	MemDC.FillSolidRect(0, 0, rcWidth, rcHeight, RGB(100,155,100));	//rxh1.5把背景填充为黄色
	//#######################################################################
	// 真正的绘制代码区 !!!!!!!!!!
	Display(&MemDC,scope_data);	
	//####################################################################
	//将内存中的图拷贝到屏幕上进行显示
	pDC->BitBlt(0, 0, rcWidth, rcHeight, &MemDC, 0, 0, SRCCOPY);	
	MemBmp.DeleteObject();
	MemDC.DeleteDC();
}
//对接收到数据进行解码，得到四个通道的数据
void CVisualscope_DlgDlg::ReceiveDataDecode(unsigned char *buffer_in,	signed short int(* buff_out)[4])
{
	int temp_index=0;
	unsigned short int scope_data_temp[4]={0};
	unsigned short CRC16 = 0,CRC16_receiv=0;
	unsigned char databuf[8] = {0};
	static unsigned char flag=0;
	while (temp_index+10<=ctTotalBufNum)
	{
		scope_data_temp[0]=*( (unsigned short int *)(&buffer_in[temp_index]) );
		temp_index+=2;
		scope_data_temp[1]=*( (unsigned short int *)(&buffer_in[temp_index]) );
		temp_index+=2;
		scope_data_temp[2]=*( (unsigned short int *)(&buffer_in[temp_index]) );
		temp_index+=2;
		scope_data_temp[3]=*( (unsigned short int *)(&buffer_in[temp_index]) );
		temp_index+=2;
		CRC16_receiv=*( (unsigned short int *)(&buffer_in[temp_index]) );//接收的CRC
		temp_index+=2;
		for(char i=0;i<4;i++) //将data转换为unsigned char去校验
		{
			databuf[i<<1]   = (unsigned char)(scope_data_temp[i]&0x00ff);//rxh2.8改/256变为&0xff00)>>8
			databuf[(i<<1)+1] = (unsigned char)((scope_data_temp[i]&0xff00)>>8);
		}
		CRC16=CRC_CHECK(databuf,8);//计算CRC

		if (CRC16==CRC16_receiv)//校验合格，数据有效
		{
			for (i=0;i<4;i++)//得到波形数据
			{
				buff_out[point_num_temp][i]=(signed short int)scope_data_temp[i];
			}
			if(point_num_temp<max_point_num-1)
				point_num_temp++;
			else //缓冲区溢出
			{	
				if(flag==0)
				{	flag=1;//rxh2.9.1改变保存方式
					break;
				}
			}
		}
		else //数据出错，进行移位纠正//rxh2.0
		{
			bad_num++;
			while(temp_index+10<=ctTotalBufNum)//rxh2.1改<为=
			{	scope_data_temp[0]=*( (unsigned short int *)(&buffer_in[temp_index]) );
				temp_index+=2;
				scope_data_temp[1]=*( (unsigned short int *)(&buffer_in[temp_index]) );
				temp_index+=2;
				scope_data_temp[2]=*( (unsigned short int *)(&buffer_in[temp_index]) );
				temp_index+=2;
				scope_data_temp[3]=*( (unsigned short int *)(&buffer_in[temp_index]) );
				temp_index+=2;
				CRC16_receiv=*( (unsigned short int *)(&buffer_in[temp_index]) );//接收的CRC
				temp_index+=2;
				for(char i=0;i<4;i++) //将data转换为unsigned char去校验
				{
					databuf[i<<1]   = (unsigned char)(scope_data_temp[i]&0x00ff);//rxh2.8改/256变为&0xff00)>>8
					databuf[(i<<1)+1] = (unsigned char)((scope_data_temp[i]&0xff00)>>8);
				}
				CRC16=CRC_CHECK(databuf,8);//计算CRC
				
				if (CRC16==CRC16_receiv)//校验合格，数据有效
				{
					for (i=0;i<4;i++)//得到波形数据
					{
						buff_out[point_num_temp][i]=(signed short int)scope_data_temp[i];
					}
					if(point_num_temp<max_point_num-1)
						point_num_temp++;
					break;//数据恢复正常跳出循环
				}
				temp_index-=9;//一次移动一位，而不是移动10位
			}
		}
	}
	if(disp_point_add_flag)//rxh2.3是否暂停显示
	point_num=point_num_temp;
	///////////////////
	// 总缓冲串移
	int move_num=ctTotalBufNum-temp_index;//rxh2.9.1防止移位出错
	if (move_num<0)
	{
		move_num=0;
		AfxMessageBox("缓冲串移个数出现负值！");
	}
	memmove(receive_buffer,&receive_buffer[temp_index],move_num);
	ctTotalBufNum-=temp_index;
	temp_index=0;

	if (flag==1)//rxh2.9.1改变保存方式
	{	
		flag=0;
		close_port_all();
		ctTotalBufNum=0;
		//	AfxMessageBox("串口数据缓冲区已满,保存当前波形数据");
		OnButtonSaveScope();//rxh2.8//保存数据
		OnButtonCleanScope();
		point_num_temp=0;
	}
}
//CRC计算函数
unsigned short CVisualscope_DlgDlg::CRC_CHECK(unsigned char *Buf, unsigned char CRC_CNT)
{
    unsigned short CRC_Temp;
    unsigned char i,j;
    CRC_Temp = 0xffff;
	
    for (i=0;i<CRC_CNT; i++){      
        CRC_Temp ^= Buf[i];
        for (j=0;j<8;j++) {
            if (CRC_Temp & 0x01)
                CRC_Temp = (CRC_Temp >>1 ) ^ 0xa001;
            else
                CRC_Temp = CRC_Temp >> 1;
        }
    }
    return(CRC_Temp);
}
//显示函数
void CVisualscope_DlgDlg::Display(CDC *pDC,signed short int(* buff_out)[4])
{
	static short int max=0,min=0;//rxh2.8增加最小值判断
	static select_left_change=0;//rxh3.0
	CString string_temp;
	CString strTemp;
	strTemp.Format("正确:%ld错误:%d",point_num_temp,bad_num);
	m_static_disp_nothing.SetWindowText(strTemp);
	//rxh2.4叠加鼠标拖动偏移量
	//基准坐标
	int X_basic=tRect1.left+40,Y_basic;
	//是否显示负数部分
	if (positive_only_flag)
		Y_basic=tRect1.bottom-20;
	else
		Y_basic=tRect1.top+tRect1.Height()/2;
	//绘制矩形背景
	CBrush tBrush(RGB(28,28,28));
	pDC->SelectObject(&tBrush);
	pDC->Rectangle(tRect1);
	//网格线
	CPen tPen0(0,1,RGB(0,50,0));
	pDC->SelectObject(&tPen0);
	int x_line=tRect1.bottom/40;//
	for (int i=1;i<x_line;i++)//横线
	{
		int x_temm=i*40;
		if(Y_basic-x_temm<tRect1.top)//防止画到矩形外
			break;
		pDC->MoveTo(X_basic,Y_basic+x_temm);
		pDC->LineTo(tRect1.right,Y_basic+x_temm);
		pDC->MoveTo(X_basic,Y_basic-x_temm);
		pDC->LineTo(tRect1.right,Y_basic-x_temm);
	}
	int y_line=tRect1.right/50;
	for (i=1;i<y_line;i++)//竖线
	{

		pDC->MoveTo(X_basic+i*50,tRect1.top);
		pDC->LineTo(X_basic+i*50,tRect1.bottom);		
 	}
	//X轴坐标线
	CPen tPen1(0,2,RGB(100,0,0));
	pDC->SelectObject(&tPen1);	
	// 	pDC->MoveTo(tRect1.left,tRect1.bottom);
	// 	pDC->LineTo(tRect1.right,tRect1.bottom);
	pDC->MoveTo(X_basic,Y_basic);
	pDC->LineTo(tRect1.right,Y_basic);
	//Y轴坐标线
	pDC->MoveTo(X_basic,tRect1.top);
	pDC->LineTo(X_basic,tRect1.bottom-2);
	//Y轴自适应//有待商榷，可以改为只调整当前屏幕的点的放大比例,而不是全部数据
	if(y_auto)
	{	
		for (int i1=point_num_old;i1<point_num_temp;i1++)
			for (char j1=0;j1<4;j1++)
			{			
				if(buff_out[i1][j1]>=max)
					max=buff_out[i1][j1];
				else if(buff_out[i1][j1]<=min)
					min=buff_out[i1][j1];
			}
			int scale_temp=0;
			if (positive_only_flag)//正负数自动缩放的差别
				scale_temp=45;
			else
				scale_temp=85;
		YDispScale=(int)max*scale_temp/tRect1.Height();//自动变换缩放比例
		int YDispScale_temp=0;
		if (min<0)
			YDispScale_temp=-(int)min*scale_temp/tRect1.Height();
		if(YDispScale_temp>YDispScale)
			YDispScale=YDispScale_temp;

		if(YDispScale<=1)//防止除数为零
			YDispScale=1;
	}
	//记录本次解码的个数
	point_num_old=point_num_temp;

	int color[4]={RGB(255,0,0),RGB(255,255,0),RGB(0,0,255),RGB(255,0,255)};//四个通道的颜色

	int disp_num=tRect1.right*XDispScale/50-1;//屏幕能显示的个数
	int num_to_change=point_num-disp_num;
	if(num_to_change<=0)
			num_to_change=0;
	int disp_point_start=(int)(num_to_change*(scoll_position*1.0/max_scoll_position));//x轴的起始显示坐标//rxh2.9.3修改了disp的计算方式
// 	if(mouse_right_down_flag&&select_left_change==1)//rxh3.0
// 	{
// 		select_left_change=0;
// 		disp_point_start=select_left;
// 	}
	//串口数据曲线  
 	if (disp_scope_flag)//是否清空波形标志
 	{ 

		for (unsigned char j=0;j<4;j++)//四条线
		{
			CPen tPen2(0,1,color[j]);
			pDC->SelectObject(&tPen2);
			if(disp_channl[j])//如果允许显示本通道
			for (int i=1;i<point_num&&i<disp_num;i++)
			{	
				int x_temp1=X_basic+(i)*50/XDispScale,xtemp2=X_basic+(i+1)*50/XDispScale;
				int y_temp1=Y_basic-buff_out[disp_point_start+i-1][j]*40/YDispScale
					,y_temp2=Y_basic-buff_out[disp_point_start+i][j]*40/YDispScale;
				pDC->MoveTo(x_temp1,y_temp1);
				pDC->LineTo(xtemp2,y_temp2);
 			}
		}
 		// 绘制距离探测点
		if(XDispScale<50)//如果数据过于密集，则不显示圆点，只显示曲线
		for (j=0;j<4;j++)
		{
			CPen tPen2(0,1,color[j]);//rxh1.9画笔决定圆的外侧
			pDC->SelectObject(&tPen2);
			CBrush tBrush2(color[j]);//rxh1.9画刷决定圆的内侧
 			pDC->SelectObject(&tBrush2);
			if(disp_channl[j])//如果显示
			for (i=0;i<point_num&&i<disp_num;i++)
			{	
				int TmpCtDispX=X_basic+(i+1)*50/XDispScale;
				int TmpCtDispY=Y_basic-buff_out[disp_point_start+i][j]*40/YDispScale;
				pDC->Ellipse(TmpCtDispX-3,TmpCtDispY-3,TmpCtDispX+3,TmpCtDispY+3);		
 			}
		}		
 	}
	//rxh1.6改变坐标字体
	pDC->SelectObject(&m_font);
	pDC->SetTextColor(RGB(156,156,156));//设置对话框字体的颜色
//	pDC->SetBkColor(RGB(100,200,200));//设置字体背景颜色
	pDC->SetBkMode(TRANSPARENT);//设置控件背景透明
 	//x轴坐标值   //rxh1.6
	int X_zuobiao[max_point_num]={0},X_zuobiao_first=0;
	int x_total=point_num/XDispScale+1;
	for (i=1;i<x_total&&i<max_point_num;i++)//把所有的坐标值存到数组
	{
		X_zuobiao[i]=i*XDispScale;
	}
	if (point_num>disp_num)//点数大于屏幕显示数目
	{
		for (i=0;X_zuobiao[i]<disp_point_start+1;i++)//把滚动显示的最左边坐标选出来//############：xx+1待调整！！！！！！！！！！
			X_zuobiao_first=i;
	}
	
	int num_x=tRect1.right/50;//X轴显示的坐标个数
	if (point_num/XDispScale<num_x)//如果总需要的坐标个数小于屏幕可显示的个数
 	for (i=1;i<num_x;i++)
	{
		string_temp.Format("%d",i*XDispScale);	
		pDC->TextOut(X_basic-7+i*50,Y_basic+4,string_temp);
		//pDC->TextOut(tRect1.left+40+i*50,bottom_right_y-95,string_temp);
 	}else//超过
	for (i=1;i<num_x+1;i++)
	{
		string_temp.Format("%d",X_zuobiao[X_zuobiao_first+i]);	
		pDC->TextOut(X_basic-7+i*50,Y_basic+4,string_temp);
 	}
 	//y轴坐标值
 	for (i=0;i<tRect1.bottom/40;i++)//rxh2.9.6，80改变为40
 	{
		if(Y_basic-7-i*40<tRect1.top)//防止画到矩形外
			break;
 		string_temp.Format("%d",-i*YDispScale);	
 		pDC->TextOut(5,Y_basic-7+i*40,string_temp);
 		string_temp.Format("%d",i*YDispScale);
 		pDC->TextOut(5,Y_basic-7-i*40,string_temp);
 	}
	//在曲线点显示数据大小//rxh2.2
	if(disp_scope_flag)
		for (unsigned char j=0;j<4;j++)
		{
			//char biao_flag=0;//只有坐标后第一个显示
			static char biao_flag2=0,biao_flag3=0;
			if(disp_channl[j])//如果显示
				for (i=1;i<=point_num&&i<=disp_num;i++)
				{	
					int x_temp1=X_basic+(i)*50/XDispScale
						,y_temp1=Y_basic-buff_out[disp_point_start+i-1][j]*40/YDispScale;
					//int x_temp2=X_basic+(i+1)*50/XDispScale;
					if((x_temp1>=mouse_point.x+25/XDispScale)&&disp_biaochi==1)//在图中显示值//rxh2.9.6修改了判断条件x_temp2为x_temp1
					{	
						//biao_flag=1;
						//rxh1.6改变坐标字体
						pDC->SelectObject(&n_font);
						pDC->SetTextColor(color[j]);//设置对话框字体的颜色
						pDC->SetBkColor(RGB(28,28,28));//设置字体背景颜色
						pDC->SetBkMode(2);//设置控件背景透明
						string_temp.Format("%d",buff_out[disp_point_start+i-1][j]);	
						pDC->TextOut(x_temp1+5,y_temp1-5,string_temp);
						CPen tPen3(0,1,RGB(200,200,200));//醒目标志线
						pDC->SelectObject(&tPen3);
						pDC->MoveTo(x_temp1,tRect1.top);
						pDC->LineTo(x_temp1,tRect1.bottom);
						break;//只需要显示一条醒目标志线
					}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*					if (x_temp2>mouse_right_down_x&&biao_flag2==0&&mouse_right_down_flag==1)//rxh3.0寻找鼠标右键按下时左边一个坐标的点
					{
						biao_flag2=1;
						biao_flag3=0;
						mouse_right_down_flag=0;//rxh3.0置零右键按下标志位

						select_left_change=1;
						select_left=disp_point_start+i;//选中放大的最左边一个点

					}
					if (x_temp2>mouse_right_up_x&&biao_flag2==1&&biao_flag3==0&&mouse_right_up_flag==1)//寻找鼠标右键抬起时左边一个坐标的点
					{
						biao_flag2=0;
						biao_flag3=1;
						mouse_right_up_flag=0;//rxh3.0置零右键抬起标志位

						select_right=disp_point_start+i-1;//选中放大的最右边一个点
						//计算缩放比例和滚动条位置
						//XDispScale=(select_right-select_left+1)*50/tRect1.right;//根据选中的数据点个数反求x轴放大倍数
						scoll_position=select_left*max_scoll_position/num_to_change;
						 if(XDispScale<1)//限幅
							 XDispScale=1;
						 if(scoll_position>max_scoll_position)
							 scoll_position=max_scoll_position;
						 else if(scoll_position<0)
							 scoll_position=0;
					}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				}
		}
/* 		string_temp.Format("右按下:%d 右抬起:%d    select_left:%d   select_right:%d   scoll_position:%d  max_scoll:%d"
			,mouse_right_down_x,mouse_right_up_x,select_left,select_right,scoll_position,max_scoll_position);
 		m_receive_count.SetWindowText(string_temp);*/
		
 	//	string_temp.Format("scoll_position:%d max_scoll:%d mouse_move_x：%d point_number: %d",scoll_position,max_scoll_position,mouse_move_x,point_num);
  	//	m_receive_count.SetWindowText(string_temp); 
	//关于作者
	if(about_author_flag)
		DispAboutAuthor(pDC,X_basic,Y_basic);
}
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVisualscope_DlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVisualscope_DlgDlg::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent)
	{
	case 1:	ReceiveDataDecode(receive_buffer,scope_data);
			InvalidateRect(&tRect1,FALSE);
				// Invalidate(FALSE);//fprintf(print_file," %ld  \n",ctTotalBufNum);
			  // fprintf(print_file," %ld %ld %ld \n",ctTotalBufNum,point_num,bad_num);
				break;//rxh1.6,更改矩形框刷新方式
		case 2:Invalidate(FALSE);break;
	}
	CDialog::OnTimer(nIDEvent);
}
//大小变化
void CVisualscope_DlgDlg::OnSize(UINT nType, int cx, int cy) 
{
	static char i=0;
	CDialog::OnSize(nType, cx, cy);
/////////////////////////////////////////
 	CWnd *pWnd_RX= GetDlgItem(IDC_BUTTON_ABOUT_AUTHOR); //获取滚动条控件句柄
 	CRect vscoll_rect; //获取滚动条控件变化前大小
 	pWnd_RX->GetWindowRect(&vscoll_rect);
 	ScreenToClient(&vscoll_rect);//将控件大小转换为在对话框中的区域坐标
	/////获取当前客户区大小
	CRect tRect;
	GetClientRect(&tRect);//获取当前客户区的大小
	//矩形背景
	tRect1.left=tRect.left;
	tRect1.top=tRect.top+40;
	tRect1.right=tRect.right;
	tRect1.bottom=tRect.bottom;
	//InvalidateRect(&tRect1,FALSE);//rxh1.5加快刷新速度
//  	if(nType!=SIZE_MINIMIZED )  //判断窗口是不是最小化了，因为窗口最小化之后 ，窗口的长和宽会变成0，当前一次变化的时就会出现除以0的错误操作
//  	{
//  		if(pWnd_RX)//判断是否为空，因为对话框创建时会调用此函数，而当时控件还未创建
//  		{
//  			
//  			//滚动条调整
//  			vscoll_rect.left=tRect.left;//接收框左边界///调整控件大小
//  			vscoll_rect.right=tRect.left+40;//接收框右边界
//  			vscoll_rect.top=tRect.bottom-20;//上边界
//  			vscoll_rect.bottom=tRect.bottom;//接收框下边界 
//  			
//  			
//  			/*	send_rect.left=send_rect.left;
//  			send_rect.right=send_rect.right;
//  			send_rect.top=m_rect.bottom-receive_rect.bottom;
//  			send_rect.bottom=m_rect.bottom;*/
//  			
//  			pWnd_RX->MoveWindow(vscoll_rect);//设置控件大小
//  		}
//  	}
 
 	Invalidate(FALSE);
	//UpdateWindow(FALSE);
	
	
}
//改变背景色
HBRUSH CVisualscope_DlgDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	int color[4]={RGB(255,0,0),RGB(255,255,0),RGB(0,0,255),RGB(255,0,255)};
	int ID_array[4]={IDC_CHECK_CHANNEL1,IDC_CHECK_CHANNEL2,IDC_CHECK_CHANNEL3,IDC_CHECK_CHANNEL4};
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:		//rxh1.6改变坐标字体
							pDC->SelectObject(&m_font);
							pDC->SetTextColor(RGB(255,250,25));  //字体颜色
							//	pDC->SetBkColor(RGB(10, 100, 100));   //字体背景色  
								pDC->SetBkMode(TRANSPARENT);//设置控件背景透明
								break;
 	case CTLCOLOR_EDIT:pDC->SetTextColor(RGB(100,250,0));  //字体颜色
 		pDC->SetBkColor(RGB(10, 100, 100));   //字体背景色  
 		break;
	}
	for (unsigned char i=0;i<4;i++)
	{
		if (pWnd->GetDlgCtrlID()==ID_array[i])
		{
			pDC->SetTextColor(color[i]);  //字体颜色
		}
		if (pWnd->GetDlgCtrlID()==IDC_STATIC_DISP_NOTHING)
			pDC->SetTextColor(RGB(127,255,0));  //字体颜色
	}

	return m_DlgBackGroundColor;
	//return hbr;
}
//清除波形
void CVisualscope_DlgDlg::OnButtonCleanScope() 
{
	disp_scope_flag=0;
	ctTotalBufNum=0;
	point_num=0;
	point_num_temp=0;
	bad_num=0;
	about_author_flag=0;
}
//X轴放大
void CVisualscope_DlgDlg::OnButtonXBig() 
{
	if (XDispScale>=2)
	{
		if(XDispScale<=2)
			XDispScale-=1;
		else if(XDispScale<=10)
			XDispScale-=2;
		else if(XDispScale<=100)
			XDispScale-=10;
		else if(XDispScale<=1000)
			XDispScale-=100;
		else XDispScale-=1000;
	}
	
}
//X轴缩小
void CVisualscope_DlgDlg::OnButtonXLittle() 
{
	if(XDispScale<2)
		XDispScale+=1;
	else if(XDispScale<10)
		XDispScale+=2;
	else if(XDispScale<100)
		XDispScale+=10;
	else if(XDispScale<1000)
		XDispScale+=100;
	else XDispScale+=1000;
}
//Y轴放大
void CVisualscope_DlgDlg::OnButtonYBig() 
{
	if (YDispScale>=2)
	{
		if(YDispScale<=2)
			YDispScale-=1;
		else if(YDispScale<=10)
			YDispScale-=2;
		else if(YDispScale<=100)
			YDispScale-=10;
		else if(YDispScale<=1000)
			YDispScale-=100;
		else YDispScale-=1000;
	}
	y_auto=0;
	m_check_y_auto.SetCheck(0);//取消选中自适应
}
//Y轴缩小
void CVisualscope_DlgDlg::OnButtonYLittle() 
{
	if(YDispScale<2)
		YDispScale+=1;
	else if(YDispScale<10)
		YDispScale+=2;
	else if(YDispScale<100)
		YDispScale+=10;
	else if(YDispScale<1000)
		YDispScale+=100;
	else YDispScale+=1000;
	y_auto=0;
	m_check_y_auto.SetCheck(0);//取消选中自适应
}
//键盘响应
BOOL CVisualscope_DlgDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN)
	{
		// 假如截获键盘按下消息，就分析按下的哪个键，然后给相应的按钮发送消息  
		if(pMsg->message==WM_KEYDOWN)  
		{     
			UINT   iKey=(UINT)pMsg->wParam;      
			switch(iKey)  
			{  
			case VK_NUMPAD1:  
				SendMessage(WM_COMMAND, MAKEWPARAM(IDC_BUTTON_X_BIG, BN_CLICKED), (LPARAM)(GetDlgItem(IDC_BUTTON_X_BIG)->m_hWnd));                           
				::SetFocus(GetDlgItem(IDC_BUTTON_X_BIG)->m_hWnd);  
				break;  
			case VK_NUMPAD2:  
				SendMessage(WM_COMMAND, MAKEWPARAM(IDC_BUTTON_X_LITTLE, BN_CLICKED), (LPARAM)(GetDlgItem(IDC_BUTTON_X_LITTLE)->m_hWnd));                           
				::SetFocus(GetDlgItem(IDC_BUTTON_X_LITTLE)->m_hWnd);  
				break;  
			case VK_NUMPAD3:  
				SendMessage(WM_COMMAND, MAKEWPARAM(IDC_BUTTON_Y_BIG, BN_CLICKED), (LPARAM)(GetDlgItem(IDC_BUTTON_Y_BIG)->m_hWnd));                           
				::SetFocus(GetDlgItem(IDC_BUTTON_Y_BIG)->m_hWnd);  
				break;  
			case VK_NUMPAD4:  
				SendMessage(WM_COMMAND, MAKEWPARAM(IDC_BUTTON_Y_LITTLE, BN_CLICKED), (LPARAM)(GetDlgItem(IDC_BUTTON_Y_LITTLE)->m_hWnd));                           
				::SetFocus(GetDlgItem(IDC_BUTTON_Y_LITTLE)->m_hWnd);  
				break;  
			default:  
				break;  
			}  		
		} 
		// 组合键响应keydown消息
		if( pMsg->wParam == VK_SPACE&& (GetKeyState(VK_SHIFT)& 0x8000))		
		{		// 空格 + Shift
			OnButtonXBig();		
		}
	}
	else if(pMsg->message == WM_SYSKEYDOWN)
	{	
		// Alt组合键响应syskeydown消息	// A + Alt
		if( pMsg->wParam == 'A'&& (HIWORD(pMsg->lParam) & KF_ALTDOWN))				
		{	}
	}
	return CDialog::PreTranslateMessage(pMsg); 
}
//rxh1.5波特率选择
void CVisualscope_DlgDlg::OnSelendokComboBandrate() 
{
	CString temp;
	int i=m_Combo_bandRate.GetCurSel();//将组合框选中的项赋值给i
	switch(i)
	{
	case 0:
		i=300;
		break;
	case 1:
		i=600;
		break;
	case 2:
		i=1200;
		break;
	case 3:
		i=2400;
		break;
	case 4:
		i=4800;
		break;
	case 5:
		i=9600;
		break;
	case 6:
		i=19200;
		break;
	case 7:
		i=38400;
		break;
	case 8:
		i=43000;
		break;
	case 9:
		i=56000;
		break;
	case 10:
		i=57600;
		break;
	case 11:
		i=115200;
		break;
	default:
		break;		
	}
	m_BaudRate=i;//把i的值赋值给波特率
	//关闭串口 
	close_port_all();	
}
//rxh1.5关闭串口总入口
void CVisualscope_DlgDlg::close_port_all()
{
	tCSerialPort.ClosePort();//关闭串口   
	m_bSerialPortOpened=FALSE;		
	m_open_serial_port.SetUpColor(RGB(0,245,255));//设置背景颜色
	m_open_serial_port.SetWindowText("打开串口");//在按钮上显示字符串
	//m_open_serial_port.SetForeColor(RGB(0,155,0));  //串口打开后文本颜色变绿
	
}
//rxh1.5串口号选择
void CVisualscope_DlgDlg::OnSelendokComboComNum() 
{
	unsigned char i;
	//Com_Num=m_combo_com_num.GetCurSel()+1;//本行程序适用于下拉框中串口号按从小到大排列，即可选中串口号
	i=m_combo_com_num.GetCurSel();
	Com_Num=m_nComArray[i];//在遍历函数中从注册表中读取的串口号存储到m_nComArray[]数组中
	
}
//rxh1.5下拉串口号组合框
void CVisualscope_DlgDlg::OnDropdownComboComNum() 
{
	//关闭串口 
	close_port_all();
	
	//重新扫描电脑所有串口
	tCSerialPort.Hkey2ComboBox(m_combo_com_num);//遍历串口//rxh2.0
	m_combo_com_num.SetCurSel(0);
	Com_Num=m_nComArray[0];//在遍历函数中从注册表中读取的串口号存储到m_nComArray[]数组中	
}
//rxh1.5销毁内存空间
void CVisualscope_DlgDlg::OnDestroy() 
{
	CDialog::OnDestroy();

	SaveSoftwareConfig();
	
	if(receive_buffer != NULL)//rxh2.8删除自开辟的内存
    {
        delete [] receive_buffer;
        receive_buffer = NULL;//赋值空指针，防止乱删空间
    }	
	if(scope_data!=NULL)
	{
		delete[]scope_data;
		scope_data=NULL;
	}
	if(disp_channl!=NULL)
	{
		delete[]disp_channl;
		disp_channl=NULL;
	}
	
}
//rxh1.5串口错误消息
void CVisualscope_DlgDlg::OnComErrorAndClose()
{	//关闭串口
	close_port_all();
	//重新扫描电脑所有串口
	tCSerialPort.Hkey2ComboBox(m_combo_com_num);//遍历串口//rxh2.0
	m_combo_com_num.SetCurSel(0);
	Com_Num=m_nComArray[0];//在遍历函数中从注册表中读取的串口号存储到m_nComArray[]数组中
}

void CVisualscope_DlgDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    int minpos = 0;  
    int maxpos = 0;  
	//rxh2.9.3修改滚动条的拖动方式
	SCROLLINFO lpscrollInfo;
	GetScrollInfo(SB_HORZ,&lpscrollInfo,SIF_ALL);
	//
    GetScrollRange(SB_HORZ, &minpos, &maxpos);   
    maxpos = GetScrollLimit(SB_HORZ);  
	
    // Get the current position of scroll box.  //得到滚动条的当前位置
    int curpos = GetScrollPos(SB_HORZ);  
	
    // Determine the new position of scroll box.  //确定新的滚动条的位置
    switch (nSBCode)  
    {  
    case SB_LEFT:      // Scroll to far left.滚动到左端  
        curpos = minpos;  
        break;  
		
    case SB_RIGHT:      // Scroll to far right.滚动到右端  
        curpos = maxpos;  
        break;  
		
    case SB_ENDSCROLL:   // End scroll.  
        break;  
		
    case SB_LINELEFT:      // Scroll left. 向左滚动一列 
        if (curpos > minpos)  
            curpos--;  
        break;  
		
    case SB_LINERIGHT:   // Scroll right.  向右滚动一列
        if (curpos < maxpos)  
            curpos++;  
        break;  
		
    case SB_PAGELEFT:    // Scroll one page left. 向左滚动一页 
        {  
            // Get the page size.   
            SCROLLINFO   info;  
            GetScrollInfo(SB_HORZ, &info, SIF_ALL);  
			
            if (curpos > minpos)  
                curpos = max(minpos, curpos - (int) info.nPage);  
        }  
        break;  
		
    case SB_PAGERIGHT:      // Scroll one page right. 向右滚动一页 
        {  
            // Get the page size.   
            SCROLLINFO   info;  
            GetScrollInfo(SB_HORZ, &info, SIF_ALL);  
			
            if (curpos < maxpos)  
                curpos = min(maxpos, curpos + (int) info.nPage);  
        }  
        break;  
		
    case SB_THUMBPOSITION: // Scroll to absolute position. nPos is the position  
        //curpos = nPos;      // of the scroll box at the end of the drag operation.  
        curpos=lpscrollInfo.nTrackPos;//rxh2.9.3修改的拖动方式
		break;  //滚动到指定位置
		
    case SB_THUMBTRACK:   // Drag scroll box to specified position. nPos is the  
       // curpos = nPos;     // position that the scroll box has been dragged to.  
        curpos=lpscrollInfo.nTrackPos;
		break;  //滚动条被拖动
    } 
    // Set the new position of the thumb (scroll box).  
    SetScrollPos(SB_HORZ, curpos);  

	//
	//记录之前的位置
	scoll_position=curpos;

	m_check_x_follow.SetCheck(0);//rxh2.4调整显示,暂停波形
   // UpdateWindow();  	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
//X轴跟随
void CVisualscope_DlgDlg::OnCheckXFollow() 
{
	if (m_check_x_follow.GetCheck())
	{
		scoll_position=max_scoll_position;
		SetScrollPos(SB_HORZ, scoll_position);  	
	}
	else
		scoll_position=0;
		SetScrollPos(SB_HORZ, scoll_position);
}
//纯正数复选框
void CVisualscope_DlgDlg::OnCheckPositiveOnly() 
{
	if (m_check_positive_only.GetCheck())
		positive_only_flag=1;
	else positive_only_flag=0;
}
//Y轴自适应
void CVisualscope_DlgDlg::OnCheckYAuto() 
{
	if (m_check_y_auto.GetCheck())
		y_auto=1;
	else y_auto=0;
}
//通道1复选框
void CVisualscope_DlgDlg::OnCheckChannel1() 
{
	if (m_check_channel1.GetCheck())
		disp_channl[0]=1;
	else disp_channl[0]=0;	
}
//通道2复选框
void CVisualscope_DlgDlg::OnCheckChannel2() 
{
	if (m_check_channel2.GetCheck())
		disp_channl[1]=1;
	else disp_channl[1]=0;	
}
//通道3复选框
void CVisualscope_DlgDlg::OnCheckChannel3() 
{
	if (m_check_channel3.GetCheck())
		disp_channl[2]=1;
	else disp_channl[2]=0;	
}
//通道4复选框
void CVisualscope_DlgDlg::OnCheckChannel4() 
{
	if (m_check_channel4.GetCheck())
		disp_channl[3]=1;
	else disp_channl[3]=0;	
}
//左键按下
void CVisualscope_DlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
 	SetCapture();//捕捉鼠标
 	::SetCursor(hCross);
// 	static int point_temp_old=0;
// 	if(point_num!=point_temp_old)//根据点数的多少进行滚动条调整
// 	{
// 		//改变滚动条长度
// 		xSi.nMin = 0; //最小滚动位置
// 		xSi.nMax = point_num;//最大滚动位置
// 		SetScrollInfo(SB_HORZ,&xSi);
// 		max_scoll_position=xSi.nMax-xSi.nMin+1-xSi.nPage;//滚动条最大位置=nMax-nMin+1-nPage
// 		//限幅
// 		if (scoll_position<=0)
// 			scoll_position=0;
// 		else if(scoll_position>=max_scoll_position)
// 			scoll_position=max_scoll_position;
// 		//	scoll_position=max_scoll_position;//初始化滚动条位置
// 		//	SetScrollPos(SB_HORZ, max_scoll_position);
// 	}
//   point_temp_old=point_num;//保存上一次
	//捕捉坐标
	mouse_point=point;
	Dragging=TRUE;//设置拖拽标记	
	CDialog::OnLButtonDown(nFlags, point);
}
//左键抬起
void CVisualscope_DlgDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (Dragging)
	{
		Dragging=false;//清拖拽标记
		ReleaseCapture();//释放鼠标，还原鼠标形状
		
	}	
	CDialog::OnLButtonUp(nFlags, point);
}
//鼠标移动
void CVisualscope_DlgDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(Dragging)//按下鼠标左键拖动鼠标
	{
	//	CClientDC dc(this);
		disp_biaochi=0;//按下鼠标不显示标尺
// 		dc.MoveTo(mouse_point);//起点
// 		dc.LineTo(point);//绘制线段
		CPoint new_point=point;//新起点rxh
		mouse_move_x=(new_point.x-mouse_point.x);//获取鼠标移动距离
		mouse_point=new_point;//更新rxh2.9.3

		if(mouse_move_x<0&&point_num!=0)//rxh2.5添加鼠标拖动
			scoll_position+=199999/point_num;//累加鼠标移动距离
		else if(mouse_move_x>0&&point_num!=0)
			scoll_position-=199999/point_num;
		//限幅
		if (scoll_position<=0)
			scoll_position=0;
		else if(scoll_position>=max_scoll_position)
			scoll_position=max_scoll_position;

		SetScrollPos(SB_HORZ, scoll_position);  
		//暂停波形
		m_check_x_follow.SetCheck(0);//取消选中X跟随
		disp_point_add_flag=FALSE;
		m_button_stop_scope.SetUpColor(RGB(255,255,0));//设置背景颜色		
		m_button_stop_scope.SetWindowText("继续跟随");//在按钮上显示字符串

	}	
	else//不按左键拖动
	{
		mouse_point=point;
		disp_biaochi=1;
	}	
	////////////////////////////////////////////////////////////
	TRACKMOUSEEVENT tme;
	tme.cbSize=sizeof(TRACKMOUSEEVENT);
	tme.dwFlags=TME_HOVER | TME_LEAVE;
	tme.dwHoverTime=HOVER_DEFAULT;
	tme.hwndTrack=m_hWnd;
	if(!_TrackMouseEvent(&tme))
    AfxMessageBox("鼠标事件捕捉失败！");
	CDialog::OnMouseMove(nFlags, point);
}
//鼠标右键按下
void CVisualscope_DlgDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	//     CPoint pt;
	//     GetCursorPos(&pt);
	//     ScreenToClient(&pt);//改如何把参数转化成LPARAM类型的呀?
	// 	CString string_temp;
	// 	string_temp.Format("客户鼠标:%d 设备鼠标：%d",pt.x,point.x);
	// 	m_receive_count.SetWindowText(string_temp);
	mouse_right_down_x=point.x;//rxh3.0
	mouse_right_down_flag=1;
	//不跟踪
	disp_point_add_flag=0;
	m_button_stop_scope.SetUpColor(RGB(255,255,0));//设置背景颜色		
	m_button_stop_scope.SetWindowText("继续跟随");//在按钮上显示字符串

	CDialog::OnRButtonDown(nFlags, point);
	
}
//右键抬起
void CVisualscope_DlgDlg::OnRButtonUp(UINT nFlags, CPoint point) 
{
	
	mouse_right_up_x=point.x;//rxh3.0
	mouse_right_up_flag=1;
	CDialog::OnRButtonUp(nFlags, point);
}
//鼠标离开
LRESULT CVisualscope_DlgDlg::OnMouseLeave(WPARAM wParam,LPARAM lParam)
{
// 	m_bMouseOver=FALSE;
// 	m_bTrack=FALSE;
// 	
// 	InvalidateRect(NULL);
	disp_biaochi=0;
	return 0;
}
//鼠标进入客户区
LRESULT CVisualscope_DlgDlg::OnMouseHover(WPARAM wParam,LPARAM lParam)
{
// 	m_bMouseOver=TRUE;
// 	
	disp_biaochi=1;
	return 0;
}
//鼠标滚轮函数//rxh2.3
BOOL CVisualscope_DlgDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	if (nFlags==MK_CONTROL)//ctrl键被按下,缩放X比例尺
	{
		if(zDelta>0)
			OnButtonXBig();
		else
		OnButtonXLittle();
	}
	else//否则缩放Y比例尺
	{
		if(zDelta>0)
			OnButtonYBig();
		else
		OnButtonYLittle();
	}

	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}
//暂停波形
void CVisualscope_DlgDlg::OnButtonStopScope() 
{
	disp_point_add_flag=!disp_point_add_flag;
	if(disp_point_add_flag)//开始
	{
		m_button_stop_scope.SetUpColor(RGB(0,255,0));//设置背景颜色)
		m_button_stop_scope.SetWindowText("暂停波形");//在按钮上显示字符串
		scoll_position=max_scoll_position;
		SetScrollPos(SB_HORZ, max_scoll_position);
		m_check_x_follow.SetCheck(1);//选中X跟随
	}
	else
	{
		m_button_stop_scope.SetUpColor(RGB(255,255,0));//设置背景颜色		
		m_button_stop_scope.SetWindowText("继续跟随");//在按钮上显示字符串
	}
}
//关于作者
void CVisualscope_DlgDlg::OnButtonAboutAuthor() 
{
	about_author_flag=1;
}
void CVisualscope_DlgDlg::DispAboutAuthor(CDC *pDC,int X_basic,int Y_basic)
{
	//pDC->SelectObject(m_hBitmap);rxh2.6显示图片
CString about[8]=
{
	"本虚拟示波器是作者花少利用近两个月开发的一款高速、精致的虚拟示波器",
	"具有如下：端口自动扫描、设置自动保存、多波特率选择、串口拔出互锁解除、X、Y轴任意缩放、四通道选择",
	"波形自动跟随、Y轴自动适应屏幕、接收点数和错误数据个数统计、波形保存、打开历史波形（txt格式）",
	"波形数据实时标尺、滚轮Y轴缩放、滚轮+Ctrl键X轴缩放、鼠标左键拖动X轴等很棒的功能！！！",
	"如有问题或改进建议请加群反馈,串口软件反馈交流群：476174311",
	"作者为了开发一款好用的虚拟示波器，投入了很大的时间和精力，没有采用注册码的方式收费，而是免费分享给大家",
	"如果您觉得这款虚拟示波器给您的开发工作带来方便，请捐赠开发者 支付宝:861063204@qq.com",
	"您的捐赠是对我工作的肯定，也是我继续开发的最强动力！！！(PS:写软件累成狗，支持一下吧*^_^*)"};
	pDC->SelectObject(&x_font);
	pDC->SetTextColor(RGB(255,255,0));//设置对话框字体的颜色
//	pDC->SetBkColor(RGB(100,200,200));//设置字体背景颜色
	pDC->SetBkMode(TRANSPARENT);//设置控件背景透明
	for (char i=0;i<8;i++)
	{
		pDC->TextOut(X_basic+5,tRect1.top+10+35*i,about[i]);

	}

//	CBitmap* pBitmap = CBitmap::FromHandle(m_hBitmap);
}
//保存波形rxh2.8
void CVisualscope_DlgDlg::OnButtonSaveScope() 
{
    // 设置过滤器   
    TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");   
    // 构造保存文件对话框   
    CFileDialog fileDlg(FALSE, _T("doc"), _T("波形数据"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);   
    CString strFilePath=" ";   
    // 显示保存文件对话框   
    if (IDOK == fileDlg.DoModal())   
        strFilePath = fileDlg.GetPathName(); //获取文件名  
	//打印
	if (strFilePath!=" ")
	{
		FILE *print_file=fopen(strFilePath,"w+");
		for (int i=0;i<point_num_temp;i++)
		{
			fprintf(print_file,"%d %d %d %d \n",scope_data[i][0],scope_data[i][1],scope_data[i][2],scope_data[i][3]);	
			
		}
		Sleep(200);
		fclose(print_file);
		AfxMessageBox("波形数据保存成功");
	}
	else 
	{	
		AfxMessageBox("未保存文件");
	}
}
//打开历史波形
void CVisualscope_DlgDlg::OnButtonOpenDataFromFile() 
{
	close_port_all();//先关闭串口
	OnButtonCleanScope();//清除波形
	Sleep(200);
	CFileDialog *lpszOpenFile;    //定义一个CfileDialog对象
	lpszOpenFile = new
	CFileDialog(TRUE,"","",OFN_FILEMUSTEXIST |OFN_HIDEREADONLY,"(*.txt)|*.txt|所有文件(*.*)|*.*||");//生成一个对话框
	CString szGetName=" ";
	if(lpszOpenFile->DoModal()==IDOK)//假如点击对话框确定按钮
	{
		szGetName = lpszOpenFile->GetPathName();//得到打开文件的路径
		SetWindowText(szGetName);//在窗口标题上显示路径
	}
	delete lpszOpenFile;//释放分配的对话框

	//打开文件--方法1--成功
// 	CStdioFile tStdioFile;
// 	if (szGetName!=" ")
// 	{
// 		tStdioFile.Open(szGetName,CFile::modeRead);  //手推-方案2  手推-方案3 ;  -- 方案1整理.txt 方案2整理.txt  ..
// 		int TmpctLoadIndex=0;
// 		CString ctReadLineStr;
// 		
// 		while(1)
// 		{	//将文件中的字符串读出来
// 			int TmpCtReadRes=tStdioFile.ReadString(ctReadLineStr);
// 			if(TmpCtReadRes==0)
// 				break;
// 			
// 			sscanf(ctReadLineStr,"%d %d %d %d",&scope_data[TmpctLoadIndex][0],&scope_data[TmpctLoadIndex][1],&scope_data[TmpctLoadIndex][2],&scope_data[TmpctLoadIndex][3]);
// 			if(TmpctLoadIndex<max_point_num)
// 			TmpctLoadIndex++;
// 			else 
// 			{
// 				AfxMessageBox("点数多于20万,已忽略多出的点数！");
// 				break;
// 			}
// 		}
// 		
// 		tStdioFile.Close();
// 		
// 		point_num_temp=TmpctLoadIndex;//波形数据个数
// 		disp_point_add_flag=1;//跟踪
// 		disp_scope_flag=1;//显示波形
// 	}
// 	else 
// 	{	
// 		AfxMessageBox("未找到文件");
// 	}

//////////////////////////////////////////////////////////////////////////
	//打开文件---方法2--不成功
// 	if (szGetName!=" ")
// 	{
// 
// 		int TmpctLoadIndex=0;
// 		CFile mFile(/*_T("user.txt")*/szGetName,CFile::modeRead);
// 		for(;;)
// 		{
// 			for(int i=0;i<4;i++)
// 				mFile.Read(&scope_data[TmpctLoadIndex][i],1);
// 			if(TmpctLoadIndex<max_point_num)
// 				TmpctLoadIndex++;	
// 			else 
// 			{
// 				AfxMessageBox("点数多于20万,已忽略多出的点数！");
// 				break;
// 			}
// 		}
// 
// 		mFile.Close();
// 		point_num_temp=TmpctLoadIndex;//波形数据个数
// 		disp_point_add_flag=1;//跟踪
// 		disp_scope_flag=1;//显示波形
// 	
// 	}
// 	else 
// 	{	
// 	 	AfxMessageBox("未找到文件");
// 	}
//////////////////////////////////////////////////////////////////////////
	//打开文件---方法3成功
	if (szGetName!=" ")
	{
		FILE *fp;
		if((fp=fopen(szGetName,"r"))==NULL)
			return ;
		int TmpctLoadIndex=0;
		CString ctReadLineStr;
		
		while(1)
		{	//将文件中的字符串读出来
			for(int i=0;i<4;i++)
				fscanf(fp,"%d",&scope_data[TmpctLoadIndex][i]);
			if(feof(fp)) //文件结尾
				break; 
			if(TmpctLoadIndex<max_point_num)
				TmpctLoadIndex++;
			else 
			{
				AfxMessageBox("点数多于20万,已忽略多出的点数！");
				break;
			}
		}
		
		fclose(fp);//关闭文件
		
		point_num_temp=TmpctLoadIndex;//波形数据个数
		disp_point_add_flag=1;//跟踪
		disp_scope_flag=1;//显示波形
	}
	else 
	{	
		AfxMessageBox("未找到文件");
	}
//////////////////////////////////////////////////////////////////////////

}
//保存软件的当前设置
void CVisualscope_DlgDlg::SaveSoftwareConfig()
{
	FILE *print_file=fopen("虚拟示波器设置.ini","w+");
	int data[10]={0};
	data[0]=Com_Num;
	data[1]=m_Combo_bandRate.GetCurSel();
	if(m_check_positive_only.GetCheck())//显示正数还是负数
		data[2]=1;
	else 
		data[2]=0;

// 	data[3]=
// 	data[4]=
// 	data[5]=
// 	data[6]=
// 	data[7]=
// 	data[8]=
// 	data[9]=
	
	for (int i=0;i<10;i++)
	{
		fprintf(print_file,"%d \n",data[i]);	
		
	}
	Sleep(200);
		fclose(print_file);
}
//打开软件之前的设置
void CVisualscope_DlgDlg::OpenSoftwareConfig()
{
		FILE *fp;
		if((fp=fopen("虚拟示波器设置.ini","r"))==NULL)
			return ;
		int data[10]={0};
		
		while(1)
		{	//将文件中的字符串读出来
			for(int i=0;i<10;i++)
				fscanf(fp,"%d",&data[i]);
			if(feof(fp)) //文件结尾
				break; 
		}
		for (int i=0;i<20;i++)//读取串口号
		{
			if (data[0]==m_nComArray[i])
			{
				Com_Num=data[0];
				m_combo_com_num.SetCurSel(i);
				//AfxMessageBox("找到串口号");
			}
		}
		int choose=data[1];//读取波特率
		unsigned int band_rate_buff[12]={300,600,1200,2400,4800,9600,19200,38400,43000,56000,57600,115200};
		if(choose<12)
		{
			m_BaudRate=band_rate_buff[choose];
			m_Combo_bandRate.SetCurSel(choose);//波特率默认115200
		}

		if(data[2])//正数还是正负数
		{
			positive_only_flag=1;
			m_check_positive_only.SetCheck(1);
		}
		else
		{
			positive_only_flag=0;
			m_check_positive_only.SetCheck(0);
		}
		fclose(fp);//关闭文件
}