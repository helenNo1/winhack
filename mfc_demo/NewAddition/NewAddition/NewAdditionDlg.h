
// NewAdditionDlg.h : ͷ�ļ�
//

#include "TipDlg.h"
#pragma once


// CNewAdditionDlg �Ի���
class CNewAdditionDlg : public CDialogEx
{
 CTipDlg  *m_pTipDlg;
// ����
public:
	CNewAdditionDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NEWADDITION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double m_editSummand;
	double m_editAddend;
	double m_editSum;
	afx_msg void OnClickedAddButton();
	afx_msg void OnBnClickedInstructButton();
};
