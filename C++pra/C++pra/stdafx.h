// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーから使用されていない部分を除外します。

using namespace std;
// Windows ヘッダー ファイル:
#include <windows.h>

// C ランタイム ヘッダー ファイル
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <cmath>
#include <vector>
#include <list>
#include <map>

//	DirectX
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
//必要なライブラリファイルのロード]
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d9.lib") 
#pragma comment(lib,"d3dx9.lib") 
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"user32.lib")


// TODO: プログラムに必要な追加ヘッダーをここで参照してください
#include"GameParameter.h"
#include"Singleton.h"