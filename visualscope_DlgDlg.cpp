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
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommReceivedata) //������Ϣ����ֻ�������һ��
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
	ON_MESSAGE(WM_MOUSELEAVE,OnMouseLeave)//rxh2.2�ֶ����
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
	//rxh2.7���ӽ��ջ�����
	receive_buffer=new unsigned char[1024*10];;
	MaxTotalBufNum=1024*10;//�ܵ��ֽ���
	memset(receive_buffer,0,sizeof(unsigned char)*MaxTotalBufNum);//rxh2.9.1
	ctTotalBufNum=0;
	tCSerialPort.Hkey2ComboBox(m_combo_com_num);//��������//rxh2.0
	Com_Num=m_nComArray[0];//�ڱ��������д�ע����ж�ȡ�Ĵ��ںŴ洢��m_nComArray[]������
	m_Combo_bandRate.SetCurSel(11);//������Ĭ��115200
	//��ȡ�ؼ���С//rxh2.2
	CRect tRect;
	GetClientRect(&tRect);//��ȡ��ǰ�ͻ����Ĵ�С
	tRect1.left=tRect.left;
	tRect1.top=tRect.top+40;
	tRect1.right=tRect.right;
	tRect1.bottom=tRect.bottom;
	disp_scope_flag=0;	
	SetTimer(1,100,NULL);//���ö�ʱ��
	SetTimer(2,2000,NULL);//���ö�ʱ��
	//	CreatePointFont(90, "����");
	m_DlgBackGroundColor.CreateSolidBrush(RGB(100,155,100));//�Զ���һ����ˢ,��ɫ��˫������ɫ��ͬ
	// ��ʾ������
	XDispScale=10;
	YDispScale=10; 
	//�ı�����
	m_font.CreatePointFont(100,"������");
	n_font.CreatePointFont(109,"����");
	x_font.CreatePointFont(120,"����");
	//�޸İ�ť��ɫ//rxh1.5
	change_buttun_color();
	//m_open_serial_port.SetFont(&m_font);//�ı䰴ť����
	//����������//rxh2.4
	xSi.cbSize = sizeof (xSi);
	xSi.fMask  = SIF_ALL;
	xSi.nMin = 0; //��С����λ��
	xSi.nMax = 200000;//������λ��
	xSi.nPage = 10;//
	xSi.nPos = 0;
	xSi.nTrackPos = 0;
	SetScrollInfo(SB_HORZ,&xSi);
	max_scoll_position=xSi.nMax-xSi.nMin+1-xSi.nPage;//���������λ��=nMax-nMin+1-nPage
	scoll_position=max_scoll_position;//��ʼ��������λ��
	SetScrollPos(SB_HORZ, max_scoll_position);  
	m_check_x_follow.SetCheck(1);//��ʼ������
	//���δ洢����
	scope_data=new short int[max_point_num][4];
	memset(scope_data,0,sizeof(short int)*max_point_num*4);
	point_num=0;
	point_num_temp=0;
	point_num_old=0;
	bad_num=0;
	y_auto=1;//Y����Ӧ
	positive_only_flag=0;//��������ʾ
	m_check_positive_only.SetCheck(0);
	m_check_y_auto.SetCheck(1);//Ĭ��Y���Զ���Ӧ//rxh2.7
	disp_channl=new char[4];//���ƶ�ͨ����ʾ
	memset(disp_channl,1,sizeof(char)*4);
	m_check_channel1.SetCheck(1);//Ĭ��ѡ��ͨ��
	m_check_channel2.SetCheck(1);
	m_check_channel3.SetCheck(1);
	m_check_channel4.SetCheck(1);
	Dragging=false;//��ʼ����ק
	hCross=AfxGetApp()->LoadStandardCursor(IDC_SIZENESW);//���ʮ�ֹ����
	mouse_move_x=0;
	mouse_right_down_x=0;
	mouse_right_up_x=0;
	disp_biaochi=1;//�Ƿ���ʾ����ֵ�ͱ�ʾ��
	disp_point_add_flag=true;//���β���ͣ
	about_author_flag=0;
	mouse_right_down_flag=0;
	mouse_right_up_flag=0;//�Ҽ�̧���־
	select_left=0;//���ο�ѡ���������
	select_right=0;
	OpenSoftwareConfig();//��ȡ�ϴ����������
