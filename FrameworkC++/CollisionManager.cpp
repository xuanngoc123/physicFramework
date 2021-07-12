#include"CollisionManager.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::checkCollision(vector<Object*> listObj) {
	for (int i = 0; i < listObj.size()-1; i++) {
		for (int j = i+1; j < listObj.size(); j++) {
			char *type1 = listObj.at(i)->type;
			char *type2 = listObj.at(j)->type;
			if ((strcmp(type1, "CIRCLE") == 0 && strcmp(type2, "PLANE") == 0)==1) {
				if (checkCollosionCircleAndPlane(listObj.at(i))) {
					//listObj.at(i)->iDrop = false;
					listObj.at(i)->fposition[1] = SCREEN_H - listObj.at(i)->GetRadius();
					cout << "edge collision detected" << endl;
				}
				continue;
			}
			else if ((strcmp(type1, "RECT") == 0 && strcmp(type2, "PLANE") == 0) == 1) {
				if (checkCollosionRectAndPlan(listObj.at(i))) {
					//listObj.at(i)->iDrop = false;
					listObj.at(i)->iVelocity = 0;
					listObj.at(i)->fposition[1] = SCREEN_H - listObj.at(i)->GetHeight();
					cout << "edge collision detected" << endl;
				}
				continue;
			}
			else if ((strcmp(type1, "RECT") == 0 && strcmp(type2, "RECT") == 0)) {
				checkCollosionRectAndRect(listObj.at(i), listObj.at(j));
				continue;
			}
				
			else if ((strcmp(type1, "RECT") == 0 && strcmp(type2, "CIRCLE") == 0)==1) {
				checkCollosionRectAndCircle(listObj.at(i), listObj.at(j));
				continue;
			}
			else if ((strcmp(type1, "CIRCLE") == 0 && strcmp(type2, "RECT") == 0)==1) {
				checkCollosionRectAndCircle(listObj.at(j), listObj.at(i));
				continue;
			}
			else if ((strcmp(type1, "CIRCLE") == 0 && strcmp(type2, "CIRCLE") == 0)) {
				checkCollosionCircleAndCircle(listObj.at(j), listObj.at(i));
				continue;
			}
		}
	}
}

