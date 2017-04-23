#pragma once
#include "Vehicle.h"
#include "Settings.h"

class Tank :
	public Vehicle {
public:
	Tank(aie::Texture *tex, aie::Texture *turretTex);
	~Tank();

	void update(float dt);
	void render(aie::Renderer2D *renderer);
	void updateTurretControls(MCOORD &deltaMouse);
	void updateTurretControls(aie::Input *input);
	void setTurretControls(aie::EInputCodes turnL, aie::EInputCodes turnR);

private:
	std::unique_ptr<SpriteNode> m_turret;
	aie::Texture *m_turretSprite;

	bool m_turnTurretL, m_turnTurretR;
	float m_turretTurnSpeed = 0;
};

