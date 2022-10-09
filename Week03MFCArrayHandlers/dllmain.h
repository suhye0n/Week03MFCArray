// dllmain.h : 모듈 클래스의 선언입니다.

class CWeek03MFCArrayHandlersModule : public ATL::CAtlDllModuleT<CWeek03MFCArrayHandlersModule>
{
public :
	DECLARE_LIBID(LIBID_Week03MFCArrayHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_WEEK03MFCARRAYHANDLERS, "{f1198175-66b6-49e4-877f-f7c02edaad54}")
};

extern class CWeek03MFCArrayHandlersModule _AtlModule;
