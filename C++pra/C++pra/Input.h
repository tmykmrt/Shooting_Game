#pragma once
#include"stdafx.h"

class Input : public Singleton<Input>
{
public:
	friend class Singleton<Input>;
	HRESULT Init(HWND hwnd);
	HRESULT InitMouse(HWND hwnd);
	HRESULT InitKey(HWND hwnd);
	//	�L�[���͂̊m�F
	bool ConfirmKeyEntry();
	//	�X�V
	void Update();
	void UpdateKeys();
	void UpdateMouse();
	D3DXVECTOR2 GetMousePoint() { return mousePoint; }
	//	�����Ă���
	bool OnRight() { return onMouseRight; }
	bool OnLeft() { return onMouseLeft; }
	//	�������u��
	bool OnJustRight() { return onJustRight; }
	bool OnJustLeft() { return onJustLeft; }
	//	�������u��
	bool UpRight() { return upJustRight; }
	bool UpLeft() { return upJustLeft; }
	bool ChackKey(int code);
	void Release();
protected:
	Input();
	~Input();
private:
	//	�L�[�{�[�h�[
	static LPDIRECTINPUT8 pDinput;
	//	�L�[�{�[�h�[�p
	static LPDIRECTINPUTDEVICE8 pKeyDevice;
	//	�}�E�X�p
	static LPDIRECTINPUTDEVICE8 pMouseDevice;
	//	�L�[�{�[�h���͒l
	char inputKeys[256];
	DIMOUSESTATE2 inputMouse;
	//	�}�E�X���W
	D3DXVECTOR2 mousePoint;
	bool onMouseRight;
	bool onMouseLeft;
	bool onJustRight;
	bool onJustLeft;
	bool upJustRight;
	bool upJustLeft;
	bool oldRight;
	bool oldLeft;
};

