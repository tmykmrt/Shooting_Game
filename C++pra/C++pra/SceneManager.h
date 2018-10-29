#pragma once
#include"stdafx.h"
#include"SceneBase.h"

/**
* @file SceneManager.h
* @brief シーン管理
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
	//	シーンの切り替え
	void Change(Scene newScene);
	//	更新
	void Update();
	//	描画
	void Render();

private:
	//	今更新中のシーン
	SceneBase *m_nowScene;
};

