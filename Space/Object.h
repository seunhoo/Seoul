#pragma once
class Object
{
public:
	Object* m_Parent;
	Matrix m_wMat;
	Vec2 m_Position;
	Vec2 m_Scale;
	Vec2 m_Size;

	float m_Radius;
	float m_Rotation;

	bool m_Destroy;
	RECT m_Collision;

	bool m_Visible;

	int m_Layer;
	std::string m_Tag;

public:
	Object();
	~Object();


protected:
	Matrix GetMatrix();

public:
	virtual void Update(float deltaTime, float time);
	virtual void Render();
	virtual void OnCollision(Object* other);

public:
	void SetPosition(float x, float y);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	void SetTag(const std::string tag);
	void SetParent(Object* obj);
public:
	bool GetDestroy() { return m_Destroy; }
};                                                                                                                                                                                         