// 	m_hBitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),//rxh2.6λͼ
//             "1.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CVisualscope_DlgDlg::change_buttun_color()
{	int ID_array[6]={IDC_BUTTON_OPEN_COM_FIRST,IDC_BUTTON_CLEAN_SCOPE};//rxh2.0
	COLORREF color[4]={RGB(0,255,0),RGB(0,245,255),RGB(10,100,255)};
// 	CMyButtun my_button[6];
// 	my_button[0]=m_open_serial_port;
	GetDlgItem(IDC_BUTTON_OPEN_COM_FIRST)->ModifyStyle(0,BS_OWNERDRAW,0);//�򿪴���	
	m_open_serial_port.Attach(IDC_BUTTON_OPEN_COM_FIRST,this);
    m_open_serial_port.SetDownColor(color[0]);
    m_open_serial_port.SetUpColor(color[1]);
	GetDlgItem(IDC_BUTTON_CLEAN_SCOPE)->ModifyStyle(0,BS_OWNERDRAW,0);//�������
	m_buttun_clean_scope.Attach(IDC_BUTTON_CLEAN_SCOPE,this);
    m_buttun_clean_scope.SetDownColor(RGB(255,255,200));
    m_buttun_clean_scope.SetUpColor(color[2]);
	GetDlgItem(IDC_BUTTON_STOP_SCOPE)->ModifyStyle(0,BS_OWNERDRAW,0);//��ͣ����
	m_button_stop_scope.Attach(IDC_BUTTON_STOP_SCOPE,this);
    m_button_stop_scope.SetDownColor(color[0]);
    m_button_stop_scope.SetUpColor(color[0]);
	GetDlgItem(IDC_BUTTON_SAVE_SCOPE)->ModifyStyle(0,BS_OWNERDRAW,0);//����
	m_buttun_X_big.Attach(IDC_BUTTON_SAVE_SCOPE,this);
    m_buttun_X_big.SetDownColor(color[0]);
    m_buttun_X_big.SetUpColor(color[1]);
	GetDlgItem(IDC_BUTTON_OPEN_DATA_FROM_FILE)->ModifyStyle(0,BS_OWNERDRAW,0);	//�򿪲���
	m_buttun_x_little.Attach(IDC_BUTTON_OPEN_DATA_FROM_FILE,this);
    m_buttun_x_little.SetDownColor(color[0]);
    m_buttun_x_little.SetUpColor(color[2]);
	GetDlgItem(IDC_BUTTON_ABOUT_AUTHOR)->ModifyStyle(0,BS_OWNERDRAW,0);	//����
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

//�򿪴���
void CVisualscope_DlgDlg::OnButtonOpenComFirst() 
{
	m_bSerialPortOpened=!m_bSerialPortOpened;//ȡ����־λ
	if(m_bSerialPortOpened)//�򿪴���
	{
		if(tCSerialPort.InitPort(this->m_hWnd, Com_Num,m_BaudRate,'N',8,1,EV_RXFLAG | EV_RXCHAR,512))//��ʼ����������ɹ��ͷ���TRUE�����������ж�
		{
			tCSerialPort.StartMonitoring();///���ô���ͨ�ż���̺߳���
			m_bSerialPortOpened=TRUE;//
			scoll_position=max_scoll_position;//�򿪴���ʱ��������
			SetScrollPos(SB_HORZ, max_scoll_position);
			m_check_x_follow.SetCheck(1);//��ʼ������rxh2.9.3
			disp_point_add_flag=TRUE;
			m_open_serial_port.SetUpColor(RGB(255,255,0));//���ñ�����ɫ
			m_open_serial_port.SetWindowText("�رմ���");//�ڰ�ť����ʾ�ַ���
		}
		else
		{
			m_bSerialPortOpened=FALSE;//��־λȡ��
			CString str;
			str.Format("COM%d û�з��ֻ������豸ռ��",Com_Num);//�ܰ�~~~~~~~~~~~~~~~~~~~~~~~
			AfxMessageBox(str);
		}
	}
	else//�رմ���
	close_port_all();
}
//���ڽ��յ�����
//ch->���յ����ַ����ݣ�port->���ں�##########################################
LONG CVisualscope_DlgDlg::OnCommReceivedata(WPARAM ch, LPARAM port)
{	
	receive_buffer[ctTotalBufNum]=ch;//���뻺����
	if(ctTotalBufNum<MaxTotalBufNum)
	ctTotalBufNum++;//rxh2.7������ָ��+1
	else ctTotalBufNum=0;
	disp_scope_flag=1;//�յ�������ʾ����
	// 	//�������ch���Ǵ��������ַ������ݣ�����ʹ�õ�����*******************#########
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
		//��ʾ����
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
	//����˫�����ͼ����ֹ��˸
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
	MemDC.FillSolidRect(0, 0, rcWidth, rcHeight, RGB(100,155,100));	//rxh1.5�ѱ������Ϊ��ɫ
	//#######################################################################
	// �����Ļ��ƴ����� !!!!!!!!!!
	Display(&MemDC,scope_data);	
	//####################################################################
	//���ڴ��е�ͼ��������Ļ�Ͻ�����ʾ
	pDC->BitBlt(0, 0, rcWidth, rcHeight, &MemDC, 0, 0, SRCCOPY);	
	MemBmp.DeleteObject();
	MemDC.DeleteDC();
}
//�Խ��յ����ݽ��н��룬�õ��ĸ�ͨ��������
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
		CRC16_receiv=*( (unsigned short int *)(&buffer_in[temp_index]) );//���յ�CRC
		temp_index+=2;
		for(char i=0;i<4;i++) //��dataת��Ϊunsigned charȥУ��
		{
			databuf[i<<1]   = (unsigned char)(scope_data_temp[i]&0x00ff);//rxh2.8��/256��Ϊ&0xff00)>>8
			databuf[(i<<1)+1] = (unsigned char)((scope_data_temp[i]&0xff00)>>8);
		}
		CRC16=CRC_CHECK(databuf,8);//����CRC

		if (CRC16==CRC16_receiv)//У��ϸ�������Ч
		{
			for (i=0;i<4;i++)//�õ���������
			{
				buff_out[point_num_temp][i]=(signed short int)scope_data_temp[i];
			}
			if(point_num_temp<max_point_num-1)
				point_num_temp++;
			else //���������
			{	
				if(flag==0)
				{	flag=1;//rxh2.9.1�ı䱣�淽ʽ
					break;
				}
			}
		}
		else //���ݳ���������λ����//rxh2.0
		{
			bad_num++;
			while(temp_index+10<=ctTotalBufNum)//rxh2.1��<Ϊ=
			{	scope_data_temp[0]=*( (unsigned short int *)(&buffer_in[temp_index]) );
				temp_index+=2;
				scope_data_temp[1]=*( (unsigned short int *)(&buffer_in[temp_index]) );
				temp_index+=2;
				scope_data_temp[2]=*( (unsigned short int *)(&buffer_in[temp_index]) );
				temp_index+=2;
				scope_data_temp[3]=*( (unsigned short int *)(&buffer_in[temp_index]) );
				temp_index+=2;
				CRC16_receiv=*( (unsigned short int *)(&buffer_in[temp_index]) );//���յ�CRC
				temp_index+=2;
				for(char i=0;i<4;i++) //��dataת��Ϊunsigned charȥУ��
				{
					databuf[i<<1]   = (unsigned char)(scope_data_temp[i]&0x00ff);//rxh2.8��/256��Ϊ&0xff00)>>8
					databuf[(i<<1)+1] = (unsigned char)((scope_data_temp[i]&0xff00)>>8);
				}
				CRC16=CRC_CHECK(databuf,8);//����CRC
				
				if (CRC16==CRC16_receiv)//У��ϸ�������Ч
				{
					for (i=0;i<4;i++)//�õ���������
					{
						buff_out[point_num_temp][i]=(signed short int)scope_data_temp[i];
					}
					if(point_num_temp<max_point_num-1)
						point_num_temp++;
					break;//���ݻָ���������ѭ��
				}
				temp_index-=9;//һ���ƶ�һλ���������ƶ�10λ
			}
		}
	}
	if(disp_point_add_flag)//rxh2.3�Ƿ���ͣ��ʾ
	point_num=point_num_temp;
	///////////////////
	// �ܻ��崮��
	int move_num=ctTotalBufNum-temp_index;//rxh2.9.1��ֹ��λ����
	if (move_num<0)
	{
		move_num=0;
		AfxMessageBox("���崮�Ƹ������ָ�ֵ��");
	}
	memmove(receive_buffer,&receive_buffer[temp_index],move_num);
	ctTotalBufNum-=temp_index;
	temp_index=0;

	if (flag==1)//rxh2.9.1�ı䱣�淽ʽ
	{	
		flag=0;
		close_port_all();
		ctTotalBufNum=0;
		//	AfxMessageBox("�������ݻ���������,���浱ǰ��������");
		OnButtonSaveScope();//rxh2.8//��������
		OnButtonCleanScope();
		point_num_temp=0;
	}
}
//CRC���㺯��
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
//��ʾ����
void CVisualscope_DlgDlg::Display(CDC *pDC,signed short int(* buff_out)[4])
{
	static short int max=0,min=0;//rxh2.8������Сֵ�ж�
	static select_left_change=0;//rxh3.0
	CString string_temp;
	CString strTemp;
	strTemp.Format("��ȷ:%ld����:%d",point_num_temp,bad_num);
	m_static_disp_nothing.SetWindowText(strTemp);
	//rxh2.4��������϶�ƫ����
	//��׼����
	int X_basic=tRect1.left+40,Y_basic;
	//�Ƿ���ʾ��������
	if (positive_only_flag)
		Y_basic=tRect1.bottom-20;
	else
		Y_basic=tRect1.top+tRect1.Height()/2;
	//���ƾ��α���
	CBrush tBrush(RGB(28,28,28));
	pDC->SelectObject(&tBrush);
	pDC->Rectangle(tRect1);
	//������
	CPen tPen0(0,1,RGB(0,50,0));
	pDC->SelectObject(&tPen0);
	int x_line=tRect1.bottom/40;//
	for (int i=1;i<x_line;i++)//����
	{
		int x_temm=i*40;
		if(Y_basic-x_temm<tRect1.top)//��ֹ����������
			break;
		pDC->MoveTo(X_basic,Y_basic+x_temm);
		pDC->LineTo(tRect1.right,Y_basic+x_temm);
		pDC->MoveTo(X_basic,Y_basic-x_temm);
		pDC->LineTo(tRect1.right,Y_basic-x_temm);
	}
	int y_line=tRect1.right/50;
	for (i=1;i<y_line;i++)//����
	{

		pDC->MoveTo(X_basic+i*50,tRect1.top);
		pDC->LineTo(X_basic+i*50,tRect1.bottom);		
 	}
	//X��������
	CPen tPen1(0,2,RGB(100,0,0));
	pDC->SelectObject(&tPen1);	
	// 	pDC->MoveTo(tRect1.left,tRect1.bottom);
	// 	pDC->LineTo(tRect1.right,tRect1.bottom);
	pDC->MoveTo(X_basic,Y_basic);
	pDC->LineTo(tRect1.right,Y_basic);
	//Y��������
	pDC->MoveTo(X_basic,tRect1.top);
	pDC->LineTo(X_basic,tRect1.bottom-2);
	//Y������Ӧ//�д���ȶ�����Ը�Ϊֻ������ǰ��Ļ�ĵ�ķŴ����,������ȫ������
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
			if (positive_only_flag)//�������Զ����ŵĲ��
				scale_temp=45;
			else
				scale_temp=85;
		YDispScale=(int)max*scale_temp/tRect1.Height();//�Զ��任���ű���
		int YDispScale_temp=0;
		if (min<0)
			YDispScale_temp=-(int)min*scale_temp/tRect1.Height();
		if(YDispScale_temp>YDispScale)
			YDispScale=YDispScale_temp;

		if(YDispScale<=1)//��ֹ����Ϊ��
			YDispScale=1;
	}
	//��¼���ν���ĸ���
	point_num_old=point_num_temp;

	int color[4]={RGB(255,0,0),RGB(255,255,0),RGB(0,0,255),RGB(255,0,255)};//�ĸ�ͨ������ɫ

	int disp_num=tRect1.right*XDispScale/50-1;//��Ļ����ʾ�ĸ���
	int num_to_change=point_num-disp_num;
	if(num_to_change<=0)
			num_to_change=0;
	int disp_point_start=(int)(num_to_change*(scoll_position*1.0/max_scoll_position));//x�����ʼ��ʾ����//rxh2.9.3�޸���disp�ļ��㷽ʽ
