
// SDI_tView.cpp: реализация класса CSDItView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SDI_t.h"
#endif

#include "SDI_tDoc.h"
#include "SDI_tView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDItView

IMPLEMENT_DYNCREATE(CSDItView, CView)

BEGIN_MESSAGE_MAP(CSDItView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_SIZE()
ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CSDItView

CSDItView::CSDItView() noexcept
{
	// TODO: добавьте код создания

}

CSDItView::~CSDItView()
{
}

BOOL CSDItView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CSDItView

void CSDItView::OnDraw(CDC* pDC)
{
	CSDItDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//Получение размера окна
	CRect rect;
	GetClientRect(&rect);

	//Отрисовка каждого шарика
	for (int i = 0; i <= pDoc->m_num; i++)
		pDoc->m_circ[i].Draw(pDC, rect);
}

// Печать CSDItView

BOOL CSDItView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSDItView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSDItView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CSDItView

#ifdef _DEBUG
void CSDItView::AssertValid() const
{
	CView::AssertValid();
}

void CSDItView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDItDoc* CSDItView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDItDoc)));
	return (CSDItDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CSDItView


void CSDItView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// 0 отвечает так же за скорость
	SetTimer(0, 20, NULL);
	SetTimer(1, 500, NULL);
}


void CSDItView::OnTimer(UINT_PTR nIDEvent)
{
	CSDItDoc* pDoc = GetDocument();

	CRect rc;
	GetClientRect(&rc);

	//Проверка по таймерам
	if (nIDEvent == 1)
		for (int i = 0; i <= pDoc->m_num; i++)
		{
			pDoc->m_circ[i].setValues(rc);
		}
	else
	{
		Invalidate();

		for (int i = 0; i <= pDoc->m_num; i++)
			if (!pDoc->m_bStop)
				pDoc->m_circ[i].move(rc);
	}
		

	CView::OnTimer(nIDEvent);
}

void CSDItView::OnRButtonUp(UINT nFlags, CPoint point)
{
	CMenu MainMenu;
	MainMenu.LoadMenuW(IDR_MAINFRAME);
	CMenu* SubMenu = MainMenu.GetSubMenu(3);
	ClientToScreen(&point);
	SubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

	CView::OnRButtonUp(nFlags, point);
}

