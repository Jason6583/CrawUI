#ifndef __UIDLGBUILDER_H__
#define __UIDLGBUILDER_H__

#pragma once

namespace UiLib {

class IDialogBuilderCallback
{
public:
    virtual CControlUI* CreateControl(LPCTSTR pstrClass,CPaintManagerUI* pManager = NULL) = 0;
};


class UILIB_API CDialogBuilder
{
public:
    CDialogBuilder();
	~CDialogBuilder();
    CControlUI* Create(STRINGorID xml, LPCTSTR type = NULL, IDialogBuilderCallback* pCallback = NULL,
        CPaintManagerUI* pManager = NULL, CControlUI* pParent = NULL);
    CControlUI* Create(IDialogBuilderCallback* pCallback = NULL, CPaintManagerUI* pManager = NULL,
        CControlUI* pParent = NULL);

    CMarkup* GetMarkup();

	void ParseMultiLanguage(CDuiString xml,CPaintManagerUI* pManager);
    void GetLastErrorMessage(LPTSTR pstrMessage, SIZE_T cchMax) const;
    void GetLastErrorLocation(LPTSTR pstrSource, SIZE_T cchMax) const;
private:
    CControlUI* _Parse(CMarkupNode* parent, CControlUI* pParent = NULL, CPaintManagerUI* pManager = NULL);

    CMarkup m_xml;
    IDialogBuilderCallback* m_pCallback;
    LPCTSTR m_pstrtype;
};

} // namespace UiLib

#endif // __UIDLGBUILDER_H__
