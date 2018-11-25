#pragma once
#include"stdafx.h"
#include"m2DObj.h"
#include"Sprite.h"


Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

//	�ǂݍ���
void Sprite::Load(TCHAR *name, int x, int y)
{
	size.x = x;
	size.y = y;
	m2DObj::LoadTexture(name, &pTexture, x, y);
}

//	�ǂݍ���
void Sprite::Load(TCHAR *name, int imageSizeX, int imageSizeY, int sizeX, int sizeY)
{
	size.x = sizeX;
	size.y = sizeY;
	m2DObj::LoadTexture(name, &pTexture, imageSizeX, imageSizeY);
}

void Sprite::Draw()
{
	RECT rec = { 0, 0, size.x, size.y };
	m2DObj::Draw(&pTexture, pos,rec);
}

void Sprite::DrawCenter()
{
	RECT rec = { 0, 0, size.x, size.y };
	m2DObj::DrawCenter(&pTexture, pos, rec,size);
}

void Sprite::DrawCenter(int top,int right)
{
	//	�`��͈�
	RECT rec = { size.x * (right -1),size.y  *(top - 1), size.x * right, size.y * top };
	m2DObj::DrawCenter(&pTexture, pos, rec,size);
}

//	���
void Sprite::Release()
{
	if(pTexture != NULL)pTexture->Release();
}

