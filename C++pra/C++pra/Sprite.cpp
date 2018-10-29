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

//	読み込み
void Sprite::Load(TCHAR *name, int x, int y)
{
	size.x = x;
	size.y = y;
	m2DObj::LoadTexture(name, &pTexture, x, y);
}

void Sprite::Draw()
{
	RECT rec = { 0, 0, size.x, size.y };
	m2DObj::Draw(&pTexture, pos,rec);
}

void Sprite::DrawCenter()
{
	RECT rec = { 0, 0, size.x, size.y };
	m2DObj::DrawCenter(&pTexture, pos, rec);
}
//	解放
void Sprite::Release()
{
	if(pTexture != NULL)pTexture->Release();
}

