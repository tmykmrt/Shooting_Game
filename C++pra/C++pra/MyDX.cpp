#include"stdafx.h"
#include"MyDX.h"

MyDX::MyDX()
{
	pD3d = NULL;
	pDevice = NULL;
}

//	デストラクタ
MyDX::~MyDX()
{
	//	解放
	//m_p_d3d->Release();
	//m_p_device->Release();
}


//	解放
void MyDX::Release()
{
	pD3d->Release();
	pDevice->Release();
}


//	DirectXの初期化
HRESULT MyDX::Init(HWND hwnd)
{
	// 作成
	if (NULL == (pD3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3Dの作成に失敗しました", "", MB_OK);
		return E_FAIL;
	}
	// 「DIRECT3Dデバイス」オブジェクトの作成
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	//	画面のフォーマット情報の格納
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	//	バックバッファの数を格納
	d3dpp.BackBufferCount = 1;
	//	フロントバッファとバックバッファの切り替え定義
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	//	スクリーンモードを定義　true : ウィンドウ　それ以外 : フルスクリーン
	d3dpp.Windowed = TRUE;
	//	深度ステンシルバッファの有無
	d3dpp.EnableAutoDepthStencil = TRUE;
	//	ステンシルバッファのフォーマット指定
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &pDevice)))
	{
		if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp, &pDevice)))
		{
			MessageBox(0, "HALモードでDIRECT3Dデバイスを作成できません\nREFモードで再試行します", NULL, MB_OK);
			if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hwnd,
				D3DCREATE_HARDWARE_VERTEXPROCESSING,
				&d3dpp, &pDevice)))
			{
				if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hwnd,
					D3DCREATE_SOFTWARE_VERTEXPROCESSING,
					&d3dpp, &pDevice)))
				{
					MessageBox(0, "DIRECT3Dデバイスの作成に失敗しました", NULL, MB_OK);
					return E_FAIL;
				}
			}
		}
	}
	return S_OK;
}

void MyDX::Render()
{
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	if (SUCCEEDED(pDevice->BeginScene()))
	{
		//---------------------------------
		//	描画
		//---------------------------------
		
		
		pDevice->EndScene();
	}
	//	フリップ
	pDevice->Present(NULL, NULL, NULL, NULL);
}