#include "StdAfx.h"
#include "MainWnd.h"

#define IDM_SHOW_LOG		WM_USER+2200
#define IDM_EXIT_APP		WM_USER+2300




CMainWnd::CMainWnd(void)
{
	mChartDataPos = 0;
	m_pRichEditWnd = NULL;
} 


CMainWnd::~CMainWnd(void)
{
}

UiLib::CDuiString CMainWnd::GetSkinFile()
{
	try
	{
		return CDuiString(_T("MainSkin.xml"));
	}
	catch (...)
	{
		throw "CMainWnd::GetSkinFile";
	}
}

CDuiString CMainWnd::GetSkinFolder()
{
	return CDuiString(CPaintManagerUI::GetInstancePath()) + _T("Skins\\360\\");
}

LPCTSTR CMainWnd::GetWindowClassName() const
{
	try
	{
		return _T("UiLib_Demos");
	}
	catch (...)
	{
		throw "CMainWnd::GetWindowClassName";
	}
}

LRESULT CMainWnd::HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	try
	{
		if(lParam == WM_RBUTTONUP)
		{
			::SetForegroundWindow(this->m_hWnd);

			hMenu = CreatePopupMenu();
			AppendMenu(hMenu,MF_STRING,IDM_SHOW_LOG,_T("��ʾ��־"));
			AppendMenu(hMenu,MF_STRING,IDM_EXIT_APP,_T("�˳�����"));

			POINT point;
			point.x=LOWORD(lParam);
			point.y=HIWORD(lParam);
			GetCursorPos(&point);
			TrackPopupMenu(hMenu,TPM_RIGHTALIGN,point.x,point.y,0,m_hWnd,NULL);

			::PostMessage(m_hWnd,WM_NULL,0,0);

			return TRUE;
		}
		else if(wParam == IDM_SHOW_LOG || lParam == WM_LBUTTONDBLCLK)
		{
			this->ShowWindow();
			return TRUE;
		}
		else if(wParam == IDM_EXIT_APP)
		{
			Close(IDOK);
			return TRUE;
		}
		else if( uMsg == WM_MOVE || uMsg == WM_SIZE ) 
		{
			if( m_pRichEditWnd )
			{
				RECT rcWnd = {0};
				::GetWindowRect(m_hWnd, &rcWnd);
				::SetWindowPos(m_pRichEditWnd->GetHWND(), m_hWnd, rcWnd.left, rcWnd.top, rcWnd.right -rcWnd.left,rcWnd.bottom -rcWnd.top, SWP_NOZORDER);
			}
		}
		return IWindowBase::HandleMessage(uMsg,wParam,lParam);
	}
	catch (...)
	{
		throw "CMainWnd::HandleMessage";
	}
}

