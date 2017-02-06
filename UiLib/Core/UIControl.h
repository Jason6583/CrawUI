#ifndef __UICONTROL_H__
#define __UICONTROL_H__

#pragma once
#include "Utils/DuiReflection.h"

namespace UiLib {

/////////////////////////////////////////////////////////////////////////////////////
//

	typedef struct tagActionPropertys
	{
		CDuiString nAGroupName;
		CTimerSource nActionTimers;
		TAGroup* pTAGroup;
	}TActionProperty;

typedef CControlUI* (CALLBACK* FINDCONTROLPROC)(CControlUI*, LPVOID);

typedef enum 
{
	INSETFLAG_HEAD = 0,
	INSETFLAG_TAIL = 1,
	INSETFLAG_SORT = 2
}eInsertFlag;

class UILIB_API CControlUI
{
public:
    CControlUI();
    virtual ~CControlUI();
	void RemoveAllActionNotifys();

public:
    virtual CDuiString GetName() const;
    virtual void SetName(LPCTSTR pstrName);
    virtual LPCTSTR GetClass() const;
    virtual LPVOID GetInterface(LPCTSTR pstrName);
    virtual UINT GetControlFlags() const;

    virtual bool Activate();
    virtual CPaintManagerUI* GetManager() const;
    virtual void SetManager(CPaintManagerUI* pManager, CControlUI* pParent, bool bInit = true);
    virtual CControlUI* GetParent() const;
	virtual CControlUI *GetParentByName(CDuiString pstrName);
	virtual CControlUI* GetParentByClass(CDuiString pstrClass);
    // �ı����
    virtual CDuiString GetText() const;
    virtual void SetText(LPCTSTR pstrText);

    // ͼ�����
    DWORD GetBkColor() const;
    void SetBkColor(DWORD dwBackColor);
    DWORD GetBkColor2() const;
    void SetBkColor2(DWORD dwBackColor);
    DWORD GetBkColor3() const;
    void SetBkColor3(DWORD dwBackColor);
	void SetDisabledBkColor(DWORD dwDisabledBkColor);
	DWORD GetDisabledBkColor() const;
    CDuiString GetBkImage();
    void SetBkImage(LPCTSTR pStrImage);
	void SetBkImage(LPCTSTR pStrImage ,HBITMAP hBitmap,int nWidth,int nHeight,bool bForceReplace = false);
	LPCTSTR GetDisableBkImage();
	void SetDisableBkImage(LPCTSTR pStrImage);

    DWORD GetBorderColor() const;
    void SetBorderColor(DWORD dwBorderColor);
	DWORD GetFocusBorderColor() const;
	void SetFocusBorderColor(DWORD dwBorderColor,int nSize = -1);
	void SetHotBorderColor(DWORD dwBorderColor,int nSize= -1);
    bool IsColorHSL() const;
    void SetColorHSL(bool bColorHSL);
    int GetBorderSize() const;
    void SetBorderSize(int nSize);
	void SetBorderSize(RECT rc);
	int GetBorderStyle() const;
	void SetBorderStyle(int nStyle);
    SIZE GetBorderRound() const;
    void SetBorderRound(SIZE cxyRound);
	int GetLeftBorderSize() const;
	void SetLeftBorderSize(int nSize);
	int GetTopBorderSize() const;
	void SetTopBorderSize(int nSize);
	int GetRightBorderSize() const;
	void SetRightBorderSize(int nSize);
	int GetBottomBorderSize() const;
	void SetBottomBorderSize(int nSize);
	void SetIrregion(bool bIrregion);
	bool DrawImage(CDuiImage& pStrImage, bool bNeedAlpha = FALSE, BYTE bNewFade = 255);
	bool DrawImage(CDuiImage& pStrImage,RECT& rcModify, bool bNeedAlpha = FALSE, BYTE bNewFade = 255);

