#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	m_LStand = new Animation();
	m_LStand->SetParent(this);
	m_LStand->Init(0.2, true);
	m_LStand->AddContinueFrame(L"Painting/Fight/Kyo/Stand/", 11, 15);
	m_LStand->m_Scale /= 1.5;

	m_RStand = new Animation();
	m_RStand->SetParent(this);
	m_RStand->Init(0.2, true);
	m_RStand->AddContinueFrame(L"Painting/Fight/Kyo/Stand/", 21, 25);
	m_RStand->m_Scale /= 1.5;

	m_LPunch = new Animation();
	m_LPunch->SetParent(this);
	m_LPunch->Init(0.2, true);
	m_LPunch->AddContinueFrame(L"Painting/Fight/Kyo/Punch/", 21, 25);
	m_LPunch->m_Scale /= 1.5;

	m_RPunch = new Animation();
	m_RPunch->SetParent(this);
	m_RPunch->Init(0.2, true);
	m_RPunch->AddContinueFrame(L"Painting/Fight/Kyo/Punch/", 31, 35);
	m_RPunch->m_Scale /= 1.5;

	m_LKick = new Animation();
	m_LKick->SetParent(this);
	m_LKick->Init(0.2, true);
	m_LKick->AddContinueFrame(L"Painting/Fight/Kyo/Kick/", 11, 17);
	m_LKick->m_Scale /= 1.5;

	m_RKick = new Animation();
	m_RKick->SetParent(this);
	m_RKick->Init(0.2, true);
	m_RKick->AddContinueFrame(L"Painting/Fight/Kyo/Kick/", 21, 27);
	m_RKick->m_Scale /= 1.5;

	m_LJump = new Animation();
	m_LJump->SetParent(this);
	m_LJump->Init(0.2, true);
	m_LJump->AddContinueFrame(L"Painting/Fight/Kyo/Jump/", 11, 17);
	m_LJump->m_Scale /= 1.5;

	m_RJump = new Animation();
	m_RJump->SetParent(this);
	m_RJump->Init(0.2, true);
	m_RJump->AddContinueFrame(L"Painting/Fight/Kyo/Jump/", 21, 27);
	m_RJump->m_Scale /= 1.5;

	m_RMove = new Animation();
	m_RMove->SetParent(this);
	m_RMove->Init(0.2, true);
	m_RMove->AddContinueFrame(L"Painting/Fight/Kyo/RunRight/", 11, 16);
	m_RMove->m_Scale /= 1.5;

	m_LMove = new Animation();
	m_LMove->SetParent(this);
	m_LMove->Init(0.2, true);
	m_LMove->AddContinueFrame(L"Painting/Fight/Kyo/RunLeft/", 11, 16);
	m_LMove->m_Scale /= 1.5;

	m_LSit = new Animation();
	m_LSit->SetParent(this);
	m_LSit->Init(0.2, true);
	m_LSit->AddContinueFrame(L"Painting/Fight/Kyo/Sit/", 2, 3);
	m_LSit->m_Scale *= 2;

	m_RSit = new Animation();
	m_RSit->SetParent(this);
	m_RSit->Init(0.2, true);
	m_RSit->AddContinueFrame(L"Painting/Fight/Kyo/Sit/", 4, 5);
	m_RSit->m_Scale *= 2;

	m_Player = m_RStand;
	m_Player->SetParent(this);
	m_State = State::NONE;


	SetPosition(200, 900);
}

void Player::Update(float deltatime, float time)
{
	Move();
	Attack();
	m_Player->Update(deltatime, time);
}

void Player::Move()
{
	if (INPUT->GetKey('W') == KeyState::DOWN && m_Position.y > 100)
	{
		m_JumpCheck = true;
	}
	else if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x > 50)
	{
		m_State = State::LeftMove;
		m_LeftRightCheck = false;
		if (!(m_State == State::Skill || m_State == State::Kick || m_State == State::Jump || m_State == State::Punch))
			m_Player = m_LMove;
		m_Position.x -= 5;
	}
	else if (INPUT->GetKey('S') == KeyState::PRESS)
	{
		m_State = State::Sit;
		if (!(m_State == State::Skill || m_State == State::Kick || m_State == State::Jump || m_State == State::Punch))
		{
			if (m_LeftRightCheck)
				m_Player = m_RSit;
			else
				m_Player = m_LSit;
		}
	}
	else if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < 1820)
	{
		m_State = State::RightMove;
		m_LeftRightCheck = true;
		if (!(m_State == State::Skill || m_State == State::Kick || m_State == State::Jump || m_State == State::Punch))
			m_Player = m_RMove;
		m_Position.x += 5;
	}
	else
	{
		if(m_LeftRightCheck)
			m_Player = m_RStand;
		else
			m_Player = m_LStand;
	}

	if (m_JumpCheck)
	{
		m_State = State::Jump;
		if (!(m_State == State::Skill || m_State == State::Kick || m_State == State::Punch))
		{
			if (m_LeftRightCheck)
			{
				m_Player = m_RJump;

				if (m_Player->m_CurrentFrame < 3)
				{
					m_Position.y -= dt * 500;
				}
				else if (m_Player->m_CurrentFrame < 6)
				{
					m_Position.y += dt * 500;
				}

				if (m_Player->m_CurrentFrame >= 6)
				{
					if (m_LeftRightCheck)
						m_Player = m_RStand;
					else
						m_Player = m_LStand;

					m_Player->m_CurrentFrame = 0;
					m_JumpCheck = 0;
				}
			}
			else
			{
				m_Player = m_LJump;

				if (m_Player->m_CurrentFrame < 3)
				{
					m_Position.y -= dt * 500;
				}
				else if (m_Player->m_CurrentFrame < 6)
				{
					m_Position.y += dt * 500;
				}

				if (m_Player->m_CurrentFrame >= 6)
				{
					if (m_LeftRightCheck)
						m_Player = m_RStand;
					else
						m_Player = m_LStand;

					m_Player->m_CurrentFrame = 0;
					m_JumpCheck = 0;
				}
			}

			
		}

	}
}

void Player::Attack()
{
}

void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj)
{
}