void CMainWnd::Init()
{
	try
	{
		IWindowBase::Init();
		
		Bitmap pBitmap(_T("C:\\test.png"));
		HBITMAP hBitmap;
		pBitmap.GetHBITMAP(0,&hBitmap);
		
		Bitmap *pBmp = UiLib::CGenerAlgorithm::CreateBitmapFromHBITMAP(hBitmap);
		OnQuickSave(pBmp,_T("C:\\snap.png"));

		pAnimWnd		= static_cast<CHorizontalLayoutUI*>(pm.FindControl(_T("AnimWnd")));
		pTestLabel		= static_cast<CLabelUI*>(pm.FindControl(_T("TestLabel")));
		pChartView		= static_cast<CChartViewUI*>(pm.FindControl(_T("ChartView")));
		pEffectsDemo	= static_cast<CButtonUI*>(pm.FindControl(_T("EffectsDemo")));
		
		CButtonUI*	pStartTrayAminCtrl	= static_cast<CButtonUI*>(pm.FindControl(_T("StartTrayAminCtrl")));

		CButtonUI*	pTextMsgBtn			= static_cast<CButtonUI*>(pm.FindControl(_T("TextMsg")));
		CButtonUI*	pAddNodeBtn			= static_cast<CButtonUI*>(pm.FindControl(_T("AddNode")));
		CButtonUI*	pAddAtNodeBtn		= static_cast<CButtonUI*>(pm.FindControl(_T("AddAtNode")));
		CButtonUI*	pCreateChartViewBtn	= static_cast<CButtonUI*>(pm.FindControl(_T("CreateChartView")));
		CButtonUI*	pAddChartDataABtn	= static_cast<CButtonUI*>(pm.FindControl(_T("AddChartDataA")));
		CButtonUI*	pAddChartDataBBtn	= static_cast<CButtonUI*>(pm.FindControl(_T("AddChartDataB")));
		CButtonUI*	pAddChartDataCBtn	= static_cast<CButtonUI*>(pm.FindControl(_T("AddChartDataC")));
		CButtonUI*	pLegendTopCBtn		= static_cast<CButtonUI*>(pm.FindControl(_T("LegendTop")));
		CButtonUI*	pLegendRightBtn		= static_cast<CButtonUI*>(pm.FindControl(_T("LegendRight")));
		CButtonUI*	pLegendBottomBtn	= static_cast<CButtonUI*>(pm.FindControl(_T("LegendBottom")));
		CButtonUI*	pDelChartDataBtn	= static_cast<CButtonUI*>(pm.FindControl(_T("DelChartData")));
		
// 		pStartTrayAminCtrl->OnNotify	+= MakeDelegate(this,&CMainWnd::OnStartTrayAminCtrlClick,_T("click"));
		pEffectsDemo->OnNotify			+= MakeDelegate(this,&CMainWnd::OnEffectsBtnClick,_T("click"));
// 		pTextMsgBtn->OnNotify			+= MakeDelegate(this,&CMainWnd::OnMsgBtnClick,_T("click"));
// 		pTextMsgBtn->OnEvent			+= MakeDelegate(this,&CMainWnd::OnMsgBtnMouseEnter,UIEVENT_MOUSEENTER);
// 		pTextMsgBtn->OnEvent			+= MakeDelegate(this,&CMainWnd::OnMsgBtnMouseLeave,UIEVENT_MOUSELEAVE);
// 		pAddNodeBtn->OnNotify			+= MakeDelegate(this,&CMainWnd::OnAddNodeBtnClick,_T("click"));
// 		pAddAtNodeBtn->OnNotify			+= MakeDelegate(this,&CMainWnd::OnAddNodeBtnClick,_T("click"));
// 		pCreateChartViewBtn->OnNotify	+= MakeDelegate(this,&CMainWnd::OnCreateChartViewBtn,_T("click"));
// 		pAddChartDataABtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnAddChartDataABtn,_T("click"));
// 		pAddChartDataBBtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnAddChartDataBBtn,_T("click"));
// 		pAddChartDataCBtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnAddChartDataCBtn,_T("click"));
// 		pLegendTopCBtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnLegendTopBtn,_T("click"));
// 		pLegendRightBtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnLegendRightBtn,_T("click"));
// 		pLegendBottomBtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnLegendBottomBtn,_T("click"));
// 		pDelChartDataBtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnDelChartDataBtn,_T("click"));

		//pEffectsDemo ΪDuilib�ؼ�ָ��

		//IDuiTimer* pControlTimer = NULL;
		//����OnTimer�İ󶨺���Ϊ��void OnDuiTimerA(IDuiTimer* pTimer);
		//�޲������ö�ʱ��,����OnTimer������ΪCMainWnd::OnDuiTimerA�������������Ϊ1000���룬100000������Զ�ֹͣ
		//pEffectsDemo->OnTimers			+=	pControlTimer = MakeDuiTimer(this,&CMainWnd::OnDuiTimerA,1000,100000);
		//pControlTimer->KillDuiTimer();

		//����OnTimer�İ󶨺���Ϊ��void OnDuiTimerB(IDuiTimer* pTimer,CButtonUI* pControl);
		//�в������ö�ʱ��,����OnTimer������ΪCMainWnd::OnDuiTimerA�������Ҵ���һ��Button���͵�ָ�룬���Ϊ1000���룬100000������Զ�ֹͣ
		//pEffectsDemo->OnTimers			+=	pControlTimer = MakeDuiTimer(this,&CMainWnd::OnDuiTimerB,pEffectsDemo,1000,100000);
		//pControlTimer->KillDuiTimer();

		//����OnTimer�İ󶨺���Ϊ��void OnDuiTimerC(IDuiTimer* pTimer,HWND hWnd,CMainWnd* lParam,WPARAM wParam);
		//�о�����ö�ʱ��������OnTimer������ΪCMainWnd::OnDuiTimerC������lParam ֵΪthis��wParamֵΪ1234���������Ϊ1000����,��һֱ����
		//���ɶ�LPARAM WPARAM �ĸ�ֵ������2������Ϊ��ʱ���ᴥ��WM_TIMER��Ϣ��������õڶ�������������Ҫ�󶨵�OnTimer����
		//pEffectsDemo->OnTimers			+=	pControlTimer = MakeDuiTimer(this,&CMainWnd::OnDuiTimerC,m_hWnd,this,1234,1000,NULL);
		//pControlTimer->KillDuiTimer();

		//ֹͣpEffectsDemo�ؼ������ж�ʱ��
		//pEffectsDemo->OnTimers.KillTimers();
		//����pEffectsDemo�ؼ������ж�ʱ��
		//pEffectsDemo->OnTimers.SetTimers();
		//ֹͣ��ɾ��pEffectsDemo�ؼ������ж�ʱ��
		//pEffectsDemo->OnTimers.RemoveTimerAll();

		//�޿ؼ���ʹ�ö�ʱ��
// 		IDuiTimer* pTimer = MakeDuiTimer(this,&CMainWnd::OnDuiTimerC,m_hWnd,this,1234,1000,NULL);
// 		pTimer->KillDuiTimer();
// 		delete pTimer;

		//���캯����ʽ���� 
 		//CDuiTimer* mTimer = new CDuiTimer();
 		//mTimer->SetDuiTimer(m_hWnd,(LPARAM)this,1234,1000,10000);

		//ͨ��MakeDelegate��ʽ��WM_TIMER��Ϣ��ָ������
 		//pEffectsDemo->OnNotify			+= MakeDelegate(this,&CMainWnd::OnDuiTimerD,(EVENTTYPE_UI)WM_TIMER);

		//CControlUI* pControl = CreateDuiInstance<CControlUI*>("CControlUI");
		//pControl->SetText(_T("tset"));
		//CDuiString texx = pControl->GetText();

	}
	catch (...)
	{
		throw "CMainWnd::Init";
	}
}


