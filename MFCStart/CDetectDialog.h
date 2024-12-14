#pragma once
#include "afxdialogex.h"
#include <opencv2/opencv.hpp>


// CDetectDialog 대화 상자

class CDetectDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDetectDialog)

public:
	CDetectDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDetectDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DETECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CString m_imagePath;  // Image path to load

protected:
	CStatic m_imageCtrl;  // Static control

	afx_msg void OnPaint();
};
