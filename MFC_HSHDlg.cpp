
// MFC_HSHDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_HSH.h"
#include "MFC_HSHDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
#include <math.h>


int nSumX = 0;
int nSumY = 0;
int nCount = 0;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCHSHDlg 대화 상자



CMFCHSHDlg::CMFCHSHDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_HSH_DIALOG, pParent)
	, nNUM(0)
	, nNum2(0)
	, nNum3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCHSHDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_NUM, nNUM);
	DDX_Text(pDX, IDC_EDT_NUM2, nNum2);
	DDX_Text(pDX, IDC_EDT_NUM3, nNum3);
	DDX_Control(pDX, IDCANCEL, nStatic);
}

BEGIN_MESSAGE_MAP(CMFCHSHDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CIR, &CMFCHSHDlg::OnBnClickedBtnCir)
	ON_EN_CHANGE(IDC_EDT_NUM, &CMFCHSHDlg::OnEnChangeEdtNum)
	ON_EN_CHANGE(IDC_EDT_NUM2, &CMFCHSHDlg::OnEnChangeEdtNum2)
	ON_BN_CLICKED(IDC_BTN_CIR2, &CMFCHSHDlg::OnBnClickedBtnCir2)
END_MESSAGE_MAP()


// CMFCHSHDlg 메시지 처리기

BOOL CMFCHSHDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCHSHDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCHSHDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCHSHDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCHSHDlg::OnBnClickedBtnCir()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int nWidth = 640;
	int nHeight = -480;
	int nBPP = 8;


	m_image.Create(nWidth, nHeight, nBPP);
	if (nBPP == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			m_image.SetColorTable(0, 256, rgb);
		}
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			fm[j * nPitch + i] = 0;
		}
	}

	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			fm[j * nPitch + i] = 0;
		}
	}

	
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);


}

void CMFCHSHDlg::drawCircle(int x, int y, int nRadius, int nColor) {
	
	
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();


	memset(fm, 0, nWidth * nHeight);


	for (int j = x; j < x+ nRadius * 2; j++) {
		for (int i = y; i < y+nRadius * 2; i++) {
			if (isinCircle(j, i, nCenterX, nCenterY, nRadius))
				fm[j * nPitch + i] = nColor;
		}
	}



	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}
void CMFCHSHDlg::drawCircle2(int x, int y, int nRadius, int nColor) {
	
	
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	for (int j = x; j < x + nRadius * 2; j++) {
		for (int i = y; i < y + nRadius * 2; i++) {
			if (isinCircle2(j, i, nCenterX, nCenterY, nRadius))
				fm[j * nPitch + i] = 255;
			
			for (int q = -10; q < 10; q++) {
				fm[(nCenterX+ q) * nPitch + nCenterY] = 255;
			}

			for (int w = -10; w < 10; w++) {
				fm[(nCenterX ) * nPitch + (nCenterY+w)] = 255;
			}
			
		}
	}


	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}


bool CMFCHSHDlg::isinCircle(int i, int j, int nCenterX, int nCenterY, int nRadius) {
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}

bool CMFCHSHDlg::isinCircle2(int i, int j, int nCenterX, int nCenterY, int nRadius) {
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist >= nRadius * nRadius) {
		{if (dDist <= (nRadius * nRadius) + nRadius*2)
			bRet = true;
		}
	}

	

	return bRet;
}



void CMFCHSHDlg::drawData()
{

	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();


	int n_Width = GetDlgItemInt(IDC_EDT_NUM);
	int n_Height = GetDlgItemInt(IDC_EDT_NUM);

	int x = (rand() % 300)  ;
	int y = (rand() % 300) ;

	CRect rect(x, y, n_Width, n_Height);

	UpdateData(true);

	unsigned char* fm = (unsigned char*)m_image.GetBits();


	int nTh = 0x80;
	

	for (int q = rect.top; q < rect.bottom; q++) {
		for (int w = rect.left; w < rect.right; w++) {
			if (fm[q * nPitch + w] < nTh) {
				nSumX += w;
				nSumY += q;
				nCount++;
			}
		}
	}

	double dCenterX = (double)nSumX / nCount;

	double dCenterY = (double)nSumY / nCount;

	

	drawCircle(x, y, n_Width/2, nGray);
	drawCircle2(x, y, n_Width/2, 255);
	
	

	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);

	
	
	nNum2 = dCenterX;
	nNum3 = dCenterY;

	UpdateData(false);

}

void CMFCHSHDlg::OnEnChangeEdtNum()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.


}


void CMFCHSHDlg::OnEnChangeEdtNum2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCHSHDlg::OnBnClickedBtnCir2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	drawData();
}