void CMainWnd::Notify( TNotifyUI& msg )
{
	if (_tcsicmp(msg.sType,_T("menu")) == 0)
	{
		CMenuWnd* pMenu = CMenuWnd::CreateDuiMenu(m_hWnd);
		if( pMenu == NULL ) { return; } 
		POINT pt = {msg.ptMouse.x, msg.ptMouse.y};
		::ClientToScreen(m_hWnd,&pt);
		pMenu->Init(NULL,_T("menu.xml"),0,pt);
	}
	IWindowBase::Notify(msg);
}

void CMainWnd::OnFinalMessage( HWND hWnd )
{
	try
	{
		IWindowBase::OnFinalMessage(hWnd);
		PostQuitMessage(0);
		delete this;
	}
	catch (...)
	{
		throw "CMainWnd::OnFinalMessage";
	}
}

bool CMainWnd::OnMsgBtnClick( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
// 	SkBitmap bitmap;
// 	bitmap.setConfig(SkBitmap::kARGB_8888_Config, 900, 600);
// 	bitmap.allocPixels();  
// 
// 	SkCanvas canvas(bitmap);

	// 	SkPaint paint;
	// 	SkRect r;
	// 	paint.setARGB(255, 255, 0, 0);  
	// 	r.set(25, 25, 145, 145);  
	// 	canvas.drawRect(r, paint);  
	// 	paint.setARGB(125, 0, 255, 0);
	// 	r.offset(20, 20);
	// 	canvas.drawRect(r, paint);
	// 	paint.setARGB(125, 0, 0, 255);
	// 	r.offset(20, 20);
	// 	canvas.drawRect(r, paint);

// 	Bitmap *pBitmap = new Bitmap(_T("C:\\ren.jpg"));
// 
// 	SkBitmap *skBitmap = new SkBitmap;
// 	skBitmap->setConfig(SkBitmap::kARGB_8888_Config,pBitmap->GetWidth(),pBitmap->GetHeight());
// 	skBitmap->allocPixels();
// 	BitmapData data;
// 	pBitmap->LockBits(&Rect(0,0,pBitmap->GetWidth(),pBitmap->GetHeight()),ImageLockModeRead,PixelFormat32bppARGB,&data);
// 	skBitmap->lockPixels();
// 	//ָ��һ����ַ����,����pBitmap�����ڻ���ǰdelete;
// 	skBitmap->setPixels(data.Scan0);
// 	//��������ֵ��ȥ,��������delete pBitmap  �����ٶȿ϶���һЩ,  �� ��װһ�� GDI+ Bitmap��Skia Bitmap�Ķ��ձ���
// 	//skBitmap->copyPixelsFrom(data.Scan0,data.Height*data.Stride);
// 	skBitmap->unlockPixels();
// 	pBitmap->UnlockBits(&data);
// 
// 	canvas.translate(250,0);
// 
// 	SkRect rc;
// 	rc.iset(0,0,160,200);
	//canvas.clipRect(rc,SkRegion::kReplace_Op);

	// 	canvas.translate(200,300);
	// 	canvas.rotate(90);
	// 	canvas.translate(-200,-300);
// 	canvas.scale(0.5,0.5);
// 
// 	SkMatrix matrix;
// 	Sk3DView sk3DView;
// 	sk3DView.rotateX(30);
// 	sk3DView.getMatrix(&matrix);
// 
// 	canvas.translate(200,300);
// 	canvas.concat(matrix);
// 	canvas.translate(-200,-300);
// 
// 
// 	SkPaint paint;
// 	paint.setAntiAlias(true);
// 	canvas.drawBitmap(*skBitmap,0,0,&paint);
// 
// 
// 	delete pBitmap;
// 	delete skBitmap;
// 	pBitmap = NULL;
// 	skBitmap =NULL;
// 	HDC wndDC = ::GetDC(m_hWnd);
// 
// 	BITMAPINFO bmi;
// 	memset(&bmi, 0, sizeof(bmi));
// 	bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
// 	bmi.bmiHeader.biWidth       = bitmap.width();
// 	bmi.bmiHeader.biHeight      = -bitmap.height(); // top-down image 
// 	bmi.bmiHeader.biPlanes      = 1;
// 	bmi.bmiHeader.biBitCount    = 32;
// 	bmi.bmiHeader.biCompression = BI_RGB;
// 	bmi.bmiHeader.biSizeImage   = 0;
// 
// 	bitmap.lockPixels();
// 	::SetDIBitsToDevice(wndDC,0,0,900,600,0,0,0,bitmap.height(), bitmap.getPixels(), &bmi, DIB_RGB_COLORS);
// 	bitmap.unlockPixels();

	return true;
}

