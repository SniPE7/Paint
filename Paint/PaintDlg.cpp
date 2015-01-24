
// PaintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Paint.h"
#include "PaintDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPaintDlg dialog



CPaintDlg::CPaintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPaintDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPaintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CPaintDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CPaintDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CPaintDlg::OnBnClickedRadio3)
	ON_COMMAND(ID_FILE_EXITALT, &CPaintDlg::OnFileExitalt)
END_MESSAGE_MAP()


// CPaintDlg message handlers

BOOL CPaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO1);
	// TODO: Add extra initialization here

	// Load the menu resource
	if (!m_menu.LoadMenu(IDR_MENU1))
		AfxThrowResourceException();

	// Set the menu
	SetMenu(&m_menu);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPaintDlg::OnPaint()
{
	CRect rect;
	GetClientRect(&rect);

	CFont font;
	font.CreatePointFont(500, _T("Arial"));

	CPaintDC dc(this);
	CFont *oldFont = dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);

	dc.SelectObject(oldFont);
	//!!2
	//1st
	for (int i = 0; i<figs.GetSize(); i++)
		figs[i]->Draw(&dc);
	//if creation
	if (isPressed)
	{
		dc.MoveTo(startP.x, startP.y);
		dc.LineTo(startP.x, endP.y);
		dc.LineTo(endP.x, endP.y);
		dc.LineTo(endP.x, startP.y);
		dc.LineTo(startP.x, startP.y);
	}

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPaintDlg::OnQueryDragIcon()
{
	//return static_cast<HCURSOR>(m_hIcon);
	return (HCURSOR)m_hIcon;
}

void CPaintDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//!!4: added endP= 
	endP = startP = point;
	isPressed = true;

	CDialog::OnLButtonDown(nFlags, point);

}

void CPaintDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{

		endP = point;
		isPressed = false;
		switch (futureFigKIND)
		{
		case RECTANGLE:
			//!!6 instead of .push_back
			figs.Add(new RectangleM(startP.x, startP.y, endP.x, endP.y));
			break;
		case ELLIPSE:
			//!!6
			figs.Add(new EllipseM(startP.x, startP.y, endP.x, endP.y));
			break;
		}
		Invalidate();

	}

	CDialog::OnLButtonUp(nFlags, point);
}
void CPaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{


		CClientDC dc(this);

		CBrush myBrush, *oldBrush;
		myBrush.CreateSolidBrush(RGB(277, 277, 277));
		oldBrush = dc.SelectObject(&myBrush);

		CPen myPen1(PS_SOLID, 3, RGB(0, 0, 0));
		CPen *oldPen;
		oldPen = dc.SelectObject(&myPen1);
		dc.SetROP2(R2_NOTXORPEN);
		endP = point;
		switch (futureFigKIND)
		{
		case RECTANGLE:
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			break;
		case ELLIPSE:
			//dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			break;
		}
		dc.SelectObject(oldPen);
		dc.SetROP2(R2_COPYPEN);


		dc.SelectObject(oldBrush);

	}
	CDialog::OnMouseMove(nFlags, point);
}

void CPaintDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = RECTANGLE;
}

void CPaintDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = ELLIPSE;
}

void CPaintDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = SEGMENT;
}

void CPaintDlg::OnFileExitalt()
{
	// TODO: Add your command handler code here
}
