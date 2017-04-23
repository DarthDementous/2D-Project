#include "Tank.h"
#include "SpriteNode.h"
#include <Renderer2D.h>
#include <Input.h>
#include <Utility.h>

Tank::Tank(aie::Texture *baseTex, aie::Texture *turretTex) : Vehicle(baseTex) {
	m_turnTurretL = m_turnTurretR = false;

	m_turretSprite = turretTex;
	m_turret = std::unique_ptr<SpriteNode>(new SpriteNode(m_turretSprite));
	m_turret->setOrigin(Vector2(0.f, 0.5f));
	m_turret->setParent(m_base.get());
}


Tank::~Tank() {
}

void Tank::update(float dt) {
	//Call the parent update function
	Vehicle::update(dt);
	
	//Set the turn direction and speed
	if (m_turnTurretL)
		m_turretTurnSpeed = TANK_TURRET_TURN_SPEED;
	else if (m_turnTurretR)
		m_turretTurnSpeed = -TANK_TURRET_TURN_SPEED;
	else
		m_turretTurnSpeed = 0;

	m_turret->rotate(m_turretTurnSpeed * dt);
}

void Tank::render(aie::Renderer2D * renderer) {
	Vehicle::render(renderer);
	m_turret->render(renderer);
}

void Tank::updateTurretControls(MCOORD &deltaMouse) {
	//float dx = deltaMouse.x - getLocPos().x, dy = deltaMouse.y - getLocPos().y;
	//m_turret->setRotation(atan2(dy, dx));
}

void Tank::updateTurretControls(aie::Input *input) {
	if (input->isKeyDown(m_controls[TANK_TURRET_LEFT]))
		m_turnTurretL = true;
	if (input->isKeyDown(m_controls[TANK_TURRET_RIGHT]))
		m_turnTurretR = true;

	if (input->isKeyUp(m_controls[TANK_TURRET_LEFT]))
		m_turnTurretL = false;
	if (input->isKeyUp(m_controls[TANK_TURRET_RIGHT]))
		m_turnTurretR = false;
}

void Tank::setTurretControls(aie::EInputCodes turnL, aie::EInputCodes turnR) {
	m_controls[TANK_TURRET_LEFT] = turnL;
	m_controls[TANK_TURRET_RIGHT] = turnR;
}