    // λ�����
    virtual const RECT& GetPos() const;
    virtual void SetPos(RECT rc);
    virtual int GetWidth() const;
    virtual int GetHeight() const;
    virtual int GetX() const;
    virtual int GetY() const;
    virtual RECT GetPadding() const;
    virtual void SetPadding(RECT rcPadding); // ������߾࣬���ϲ㴰�ڻ���
    virtual SIZE GetFixedXY() const;         // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
    virtual void SetFixedXY(SIZE szXY);      // ��floatΪtrueʱ��Ч
    virtual int GetFixedWidth() const;       // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
    virtual void SetFixedWidth(int cx);      // Ԥ��Ĳο�ֵ
    virtual int GetFixedHeight() const;      // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
    virtual void SetFixedHeight(int cy);     // Ԥ��Ĳο�ֵ
	virtual int GetGrownWidth() const;
	virtual void SetGrownWidth(int cx);
	virtual int GetGrownHeight() const;
	virtual void SetGrownHeight(int cy);
    virtual int GetMinWidth() const;
    virtual void SetMinWidth(int cx);
    virtual int GetMaxWidth() const;
    virtual void SetMaxWidth(int cx);
    virtual int GetMinHeight() const;
    virtual void SetMinHeight(int cy);
    virtual int GetMaxHeight() const;
    virtual void SetMaxHeight(int cy);
    virtual void SetRelativePos(SIZE szMove,SIZE szZoom);
    virtual void SetRelativeParentSize(SIZE sz);
    virtual TRelativePosUI GetRelativePos() const;
    virtual bool IsRelativePos() const;
	
    // �����ʾ
    virtual CDuiString GetToolTip() const;
    virtual void SetToolTip(LPCTSTR pstrText);
	virtual void SetToolTipWidth(int nWidth);
	virtual int GetToolTipWidth();

    // ��ݼ�
    virtual TCHAR GetShortcut() const;
    virtual void SetShortcut(TCHAR ch);

	//����س�
	DWORD IsWantTab() const;
	DWORD IsWantCursor() const;
	DWORD IsWantReturn() const;
	DWORD IsWantCapture() const;

	void SetWantCapture(bool bWant);
	void SetWantTab(bool bWant);
	void SetWantCursor(bool bWant);
	void SetWantReturn(bool bWant);

	//��������
	CDuiString GetNextTabSibling();
	void SetNextTabSibling(LPCTSTR pstrText);
	CDuiString GetPrevTabSibline();
	void SetPrevTabSibling(LPCTSTR pstrText);

	//��ӦIDOK;
	virtual bool OnIDOK(TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam);

    // �˵�
    virtual bool IsContextMenuUsed() const;
    virtual void SetContextMenuUsed(bool bMenuUsed);

    // �û�����
    virtual const CDuiString& GetUserData(); // �������������û�ʹ��
    virtual void SetUserData(LPCTSTR pstrText); // �������������û�ʹ��
    virtual UINT_PTR GetTag() const; // �������������û�ʹ��
    virtual void SetTag(UINT_PTR pTag); // �������������û�ʹ��

    // һЩ��Ҫ������
    virtual bool IsVisible() const;
    virtual void SetVisible(bool bVisible = true);
    virtual void SetInternVisible(bool bVisible = true); // �����ڲ����ã���ЩUIӵ�д��ھ������Ҫ��д�˺���
    virtual bool IsEnabled() const;
	virtual bool IsRandom() const;
    virtual void SetEnabled(bool bEnable = true);
    virtual void SetRandom(bool bRandom = true);
    virtual bool IsMouseEnabled() const;
    virtual void SetMouseEnabled(bool bEnable = true);
    virtual bool IsKeyboardEnabled() const;
    virtual void SetKeyboardEnabled(bool bEnable = true);
    virtual bool IsFocused() const;
	virtual bool IsHovered() const;
    virtual void SetFocus();
    virtual bool IsFloat() const;
    virtual void SetFloat(bool bFloat = true);
	virtual bool IsLeadUp() const;
	virtual void SetLeadUp(bool bLeadUp = true);
	virtual bool IsTextGlow() const;
	virtual void SetTextGlow(bool bTextGlow = true);
	virtual const CDuiString& GetStyleName();
	virtual void SetStyleName(LPCTSTR pStrStyleName,CPaintManagerUI* pm = NULL);
	virtual void SetAction(LPCTSTR pActonName,CPaintManagerUI* pm = NULL);
	virtual void OnPropertyActionTimer(IDuiTimer* pTimer,TProperty* pTProperty);
	virtual void OnPropertyActionTimer(IDuiTimer* pTimer,HWND hWnd,TProperty* pTProperty,WPARAM _wParam);
	virtual void OnGroupActionTimer(IDuiTimer* pTimer,TAGroup* pTAGroup);
	virtual void OnGroupActionTimer(IDuiTimer* pTimer,HWND hWnd,TAGroup* pTAGroup,WPARAM _wParam);
	virtual bool OnAGroupNotify(TNotifyUI* pTNotifyUI,TAGroup* pTAGroup,WPARAM wParam);
	virtual bool OnAGroupEvent(TEventUI* pTEventUI,TAGroup* pTAGroup,WPARAM wParam);

