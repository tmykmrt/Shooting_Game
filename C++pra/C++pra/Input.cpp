#include "stdafx.h"
#include "Input.h"
#include"MyDX.h"

LPDIRECTINPUT8  Input::pDinput;
LPDIRECTINPUTDEVICE8 Input::pKeyDevice;
LPDIRECTINPUTDEVICE8 Input::pMouseDevice;
Input::Input()
{
}


Input::~Input()
{
}

HRESULT Input::Init(HWND hwnd)
{
	// 「DirectInput」オブジェクトの作成
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDinput, NULL)))
	{
		return E_FAIL;
	}
	// 「DirectInputデバイス」オブジェクトの作成
	if (FAILED(pDinput->CreateDevice(GUID_SysKeyboard,
		&pKeyDevice, NULL)))
	{
		return E_FAIL;
	}
	// デバイスをキーボードに設定
	if (FAILED(pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	// 協調レベルの設定
	if (FAILED(pKeyDevice->SetCooperativeLevel(
		hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}
	// デバイスを「取得」する
	pKeyDevice->Acquire();
	return S_OK;
}

//	キーボード初期化
HRESULT Input::InitKey(HWND hwnd)
{
	// 「DirectInputデバイス」オブジェクトの作成
	if (FAILED(pDinput->CreateDevice(GUID_SysKeyboard,
		&pKeyDevice, NULL)))
	{
		return E_FAIL;
	}
	// デバイスをキーボードに設定
	if (FAILED(pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	// 協調レベルの設定
	if (FAILED(pKeyDevice->SetCooperativeLevel(
		hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}
	// デバイスを「取得」する
	pKeyDevice->Acquire();
	return S_OK;
}

//	マウス初期化
HRESULT Input::InitMouse(HWND hwnd)
{
	// 「DirectInputデバイス」オブジェクトの作成
	if (FAILED(pDinput->CreateDevice(GUID_SysMouse, &pMouseDevice, NULL)))
	{
		return E_FAIL;
	}
	// デバイスをマウスに設定
	if (FAILED(pMouseDevice->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}
	// 協調レベルの設定
	if (FAILED(pMouseDevice->SetCooperativeLevel(
		hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		return E_FAIL;
	}
	// デバイスを「取得」する
	if (FAILED(pMouseDevice->Acquire()))
	{
		return E_FAIL;
	}
	return S_OK;
}

//	入力の確認
bool Input::ConfirmKeyEntry()
{
	return true;
}

//	
void Input::Update()
{
	UpdateKeys();
}

//	
void Input::UpdateKeys()
{
	if (pKeyDevice == NULL)return;
	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		pKeyDevice->GetDeviceState(sizeof(inputKeys), &inputKeys);
	}

}


void Input::UpdateMouse()
{
	if (FAILED(pMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE2), &inputMouse)))
	{
		pMouseDevice->Acquire();
	}

	//	マウス座標の更新
	POINT po;
	GetCursorPos(&po);
	mousePoint.x = po.x;
	mousePoint.y = po.y;

	onMouseLeft = inputMouse.rgbButtons[0] & 0x80;
	onMouseRight = inputMouse.rgbButtons[1] & 0x80;
}

void Input::Release()
{
	pDinput->Release();
	pKeyDevice->Release();
	pMouseDevice->Release();
}
