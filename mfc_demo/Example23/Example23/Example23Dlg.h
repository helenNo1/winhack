
// Example23Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExample23Dlg �Ի���
class CExample23Dlg : public CDialogEx
{
	void InitAllCheckBoxStatus();
// ����
public:
	CExample23Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE23_DIALOG };

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
	CButton m_check1;
	CButton m_check2;
	CButton m_check3;
	CButton m_check4;
	CButton m_check5;
	CButton m_check6;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedOk();
};
