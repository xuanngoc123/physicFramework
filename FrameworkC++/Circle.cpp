#include"Circle.h"

Circle::Circle(float x, float y, float radius, float velocity, float mass) {
	fposition[0] = x;
	fposition[1] = y;
	m_fRadius = radius;
	iVelocity = velocity;
	iMass = mass;
	type = "CIRCLE";
	time =0;
	iDrop = true;
}
Circle::~Circle() {

}
void Circle::Render() {
	VideoDriver::GetInstance()->DrawCircle(fposition[0], fposition[1], m_fRadius);
}
void Circle::HighLight() {
	VideoDriver::GetInstance()->DrawCircle(fposition[0], fposition[1], m_fRadius-1);
}
float Circle::GetRadius() {
	return m_fRadius;
}
void Circle::Move(float x, float y) {
	fposition[0] = x;
	fposition[1] = y;
}
void Circle::Update(float deltaTime) {
	if (fposition[0] < m_fRadius) {
		fposition[0] = m_fRadius;
	}
	if (fposition[1] < m_fRadius) {
		fposition[1] = m_fRadius;
	}
	if (fposition[0] + m_fRadius-1 >= SCREEN_W) {
		fposition[0] = SCREEN_W - m_fRadius;
	}
	if (fposition[1] + m_fRadius-1 >= SCREEN_H ) {
		fposition[1] = SCREEN_H - m_fRadius;
	}
	//time += deltaTime;
	//iVelocity = G* time + iVelocity;
	fposition[1]+=1;
}
float Circle::GetWidth() {
	return 0;

}
float Circle::GetHeight() {
	return 0;
}