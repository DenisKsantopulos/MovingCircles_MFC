#pragma once

//#include "SDI_tDoc.h"

class CSDItDoc;

// Диалоговое окно CColorDlg2

class CColorDlg2 : public CDialog
{
	DECLARE_DYNAMIC(CColorDlg2)

public:
	CSDItDoc* m_pDoc;

	CColorDlg2(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CColorDlg2();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