	virtual bool OnAnimateTimerTick(TimeEvent *pEvent);
	virtual bool OnAnimateStart(TimeEvent *pEvent);
	virtual bool OnAnimateStep(TimeEvent *pEvent);
	virtual bool OnAnimateComplete(TimeEvent *pEvent);
	virtual bool OnAnimateEnd(TimeEvent *pEvent);

    virtual CControlUI* FindControl(FINDCONTROLPROC Proc, LPVOID pData, UINT uFlags);

    void Invalidate();
    bool IsUpdateNeeded() const;
    virtual void NeedUpdate();
    void NeedParentUpdate();
    DWORD GetAdjustColor(DWORD dwColor);

	bool IsInited();
    virtual void Init();
    virtual void DoInit();

    virtual void Event(TEventUI& event);
    virtual void DoEvent(TEventUI& event);

	virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
	virtual unUserData GetAttribute(LPCTSTR pstrName);
    CControlUI* ApplyAttributeList(LPCTSTR pstrList);

	virtual SIZE EstimateNeedSize();
    virtual SIZE EstimateSize(SIZE szAvailable);

	virtual HBITMAP GetSnapBmp(int &nWidth,int &nHeight,int &nPitch,bool bUpdate = false);
	virtual BYTE * SnapShot(int &nWidth,int &nHeight,int &nPitch);
	virtual void DoPaintWithOutClip(const RECT& rcPaint);
    virtual void DoPaint(const RECT& rcPaint);
    virtual void PaintBkColor();
    virtual void PaintBkImage();
    virtual void PaintStatusImage();
    virtual void PaintText();
	virtual void PaintBorder();

    virtual void DoPostPaint(const RECT& rcPaint);

	//���ⴰ�ڲ���
	void SetVirtualWnd(LPCTSTR pstrValue);
	CDuiString GetVirtualWnd() const;
	// ���ò�������
	void	SetInsertFlag(eInsertFlag flag);
	eInsertFlag GetInsertFlag();
	// ȡ�ؼ�ͼƬ��͸��ɫ����
	void GetRegion(CDuiImage& pStrImage, COLORREF dwColorKey);

#ifdef UILIB_D3D
	virtual CDuiString GetEffectStyle() const;
	virtual void SetAnimEffects(bool bEnableEffect);
	virtual bool GetAnimEffects() const;
	virtual void SetEffectsZoom(int iZoom);
	virtual int  GetEffectsZoom() const;
	virtual void SetEffectsFillingBK(DWORD dFillingBK);
	virtual DWORD GetEffectsFillingBK() const;
	virtual void SetEffectsOffectX(int iOffectX);
	virtual int  GetEffectsOffectX() const;
	virtual void SetEffectsOffectY(int iOffectY);
	virtual int  GetEffectsOffectY() const;
	virtual void SetEffectsAlpha(int iAlpha);
	virtual int  GetEffectsAlpha() const;
	virtual void SetEffectsRotation(float fRotation);
	virtual float GetEffectsRotation();
	virtual void SetEffectsNeedTimer(int iNeedTimer);
	virtual int  GetEffectsNeedTimer();

