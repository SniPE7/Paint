
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
	, m_MouseMoveString(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, ChoosedColor);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON1, m_ChoosedColor);

	DDX_Text(pDX, IDC_AXIS, m_MouseMoveString);
	DDX_Control(pDX, IDC_MFCBUTTON_UNDO, m_btnUndo);
	DDX_Control(pDX, IDC_MFCBUTTON_REDO, m_btnRedo);
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
	ON_BN_CLICKED(IDC_MFCBUTTON_UNDO, &CPaintDlg::OnBnClickedMfcbuttonUndo)
	ON_BN_CLICKED(IDC_MFCBUTTON_REDO, &CPaintDlg::OnBnClickedMfcbuttonRedo)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CPaintDlg::OnBnClickedMfccolorbutton1)
	
	//ON_BN_CLICKED(IDC_RADIO6, &CPaintDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO_MOVE_B5, &CPaintDlg::OnBnClickedRadioMoveB5)
	ON_BN_CLICKED(IDC_RADIO_DRAW_B6, &CPaintDlg::OnBnClickedRadioDrawB6)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPaintDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CPaintDlg::OnBnClickedMfccolorbutton2)
	ON_BN_CLICKED(IDSAVEAS, &CPaintDlg::OnBnClickedSaveas)
	ON_BN_CLICKED(IDOPEN, &CPaintDlg::OnBnClickedOpen)
END_MESSAGE_MAP()


// CPaintDlg message handlers

BOOL CPaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_ChoosedColor = RGB(0, 0, 0);
	m_ChoosedColorB = RGB(0, 0, 0);


	// Add "About..." menu item to system menu.
	m_btnUndo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_UNDO)));
	m_btnRedo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_REDO)));

	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO1);

	
	pComboBox->AddString(_T("Border 1"));
	pComboBox->AddString(_T("Border 2"));
	pComboBox->AddString(_T("Border 3"));
	pComboBox->AddString(_T("Border 4"));
	pComboBox->AddString(_T("Border 5"));
	pComboBox->AddString(_T("Border 6"));
	pComboBox->AddString(_T("Border 7"));
	pComboBox->AddString(_T("Border 8"));
	pComboBox->AddString(_T("Border 9"));
	

	
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

	CBrush myBrush, *oldBrush;
	
	CPen myPen1(PS_SOLID, frameSize, m_ChoosedColorB); //Frame size and color
	CPen *oldPen;

	myBrush.CreateSolidBrush(m_ChoosedColor); //Figures color
	oldBrush = dc.SelectObject(&myBrush);

	oldPen = dc.SelectObject(&myPen1);
	dc.SetROP2(R2_NOTXORPEN);

	dc.MoveTo(startP);
	dc.LineTo(endP.x, endP.y);
	//dc.SelectObject(oldPen);
	dc.SetROP2(R2_COPYPEN);

	//!!2
	//1st
	for (list <Figure*>::const_iterator it = figs.begin(); it != figs.end(); it++)
		(*it)->Draw(&dc);
	//for (int i = 0; i<figs_arr.GetSize(); i++)
	//	figs_arr[i]->Draw(&dc);
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
		//dc.DrawIcon(x, y, m_hIcon);
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
	isPressed = true;
	indexToMove = -1;
	int counter, flag_found;
	counter = flag_found = 0;
	
	switch (actionKind)
	{
	case DRAW:
		endP = startP = point;
		break;
	case MOVE:
		for (list <Figure*>::const_reverse_iterator it = figs.rbegin(); it != figs.rend() && !(flag_found); ++it)
		{
			if (point.x >= (*it)->x1 && point.x <= (*it)->x2 && point.y >= (*it)->y1 && point.y <= (*it)->y2)     //If click on rectangle area
			{
				flag_found = 1;
				onPoint = point;
				indexToMove = counter;
			}
			counter++;
		}
		SetCapture();
		break;
	}
	CDialog::OnLButtonDown(nFlags, point);

}

void CPaintDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	switch (actionKind)
	{
	case DRAW:
		if (isPressed)
		{
			endP = point;
			isPressed = false;
			switch (futureFigKIND)
			{
			case RECTANGLE:
				figs.push_back(new RectangleM(startP.x, startP.y, endP.x, endP.y, frameSize));
				break;
			case ELLIPSE:
				figs.push_back(new EllipseM(startP.x, startP.y, endP.x, endP.y, frameSize));
				break;
			case LINE:
				figs.push_back(new LineM(endP.x, endP.y, frameSize));
				break;
			}
			Invalidate();
		}
		break;

	case MOVE:
		isPressed = false;
		list <Figure*>::const_reverse_iterator it = figs.rbegin();
		advance(it, indexToMove);
		(*it)->x1 += (point.x - onPoint.x);             //Increase left-top and right-bot Points
		(*it)->x2 += (point.x - onPoint.x);
		(*it)->y1 += (point.y - onPoint.y);
		(*it)->y2 += (point.y - onPoint.y);
		onPoint = point;
		Invalidate();
		ReleaseCapture();
		break;
	}
	CDialog::OnLButtonUp(nFlags, point);
}
void CPaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	switch (actionKind)
	{
	case MOVE:
		//AfxMessageBox(_T("AAAAAAAAAAAAAAAAA"));

		if(isPressed == true && indexToMove!= -1)
		{
			list <Figure*>::const_reverse_iterator it = figs.rbegin();
			advance(it,indexToMove);
			(*it)->x1 += (point.x - onPoint.x);             //Increase left-top and right-bot Points
			(*it)->x2 += (point.x - onPoint.x);
			(*it)->y1 += (point.y - onPoint.y);
			(*it)->y2 += (point.y - onPoint.y);
			onPoint = point;
			Invalidate();   //Invalidate the screeen 
		}
		break;
	case DRAW:
		if (isPressed)
		{
			CClientDC dc(this);

			CBrush myBrush, *oldBrush;
			myBrush.CreateSolidBrush(m_ChoosedColor); //Figures color
			oldBrush = dc.SelectObject(&myBrush);

			CPen myPen1(PS_SOLID, frameSize, m_ChoosedColorB); //Frame size and color
			CPen *oldPen;
			oldPen = dc.SelectObject(&myPen1);
			dc.SetROP2(R2_NOTXORPEN);

			switch (futureFigKIND)
			{
			case RECTANGLE:
				dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
				endP = point;
				dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
				break;
			case ELLIPSE:
				dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
				endP = point;
				dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
				break;
			case LINE:
				dc.MoveTo(startP);
				dc.LineTo(endP.x, endP.y);
				endP = point;
				dc.MoveTo(startP);
				dc.LineTo(endP.x, endP.y);
				dc.SelectObject(oldPen);
				break;
			}

			dc.SelectObject(oldPen);
			dc.SetROP2(R2_COPYPEN);


			dc.SelectObject(oldBrush);

		}
		break;
	}
	m_MouseMoveString.Format(_T("x: %d, y: %d"), point.x, point.y);
	UpdateData(FALSE);

	
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
	futureFigKIND = LINE;
}

void CPaintDlg::OnFileExitalt()
{
	// TODO: Add your command handler code here
}
/*
case ACTIONID:     // Undo 
	if (paint.empty())
	{
		MessageBox(hwnd, TEXT("List is empty"), szAppName, MB_ICONINFORMATION);
	}
	else
	{
		sp = new Figure;       // we creare new figure to insert all the data there 
		sp = paint.back();		// get the latest item 
		paint.pop_back();		// remove the last item from main list
		stack.push_back(sp);    // insert onto list we all stack //
		InvalidateRect(hwnd, &rect, 1);
	}
	break;

case ACTIONID + 1:     // Redo 
	if (stack.empty())
		MessageBox(hwnd, TEXT("Stack is empty"), szAppName, MB_ICONINFORMATION);
	else
	{
		sp = new Figure;
		sp = stack.back();
		stack.pop_back();
		paint.push_back(sp);
		InvalidateRect(hwnd, &rect, 1);
	}
	break;
	*/


	


void CPaintDlg::OnBnClickedMfcbuttonUndo()
{
	// TODO: Add your control notification handler code here
	if (figs.empty())
	{
		AfxMessageBox(_T("Error: There are no objects to UNDO!"));
	}
	else
	{
		Figure *temp = new Figure;       
		temp = figs.back();		// getting the latest Figure from list
		figs.pop_back();		// remove the last Figure from list
		figsRecycleBin.push_back(temp);    // insert Figure into the stack
		Invalidate();
	}
}

void CPaintDlg::OnBnClickedMfcbuttonRedo()
{
	if (figsRecycleBin.empty())
		AfxMessageBox(_T("Error: There are no objects to REDO!"));
	else
	{
		Figure *temp1 = new Figure;
		temp1 = figsRecycleBin.back();
		figsRecycleBin.pop_back();
		figs.push_back(temp1);
		Invalidate();
	}
}



void CPaintDlg::OnBnClickedMfccolorbutton1()
{
	CMFCColorDialog dlgColors;

	if (dlgColors.DoModal() == IDOK)
		m_ChoosedColor = dlgColors.GetColor();
}

void CPaintDlg::OnBnClickedMfccolorbutton2()
{
	CMFCColorDialog dlgColors;

	if (dlgColors.DoModal() == IDOK)
		m_ChoosedColorB = dlgColors.GetColor();
}


void CPaintDlg::OnBnClickedRadioMoveB5()
{
	// TODO: Add your control notification handler code here
	actionKind = MOVE;
}


void CPaintDlg::OnBnClickedRadioDrawB6()
{
	// TODO: Add your control notification handler code here
	actionKind = DRAW;
}


void CPaintDlg::OnCbnSelchangeCombo1()
{
	frameSize = pComboBox->GetCurSel();
}





void CPaintDlg::OnBnClickedSaveas()
{
	for (list <Figure*>::const_iterator it = figs.begin(); it != figs.end(); it++)
		figs_arr.Add(*it);

	char strFilter[] = { "Den & Stat Format (*.ds)|*.ds|" };

	CFileDialog dlg(FALSE, CString(".ds"), NULL, 0, CString(strFilter));
	CString fileName;

	if (IDOK == dlg.DoModal())
	{
		fileName = dlg.m_ofn.lpstrFile;
	}
	

	CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	figs_arr.Serialize(ar);
	ar.Close();
	file.Close();
}


void CPaintDlg::OnBnClickedOpen()
{
	CFileDialog dlg(TRUE);
	CString fileName;

	if (IDOK == dlg.DoModal())
	{
		fileName = dlg.m_ofn.lpstrFile;
		
	}
	CFile file(fileName, CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	figs_arr.Serialize(ar);
	ar.Close();
	file.Close();

	int i = 0;
	while (i<figs_arr.GetSize())
	{
		figs.push_back(figs_arr[i]);
		i++;
	}

	
	Invalidate();
}

