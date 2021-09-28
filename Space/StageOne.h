#pragma once
class StageOne : public Scene
{
public:

	Animation* m_BG;


public:

	StageOne();

	void Init();
	void Release();
	void Update(float deltatime, float time);
	void Render();
};