// 	if(mouse_right_down_flag&&select_left_change==1)//rxh3.0
// 	{
// 		select_left_change=0;
// 		disp_point_start=select_left;
// 	}
	//������������  
 	if (disp_scope_flag)//�Ƿ���ղ��α�־
 	{ 

		for (unsigned char j=0;j<4;j++)//������
		{
			CPen tPen2(0,1,color[j]);
			pDC->SelectObject(&tPen2);
			if(disp_channl[j])//���������ʾ��ͨ��
			for (int i=1;i<point_num&&i<disp_num;i++)
			{	
				int x_temp1=X_basic+(i)*50/XDispScale,xtemp2=X_basic+(i+1)*50/XDispScale;
				int y_temp1=Y_basic-buff_out[disp_point_start+i-1][j]*40/YDispScale
					,y_temp2=Y_basic-buff_out[disp_point_start+i][j]*40/YDispScale;
				pDC->MoveTo(x_temp1,y_temp1);
				pDC->LineTo(xtemp2,y_temp2);
 			}
		}
 		// ���ƾ���̽���
		if(XDispScale<50)//������ݹ����ܼ�������ʾԲ�㣬ֻ��ʾ����
		for (j=0;j<4;j++)
		{
			CPen tPen2(0,1,color[j]);//rxh1.9���ʾ���Բ�����
			pDC->SelectObject(&tPen2);
			CBrush tBrush2(color[j]);//rxh1.9��ˢ����Բ���ڲ�
 			pDC->SelectObject(&tBrush2);
			if(disp_channl[j])//�����ʾ
			for (i=0;i<point_num&&i<disp_num;i++)
			{	
				int TmpCtDispX=X_basic+(i+1)*50/XDispScale;
				int TmpCtDispY=Y_basic-buff_out[disp_point_start+i][j]*40/YDispScale;
				pDC->Ellipse(TmpCtDispX-3,TmpCtDispY-3,TmpCtDispX+3,TmpCtDispY+3);		
 			}
		}		
 	}
	//rxh1.6�ı���������
	pDC->SelectObject(&m_font);
	pDC->SetTextColor(RGB(156,156,156));//���öԻ����������ɫ
