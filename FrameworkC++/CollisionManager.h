#pragma once
#include"Object.h"
#include"Rect.h"
#include"Circle.h"
#include<vector>
class CollisionManager: public Object
{
public:
	CollisionManager();
	~CollisionManager();
	void checkCollision(vector<Object*> listObj);
	//void collisionHanding(vector<Object*> listObj);
	void checkCollosionRectAndRect(Object *rect1, Object *rect2);
	void checkCollosionRectAndCircle(Object *rect, Object *circle);
	bool checkCollosionRectAndPlan(Object *rect);
	void checkCollosionCircleAndCircle(Object *circle1, Object *circle2);
	bool checkCollosionCircleAndPlane(Object *circle);


	float GetWidth();
	 float GetHeight();
	 float GetRadius();
	 void Render();
	 void HighLight();
	void Update(float deltaTime);
	void Move(float, float);
	
};

