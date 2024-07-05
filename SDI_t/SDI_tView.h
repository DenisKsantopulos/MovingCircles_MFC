
// SDI_tView.h: интерфейс класса CSDItView
//

#pragma once

#include "SDI_tDoc.h"

class CSDItView : public CView
{
protected: // создать только из сериализации
	CSDItView() noexcept;
	DECLARE_DYNCREATE(CSDItView)

// Атрибуты
public:
	CSDItDoc* GetDocument() const;

	CDC m_cacheDC;
	CBitmap m_cacheCBitmap;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSDItView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnPaint();
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // версия отладки в SDI_tView.cpp
inline CSDItDoc* CSDItView::GetDocument() const
   { return reinterpret_cast<CSDItDoc*>(m_pDocument); }
#endif