bool CMainWnd::OnStartTrayAminCtrlClick( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	if(pm.GetTrayObject().IsTwinkling())
		pm.GetTrayObject().StopTwinkling();
	else
		pm.GetTrayObject().StartTwinkling();

	return true;
}


bool CMainWnd::OnMsgBtnMouseEnter( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	DUI__Trace(_T("���������밴ťʱ����Ϣ OK!"));
	pTEventUI->pSender->SetText(_T("��������"));
	pTEventUI->pSender->SetUserData(_T("��������"));

	pEffectsDemo->OnTimers			+= MakeDuiTimer(this,&CMainWnd::OnDuiTimerB,(CButtonUI*)pTEventUI->pSender,1000,NULL,true,true);
	return true;
}

bool CMainWnd::OnMsgBtnMouseLeave( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	DUI__Trace(_T("��������뿪��ťʱ����Ϣ OK!"));
	pTEventUI->pSender->SetText(_T("�������"));
	pTEventUI->pSender->SetUserData(_T("�������"));

	pEffectsDemo->OnTimers			+= MakeDuiTimer(this,&CMainWnd::OnDuiTimerB,(CButtonUI*)pTEventUI->pSender,1000,NULL,true,true);
	return true;
}

bool CMainWnd::OnEffectsBtnClick( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
#ifdef UILIB_D3D
	pAnimWnd->SetAnimEffects(true);
	pEffectsDemo->SetTag(pEffectsDemo->GetTag()+1);

	if(pEffectsDemo->GetTag() == 1)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("anim='left2right' offset='180'"));
	else if(pTNotifyUI->pSender->GetTag() == 2)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("anim='right2left' offset='180'"));
	else if(pEffectsDemo->GetTag() == 3)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("anim='top2bottom' offset='180'"));
	else if(pEffectsDemo->GetTag() == 4)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("anim='bottom2top' offset='180'"));
	else if(pEffectsDemo->GetTag() == 5)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("anim='zoom+' offset='180'"));
	else if(pEffectsDemo->GetTag() == 6)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("anim='zoom-' offset='180'"));
	else if(pEffectsDemo->GetTag() == 7)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("offsetx='180' rotation='0.3'"));
	else if(pEffectsDemo->GetTag() == 8)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("offsetx='180' rotation='-0.3'"));
	else if(pEffectsDemo->GetTag() == 9)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("offsety='180' rotation='0.3'"));
	else if(pEffectsDemo->GetTag() == 10)
		pAnimWnd->SetAttribute(_T("adveffects"),_T("offsety='180' rotation='-0.3'"));
	else
	{
		pEffectsDemo->SetTag(1);
		pAnimWnd->SetAttribute(_T("adveffects"),_T("anim='left2right' offset='80'"));
	}
	