//	pDC->SetBkColor(RGB(100,200,200));//�������屳����ɫ
	pDC->SetBkMode(TRANSPARENT);//���ÿؼ�����͸��
 	//x������ֵ   //rxh1.6
	int X_zuobiao[max_point_num]={0},X_zuobiao_first=0;
	int x_total=point_num/XDispScale+1;
	for (i=1;i<x_total&&i<max_point_num;i++)//�����е�����ֵ�浽����
	{
		X_zuobiao[i]=i*XDispScale;
	}
	if (point_num>disp_num)//����������Ļ��ʾ��Ŀ
	{
		for (i=0;X_zuobiao[i]<disp_point_start+1;i++)//�ѹ�����ʾ�����������ѡ����//############��xx+1��������������������������
			X_zuobiao_first=i;
	}
	
	int num_x=tRect1.right/50;//X����ʾ���������
	if (point_num/XDispScale<num_x)//�������Ҫ���������С����Ļ����ʾ�ĸ���
 	for (i=1;i<num_x;i++)
	{
		string_temp.Format("%d",i*XDispScale);	
		pDC->TextOut(X_basic-7+i*50,Y_basic+4,string_temp);
		//pDC->TextOut(tRect1.left+40+i*50,bottom_right_y-95,string_temp);
 	}else//����
	for (i=1;i<num_x+1;i++)
	{
		string_temp.Format("%d",X_zuobiao[X_zuobiao_first+i]);	
		pDC->TextOut(X_basic-7+i*50,Y_basic+4,string_temp);
 	}
 	//y������ֵ
 	for (i=0;i<tRect1.bottom/40;i++)//rxh2.9.6��80�ı�Ϊ40
 	{
		if(Y_basic-7-i*40<tRect1.top)//��ֹ����������
			break;
 		string_temp.Format("%d",-i*YDispScale);	
 		pDC->TextOut(5,Y_basic-7+i*40,string_temp);
 		string_temp.Format("%d",i*YDispScale);
 		pDC->TextOut(5,Y_basic-7-i*40,string_temp);
 	}
	//�����ߵ���ʾ���ݴ�С//rxh2.2
	if(disp_scope_flag)
		for (unsigned char j=0;j<4;j++)
		{
			//char biao_flag=0;//ֻ��������һ����ʾ
			static char biao_flag2=0,biao_flag3=0;
			if(disp_channl[j])//�����ʾ
				for (i=1;i<=point_num&&i<=disp_num;i++)
				{	
					int x_temp1=X_basic+(i)*50/XDispScale
						,y_temp1=Y_basic-buff_out[disp_point_start+i-1][j]*40/YDispScale;
					//int x_temp2=X_basic+(i+1)*50/XDispScale;
					if((x_temp1>=mouse_point.x+25/XDispScale)&&disp_biaochi==1)//��ͼ����ʾֵ//rxh2.9.6�޸����ж�����x_temp2Ϊx_temp1
					{	
						//biao_flag=1;
						//rxh1.6�ı���������
						pDC->SelectObject(&n_font);
						pDC->SetTextColor(color[j]);//���öԻ����������ɫ
						pDC->SetBkColor(RGB(28,28,28));//�������屳����ɫ
						pDC->SetBkMode(2);//���ÿؼ�����͸��
						string_temp.Format("%d",buff_out[disp_point_start+i-1][j]);	
						pDC->TextOut(x_temp1+5,y_temp1-5,string_temp);
						CPen tPen3(0,1,RGB(200,200,200));//��Ŀ��־��
						pDC->SelectObject(&tPen3);
						pDC->MoveTo(x_temp1,tRect1.top);
						pDC->LineTo(x_temp1,tRect1.bottom);
						break;//ֻ��Ҫ��ʾһ����Ŀ��־��
					}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*					if (x_temp2>mouse_right_down_x&&biao_flag2==0&&mouse_right_down_flag==1)//rxh3.0Ѱ������Ҽ�����ʱ���һ������ĵ�
					{
						biao_flag2=1;
						biao_flag3=0;
						mouse_right_down_flag=0;//rxh3.0�����Ҽ����±�־λ

						select_left_change=1;
						select_left=disp_point_start+i;//ѡ�зŴ�������һ����

					}
					if (x_temp2>mouse_right_up_x&&biao_flag2==1&&biao_flag3==0&&mouse_right_up_flag==1)//Ѱ������Ҽ�̧��ʱ���һ������ĵ�
					{
						biao_flag2=0;
						biao_flag3=1;
						mouse_right_up_flag=0;//rxh3.0�����Ҽ�̧���־λ

						select_right=disp_point_start+i-1;//ѡ�зŴ�����ұ�һ����
						//�������ű����͹�����λ��
						//XDispScale=(select_right-select_left+1)*50/tRect1.right;//����ѡ�е����ݵ��������x��Ŵ���
						scoll_position=select_left*max_scoll_position/num_to_change;
						 if(XDispScale<1)//�޷�
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
/* 		string_temp.Format("�Ұ���:%d ��̧��:%d    select_left:%d   select_right:%d   scoll_position:%d  max_scoll:%d"
			,mouse_right_down_x,mouse_right_up_x,select_left,select_right,scoll_position,max_scoll_position);
 		m_receive_count.SetWindowText(string_temp);*/
		
 	//	string_temp.Format("scoll_position:%d max_scoll:%d mouse_move_x��%d point_number: %d",scoll_position,max_scoll_position,mouse_move_x,point_num);
  	//	m_receive_count.SetWindowText(string_temp); 
	//��������
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
				break;//rxh1.6,���ľ��ο�ˢ�·�ʽ
		case 2:Invalidate(FALSE);break;
	}
	CDialog::OnTimer(nIDEvent);
}
//��С�仯
void CVisualscope_DlgDlg::OnSize(UINT nType, int cx, int cy) 
{
	static char i=0;
	CDialog::OnSize(nType, cx, cy);
/////////////////////////////////////////
 	CWnd *pWnd_RX= GetDlgItem(IDC_BUTTON_ABOUT_AUTHOR); //��ȡ�������ؼ����
 	CRect vscoll_rect; //��ȡ�������ؼ��仯ǰ��С
 	pWnd_RX->GetWindowRect(&vscoll_rect);
 	ScreenToClient(&vscoll_rect);//���ؼ���Сת��Ϊ�ڶԻ����е���������
	/////��ȡ��ǰ�ͻ�����С
	CRect tRect;
	GetClientRect(&tRect);//��ȡ��ǰ�ͻ����Ĵ�С
	//���α���
	tRect1.left=tRect.left;
	tRect1.top=tRect.top+40;
	tRect1.right=tRect.right;
	tRect1.bottom=tRect.bottom;
	//InvalidateRect(&tRect1,FALSE);//rxh1.5�ӿ�ˢ���ٶ�
//  	if(nType!=SIZE_MINIMIZED )  //�жϴ����ǲ�����С���ˣ���Ϊ������С��֮�� �����ڵĳ��Ϳ����0����ǰһ�α仯��ʱ�ͻ���ֳ���0�Ĵ������
//  	{
//  		if(pWnd_RX)//�ж��Ƿ�Ϊ�գ���Ϊ�Ի��򴴽�ʱ����ô˺���������ʱ�ؼ���δ����
//  		{
//  			
//  			//����������
//  			vscoll_rect.left=tRect.left;//���տ���߽�///�����ؼ���С
//  			vscoll_rect.right=tRect.left+40;//���տ��ұ߽�
//  			vscoll_rect.top=tRect.bottom-20;//�ϱ߽�
//  			vscoll_rect.bottom=tRect.bottom;//���տ��±߽� 
//  			
//  			
//  			/*	send_rect.left=send_rect.left;
//  			send_rect.right=send_rect.right;
//  			send_rect.top=m_rect.bottom-receive_rect.bottom;
//  			send_rect.bottom=m_rect.bottom;*/
//  			
//  			pWnd_RX->MoveWindow(vscoll_rect);//���ÿؼ���С
//  		}
//  	}
 
 	Invalidate(FALSE);
	//UpdateWindow(FALSE);
	
	
}
//�ı䱳��ɫ
HBRUSH CVisualscope_DlgDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	int color[4]={RGB(255,0,0),RGB(255,255,0),RGB(0,0,255),RGB(255,0,255)};
	int ID_array[4]={IDC_CHECK_CHANNEL1,IDC_CHECK_CHANNEL2,IDC_CHECK_CHANNEL3,IDC_CHECK_CHANNEL4};
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:		//rxh1.6�ı���������
							pDC->SelectObject(&m_font);
							pDC->SetTextColor(RGB(255,250,25));  //������ɫ
							//	pDC->SetBkColor(RGB(10, 100, 100));   //���屳��ɫ  
								pDC->SetBkMode(TRANSPARENT);//���ÿؼ�����͸��
								break;
 	case CTLCOLOR_EDIT:pDC->SetTextColor(RGB(100,250,0));  //������ɫ
 		pDC->SetBkColor(RGB(10, 100, 100));   //���屳��ɫ  
 		break;
	}
	for (unsigned char i=0;i<4;i++)
	{
		if (pWnd->GetDlgCtrlID()==ID_array[i])
		{
			pDC->SetTextColor(color[i]);  //������ɫ
		}
		if (pWnd->GetDlgCtrlID()==IDC_STATIC_DISP_NOTHING)
			pDC->SetTextColor(RGB(127,255,0));  //������ɫ
	}

	return m_DlgBackGroundColor;
	//return hbr;
}
//�������
void CVisualscope_DlgDlg::OnButtonCleanScope() 
{
	disp_scope_flag=0;
	ctTotalBufNum=0;
	point_num=0;
	point_num_temp=0;
	bad_num=0;
	about_author_flag=0;
}
//X��Ŵ�
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
//X����С
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
//Y��Ŵ�
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
	m_check_y_auto.SetCheck(0);//ȡ��ѡ������Ӧ
}
//Y����С
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
	m_check_y_auto.SetCheck(0);//ȡ��ѡ������Ӧ
}
//������Ӧ
BOOL CVisualscope_DlgDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN)
	{
		// ����ػ���̰�����Ϣ���ͷ������µ��ĸ�����Ȼ�����Ӧ�İ�ť������Ϣ  
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
		// ��ϼ���Ӧkeydown��Ϣ
		if( pMsg->wParam == VK_SPACE&& (GetKeyState(VK_SHIFT)& 0x8000))		
		{		// �ո� + Shift
			OnButtonXBig();		
		}
	}
	else if(pMsg->message == WM_SYSKEYDOWN)
	{	
		// Alt��ϼ���Ӧsyskeydown��Ϣ	// A + Alt
		if( pMsg->wParam == 'A'&& (HIWORD(pMsg->lParam) & KF_ALTDOWN))				
		{	}
	}
	return CDialog::PreTranslateMessage(pMsg); 
}
//rxh1.5������ѡ��
void CVisualscope_DlgDlg::OnSelendokComboBandrate() 
{
	CString temp;
	int i=m_Combo_bandRate.GetCurSel();//����Ͽ�ѡ�е��ֵ��i
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
	m_BaudRate=i;//��i��ֵ��ֵ��������
	//�رմ��� 
	close_port_all();	
}
//rxh1.5�رմ��������
void CVisualscope_DlgDlg::close_port_all()
{
	tCSerialPort.ClosePort();//�رմ���   
	m_bSerialPortOpened=FALSE;		
	m_open_serial_port.SetUpColor(RGB(0,245,255));//���ñ�����ɫ
	m_open_serial_port.SetWindowText("�򿪴���");//�ڰ�ť����ʾ�ַ���
	//m_open_serial_port.SetForeColor(RGB(0,155,0));  //���ڴ򿪺��ı���ɫ����
	
}
//rxh1.5���ں�ѡ��
void CVisualscope_DlgDlg::OnSelendokComboComNum() 
{
	unsigned char i;
	//Com_Num=m_combo_com_num.GetCurSel()+1;//���г����������������д��ںŰ���С�������У�����ѡ�д��ں�
	i=m_combo_com_num.GetCurSel();
	Com_Num=m_nComArray[i];//�ڱ��������д�ע����ж�ȡ�Ĵ��ںŴ洢��m_nComArray[]������
	
}
//rxh1.5�������ں���Ͽ�
void CVisualscope_DlgDlg::OnDropdownComboComNum() 
{
	//�رմ��� 
	close_port_all();
	
	//����ɨ��������д���
	tCSerialPort.Hkey2ComboBox(m_combo_com_num);//��������//rxh2.0
	m_combo_com_num.SetCurSel(0);
	Com_Num=m_nComArray[0];//�ڱ��������д�ע����ж�ȡ�Ĵ��ںŴ洢��m_nComArray[]������	
}
//rxh1.5�����ڴ�ռ�
void CVisualscope_DlgDlg::OnDestroy() 
{
	CDialog::OnDestroy();

	SaveSoftwareConfig();
	
	if(receive_buffer != NULL)//rxh2.8ɾ���Կ��ٵ��ڴ�
    {
        delete [] receive_buffer;
        receive_buffer = NULL;//��ֵ��ָ�룬��ֹ��ɾ�ռ�
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
//rxh1.5���ڴ�����Ϣ
void CVisualscope_DlgDlg::OnComErrorAndClose()
{	//�رմ���
	close_port_all();
	//����ɨ��������д���
	tCSerialPort.Hkey2ComboBox(m_combo_com_num);//��������//rxh2.0
	m_combo_com_num.SetCurSel(0);
	Com_Num=m_nComArray[0];//�ڱ��������д�ע����ж�ȡ�Ĵ��ںŴ洢��m_nComArray[]������
}

void CVisualscope_DlgDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    int minpos = 0;  
    int maxpos = 0;  
	//rxh2.9.3�޸Ĺ��������϶���ʽ
	SCROLLINFO lpscrollInfo;
	GetScrollInfo(SB_HORZ,&lpscrollInfo,SIF_ALL);
	//
    GetScrollRange(SB_HORZ, &minpos, &maxpos);   
    maxpos = GetScrollLimit(SB_HORZ);  
	
    // Get the current position of scroll box.  //�õ��������ĵ�ǰλ��
    int curpos = GetScrollPos(SB_HORZ);  
	
    // Determine the new position of scroll box.  //ȷ���µĹ�������λ��
    switch (nSBCode)  
    {  
    case SB_LEFT:      // Scroll to far left.���������  
        curpos = minpos;  
        break;  
		
    case SB_RIGHT:      // Scroll to far right.�������Ҷ�  
        curpos = maxpos;  
        break;  
		
    case SB_ENDSCROLL:   // End scroll.  
        break;  
		
    case SB_LINELEFT:      // Scroll left. �������һ�� 
        if (curpos > minpos)  
            curpos--;  
        break;  
		
    case SB_LINERIGHT:   // Scroll right.  ���ҹ���һ��
        if (curpos < maxpos)  
            curpos++;  
        break;  
		
    case SB_PAGELEFT:    // Scroll one page left. �������һҳ 
        {  
            // Get the page size.   
            SCROLLINFO   info;  
            GetScrollInfo(SB_HORZ, &info, SIF_ALL);  
			
            if (curpos > minpos)  
                curpos = max(minpos, curpos - (int) info.nPage);  
        }  
        break;  
		
    case SB_PAGERIGHT:      // Scroll one page right. ���ҹ���һҳ 
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
        curpos=lpscrollInfo.nTrackPos;//rxh2.9.3�޸ĵ��϶���ʽ
		break;  //������ָ��λ��
		
    case SB_THUMBTRACK:   // Drag scroll box to specified position. nPos is the  
       // curpos = nPos;     // position that the scroll box has been dragged to.  
        curpos=lpscrollInfo.nTrackPos;
		break;  //���������϶�
    } 
    // Set the new position of the thumb (scroll box).  
    SetScrollPos(SB_HORZ, curpos);  

	//
	//��¼֮ǰ��λ��
	scoll_position=curpos;

	m_check_x_follow.SetCheck(0);//rxh2.4������ʾ,��ͣ����
   // UpdateWindow();  	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
//X�����
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
//��������ѡ��
void CVisualscope_DlgDlg::OnCheckPositiveOnly() 
{
	if (m_check_positive_only.GetCheck())
		positive_only_flag=1;
	else positive_only_flag=0;
}
//Y������Ӧ
void CVisualscope_DlgDlg::OnCheckYAuto() 
{
	if (m_check_y_auto.GetCheck())
		y_auto=1;
	else y_auto=0;
}
//ͨ��1��ѡ��
void CVisualscope_DlgDlg::OnCheckChannel1() 
{
	if (m_check_channel1.GetCheck())
		disp_channl[0]=1;
	else disp_channl[0]=0;	
}
//ͨ��2��ѡ��
void CVisualscope_DlgDlg::OnCheckChannel2() 
{
	if (m_check_channel2.GetCheck())
		disp_channl[1]=1;
	else disp_channl[1]=0;	
}
//ͨ��3��ѡ��
void CVisualscope_DlgDlg::OnCheckChannel3() 
{
	if (m_check_channel3.GetCheck())
		disp_channl[2]=1;
	else disp_channl[2]=0;	
}
//ͨ��4��ѡ��
void CVisualscope_DlgDlg::OnCheckChannel4() 
{
	if (m_check_channel4.GetCheck())
		disp_channl[3]=1;
	else disp_channl[3]=0;	
}
//�������
void CVisualscope_DlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
 	SetCapture();//��׽���
 	::SetCursor(hCross);
// 	static int point_temp_old=0;
// 	if(point_num!=point_temp_old)//���ݵ����Ķ��ٽ��й���������
// 	{
// 		//�ı����������
// 		xSi.nMin = 0; //��С����λ��
// 		xSi.nMax = point_num;//������λ��
// 		SetScrollInfo(SB_HORZ,&xSi);
// 		max_scoll_position=xSi.nMax-xSi.nMin+1-xSi.nPage;//���������λ��=nMax-nMin+1-nPage
// 		//�޷�
// 		if (scoll_position<=0)
// 			scoll_position=0;
// 		else if(scoll_position>=max_scoll_position)
// 			scoll_position=max_scoll_position;
// 		//	scoll_position=max_scoll_position;//��ʼ��������λ��
// 		//	SetScrollPos(SB_HORZ, max_scoll_position);
// 	}
//   point_temp_old=point_num;//������һ��
	//��׽����
	mouse_point=point;
	Dragging=TRUE;//������ק���	
	CDialog::OnLButtonDown(nFlags, point);
}
//���̧��
void CVisualscope_DlgDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (Dragging)
	{
		Dragging=false;//����ק���
		ReleaseCapture();//�ͷ���꣬��ԭ�����״
		
	}	
	CDialog::OnLButtonUp(nFlags, point);
}
//����ƶ�
void CVisualscope_DlgDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(Dragging)//�����������϶����
	{
	//	CClientDC dc(this);
		disp_biaochi=0;//������겻��ʾ���
// 		dc.MoveTo(mouse_point);//���
// 		dc.LineTo(point);//�����߶�
		CPoint new_point=point;//�����rxh
		mouse_move_x=(new_point.x-mouse_point.x);//��ȡ����ƶ�����
		mouse_point=new_point;//����rxh2.9.3

		if(mouse_move_x<0&&point_num!=0)//rxh2.5�������϶�
			scoll_position+=199999/point_num;//�ۼ�����ƶ�����
		else if(mouse_move_x>0&&point_num!=0)
			scoll_position-=199999/point_num;
		//�޷�
		if (scoll_position<=0)
			scoll_position=0;
		else if(scoll_position>=max_scoll_position)
			scoll_position=max_scoll_position;

		SetScrollPos(SB_HORZ, scoll_position);  
		//��ͣ����
		m_check_x_follow.SetCheck(0);//ȡ��ѡ��X����
		disp_point_add_flag=FALSE;
		m_button_stop_scope.SetUpColor(RGB(255,255,0));//���ñ�����ɫ		
		m_button_stop_scope.SetWindowText("��������");//�ڰ�ť����ʾ�ַ���

	}	
	else//��������϶�
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
    AfxMessageBox("����¼���׽ʧ�ܣ�");
	CDialog::OnMouseMove(nFlags, point);
}
//����Ҽ�����
void CVisualscope_DlgDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	//     CPoint pt;
	//     GetCursorPos(&pt);
	//     ScreenToClient(&pt);//����ΰѲ���ת����LPARAM���͵�ѽ?
	// 	CString string_temp;
	// 	string_temp.Format("�ͻ����:%d �豸��꣺%d",pt.x,point.x);
	// 	m_receive_count.SetWindowText(string_temp);
	mouse_right_down_x=point.x;//rxh3.0
	mouse_right_down_flag=1;
	//������
	disp_point_add_flag=0;
	m_button_stop_scope.SetUpColor(RGB(255,255,0));//���ñ�����ɫ		
	m_button_stop_scope.SetWindowText("��������");//�ڰ�ť����ʾ�ַ���

	CDialog::OnRButtonDown(nFlags, point);
	
}
//�Ҽ�̧��
void CVisualscope_DlgDlg::OnRButtonUp(UINT nFlags, CPoint point) 
{
	
	mouse_right_up_x=point.x;//rxh3.0
	mouse_right_up_flag=1;
	CDialog::OnRButtonUp(nFlags, point);
}
//����뿪
LRESULT CVisualscope_DlgDlg::OnMouseLeave(WPARAM wParam,LPARAM lParam)
{
// 	m_bMouseOver=FALSE;
// 	m_bTrack=FALSE;
// 	
// 	InvalidateRect(NULL);
	disp_biaochi=0;
	return 0;
}
//������ͻ���
LRESULT CVisualscope_DlgDlg::OnMouseHover(WPARAM wParam,LPARAM lParam)
{
// 	m_bMouseOver=TRUE;
// 	
	disp_biaochi=1;
	return 0;
}
//�����ֺ���//rxh2.3
BOOL CVisualscope_DlgDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	if (nFlags==MK_CONTROL)//ctrl��������,����X������
	{
		if(zDelta>0)
			OnButtonXBig();
		else
		OnButtonXLittle();
	}
	else//��������Y������
	{
		if(zDelta>0)
			OnButtonYBig();
		else
		OnButtonYLittle();
	}

	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}
