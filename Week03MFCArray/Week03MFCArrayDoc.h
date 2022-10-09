﻿
// Week03MFCArrayDoc.h: CWeek03MFCArrayDoc 클래스의 인터페이스
//


#pragma once

#define MAX_POINTS	10000

class CWeek03MFCArrayDoc : public CDocument
{
protected:
	int Count = 0;
	CPoint Points[MAX_POINTS];
public:
	void AddPoint(CPoint p) {
		if (Count < MAX_POINTS - 1) {
			Points[Count++] = p;
			SetModifiedFlag();
		}
	}
	CPoint GetPoint(int i) { return Points[i]; }
	int GetCount() { return Count; }

protected: // serialization에서만 만들어집니다.
	CWeek03MFCArrayDoc() noexcept;
	DECLARE_DYNCREATE(CWeek03MFCArrayDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CWeek03MFCArrayDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
