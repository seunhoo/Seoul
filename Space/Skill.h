#pragma once
class Skill : public Object
{
public:

	Animation* m_Skill;

	Skill(float posx,float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);
};