//��ͣ����
void CVisualscope_DlgDlg::OnButtonStopScope() 
{
	disp_point_add_flag=!disp_point_add_flag;
	if(disp_point_add_flag)//��ʼ
	{
		m_button_stop_scope.SetUpColor(RGB(0,255,0));//���ñ�����ɫ)
		m_button_stop_scope.SetWindowText("��ͣ����");//�ڰ�ť����ʾ�ַ���
		scoll_position=max_scoll_position;
		SetScrollPos(SB_HORZ, max_scoll_position);
		m_check_x_follow.SetCheck(1);//ѡ��X����
	}
	else
	{
		m_button_stop_scope.SetUpColor(RGB(255,255,0));//���ñ�����ɫ		
		m_button_stop_scope.SetWindowText("��������");//�ڰ�ť����ʾ�ַ���
	}
}
//��������
void CVisualscope_DlgDlg::OnButtonAboutAuthor() 
{
	about_author_flag=1;
}
void CVisualscope_DlgDlg::DispAboutAuthor(CDC *pDC,int X_basic,int Y_basic)
{
	//pDC->SelectObject(m_hBitmap);rxh2.6��ʾͼƬ
CString about[8]=
{
	"������ʾ���������߻������ý������¿�����һ����١����µ�����ʾ����",
	"�������£��˿��Զ�ɨ�衢�����Զ����桢�ನ����ѡ�񡢴��ڰγ����������X��Y���������š���ͨ��ѡ��",
	"�����Զ����桢Y���Զ���Ӧ��Ļ�����յ����ʹ������ݸ���ͳ�ơ����α��桢����ʷ���Σ�txt��ʽ��",
	"��������ʵʱ��ߡ�����Y�����š�����+Ctrl��X�����š��������϶�X��Ⱥܰ��Ĺ��ܣ�����",
	"���������Ľ��������Ⱥ����,���������������Ⱥ��476174311",
	"����Ϊ�˿���һ����õ�����ʾ������Ͷ���˺ܴ��ʱ��;�����û�в���ע����ķ�ʽ�շѣ�������ѷ�������",
	"����������������ʾ���������Ŀ��������������㣬����������� ֧����:861063204@qq.com",
	"���ľ����Ƕ��ҹ����Ŀ϶���Ҳ���Ҽ�����������ǿ����������(PS:д����۳ɹ���֧��һ�°�*^_^*)"};
	pDC->SelectObject(&x_font);
	pDC->SetTextColor(RGB(255,255,0));//���öԻ����������ɫ
//	pDC->SetBkColor(RGB(100,200,200));//�������屳����ɫ
	pDC->SetBkMode(TRANSPARENT);//���ÿؼ�����͸��
	for (char i=0;i<8;i++)
	{
		pDC->TextOut(X_basic+5,tRect1.top+10+35*i,about[i]);

	}

//	CBitmap* pBitmap = CBitmap::FromHandle(m_hBitmap);
}
//���沨��rxh2.8
void CVisualscope_DlgDlg::OnButtonSaveScope() 
{
    // ���ù�����   
    TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|Word�ļ�(*.doc)|*.doc|�����ļ�(*.*)|*.*||");   
    // ���챣���ļ��Ի���   
    CFileDialog fileDlg(FALSE, _T("doc"), _T("��������"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);   
    CString strFilePath=" ";   
    // ��ʾ�����ļ��Ի���   
    if (IDOK == fileDlg.DoModal())   
        strFilePath = fileDlg.GetPathName(); //��ȡ�ļ���  
	//��ӡ
	if (strFilePath!=" ")
	{
		FILE *print_file=fopen(strFilePath,"w+");
		for (int i=0;i<point_num_temp;i++)
		{
			fprintf(print_file,"%d %d %d %d \n",scope_data[i][0],scope_data[i][1],scope_data[i][2],scope_data[i][3]);	
			
		}
		Sleep(200);
		fclose(print_file);
		AfxMessageBox("�������ݱ���ɹ�");
	}
	else 
	{	
		AfxMessageBox("δ�����ļ�");
	}
}
//����ʷ����
void CVisualscope_DlgDlg::OnButtonOpenDataFromFile() 
{
	close_port_all();//�ȹرմ���
	OnButtonCleanScope();//�������
	Sleep(200);
	CFileDialog *lpszOpenFile;    //����һ��CfileDialog����
	lpszOpenFile = new
	CFileDialog(TRUE,"","",OFN_FILEMUSTEXIST |OFN_HIDEREADONLY,"(*.txt)|*.txt|�����ļ�(*.*)|*.*||");//����һ���Ի���
	CString szGetName=" ";
	if(lpszOpenFile->DoModal()==IDOK)//�������Ի���ȷ����ť
	{
		szGetName = lpszOpenFile->GetPathName();//�õ����ļ���·��
		SetWindowText(szGetName);//�ڴ��ڱ�������ʾ·��
	}
	delete lpszOpenFile;//�ͷŷ���ĶԻ���

	//���ļ�--����1--�ɹ�
// 	CStdioFile tStdioFile;
// 	if (szGetName!=" ")
// 	{
// 		tStdioFile.Open(szGetName,CFile::modeRead);  //����-����2  ����-����3 ;  -- ����1����.txt ����2����.txt  ..
// 		int TmpctLoadIndex=0;
// 		CString ctReadLineStr;
// 		
// 		while(1)
// 		{	//���ļ��е��ַ���������
// 			int TmpCtReadRes=tStdioFile.ReadString(ctReadLineStr);
// 			if(TmpCtReadRes==0)
// 				break;
// 			
// 			sscanf(ctReadLineStr,"%d %d %d %d",&scope_data[TmpctLoadIndex][0],&scope_data[TmpctLoadIndex][1],&scope_data[TmpctLoadIndex][2],&scope_data[TmpctLoadIndex][3]);
// 			if(TmpctLoadIndex<max_point_num)
// 			TmpctLoadIndex++;
// 			else 
// 			{
// 				AfxMessageBox("��������20��,�Ѻ��Զ���ĵ�����");
// 				break;
// 			}
// 		}
// 		
// 		tStdioFile.Close();
// 		
// 		point_num_temp=TmpctLoadIndex;//�������ݸ���
// 		disp_point_add_flag=1;//����
// 		disp_scope_flag=1;//��ʾ����
// 	}
// 	else 
// 	{	
// 		AfxMessageBox("δ�ҵ��ļ�");
// 	}

//////////////////////////////////////////////////////////////////////////
	//���ļ�---����2--���ɹ�
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
// 				AfxMessageBox("��������20��,�Ѻ��Զ���ĵ�����");
// 				break;
// 			}
// 		}
// 
// 		mFile.Close();
// 		point_num_temp=TmpctLoadIndex;//�������ݸ���
// 		disp_point_add_flag=1;//����
// 		disp_scope_flag=1;//��ʾ����
// 	
// 	}
// 	else 
// 	{	
// 	 	AfxMessageBox("δ�ҵ��ļ�");
// 	}
//////////////////////////////////////////////////////////////////////////
	//���ļ�---����3�ɹ�
	if (szGetName!=" ")
	{
		FILE *fp;
		if((fp=fopen(szGetName,"r"))==NULL)
			return ;
		int TmpctLoadIndex=0;
		CString ctReadLineStr;
		
		while(1)
		{	//���ļ��е��ַ���������
			for(int i=0;i<4;i++)
				fscanf(fp,"%d",&scope_data[TmpctLoadIndex][i]);
			if(feof(fp)) //�ļ���β
				break; 
			if(TmpctLoadIndex<max_point_num)
				TmpctLoadIndex++;
			else 
			{
				AfxMessageBox("��������20��,�Ѻ��Զ���ĵ�����");
				break;
			}
		}
		
		fclose(fp);//�ر��ļ�
		
		point_num_temp=TmpctLoadIndex;//�������ݸ���
		disp_point_add_flag=1;//����
		disp_scope_flag=1;//��ʾ����
	}
	else 
	{	
		AfxMessageBox("δ�ҵ��ļ�");
	}
//////////////////////////////////////////////////////////////////////////

}
//��������ĵ�ǰ����
void CVisualscope_DlgDlg::SaveSoftwareConfig()
{
	FILE *print_file=fopen("����ʾ��������.ini","w+");
	int data[10]={0};
	data[0]=Com_Num;
	data[1]=m_Combo_bandRate.GetCurSel();
	if(m_check_positive_only.GetCheck())//��ʾ�������Ǹ���
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
//�����֮ǰ������
void CVisualscope_DlgDlg::OpenSoftwareConfig()
{
		FILE *fp;
		if((fp=fopen("����ʾ��������.ini","r"))==NULL)
			return ;
		int data[10]={0};
		
		while(1)
		{	//���ļ��е��ַ���������
			for(int i=0;i<10;i++)
				fscanf(fp,"%d",&data[i]);
			if(feof(fp)) //�ļ���β
				break; 
		}
		for (int i=0;i<20;i++)//��ȡ���ں�
		{
			if (data[0]==m_nComArray[i])
			{
				Com_Num=data[0];
				m_combo_com_num.SetCurSel(i);
				//AfxMessageBox("�ҵ����ں�");
			}
		}
		int choose=data[1];//��ȡ������
		unsigned int band_rate_buff[12]={300,600,1200,2400,4800,9600,19200,38400,43000,56000,57600,115200};
		if(choose<12)
		{
			m_BaudRate=band_rate_buff[choose];
			m_Combo_bandRate.SetCurSel(choose);//������Ĭ��115200
		}

		if(data[2])//��������������
		{
			positive_only_flag=1;
			m_check_positive_only.SetCheck(1);
		}
		else
		{
			positive_only_flag=0;
			m_check_positive_only.SetCheck(0);
		}
		fclose(fp);//�ر��ļ�
}