#ifndef __UITABCTRL_H__
#define __UITABCTRL_H__

#pragma once

namespace UiLib
{

//////////////////////////////////////////////////////////////////////////
//
	class CTabBodyUI;

	class UILIB_API CTabUI : public CHorizontalLayoutUI
	{
	public:
		CTabUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		void PaintBkColor();
		void PaintBkImage();
		void DoEvent(TEventUI& event);

		bool Add(CControlUI* pControl);
		bool AddAt(CControlUI* pControl, int iIndex);
		bool Remove(CControlUI* pControl);
		void RemoveAll(bool bUpdate = true);
		int GetCurSel() const;
		bool SelectItem(int iIndex);
		bool SelectItem(CControlUI* pControl);
		CControlUI* GetItemAt(int iIndex) const;
		int	GetItemIndex(CControlUI* pControl) const;
		int GetCount() const;

		void SetPos(RECT rc);

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		//�����ٶ�
		int GetScrollSpeed();
		void SetScrollSpeed(int nSpeed);

		//��ť���
		int GetBtnInterval();
		void SetBtnInterval(int nInterval);

		//Tab���
		int GetInterval();
		void SetInterval(int nInterval);

		//��ఴťͼ��
		LPCTSTR GetLNoramlImage();
		void SetLNormalImage(LPCTSTR pstrName);
		LPCTSTR GetLForeImage();
		void SetLForeImage(LPCTSTR pstrName);
		LPCTSTR GetLHotImage();
		void SetLHotImage(LPCTSTR pstrName);
		LPCTSTR GetLHotForeImage();
		void SetLHotForeImage(LPCTSTR pstrName);
		LPCTSTR GetLPushedImage();
		void SetLPushedImage(LPCTSTR pstrName);
		LPCTSTR GetLPushedForeImage();
		void SetLPushedForeImage(LPCTSTR pstrName);
		LPCTSTR GetLFocusedImage();
		void SetLFocusedImage(LPCTSTR pstrName);
		LPCTSTR GetLDisabledImage();
		void SetLDisabledImage(LPCTSTR pstrName);

		//�Ҳఴťͼ��
		LPCTSTR GetRNoramlImage();
		void SetRNormalImage(LPCTSTR pstrName);
		LPCTSTR GetRForeImage();
		void SetRForeImage(LPCTSTR pstrName);
		LPCTSTR GetRHotImage();
		void SetRHotImage(LPCTSTR pstrName);
		LPCTSTR GetRHotForeImage();
		void SetRHotForeImage(LPCTSTR pstrName);
		LPCTSTR GetRPushedImage();
		void SetRPushedImage(LPCTSTR pstrName);
		LPCTSTR GetRPushedForeImage();
		void SetRPushedForeImage(LPCTSTR pstrName);
		LPCTSTR GetRFocusedImage();
		void SetRFocusedImage(LPCTSTR pstrName);
		LPCTSTR GetRDisabledImage();
		void SetRDisabledImage(LPCTSTR pstrName);

		//�õ�Tab����ص�URL
		CDuiString GetItemUrl(int nIndex);
		//����Tab����ص�URL
		void SetItemUrl(int nIndex, LPCTSTR lpszUrl);

		//�õ�Tab����ص�Text
		CDuiString GetItemText(int nIndex);
		//����Tab����ص�Text
		void SetItemText(int nIndex, LPCTSTR lpszText);

		//�õ�Tab����ص�ForeImage
		LPCTSTR GetItemForeImage(int nIndex);
		//����Tab����ص�ForeImage
		void SetItemForeImage(int nIndex, LPCTSTR pstrName);

	protected:
		//�õ�������Ŀ�ĳ���
		int GetItemsLength();
		//�Ƿ���ʾ��ఴť
		BOOL IsShowLBtn();
		//�Ƿ���ʾ�Ҳఴť
		BOOL IsShowRBtn();
		//�����
		void ScrollLeft();
		//�ҹ���
		void ScrollRight();
		//������ť
		void DrawLButton();
		//�����Ұ�ť
		void DrawRButton();
		//������ťͼ��
		void DrawLButtonImage();
		//�����Ұ�ťͼ��
		void DrawRButtonImage();
		//�õ�ͼ���ļ�
		void GetImageFileName(LPCTSTR pstrName, TCHAR* pstrRes);
		//�õ�ĳ��Ŀɼ�״̬ = 0 ��ȫ�ɼ� = 1 ���ֿɼ� = 2 �����߽����� = 3 �Ҳ���߽����� = 4 ��ȫ���ɼ� = -1 �����ڸÿؼ�
		int GetItemVisible(int nIndex);

	protected:
		int				m_iCurSel;				//��ǰѡ��������
		int				m_nSpeed;				//���������ٶ�
		int				m_nBtnInterval;			//��ť���
		RECT			m_rcLBtn;				//��������ť����
		RECT			m_rcRBtn;				//�Ҳ������ť����
		DWORD			m_uLBtnState;			//��������ť״̬
		DWORD			m_uRBtnState;			//�Ҳ������ť״̬
		CTabBodyUI*		m_pTabList;				//TabItem����

		CDuiImage		m_sLNormalImage;		//��ťNormalͼ��
		CDuiImage		m_sLForeImage;			//��ťNormalǰ��ͼ��
		CDuiImage		m_sLHotImage;			//��ťHoverͼ��
		CDuiImage		m_sLHotForeImage;		//��ťHoverǰ��ͼ��
		CDuiImage		m_sLPushedImage;		//��ťPushͼ��
		CDuiImage		m_sLPushedForeImage;	//��ťPushǰ��ͼ��
		CDuiImage		m_sLFocusedImage;		//��ťFocusͼ��
		CDuiImage		m_sLDisabledImage;		//��ťDisableͼ��

		CDuiImage		m_sRNormalImage;		//�Ұ�ťNormalͼ��
		CDuiImage		m_sRForeImage;			//�Ұ�ťNormalǰ��ͼ��
		CDuiImage		m_sRHotImage;			//�Ұ�ťHoverͼ��
		CDuiImage		m_sRHotForeImage;		//�Ұ�ťHoverǰ��ͼ��
		CDuiImage		m_sRPushedImage;		//�Ұ�ťPushͼ��
		CDuiImage		m_sRPushedForeImage;	//�Ұ�ťPushǰ��ͼ��
		CDuiImage		m_sRFocusedImage;		//�Ұ�ťFocusͼ��
		CDuiImage		m_sRDisabledImage;		//�Ұ�ťDisableͼ��
	};

	/////////////////////////////////////////////////////////////////////////////////////
	//

	class UILIB_API CTabBodyUI : public CHorizontalLayoutUI
	{
	public:
		CTabBodyUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
	};

	/////////////////////////////////////////////////////////////////////////////////////
	//

	class UILIB_API CTabItemUI : public COptionUI
	{
	public:
		CTabItemUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		CDuiString GetUrl() {return m_sUrl;};
		void SetUrl(LPCTSTR lpszUrl) {m_sUrl = lpszUrl;};

		void Selected(bool bSelected);

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	private:
		CDuiString	m_sUrl;
	};
}
#endif // __UITABLAYOUT_H__
