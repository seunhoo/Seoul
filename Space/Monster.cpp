#include "stdafx.h"
#include "Monster.h"

Monster::Monster(float posx, float posy, int type)
{
	if (type == 1)
	{
		m_MonsterName = L"Kyo Kusanagi";
	}
	else if (type == 2)
	{
		m_MonsterName = L"Tizoc";
	}
	else if (type == 3)
	{
		m_MonsterName = L"Andy Bogard";
	}
	else if (type == 4)
	{
		m_MonsterName = L"Goro Daimon";
	}
	else if (type == 5)
	{
		m_MonsterName = L"Jyazu";
	}
	else if (type == 6)
	{

	}
	else if (type == 7)
	{

	}
	else if (type == 8)
	{

	}
	else if (type == 9)
	{

	}

	m_State = MState::NONE;
	m_LStand = new Animation();
	m_LStand->SetParent(this);
	m_LStand->Init(0.2, true);
	m_LStand->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 11, 15);
	m_LStand->m_Scale /= 1.5;


	m_RStand = new Animation();
	m_RStand->SetParent(this);
	m_RStand->Init(0.2, true);
	m_RStand->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 21, 25);
	m_RStand->m_Scale /= 1.5;

	m_LPunch = new Animation();
	m_LPunch->SetParent(this);
	m_LPunch->Init(0.2, true);
	m_LPunch->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 21, 25);
	m_LPunch->m_Scale /= 1.5;

	m_RPunch = new Animation();
	m_RPunch->SetParent(this);
	m_RPunch->Init(0.2, true);
	m_RPunch->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 31, 35);
	m_RPunch->m_Scale /= 1.5;

	m_LKick = new Animation();
	m_LKick->SetParent(this);
	m_LKick->Init(0.2, true);
	m_LKick->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 11, 17);
	m_LKick->m_Scale /= 1.5;

	m_RKick = new Animation();
	m_RKick->SetParent(this);
	m_RKick->Init(0.2, true);
	m_RKick->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 21, 27);
	m_RKick->m_Scale /= 1.5;

	m_LJump = new Animation();
	m_LJump->SetParent(this);
	m_LJump->Init(0.1, true);
	m_LJump->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 11, 17);
	m_LJump->m_Scale /= 1.5;

	m_RJump = new Animation();
	m_RJump->SetParent(this);
	m_RJump->Init(0.1, true);
	m_RJump->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 21, 27);
	m_RJump->m_Scale /= 1.5;

	m_RMove = new Animation();
	m_RMove->SetParent(this);
	m_RMove->Init(0.2, true);
	m_RMove->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 11, 16);
	m_RMove->m_Scale /= 1.5;

	m_LMove = new Animation();
	m_LMove->SetParent(this);
	m_LMove->Init(0.2, true);
	m_LMove->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 11, 16);
	m_LMove->m_Scale /= 1.5;

	m_LSit = new Animation();
	m_LSit->SetParent(this);
	m_LSit->Init(0.2, true);
	m_LSit->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 2, 3);
	m_LSit->m_Scale *= 2;

	m_RSit = new Animation();
	m_RSit->SetParent(this);
	m_RSit->Init(0.2, true);
	m_RSit->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 4, 5);
	m_RSit->m_Scale *= 2;

	m_RSkill = new Animation();
	m_RSkill->SetParent(this);
	m_RSkill->Init(0.2, true);
	m_RSkill->AddContinueFrame(L"Painting/Fight/" + m_MonsterName + L"/" + m_MonsterName + L"_", 3, 6);
	m_RSkill->m_Scale.x *= -1;

	m_Monster = m_LStand;
	m_Monster->SetParent(this);
	SetPosition(posx, posy);
	m_State = MState::NONE;
}

void Monster::Update(float deltatime, float time)
{
	m_Monster->Update(deltatime, time);
	if (m_Start == false)
	{
		m_Position.x -= 5;
	}
	if (m_Position.x < 1800)
		m_Start = true;

	if (m_Start == true)
	{
		Move();
		Attack();
	}
}

void Monster::Move()
{

	if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x > 50)
	{

		if (!(m_State == MState::Skill || m_State == MState::Kick || m_State == MState::Jump || m_State == MState::Punch))
		{
			m_State = MState::LeftMove;
			m_Monster = m_LMove;
			m_Position.x -= 5;
		}
	}
	else if (INPUT->GetKey('S') == KeyState::PRESS)
	{

		m_State = MState::Sit;
		if (!(m_State == MState::Skill || m_State == MState::Kick || m_State == MState::Jump || m_State == MState::Punch))
		{
			if (m_LeftRightCheck)
				m_Monster = m_RSit;
			else
				m_Monster = m_LSit;
		}
	}
	else if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < 1820)
	{

		m_LeftRightCheck = true;
		if (!(m_State == MState::Skill || m_State == MState::Kick || m_State == MState::Jump || m_State == MState::Punch))
		{
			m_State = MState::RightMove;
			m_Monster = m_RMove;
			m_Position.x += 5;
		}
	}
	else if (m_State == MState::LeftMove || m_State == MState::RightMove)
	{
		if (!(m_State == MState::Skill || m_State == MState::Jump))
		{
			m_State = MState::NONE;
		}
	}
	if (!(m_State == MState::Skill || m_State == MState::Kick || m_State == MState::Jump || m_State == MState::Punch || m_State == MState::RightMove || m_State == MState::LeftMove))
	{
		if (m_LeftRightCheck)
			m_Monster = m_RStand;
		else
			m_Monster = m_LStand;
	}
}

void Monster::Attack()
{
}

void Monster::Render()
{
	m_Monster->Render();
}

void Monster::OnCollision(Object* obj)
{
}
