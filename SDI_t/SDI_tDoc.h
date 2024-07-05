// SDI_tDoc.h: интерфейс класса CSDItDoc 
//


#include <vector>

#include "MainFrm.h"
#include "CColorDlg.h"

#pragma once

class CMyTreeView;

class CMyCircle
{
public:
	CMyCircle();
	CMyCircle(int x, int y, int r);
	int m_iX = 0, m_iY = 0, m_iR = 0, m_moveX = 0, m_moveY = 0, m_speed = 0;

	int m_bThick = 1;
	COLORREF m_color = RGB(0, 0, 0);

	bool isSpawned = false;

	void Draw(CDC* pDC, CRect rect);
	void setValues(CRect obl);
	void move(CRect obl);
	void changeDirection();
};

class CSDItDoc : public CDocument
{
protected: // создать только из сериализации
	CSDItDoc() noexcept;
	DECLARE_DYNCREATE(CSDItDoc)

// Атрибуты
public:
	int m_num;

	std::vector <CMyCircle> m_circ;

	bool m_bRed, m_bBlue, m_bGreen, m_bStop;
	bool m_bFirstThick, m_bSecondThick, m_bThirdThick;

	int m_iThickness = 1;

	CColorDlg m_ColorDlg;

	CMyTreeView* m_pTreeView;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSDItDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnOptionsStop();
	afx_msg void OnUpdateOptionsStop(CCmdUI* pCmdUI);;
	afx_msg void OnOptionsThickness();
	afx_msg void OnOptionsColor();
};
