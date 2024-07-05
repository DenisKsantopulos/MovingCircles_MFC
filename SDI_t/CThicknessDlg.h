#pragma once


// Диалоговое окно CThicknessDlg

class CThicknessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CThicknessDlg)

public:
	CThicknessDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CThicknessDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_THICKNESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int m_iValue;
};
