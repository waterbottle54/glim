
// MFCStartDlg.h: 헤더 파일
//

#pragma once


// CMFCStartDlg 대화 상자
class CMFCStartDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCStartDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSTART_DIALOG };
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
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickedLogo();
	afx_msg void OnEnChangeStartX();
	afx_msg void OnEnChangeStartY();
	afx_msg void OnEnChangeEndX();
	afx_msg void OnEnChangeEndY();
	afx_msg void OnBnClickedButtonDraw();
	afx_msg void OnBnClickedButtonAction();
	afx_msg void OnBnClickedButtonOpen();
};
