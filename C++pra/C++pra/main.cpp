//�K�v�ȃw�b�_�[�t�@�C���̃C���N���[�h
#include"stdafx.h"
#include"MyDX.h"
#include"m2DObj.h"
#include"Sprite.h"
#include"SceneManager.h"
#include"Input.h"
#include"SpriteManager.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//INT WINAPI WinMain( HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR szStr,INT iCmdShow)
//�A�v���P�[�V�����̃G���g���[�֐�
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow)
{
	HWND hWnd = NULL;
	MSG msg;
	//	����
	MyDX::CreateInstance();
	m2DObj::CreateInstance();
	Input::CreateInstance();
	SpriteManager::CreateInstance();
	// �E�B���h�E�̏�����
	static char szAppName[] = "�V���[�e�B���O�@��";
	WNDCLASSEX  wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInst;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_ASTERISK);
	RegisterClassEx(&wndclass);

	hWnd = CreateWindow(szAppName, szAppName, WS_OVERLAPPEDWINDOW,
		0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);


	// �_�C���N�g�RD�̏������֐����Ă�
	if (FAILED(MyDX::GetInstance()->Init(hWnd))) return 0;

	//	2D�`�揉����
	if (FAILED(m2DObj::GetInstance()->Init())) return 0;

	//	���͏�����
	if (Input::GetInstance()->Init(hWnd)) return 0;
	if (Input::GetInstance()->InitMouse(hWnd)) return 0;
	
	SceneManager::CreateInstance();
	SceneManager::GetInstance()->Change(SceneManager::Scene::Game);

	// ���b�Z�[�W���[�v
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			MyDX::Device()->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
			if (SUCCEEDED(MyDX::Device()->BeginScene()))
			{
				//	�X�V
				Input::GetInstance()->Update();
				SceneManager::GetInstance()->Update();
				SceneManager::GetInstance()->Render();

				MyDX::Device()->EndScene();
			}
			MyDX::Device()->Present(NULL, NULL, NULL, NULL);
		}
	}
	//	�j��
	MyDX::GetInstance()->Release();
	m2DObj::GetInstance()->Release();
	SceneManager::Destroy();
	SpriteManager::Destroy();
	Input::GetInstance()->Release();
	return (INT)msg.wParam;

}
//
//LRESULT CALLBACK WndProc(HWND hWnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
// �E�B���h�E�v���V�[�W���[�֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
