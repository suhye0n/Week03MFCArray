
// Week03MFCArrayView.cpp: CWeek03MFCArrayView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Week03MFCArray.h"
#endif

#include "Week03MFCArrayDoc.h"
#include "Week03MFCArrayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek03MFCArrayView

IMPLEMENT_DYNCREATE(CWeek03MFCArrayView, CView)

BEGIN_MESSAGE_MAP(CWeek03MFCArrayView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CWeek03MFCArrayView 생성/소멸

CWeek03MFCArrayView::CWeek03MFCArrayView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWeek03MFCArrayView::~CWeek03MFCArrayView()
{
}

BOOL CWeek03MFCArrayView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWeek03MFCArrayView 그리기

void CWeek03MFCArrayView::OnDraw(CDC* pDC)
{
	CWeek03MFCArrayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int count = pDoc->GetCount();
	CPoint p;
	for (int i = 0; i < count; i++) {
		p = pDoc->GetPoint(i);
		pDC->Ellipse(p.x - 100, p.y - 100, p.x + 100, p.y + 100);
	}
}


// CWeek03MFCArrayView 인쇄

BOOL CWeek03MFCArrayView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWeek03MFCArrayView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWeek03MFCArrayView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWeek03MFCArrayView 진단

#ifdef _DEBUG
void CWeek03MFCArrayView::AssertValid() const
{
	CView::AssertValid();
}

void CWeek03MFCArrayView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek03MFCArrayDoc* CWeek03MFCArrayView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek03MFCArrayDoc)));
	return (CWeek03MFCArrayDoc*)m_pDocument;
}
#endif //_DEBUG


// CWeek03MFCArrayView 메시지 처리기


void CWeek03MFCArrayView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	GetDocument()->AddPoint(point);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
