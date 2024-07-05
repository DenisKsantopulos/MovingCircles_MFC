// CColorDlg2.cpp: файл реализации
//

#include "pch.h"
#include "SDI_t.h"
#include "CColorDlg2.h"
#include "afxdialogex.h"


// Диалоговое окно CColorDlg2

IMPLEMENT_DYNAMIC(CColorDlg2, CDialog)

CColorDlg2::CColorDlg2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_COLOR, pParent)
{

}

CColorDlg2::~CColorDlg2()
{
}

void CColorDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CColorDlg2, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CColorDlg2
