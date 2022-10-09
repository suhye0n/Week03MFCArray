// FilterHandler.h : 필터 처리기의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include <atlhandler.h>
#include <atlhandlerimpl.h>
#include ".. \Week03MFCArray\Week03MFCArrayDoc.h"
#include "Week03MFCArrayHandlers_i.h"

using namespace ATL;

// CFilterHandler

class ATL_NO_VTABLE CFilterHandler :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CFilterHandler, &CLSID_Search>,
	public CSearchFilterImpl
{
public:
	CFilterHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FILTER_HANDLER)
DECLARE_NOT_AGGREGATABLE(CFilterHandler)

BEGIN_COM_MAP(CFilterHandler)
	COM_INTERFACE_ENTRY(IPersistStream)
	COM_INTERFACE_ENTRY(IPersistFile)
	COM_INTERFACE_ENTRY(IFilter)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		CSearchFilterImpl::FinalRelease();
	}

public:
	// IPersistStream 구현
	IFACEMETHODIMP GetClassID(CLSID* pClassID)
	{
		*pClassID = CLSID_Search;
		return S_OK;
	}

protected:
	DECLARE_DOCUMENT(CWeek03MFCArrayDoc)
};

OBJECT_ENTRY_AUTO(__uuidof(Search), CFilterHandler)
