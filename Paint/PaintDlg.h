
// PaintDlg.h : header file
//
#if !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
#define AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>         // vector lib
#include <list> 
#include "Figure.h"
#include "afxcolorbutton.h"

using namespace std;
// CPaintDlg dialog
class CPaintDlg : public CDialogEx
{
	//!!2
	enum FIGURES{ RECTANGLE, ELLIPSE, LINE };
	FIGURES futureFigKIND;

	enum ACTION_TYPE{ DRAW, MOVE };
	ACTION_TYPE actionKind;

	// added s
	Figure *f;
	//!!6 b
	//vector <Figure *> figs;
	//CTypedPtrArray< CObArray, Figure*> figs;
	list <Figure*> figs;
	//stack <Figure*> figsRecycleBin;
	list <Figure*> figsRecycleBin;
	//!!6 e

	bool isPressed;
	CPoint startP;
	CPoint endP;
	CPoint onPoint;
	int indexToMove;
	// added e
	// Construction
// Construction
public:
	CPaintDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_PAINT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CMenu m_menu;
	CMFCColorButton ChoosedColor;
	HCURSOR m_Cursor;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP();

public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnFileExitalt();
	afx_msg void OnBnClickedMfcbuttonRedo();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedMfcbutton2();
	afx_msg void OnBnClickedMfcbuttonUndo();
	afx_msg void OnBnClickedMfccolorbutton1();
	CString m_MouseMoveString;
	COLORREF m_ChoosedColor;
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadioMoveB5();
	afx_msg void OnBnClickedRadioDrawB6();
};

#endif