#endif
	pEffectsDemo->SetTag(pEffectsDemo->GetTag()%2?2:3);
	pm.SetCurStyles(pEffectsDemo->GetTag()%2?_T("LangChinese"):_T("LangEnglish"));

	if(pEffectsDemo->GetTag()%2)
		pm.SetCurStyles(_T("LangChinese"));
	else 
		pm.SetCurStyles(_T("LangEnglish"));
	pAnimWnd->TriggerEffects();

 	int nBkWidth,nBkHeight,nPitch;
	BYTE * bit = pAnimWnd->SnapShot(nBkWidth,nBkHeight,nPitch);
	Bitmap *pBitmap = new Bitmap(nBkWidth,nBkHeight,nPitch,PixelFormat32bppARGB,bit);
// 	Graphics gs(GetDC(NULL));
// 	gs.DrawImage(pBitmap,0,0);
	OnQuickSave(pBitmap,_T("C:\\test.png"));

 //	m_pRichEditWnd = new CRichEditWnd;
 	
	return true;
}


bool CMainWnd::OnAddNodeBtnClick( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	CEditUI* pEdit = static_cast<CEditUI*>(pm.FindControl(_T("AddNodeText")));
	if(!pEdit && pEdit->GetText().GetLength() > 0)
		return true;

	CTreeNodeUI* pParentNode = static_cast<CTreeNodeUI*>(pTNotifyUI->pSender->GetParent()->GetParent());
	if(!pParentNode || !pParentNode->GetInterface(_T("TreeNode")))
		return true;

	CFadeButtonUI* pRemoveBtn = new CFadeButtonUI();
	pRemoveBtn->SetText(_T("ɾ���ڵ�"));
	pRemoveBtn->SetName(_T("RemoveNodeBtn"));

	CTreeNodeUI* pNewNode = new CTreeNodeUI();
	pNewNode->SetItemText(pEdit->GetText().GetData());
	pParentNode->Add(pNewNode);
	pNewNode->GetTreeNodeHoriznotal()->Add(pRemoveBtn);

	pNewNode->SetStyleName(_T("treenode"));
	pRemoveBtn->SetStyleName(_T("FadeButtonDemo"),&pm);
	pRemoveBtn->SetFixedWidth(60);

	pRemoveBtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnRemoveNodeBtnClick,_T("click"));

	return true;
}


