#ifndef  __UILISTVIEW_H__
#define __UILISTVIEW_H__

#pragma once
#include "UIList.h"
#include "Layout/UITileLayout.h"

namespace UiLib
{
	class UILIB_API CListViewUI : public CTileLayoutUI ,public IListUI
	{
	public:
		CListViewUI();
		~CListViewUI();
		//��ȡ����;
		virtual LPCTSTR GetClass() const;
		//�ؼ���־λTabStop;
		UINT GetControlFlags() const;
		//��̬ʶ�𷵻�����;
		LPVOID GetInterface(LPCTSTR pstrName);
		//�����Ƿ�Ϊ��ѡ���ѡ;
		void SetSingleSelect(bool bSingleSel);
		bool GetSingleSelect() const;
		void SetMultipleItem(bool bMultipleable);
		bool GetMultipleItem() const;
		//��ȡ��ǰѡ����,����Ƕ�ѡ�򷵻ص�һ��;
		int GetCurSel() const;
		CStdPtrArray GetSelectItems();
		//��ȡ����״̬;
		TListInfoUI* GetListInfo();
		CListHeaderUI* GetHeader() const{return NULL;}
		CContainerUI* GetList() const{return NULL;}
		
		IListCallbackUI* GetTextCallback() const;
		void SetTextCallback(IListCallbackUI* pCallback);

		void SetItemFont(int index);
		void SetItemTextStyle(UINT uStyle);
		void SetItemTextPadding(RECT rc);
		void SetItemTextColor(DWORD dwTextColor);
		void SetItemBkColor(DWORD dwBkColor);
		void SetItemBkImage(LPCTSTR pStrImage);
		void SetAlternateBk(bool bAlternateBk);
		void SetSelectedItemTextColor(DWORD dwTextColor);
		void SetSelectedItemBkColor(DWORD dwBkColor);
		void SetSelectedItemImage(LPCTSTR pStrImage); 
		void SetHotItemTextColor(DWORD dwTextColor);
		void SetHotItemBkColor(DWORD dwBkColor);
		void SetHotItemImage(LPCTSTR pStrImage);
		void SetDisabledItemTextColor(DWORD dwTextColor);
		void SetDisabledItemBkColor(DWORD dwBkColor);
		void SetDisabledItemImage(LPCTSTR pStrImage);
		void SetItemLineColor(DWORD dwLineColor);
		void SetCheckImgSize(SIZE szCheckImg);
		void SetIconImgSize(SIZE szIconImg);
		bool IsItemShowHtml();
		void SetItemShowHtml(bool bShowHtml = true);
		RECT GetItemTextPadding() const;
		DWORD GetItemTextColor() const;
		DWORD GetItemBkColor() const;
		LPCTSTR GetItemBkImage() const;
		bool IsAlternateBk() const;
		DWORD GetSelectedItemTextColor() const;
		DWORD GetSelectedItemBkColor() const;
		LPCTSTR GetSelectedItemImage() const;
		DWORD GetHotItemTextColor() const;
		DWORD GetHotItemBkColor() const;
		LPCTSTR GetHotItemImage() const;
		DWORD GetDisabledItemTextColor() const;
		DWORD GetDisabledItemBkColor() const;
		LPCTSTR GetDisabledItemImage() const;
		DWORD GetItemLineColor() const;
		SIZE GetCheckImgSize() const;
		SIZE GetIconImgSize() const;


		CControlUI* GetItemAt(int iIndex) const;
		int GetItemIndex(CControlUI* pControl) const;
		bool SetItemIndex(CControlUI* pControl, int iIndex);
		bool Add(CControlUI* pControl);
		bool AddAt(CControlUI* pControl, int iIndex);
		bool Remove(CControlUI* pControl);
		bool RemoveAt(int iIndex);
		bool RemoveItems(int iIndex,int iSel);
		void RemoveAll(bool bUpdate = true);
		//ɾ��ѡ����;
		bool RemoveSelectItems();
		//ѡ��ĳһ��;
		virtual bool SelectItem(int iIndex, bool bTakeFocus = false);
		int GetNextSelItem(int nItem) const;
		//��ѡ;
		bool SelectMultiItem(int iIndex, bool bTakeFocus = false);
		//��ѡĳһ��;
		bool UnSelectItem(int iIndex);
		//ѡ������Items;
		virtual void SelectAllItems();
		//��ѡ����Items;
		void UnSelectAllItems();
		//��ȡѡ��������;
		int GetSelectItemCount() const;
		//��Ӧ�ڲ��¼�;
		 void DoEvent(TEventUI& event);
		 
		 void AllowUnSelectAll(bool bAllow = true){m_bUnSelectAll = bAllow;}
		 bool ExpandItem(int iIndex, bool bExpand = true){return true;}
		 int GetExpandedItem() const{return 0;}
	protected:
		int GetMinSelItemIndex();
		int GetMaxSelItemIndex();
	public:
		bool m_bUnSelectAll;
		TListInfoUI m_ListInfo;
		//�Ƿ�ѡ;
		bool m_bSingleSel;
		//��ѡ����Ŀ;
		CStdPtrArray m_aSelItems;
		 IListCallbackUI* m_pCallback;
	};
}
#endif