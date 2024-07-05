#include "pch.h"
#include "framework.h"
#ifndef SHARED_HANDLERS
#include "SDI_t.h"
#endif

#include "SDI_tDoc.h"

#include <propkey.h>

#include <vector>
#include <random>
#include "CColorDlg.h"
#include "CMyTreeView.h"
#include "CThicknessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSDItDoc

IMPLEMENT_DYNCREATE(CSDItDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDItDoc, CDocument)
	ON_COMMAND(ID_OPTIONS_STOP, &CSDItDoc::OnOptionsStop)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_STOP, &CSDItDoc::OnUpdateOptionsStop)
	ON_COMMAND(ID_OPTIONS_THICKNESS, &CSDItDoc::OnOptionsThickness)
	ON_COMMAND(ID_OPTIONS_COLOR, &CSDItDoc::OnOptionsColor)
END_MESSAGE_MAP()


CMyCircle::CMyCircle()
{

}

CMyCircle::CMyCircle(int x, int y, int r)
{
	m_iX = x;
	m_iY = y;
	m_iR = r;
}

void CMyCircle::Draw(CDC* pDC, CRect rect)
{
	//Создание инструмента рисования (для изменения цвета и толщины)
	CPen pen;
	pen.CreatePen(PS_NONE, m_bThick, m_color);
	CPen* pOldPen = pDC->SelectObject(&pen);

	//Отрисовка
	pDC->MoveTo(m_iX + m_iR, m_iY);
	pDC->AngleArc(m_iX, m_iY, m_iR, 0, 360);

	//Выбор старого инструмента для изменения цвета назад
	pDC->SelectObject(pOldPen);
}

void CMyCircle::setValues(CRect obl)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<> forSpeed(3, 10);

	//1 - если шарик еще не создан
	//2 - если шарик столнклся со стеной
	//3 - Если шарик не движется
	if (!isSpawned)
	{
		m_iR = 5 + rng() % 70;

		m_iX = m_iR + rng() % (obl.Width() - m_iR * 2);
		m_iY = m_iR + rng() % (obl.Height() - m_iR * 2);
		m_speed = forSpeed(rng);
		isSpawned = true;
	}
	else if ((m_iX + m_iR > obl.Width()) || (m_iY + m_iR >= obl.Height()) || (m_iX - m_iR < 0) || (m_iY - m_iR < 0))
	{
		m_iX = m_iR + rng() % (obl.Width() - m_iR * 2);
		m_iY = m_iR + rng() % (obl.Height() - m_iR * 2);
	}

	if(m_moveX == 0 && m_moveY == 0)
		changeDirection();
}

void CMyCircle::move(CRect obl)
{
	if ((m_moveX + m_iX + m_iR >= obl.Width() || m_moveY + m_iY + m_iR >= obl.Height() || m_moveY + m_iY - m_iR < 1 || m_moveX + m_iX - m_iR < 1))
	{
		//Если столкнулся со стеной
		changeDirection();
	}
	else
	{
		//Если не столкнулся и движется
		m_iX += m_moveX;
		m_iY += m_moveY;
	}
}

void CMyCircle::changeDirection()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<> PosOrNeg(1, 2);
	std::uniform_int_distribution<> direction(0, m_speed);
	
	int kx, ky, dir = direction(rng);
	
	if (PosOrNeg(rng) == 1)
		kx = 1;
	else
		kx = -1;

	if (PosOrNeg(rng) == 1)
		ky = 1;
	else
		ky = -1;


	//Для постоянной скорости
	m_moveX = (m_speed - dir) * kx;
	m_moveY = dir * ky;
}

// Создание или уничтожение CSDItDoc

CSDItDoc::CSDItDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CSDItDoc::~CSDItDoc()
{
}

BOOL CSDItDoc::OnNewDocument()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<> dist(2, 10);

	if (!CDocument::OnNewDocument())
		return FALSE;

	CWnd* MainWnd = AfxGetMainWnd();

	if (MainWnd)
	{
		m_pTreeView = (CMyTreeView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 0);

		m_pTreeView->m_pDoc = this;
	}

	m_pTreeView->FillTree();

	m_num = dist(rng);

	for (int i = 0; i <= m_num; i++)
	{
		CMyCircle circle;

		circle.m_iX = 0;
		circle.m_iY = 0;
		circle.m_iR = 0;

		m_circ.push_back(circle);
	}

	m_bRed = m_bBlue = m_bGreen = false;
	m_bFirstThick = m_bSecondThick = m_bThirdThick = m_bStop = false;

	return TRUE;
}


// Сериализация CSDItDoc

void CSDItDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CSDItDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CSDItDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CSDItDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CSDItDoc

#ifdef _DEBUG
void CSDItDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDItDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CSDItDoc

void CSDItDoc::OnOptionsStop()
{
	m_bStop = !m_bStop;
}


void CSDItDoc::OnUpdateOptionsStop(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bStop);
}

void CSDItDoc::OnOptionsColor()
{
	if (!m_ColorDlg)
	{
		m_ColorDlg.Create(IDD_DLG_COLOR, AfxGetMainWnd());
		m_ColorDlg.m_pDoc = this;
	}

	m_ColorDlg.m_colorButton.SetColor(m_circ[0].m_color);

	m_ColorDlg.ShowWindow(SW_SHOW);
}

void CSDItDoc::OnOptionsThickness()
{
	CThicknessDlg dlg;

	dlg.m_iValue = m_iThickness;

	if(dlg.DoModal() == IDOK)
		m_iThickness = dlg.m_iValue;

	for (int i = 0; i <= m_num; i++)
		m_circ[i].m_bThick = m_iThickness;
}
