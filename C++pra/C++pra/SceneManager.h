#pragma once
#include"stdafx.h"
#include"SceneBase.h"

/**
* @file SceneManager.h
* @brief �V�[���Ǘ�
* @date 2018 7/25
*/
class SceneManager
{
public:
	enum Scene
	{
		Title,
		Game,
	};

	SceneManager();
	~SceneManager();
	//	�V�[���̐؂�ւ�
	void Change(Scene newScene);
	//	�X�V
	void Update();
	//	�`��
	void Render();

private:
	//	���X�V���̃V�[��
	SceneBase *m_nowScene;
};

