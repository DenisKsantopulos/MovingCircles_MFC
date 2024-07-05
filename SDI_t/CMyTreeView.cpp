// CMyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "SDI_t.h"
#include "CMyTreeView.h"

#include "SDI_tDoc.h"

// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG

void CMyTreeView::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();

	tree.DeleteAllItems();

	m_hColor = tree.InsertItem(L"Цвет", -1, -1, NULL, TVI_FIRST);

	m_hRed = tree.InsertItem(L"Красный", -1, -1, m_hColor, TVI_FIRST);
	m_hBlue = tree.InsertItem(L"Синий", -1, -1, m_hColor, TVI_FIRST);
	m_hGreen = tree.InsertItem(L"Зеленый", -1, -1, m_hColor, TVI_FIRST);

	tree.Expand(m_hColor, TVE_EXPAND);

	m_hThick = tree.InsertItem(L"Толщина", -1, -1, NULL);

	m_hFirstThick = tree.InsertItem(L"1 px", -1, -1, m_hThick);
	m_hSecondThick = tree.InsertItem(L"5 px", -1, -1, m_hThick);
	m_hThirdThick = tree.InsertItem(L"10 px", -1, -1, m_hThick);

	tree.Expand(m_hThick, TVE_EXPAND);
}

// Обработчики сообщений CMyTreeView


int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS
		| TVS_LINESATROOT | TVS_SHOWSELALWAYS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}


void CMyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTreeCtrl& tree = GetTreeCtrl();
	CTreeView::OnLButtonDown(nFlags, point);
	
	CRect rc;

	//
	tree.GetItemRect(m_hColor, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hColor);

	tree.GetItemRect(m_hRed, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hRed);

	tree.GetItemRect(m_hBlue, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hBlue);
		
	tree.GetItemRect(m_hGreen, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hGreen);

	tree.GetItemRect(m_hThick, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hThick);

	tree.GetItemRect(m_hFirstThick, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hFirstThick);

	tree.GetItemRect(m_hSecondThick, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hSecondThick);

	tree.GetItemRect(m_hThirdThick, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hThirdThick);
	//

	m_pDoc->m_pTreeView->Invalidate();

	for (int i = 0; i <= m_pDoc->m_num; i++)
	{
		if (tree.GetSelectedItem() == m_hGreen)
			m_pDoc->m_circ[i].m_color = RGB(0, 255, 0);
		if (tree.GetSelectedItem() == m_hRed)
			m_pDoc->m_circ[i].m_color = RGB(255, 0, 0);;
		if (tree.GetSelectedItem() == m_hBlue)
			m_pDoc->m_circ[i].m_color = RGB(0, 0, 255);;

		if (tree.GetSelectedItem() == m_hFirstThick)
			m_pDoc->m_circ[i].m_bThick = 1;
		if (tree.GetSelectedItem() == m_hSecondThick)
			m_pDoc->m_circ[i].m_bThick = 5;
		if (tree.GetSelectedItem() == m_hThirdThick)
			m_pDoc->m_circ[i].m_bThick = 10;

	}
}