void CollisionManager::checkCollosionRectAndRect(Object *rect1, Object *rect2) {
	/*if((rect2->fposition[0]>rect1->fposition[0] && rect2->fposition[0]<rect1->fposition[0] + rect1->GetWidth() && rect2->fposition[1]>rect1->fposition[1] && rect2->fposition[1]<rect1->fposition[1] + rect1->GetHeight()) == true) return true;
	if((rect2->fposition[0]+rect2->GetWidth()>rect1->fposition[0] && rect2->fposition[0] + rect2->GetWidth()<rect1->fposition[0] + rect1->GetWidth() && rect2->fposition[1]>rect1->fposition[1] && rect2->fposition[1]<rect1->fposition[1] + rect1->GetHeight()) == true) return true;
	if((rect2->fposition[0]>rect1->fposition[0] && rect2->fposition[0]<rect1->fposition[0] + rect1->GetWidth() && rect2->fposition[1]+rect2->GetHeight()>rect1->fposition[1] && rect2->fposition[1] + rect2->GetHeight()<rect1->fposition[1] + rect1->GetHeight()) == true) return true;
	if((rect2->fposition[0] + rect2->GetWidth()>rect1->fposition[0] && rect2->fposition[0] + rect2->GetWidth()<rect1->fposition[0] + rect1->GetWidth() && rect2->fposition[1] + rect2->GetHeight()>rect1->fposition[1] && rect2->fposition[1] + rect2->GetHeight()<rect1->fposition[1] + rect1->GetHeight()) == true) return true;
	return true;*/
	if (((rect1->fposition[0] + rect1->GetWidth()) < rect2->fposition[0]) || ((rect2->fposition[0] + rect2->GetWidth()) < rect1->fposition[0]) || ((rect1->fposition[1] + rect1->GetHeight()) < rect2->fposition[1]) || ((rect2->fposition[1] + rect2->GetHeight()) < rect1->fposition[1])) {
		if (rect1->iDrop == false) {
			rect1->iDrop = false;
			rect2->iDrop = true; return;
		}
		if (rect2->iDrop == false) {
			rect2->iDrop = false;
			rect1->iDrop = true;return;
		}
		if (rect2->iDrop == false && rect1->iDrop == false) {
			rect2->iDrop = false;
			rect1->iDrop = false;return;
		}
		rect1->iDrop = true;
		rect2->iDrop = true;
		return;
	}
	else {
		rect1->iDrop = false;
		rect2->iDrop = false;
		cout << "object collision detected" << endl;
	}
	
	
}
void CollisionManager::checkCollosionRectAndCircle(Object *rect, Object *circle) {
	//return checkOverlap(circle->GetRadius(), circle->fposition[0], circle->fposition[1], rect->fposition[0] , rect->fposition[1] +  rect->GetHeight(), rect->fposition[0] + rect->GetWidth(), rect->fposition[1]);
	int R = circle->GetRadius();
	int Xc = circle->fposition[0];
	int Yc = circle->fposition[1];
	int X1 = rect->fposition[0];
	int Y1 = rect->fposition[1];
	int X2 = rect->fposition[0] + rect->GetWidth();
	int Y2 = rect->fposition[1] + rect->GetHeight();
	/*int Xn = max(rect->fposition[0],min(circle->fposition[0],rect->fposition[0]+rect->GetWidth()));
	int Yn = max(rect->fposition[1],min(circle->fposition[1],rect->fposition[1] + rect->GetHeight()));
	int Dx = Xn - circle->fposition[0];
	int Dy = Yn - circle->fposition[1];
	if((Dx*Dx + Dy*Dy) <= (circle->GetRadius()*circle->GetRadius())) return true;
	return false;*/
	int Xn = max(X1, min(Xc, X2));
	int Yn = max(Y1, min(Yc, Y2));
	int Dx = Xn - Xc;
	int Dy = Yn - Yc;
	if ((Dx * Dx + Dy * Dy) <= R * R) {
		rect->iDrop = false;
		circle->iDrop = false;
	}
	else {
		if (circle->iDrop == false) {
			circle->iDrop = false;
			rect->iDrop = true; return;
		}
		if (rect->iDrop == false) {
			rect->iDrop = false;
			circle->iDrop = true;return;
		}
		if (circle->iDrop == false && rect->iDrop == false) {
			circle->iDrop = false;
			rect->iDrop = false;return;
		}
		circle->iDrop = true;
		rect->iDrop = true;
	}
}
bool CollisionManager::checkCollosionRectAndPlan(Object *rect) {
	if((SCREEN_H - rect->fposition[1]) <= rect->GetHeight()) return true;
	return false;
}

void CollisionManager::checkCollosionCircleAndCircle(Object *circle1, Object *circle2) {
	float kc = sqrt((circle1->fposition[0]-circle2->fposition[0])*(circle1->fposition[0] - circle2->fposition[0]) + (circle1->fposition[1] - circle2->fposition[1])*(circle1->fposition[1] - circle2->fposition[1]));
	if(kc-1 <= (circle1->GetRadius() + circle2->GetRadius())){
		circle1->iDrop = false;
		circle2->iDrop = false;
		cout << "object collision detected" << endl;
	}
	else
	{
		if(circle1->iDrop == false) {
			circle1->iDrop = false;
			circle2->iDrop = true; return;}
		if (circle2->iDrop == false) { 
			circle2->iDrop = false;
			circle1->iDrop = true;return;
		}
		if (circle2->iDrop == false && circle1->iDrop == false) {
			circle2->iDrop = false;
			circle1->iDrop = false;return;
		}
		circle1->iDrop = true;
		circle2->iDrop = true;
	}
}
bool CollisionManager::checkCollosionCircleAndPlane(Object *circle) {
	if ((SCREEN_H - circle->fposition[1]) <= circle->GetRadius()) return true;
	return false;
}
float CollisionManager::GetWidth() {
	return 0;
 }
 float CollisionManager::GetHeight(){
	return 0;
 }
 float CollisionManager::GetRadius(){
	return 0;
 }

 void CollisionManager::Render() {}
 void CollisionManager::HighLight() {}
void CollisionManager::Update(float deltaTime) {}
void CollisionManager::Move(float, float){}