// CDetectDialog.cpp: 구현 파일
//

#include "pch.h"
#include "MFCStart.h"
#include "afxdialogex.h"
#include "CDetectDialog.h"

using namespace cv;

// CDetectDialog 대화 상자

IMPLEMENT_DYNAMIC(CDetectDialog, CDialogEx)

CDetectDialog::CDetectDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DETECT, pParent)
{

}

CDetectDialog::~CDetectDialog()
{
}

void CDetectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGE_STATIC, m_imageCtrl);
}


BEGIN_MESSAGE_MAP(CDetectDialog, CDialogEx)
END_MESSAGE_MAP()


// CDetectDialog 메시지 처리기

void CDetectDialog::OnPaint()
{
    CPaintDC dc(this);

    if (!m_imagePath.IsEmpty())
    {
        cv::Mat img = cv::imread(std::string(CT2A(m_imagePath)));
        if (!img.empty())
        {
            // grayscale 로 변환
            Mat gray;
            cvtColor(img, gray, COLOR_BGR2GRAY);

            // threshold 기준으로 binarization
            Mat binary;
            threshold(gray, binary, 100, 255, THRESH_BINARY);

            // momments 계산
            Moments _moments = moments(binary, true);

            // 질량중심
            double m10 = _moments.m10;
            double m01 = _moments.m01;
            double area = _moments.m00;

            if (area != 0)
            {
                // 중심 좌표 획득
                int cx = static_cast<int>(m10 / area);
                int cy = static_cast<int>(m01 / area);

                // 적색 점으로 좌표 표시
                circle(img, Point(cx, cy), 5, Scalar(0, 0, 255), -1);

                // 좌표값 텍스트 표시
                std::string text = "Centroid: (" + std::to_string(cx) + ", " + std::to_string(cy) + ")";
                putText(img, text, Point(cx + 10, cy - 10), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0), 2);
            }

            // CImage로 변환
            cvtColor(img, img, COLOR_BGR2RGB);

            CImage cimg;
            cimg.Create(img.cols, img.rows, 24);
            for (int y = 0; y < img.rows; y++)
            {
                memcpy(cimg.GetPixelAddress(0, y), img.ptr(y), img.cols * 3);
            }

            // Static 컨트롤에 이미지 그리기
            CRect rect;
            m_imageCtrl.GetWindowRect(&rect);
            ScreenToClient(&rect);

            CDC* pDC = m_imageCtrl.GetDC();
            cimg.Draw(pDC->m_hDC, rect);
            m_imageCtrl.ReleaseDC(pDC);
        }
        else
        {
            AfxMessageBox(_T("Failed to load image."));
        }
    }
}