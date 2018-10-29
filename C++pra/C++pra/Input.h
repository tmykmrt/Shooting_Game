#pragma once
class Input
{
public:
	Input();
	~Input();
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
	bool OnRight() { return onMouseRight; }
	bool OnLeft() { return onMouseLeft; }
	void Release();
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
};
extern Input* input;

