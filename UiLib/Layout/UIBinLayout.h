#ifndef __UIBINLAYOUT_H__
#define __UIBINLAYOUT_H__

#pragma once

namespace UiLib
{

typedef struct 
{
	CControlUI* pControl;
	RECT	rcCellPos;		// �ؼ�դ��λ��
} CONTROLCELLPOS;

class  UILIB_API CBinLayoutUI :public CContainerUI
{
public:

public:
	CBinLayoutUI(void);
	virtual ~CBinLayoutUI(void){};
	virtual LPCTSTR GetClass() const;
	virtual LPVOID GetInterface(LPCTSTR pstrName);
	virtual void SetPos(RECT rc);
	virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
	virtual void DoPaint(const RECT& rcPaint);

	virtual int GetCount() const;
	virtual bool Remove(CControlUI* pControl);
	virtual void RemoveAll(bool bUpdate = true);
	virtual CControlUI* GetItemAt(int iIndex) const;

public:
	int GetBinWidth() ;
	void SetBinWidth(int nBinWidth,BOOL bAutoWidth = FALSE);
	int GetBinHeight() ;
	void SetBinHeight(int nBinWidth,BOOL bAutoHeight = FALSE);
	SIZE GetCellSize() const;
	void SetCellSize(SIZE szCell);
	int	 GetCellPadding();
	void SetCellPadding(int nCellPadding);
	BOOL GetAutoCell();
	void SetAutoCell(BOOL bAutoCell);
	BOOL GetAutoArrange();
	void SetAutoArrange(BOOL bAutoArrange);

	BOOL GetShowCellLine();
	void SetShowCellLine(BOOL bShowCellLine);
public:
	// ��¼�ؼ�դ��λ��
	// ���ؿɿ��ƿؼ��б����˳�� 
	virtual void SetControlCellPos(CControlUI* pControl,RECT& rcCellPos,BASEVALUECOMPFUNC pCompFunc = NULL);
	// ��ȡ�ռ�դ��λ��
	CONTROLCELLPOS* GetControlCellPos(int nIndex);
	//��ȡ�ؼ�λ��
	RECT GetControlPos(CONTROLCELLPOS& cellPos);
	// ���������ȡդ������
	POINT	PtInCell(POINT& pt);
	// ����������ȡ����
	RECT	GetCellRange(POINT& pt, SIZE szSize);
	// ָ�������Ƿ�� �����б���
	virtual BOOL  HitTest(POINT& ptLeftTop,SIZE szSize);
	// ָ��դ���ϵĿؼ�
	CControlUI* GetControl(POINT& ptCell,BASEVALUECOMPFUNC pCompFunc = NULL);
	// ��ȡ�ƶ�λ���ٽ��ؼ� 
	CControlUI* GetAdjacentControl(POINT& ptCell,BASEVALUECOMPFUNC pCompFunc);
	// ɾ����
	void RemoveAllItem(BOOL bDelete = TRUE);

public:
	// ��ȡָ���ؼ�������
	int GetControlIndex(CControlUI* pControl);
	// ��ȡָ��դ�������Ͽؼ�������   ptΪդ������
	int	GetControlIndexFromCell(POINT pt);
protected:
	SIZE		m_szCell;			// դ���С
	//SIZE		m_szInterval;		// դ�����ϼ��
	int			m_nCellPadding;		// դ����
	int			m_nBinWidth;		// Bin���		��λ:դ��
	int			m_nBinHeight;		// Bin�߶�		��λ:դ��
	BOOL		m_bAutoCell;		// ���ݴ��ڴ�С����Bin�Ŀ�Ⱥ͸߶�
	BOOL		m_bAutoArrange;		// �Ƿ��Զ�����
	BOOL		m_bShowCellLine;	// �Ƿ���ʾդ����
	DWORD		m_dwCellLineColor;	// դ������ɫ
	CStdValArray m_aControlCellPos;		// �ؼ�λ��
};

}
#endif // __UIBINLAYOUT_H__