	virtual TEffectAge* GetCurEffects();
	virtual TEffectAge* GetMouseInEffect();
	virtual TEffectAge* GetMouseOutEffect();
	virtual TEffectAge* GetClickInEffect();

	virtual void TriggerEffects(TEffectAge* pTEffectAge = NULL);
	virtual void SetEffectsStyle(LPCTSTR pstrEffectStyle,TEffectAge* pTEffectAge = NULL);
	void AnyEffectsAdvProfiles(LPCTSTR pstrEffects,TEffectAge* pTEffectAge = NULL);
	void AnyEasyEffectsPorfiles(LPCTSTR pstrEffects,TEffectAge* pTEffectAge = NULL);

	bool AddAnimationJob( const CDxAnimationUI& _DxAnimationUI );
private:
	bool		m_bEnabledEffect;
	CDuiString	m_strEffectStyle;
	
	TEffectAge	m_tCurEffects;
	TEffectAge m_tMouseInEffects;
	TEffectAge m_tMouseOutEffects;
	TEffectAge m_tMouseClickEffects;
#endif UILIB_D3D

public:
    CEventSource OnInit;
    CEventSource OnDestroy;
    CEventSource OnSize;
    CEventSource OnEvent;
    CEventSource OnNotify;
	CTimerSource OnTimers;

public:
	TActionProperty* pCurTActionProperty;
	TStdStringPtrMap<TActionProperty*> mActionNotifys;

protected:
    CPaintManagerUI* m_pManager;
	CStoryBoard *m_pStoryBoard;
    CControlUI* m_pParent;
	CDuiString m_sVirtualWnd;
    CDuiString m_sName;
    bool m_bUpdateNeeded;
    bool m_bMenuUsed;
	HRGN m_hRgn;			//�����ò���������ʱ���˱�������ö��������
    RECT m_rcItem;
    RECT m_rcPadding;
    SIZE m_cXY;
    SIZE m_cxyFixed;
	SIZE m_cxyGrown;
    SIZE m_cxyMin;
    SIZE m_cxyMax;
    bool m_bVisible;
    bool m_bInternVisible;
    bool m_bEnabled;
	bool m_bRandom;			// Is Tool random?
	bool m_bGetRegion;		//�Ƿ�ˢ��������Ϣ
    bool m_bMouseEnabled;
	bool m_bKeyboardEnabled ;
    bool m_bFocused;
    bool m_bFloat;
	bool m_bLeadUp;
	bool m_bTextGlow;
	bool m_bHover;
    bool m_bSetPos; // ��ֹSetPosѭ������
	bool m_bSqueeze;
	bool m_bInited;
	bool m_bNeedCapture;
	bool m_bNeedRet;
	bool m_bNeedTab;
	bool m_bNeedCursor;

    TRelativePosUI m_tRelativePos;
	
	CDuiString m_sNxtTabSibling;
	CDuiString m_sPrvTabSibling;

	CDuiString m_sStyleName;
    CDuiString m_sText;
    CDuiString m_sToolTip;
    TCHAR m_chShortcut;
    CDuiString m_sUserData;
    UINT_PTR m_pTag;

    DWORD m_dwBackColor;
    DWORD m_dwBackColor2;
	DWORD m_dwBackColor3;
	DWORD m_dwDisabledBkColor;
    CDuiImage m_sBkImage;
	CDuiImage m_sDisableBkImage;
	CDuiImage m_sForeImage;
    DWORD m_dwBorderColor;
	DWORD m_dwFocusBorderColor;
	DWORD m_dwHotBorderColor;
    bool m_bColorHSL;
	int m_nHotBorderSize;
	int m_nFocusBorderSize;
    int m_nBorderSize;
	int m_nBorderStyle;
    SIZE m_cxyBorderRound;
    RECT m_rcPaint;
	RECT m_rcBorderSize;
	int m_nTooltipWidth;

	BYTE *m_pBkImgStream;
	HBITMAP m_hSnapBmp;
	eInsertFlag m_eInsertFlag;
};
} // namespace UiLib

#endif // __UICONTROL_H__
