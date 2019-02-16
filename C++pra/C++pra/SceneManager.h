#pragma once
#include"stdafx.h"
#include"SceneBase.h"

/**
* @file SceneManager.h
* @brief �V�[���Ǘ�
* @date 2018 7/25
*/
class SceneManager : public Singleton<SceneManager>
{
public:
	enum Scene
	{
		Title,
		Game,
	};

	friend class Singleton<SceneManager>;
	//	�V�[���̐؂�ւ�
	void Change(Scene newScene);
	//	�X�V
	void Update();
	//	�`��
	void Render();

protected:
	SceneManager();
	~SceneManager();
private:
	//	���X�V���̃V�[��
	SceneBase *m_nowScene;
};