bool CMainWnd::OnAddAtNodeBtnClick( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	CTreeNodeUI* pParentNode = static_cast<CTreeNodeUI*>(pTNotifyUI->pSender->GetParent()->GetParent());
	if(!pParentNode || !pParentNode->GetInterface(_T("TreeNode")))
		return true;

	CEditUI* pEdit = static_cast<CEditUI*>(pParentNode->GetTreeNodeHoriznotal()->FindSubControl(_T("AddAtNodeText")));
	if(!pEdit && pEdit->GetText().GetLength() > 0)
		return true;

	CFadeButtonUI* pRemoveBtn = new CFadeButtonUI();
	pRemoveBtn->SetText(_T("ɾ"));
	pRemoveBtn->SetName(_T("RemoveNodeBtn"));

	CFadeButtonUI* pAddAtBtn = new CFadeButtonUI();
	pAddAtBtn->SetText(_T("����ڵ�"));
	pAddAtBtn->SetName(_T("AddAtNode"));

	CEditUI* pAddEdit = new CEditUI();
	pAddEdit->SetName(_T("AddAtNodeText"));
	pAddEdit->SetText(_T("�ڵ�����"));
	pAddEdit->SetTipValue(_T("�ڵ�����"));

	CTreeNodeUI* pNewNode = new CTreeNodeUI();
	pNewNode->SetItemText(pEdit->GetText().GetData());
	pParentNode->AddAt(pNewNode,0);
	pNewNode->GetTreeNodeHoriznotal()->Add(pAddEdit);
	pNewNode->GetTreeNodeHoriznotal()->Add(pAddAtBtn);
	pNewNode->GetTreeNodeHoriznotal()->Add(pRemoveBtn);

	pNewNode->SetStyleName(_T("treenode"));
	pAddAtBtn->SetStyleName(_T("FadeButtonDemo"),&pm);
	pRemoveBtn->SetStyleName(_T("FadeButtonDemo"),&pm);
	pAddEdit->SetFixedWidth(50);
	pAddAtBtn->SetFixedWidth(60);
	pRemoveBtn->SetFixedWidth(20);


	pRemoveBtn->OnNotify		+= MakeDelegate(this,&CMainWnd::OnRemoveNodeBtnClick,_T("click"));

	return true;
}


bool CMainWnd::OnRemoveNodeBtnClick( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	CTreeNodeUI* pParentNode = static_cast<CTreeNodeUI*>(pTNotifyUI->pSender->GetParent()->GetParent());
	if(!pParentNode || !pParentNode->GetInterface(_T("TreeNode")))
		return true;

	if(pParentNode->GetParentNode())
		pParentNode->GetParentNode()->Remove(pParentNode);

	return true;
}


bool CMainWnd::OnCreateChartViewBtn( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	//pChartView->GetXYAxis().SetTickLimis(-50,100,20);
	pChartView->AddLabel(_T("һ��"));
	pChartView->AddLabel(_T("����"));
	pChartView->AddLabel(_T("����"));
	pChartView->AddLabel(_T("����"));

	return true;
}


bool CMainWnd::OnAddChartDataABtn( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	if(!pChartView->GetGroupCount())
		return true;

	CDuiString mLegend;
	mLegend.Format(_T("����ͼ��%d"),mChartDataPos++);
	CChartSeries* pSeriesA = new CChartSeries(mLegend,Color(rand()%256,rand()%256,rand()%256).GetValue(),Color(rand()%256,rand()%256,rand()%256).GetValue());

	for(int nIndex = 0;(UINT)nIndex < pChartView->GetGroupCount();nIndex++){
		pSeriesA->AddSeriesData(rand()%100-50);
	}
	pChartView->AddSeries(pSeriesA);

	return true;
}


