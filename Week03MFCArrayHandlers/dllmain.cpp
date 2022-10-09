// dllmain.cpp : DllMain의 구현입니다.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "Week03MFCArrayHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CWeek03MFCArrayHandlersModule _AtlModule;

class CWeek03MFCArrayHandlersApp : public CWinApp
{
public:

// 재정의
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CWeek03MFCArrayHandlersApp, CWinApp)
END_MESSAGE_MAP()

CWeek03MFCArrayHandlersApp theApp;

BOOL CWeek03MFCArrayHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
	return CWinApp::InitInstance();
}

int CWeek03MFCArrayHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
