#pragma once
enum class MState
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
enum class MMoveState
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

	wstring m_MonsterName;

	int m_Type;

	MState m_State;

	MMoveState m_MoveState;

	bool m_LeftRightCheck;

	float m_MoveTime;
	bool m_MoveCheck;

	float m_AttackTime;
	bool m_AttackCheck;

	float m_SkillTime;
	bool m_SkillCheck;

	bool m_Start;

	void Update(float deltatime, float time);
	void Move();
	void Attack();
	void Render();
	void OnCollision(Object* obj);
};

