#pragma once
#include"stdafx.h"

class Input : public Singleton<Input>
{
public:
	friend class Singleton<Input>;
	HRESULT Init(HWND hwnd);
	HRESULT InitMouse(HWND hwnd);
	HRESULT InitKey(HWND hwnd);
	//	キー入力の確認
	bool ConfirmKeyEntry();
	//	更新
	void Update();
	void UpdateKeys();
	void UpdateMouse();
	D3DXVECTOR2 GetMousePoint() { return mousePoint; }
	bool OnRight() { return onMouseRight; }
	bool OnLeft() { return onMouseLeft; }
	void Release();
protected:
	Input();
	~Input();
private:
	//	キーボードー
	static LPDIRECTINPUT8 pDinput;
	//	キーボードー用
	static LPDIRECTINPUTDEVICE8 pKeyDevice;
	//	マウス用
	static LPDIRECTINPUTDEVICE8 pMouseDevice;
	//	キーボード入力値
	char inputKeys[256];

	DIMOUSESTATE2 inputMouse;

	//	マウス座標
	D3DXVECTOR2 mousePoint;
	
	bool onMouseRight;
	bool onMouseLeft;
};

