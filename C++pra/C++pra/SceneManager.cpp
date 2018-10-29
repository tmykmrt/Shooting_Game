#include "SceneManager.h"
#include"TitleScene.h"
#include"GameScene.h"

SceneManager::SceneManager()
{
	m_nowScene = NULL;
}


SceneManager::~SceneManager()
{
	delete m_nowScene;
}

void SceneManager::Change(Scene newScene)
{
	//	���ɂ���Ȃ�폜
	if (m_nowScene != NULL)
	{
		delete m_nowScene;
	}

	switch (newScene)
	{
	case Scene::Title:
		m_nowScene = new TitleScene();
		break;
	case Scene::Game:
		m_nowScene = new GameScene();
		break;
	}
}

void SceneManager::Update()
{
	if (m_nowScene == NULL) return;
	
	
	//	�X�V
	m_nowScene->Update();

}


void SceneManager::Render()
{
	if (m_nowScene == NULL) return;

	//	�`��
	m_nowScene->Render();

}