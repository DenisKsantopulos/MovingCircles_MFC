// CColorDlg.cpp: файл реализации
//

#include "pch.h"
#include "SDI_t.h"
#include "CColorDlg.h"
#include "afxdialogex.h"
#include "SDI_tDoc.h"

#include <random>

// Диалоговое окно CColorDlg

IMPLEMENT_DYNAMIC(CColorDlg, CDialogEx)

CColorDlg::CColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_COLOR, pParent)
{

}

CColorDlg::~CColorDlg()
{
}

void CColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_colorButton);
}


BEGIN_MESSAGE_MAP(CColorDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ApplyColor, &CColorDlg::OnBnClickedApplycolor)
END_MESSAGE_MAP()


// Обработчики сообщений CColorDlg


void CColorDlg::OnBnClickedApplycolor()
{
	for(int i = 0; i <= m_pDoc->m_num; i++)
		m_pDoc->m_circ[i].m_color = m_colorButton.GetColor();
}