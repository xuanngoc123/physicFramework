#pragma once
#include "Object.h"
#include"videoDriver.h"
class Circle : public Object
{
public:
	Circle(float x, float y, float radius, float velocity, float mass=1);
	~Circle();
	void Render();
	float GetRadius();
	void HighLight();
	void Move(float, float);
	void Update(float deltaTime);


	 float GetWidth();
	 float GetHeight();
	

public:
	float m_fRadius;
};