// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

#include <atlbase.h>
#include <atlstr.h>
#include <limits>

#include "CEF3PreProcess.h"
#include "../../Common/Include/UiLib/UIlib.h"


//������ڴ����øú��������ڴ�й¶���
//�����˳�ǰ����_CrtDumpMemoryLeaks();�����ɲ鿴�ڴ�й¶��ID�ţ���ID�ſ���ΪBreakpoint�Ĳ���������ʱ��������Ӧλ���Զ��ϵ�
inline  void  EnableMemLeakCheck(int Breakpoint = 0){
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG)  |  _CRTDBG_LEAK_CHECK_DF);
	if(Breakpoint)
		_CrtSetBreakAlloc ( 1912 );
}

#define _CRT_SECURE_NO_DEPRECATE



#pragma comment(lib, "../../Common/DLL_Debug/UiLib_d.lib")
