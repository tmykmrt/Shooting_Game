#pragma once
/**
* @file SceneBase.h
* @brief �V�[���̊��N���X
* @date 2018 7/14
*/
class SceneBase
{
public:
	SceneBase();
	~SceneBase();
	//	�X�V
	virtual void Update() = 0;
	//	�`��
	virtual void Render() = 0;
private:

};
