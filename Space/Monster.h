#pragma once
enum class State
{
	Punch,
	Kick,
	Jump,
	RightMove,
	LeftMove,
	Skill,
	Sit,
	NONE
};
enum class MoveState
{
	Right,
	Left,
	NONE
};
class Monster : public Object
{
public:


	Animation* m_LStand;
	Animation* m_RStand;

	Animation* m_RPunch;
	Animation* m_LPunch;

	Animation* m_RKick;
	Animation* m_LKick;

	Animation* m_LJump;
	Animation* m_RJump;

	Animation* m_RMove;
	Animation* m_LMove;

	Animation* m_RSit;
	Animation* m_LSit;

	Animation* m_Monster;

	Animation* m_RSkill;
	Animation* m_LSkill;


	Monster(float posx,float posy,int type);

	int m_Type;

	State m_State;

	MoveState m_MoveState;

	bool m_LeftRightCheck;

	void Update(float deltatime, float time);
	void Move();
	void Attack();
	void Render();
	void OnCollision(Object* obj);
};

