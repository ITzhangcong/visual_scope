#if !defined(AFX_MYBUTTUN_H__59B90F88_9DB2_49EB_B9C5_73F64B1EDA03__INCLUDED_)
#define AFX_MYBUTTUN_H__59B90F88_9DB2_49EB_B9C5_73F64B1EDA03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyButtun.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyButtun window

class CMyButtun : public CButton
{
public:
	CMyButton();
	//设置Button Down的背景颜色
	void SetDownColor(COLORREF color);
	//设置Button Up的背景颜色
	void SetUpColor(COLORREF color);
	BOOL Attach(const UINT nID, CWnd* pParent);
// Attributes
public:

// Operations
public:
	bool m_flag;//rxh2.9.2
	CBrush My_Brush;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyButtun)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	//}}AFX_VIRTUAL
	public:
		//三种颜色分别为文字，Button Down的背景颜色，Button Up的背景颜色
	COLORREF m_TextColor, m_DownColor,m_UpColor;
// Implementation
public:
	virtual ~CMyButtun();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyButtun)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBUTTUN_H__59B90F88_9DB2_49EB_B9C5_73F64B1EDA03__INCLUDED_)
