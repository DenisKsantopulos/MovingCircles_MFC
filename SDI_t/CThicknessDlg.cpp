// CThicknessDlg.cpp: файл реализации
//

#include "pch.h"
#include "SDI_t.h"
#include "CThicknessDlg.h"
#include "afxdialogex.h"


// Диалоговое окно CThicknessDlg

IMPLEMENT_DYNAMIC(CThicknessDlg, CDialogEx)

CThicknessDlg::CThicknessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_THICKNESS, pParent)
	, m_iValue(0)
{

}

CThicknessDlg::~CThicknessDlg()
{
}

void CThicknessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Thickness, m_iValue);
	DDV_MinMaxInt(pDX, m_iValue, 1, 25);
}


BEGIN_MESSAGE_MAP(CThicknessDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CThicknessDlg
