#include "stdafx.h"
#include "Skill.h"

Skill::Skill(float posx,float posy)
{
	m_Skill = new Animation();
	m_Skill->SetParent(this);
	m_Skill->Init(0.1f, true);
	m_Skill->AddContinueFrame(L"Painting/Fight/Effects/Effects_", 21, 35);
	m_Scale *= 3;
	SetPosition(posx, posy);
}

void Skill::Update(float deltatime, float time)
{
	m_Skill->Update(deltatime, time);

	if (m_Skill->m_CurrentFrame >= 14)
		ObjMgr->RemoveObject(this);



}

void Skill::Render()
{
	m_Skill->Render();

}

void Skill::OnCollision(Object* obj)
{
}
