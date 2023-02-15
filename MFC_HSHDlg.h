
// MFC_HSHDlg.h: 헤더 파일
//

#pragma once


// CMFCHSHDlg 대화 상자
class CMFCHSHDlg : public CDialogEx
{
private:
	CImage m_image;

// 생성입니다.
public:
	CMFCHSHDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_HSH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCir();
	void drawCircle(int x, int y, int nRidius, int nColor);
	void drawCircle2(int x, int y, int nRadius, int nColor);
	bool isinCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	bool isinCircle2(int i, int j, int nCenterX, int nCenterY, int nRadius);
	void drawData();
	afx_msg void OnEnChangeEdtNum();
	int nNUM;
	int nNum2;
	int nNum3;
	CButton nStatic;
	afx_msg void OnEnChangeEdtNum2();
	afx_msg void OnBnClickedBtnCir2();
};
