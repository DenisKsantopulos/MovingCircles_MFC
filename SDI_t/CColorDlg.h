#pragma once

class CSDItDoc;

// Диалоговое окно CColorDlg

class CColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CColorDlg)

public:
	CSDItDoc* m_pDoc;

	CColorDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CColorDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CMFCColorButton m_colorButton;
	afx_msg void OnBnClickedApplycolor();
	afx_msg void OnBnClickedRandomColor();
};
