#include "stdafx.h"
#include "StageOne.h"
#include"Player.h"
#include"Monster.h"
StageOne::StageOne()
{
	m_BG = new Animation();
	m_BG->Init(0.2f, 1);
	m_BG->AddContinueFrame(L"Painting/Fight/BackGround/Bg", 0, 6);
	m_BG->SetPosition(1920 / 2, 1080 / 2);
}

void StageOne::Init()
{
	ObjMgr->AddObject(new Player(), "Player");
	ObjMgr->AddObject(new Monster(2000,900,1), "Monster");
	ObjMgr->AddObject(new Monster(2000,800,2), "Monster");
	ObjMgr->AddObject(new Monster(2000,600,3), "Monster");
	ObjMgr->AddObject(new Monster(2000,700,4), "Monster");
	ObjMgr->AddObject(new Monster(2000,600,5), "Monster");
}

void StageOne::Release()
{
}

void StageOne::Update(float deltatime, float time)
{
	m_BG->Update(deltatime, time);
}

void StageOne::Render()
{
	m_BG->Render();
}
