
// SDI_t.h: основной файл заголовка для приложения SDI_t
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSDItApp:
// Сведения о реализации этого класса: SDI_t.cpp
//

class CSDItApp : public CWinApp
{
public:
	CSDItApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDItApp theApp;
