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
	// �uDirectInput�v�I�u�W�F�N�g�̍쐬
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDinput, NULL)))
	{
		return E_FAIL;
	}
	// �uDirectInput�f�o�C�X�v�I�u�W�F�N�g�̍쐬
	if (FAILED(pDinput->CreateDevice(GUID_SysKeyboard,
		&pKeyDevice, NULL)))
	{
		return E_FAIL;
	}
	// �f�o�C�X���L�[�{�[�h�ɐݒ�
	if (FAILED(pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	// �������x���̐ݒ�
	if (FAILED(pKeyDevice->SetCooperativeLevel(
		hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}
	// �f�o�C�X���u�擾�v����
	pKeyDevice->Acquire();
	return S_OK;
}

//	�L�[�{�[�h������
HRESULT Input::InitKey(HWND hwnd)
{
	// �uDirectInput�f�o�C�X�v�I�u�W�F�N�g�̍쐬
	if (FAILED(pDinput->CreateDevice(GUID_SysKeyboard,
		&pKeyDevice, NULL)))
	{
		return E_FAIL;
	}
	// �f�o�C�X���L�[�{�[�h�ɐݒ�
	if (FAILED(pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	// �������x���̐ݒ�
	if (FAILED(pKeyDevice->SetCooperativeLevel(
		hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}
	// �f�o�C�X���u�擾�v����
	pKeyDevice->Acquire();
	return S_OK;
}

//	�}�E�X������
HRESULT Input::InitMouse(HWND hwnd)
{
	// �uDirectInput�f�o�C�X�v�I�u�W�F�N�g�̍쐬
	if (FAILED(pDinput->CreateDevice(GUID_SysMouse, &pMouseDevice, NULL)))
	{
		return E_FAIL;
	}
	// �f�o�C�X���}�E�X�ɐݒ�
	if (FAILED(pMouseDevice->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}
	// �������x���̐ݒ�
	if (FAILED(pMouseDevice->SetCooperativeLevel(
		hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		return E_FAIL;
	}
	// �f�o�C�X���u�擾�v����
	if (FAILED(pMouseDevice->Acquire()))
	{
		return E_FAIL;
	}
	return S_OK;
}

//	���͂̊m�F
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

	//	�}�E�X���W�̍X�V
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
