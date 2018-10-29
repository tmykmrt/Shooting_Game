#pragma once
/**
* @file SceneBase.h
* @brief シーンの基底クラス
* @date 2018 7/14
*/

class SceneBase
{
public:
	SceneBase();
	~SceneBase();

	//	更新
	virtual void Update() = 0;
	//	描画
	virtual void Render() = 0;
private:

};