bool CMainWnd::OnAddChartDataBBtn( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	if(!pChartView->GetGroupCount())
		return true;

	CDuiString mLegend;
	mLegend.Format(_T("����ͼ��%d"),mChartDataPos++);
	CChartSeries* pSeriesA = new CChartSeries(mLegend,Color(rand()%256,rand()%256,rand()%256).GetValue(),Color(rand()%256,rand()%256,rand()%256).GetValue());

	for(int nIndex = 0;(UINT)nIndex < pChartView->GetGroupCount();nIndex++){
		pSeriesA->AddSeriesData(rand()%151);
	}
	pChartView->AddSeries(pSeriesA);

	return true;
}


bool CMainWnd::OnAddChartDataCBtn( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	if(!pChartView->GetGroupCount())
		return true;

	CDuiString mLegend;
	mLegend.Format(_T("����ͼ��%d"),mChartDataPos++);
	CChartSeries* pSeriesA = new CChartSeries(mLegend,Color(rand()%256,rand()%256,rand()%256).GetValue(),Color(rand()%256,rand()%256,rand()%256).GetValue());

	for(int nIndex = 0;(UINT)nIndex < pChartView->GetGroupCount();nIndex++){
		pSeriesA->AddSeriesData(rand()%151-151);
	}
	pChartView->AddSeries(pSeriesA);

	return true;
}


bool CMainWnd::OnLegendTopBtn( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	pChartView->GetXYAxis().SetLegendLocation(LOCATION_TOP);
	return true;
}


bool CMainWnd::OnLegendRightBtn( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	pChartView->GetXYAxis().SetLegendLocation(LOCATION_RIGHT);
	return true;
}

bool CMainWnd::OnLegendBottomBtn( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	pChartView->GetXYAxis().SetLegendLocation(LOCATION_BOTTOM);
	return true;
}

bool CMainWnd::OnDelChartDataBtn( TNotifyUI* pTNotifyUI,LPARAM lParam,WPARAM wParam )
{
	pChartView->RemoveSeries(0);
	return true;
}

void CMainWnd::OnDuiTimerA( IDuiTimer* pTimer )
{
	DUITRACE(_T("�޲�����ʱ������:Interval=%d CurTimer=%d TotalTimer=%d"),pTimer->GetInterval(),pTimer->GetCurTimer(),pTimer->GetTotalTimer());
}

void CMainWnd::OnDuiTimerB( IDuiTimer* pTimer,CButtonUI* pControl )
{
	CDuiString mText;
	mText.SmallFormat(_T("%s %d ��"),pControl->GetUserData().GetData(),(int)(pTimer->GetCurTimer()/1000)+1);
	DUITRACE(_T(""));
	pControl->SetText(mText);
	DUITRACE(_T("�в�����ʱ������:Interval=%d CurTimer=%d TotalTimer=%d"),pTimer->GetInterval(),pTimer->GetCurTimer(),pTimer->GetTotalTimer());
}

void CMainWnd::OnDuiTimerC( IDuiTimer* pTimer,HWND hWnd,CMainWnd* lParam,WPARAM wParam )
{
	DUITRACE(_T("�о����ʱ������:hwnd=%d lparam=%d wparam=%d Interval=%d CurTimer=%d TotalTimer=%d"),pTimer->GetHwnd(),pTimer->GetLParam(),pTimer->GetWParam(),pTimer->GetInterval(),pTimer->GetCurTimer(),pTimer->GetTotalTimer());
}


bool CMainWnd::OnDuiTimerD( TEventUI* pTEventUI )
{
	DUITRACE(_T("��ʱ���¼���ʽ����:lparam=%d wparam=%d"),pTEventUI->lParam,pTEventUI->wParam);
	return true;
}
