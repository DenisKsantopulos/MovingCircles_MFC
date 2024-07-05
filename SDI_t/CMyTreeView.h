#pragma once

#include <afxcview.h>
// Просмотр CMyTreeView

class CSDItDoc;

class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTreeView();

public:
	HTREEITEM m_hColor, m_hRed, m_hBlue, m_hGreen;

	HTREEITEM m_hThick, m_hFirstThick, m_hSecondThick, m_hThirdThick;

	void FillTree();

	CSDItDoc* m_pDoc;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


