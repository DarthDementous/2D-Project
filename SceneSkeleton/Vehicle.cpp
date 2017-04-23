#include "Vehicle.h"
#include "SpriteNode.h"

#include <Input.h>
#include <Utility.h>

Vehicle::Vehicle(aie::Texture *tex) : GameEntity(tex) {
	m_moveFW = m_moveBW = m_turnL = m_turnR = false;
}

Vehicle::~Vehicle() {
}

void Vehicle::update(float dt) {
	//Call the parent update method
	GameEntity::update(dt);

	//Update movement positions
	if (m_moveFW)
		m_speed = Vector2(cosf(getLocRot()) * TANK_MOVE_SPEED, sinf(getLocRot()) * TANK_MOVE_SPEED);
	else if (m_moveBW)
		m_speed = Vector2(-cosf(getLocRot()) * TANK_MOVE_SPEED, -sinf(getLocRot()) * TANK_MOVE_SPEED);
	else
		m_speed = Vector2(0, 0);
	if (m_turnL)
		m_turnSpeed = TANK_TURN_SPEED;
	else if (m_turnR)
		m_turnSpeed = -TANK_TURN_SPEED;
	else m_turnSpeed = 0;


	// Perform calculations in the order scale->rotation->translation
	m_base->rotate(m_turnSpeed * dt);
	m_base->translate(m_speed * dt);
}

void Vehicle::updateControls(aie::Input * input) {
	if (input->isKeyDown(m_controls[UP_KEY]))
		m_moveFW = true;
	if (input->isKeyDown(m_controls[DOWN_KEY]))
		m_moveBW = true;
	if (input->isKeyDown(m_controls[LEFT_KEY]))
		m_turnL = true;
	if (input->isKeyDown(m_controls[RIGHT_KEY]))
		m_turnR = true;

	if (input->isKeyUp(m_controls[UP_KEY]))
		m_moveFW = false;
	if (input->isKeyUp(m_controls[DOWN_KEY]))
		m_moveBW = false;
	if (input->isKeyUp(m_controls[LEFT_KEY]))
		m_turnL = false;
	if (input->isKeyUp(m_controls[RIGHT_KEY]))
		m_turnR = false;
}

void Vehicle::render(aie::Renderer2D * renderer) {
	GameEntity::render(renderer);
}

void Vehicle::setSpeed(const Vector2 & speed) {
	m_speed = speed;
}

Vector2 & Vehicle::getSpeed() {
	return m_speed;
}

void Vehicle::setTurnSpeed(const float & turnSpeed) {
	m_turnSpeed = turnSpeed;
}

float & Vehicle::getTurnSpeed() {
	return m_turnSpeed;
}

void Vehicle::setControls(aie::EInputCodes fwKey, aie::EInputCodes bwKey, aie::EInputCodes lKey, aie::EInputCodes rKey) {
	m_controls[UP_KEY] = fwKey;
	m_controls[DOWN_KEY] = bwKey;
	m_controls[LEFT_KEY] = lKey;
	m_controls[RIGHT_KEY] = rKey;
}
