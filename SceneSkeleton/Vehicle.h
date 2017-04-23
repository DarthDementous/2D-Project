#pragma once
#include "GameEntity.h"
#include "Settings.h"

#include <vector>
#include <map>
using std::map;
namespace aie {
	class Input;
	enum EInputCodes;
}

class Vehicle : public GameEntity {
public:
	Vehicle(aie::Texture *tex);
	virtual ~Vehicle();

	virtual void update(float dt);
	virtual void updateControls(aie::Input *input);
	virtual void render(aie::Renderer2D *renderer);

	void setSpeed(const Vector2 &speed);
	Vector2& getSpeed();

	void setTurnSpeed(const float &turnSpeed);
	float& getTurnSpeed();

	void setControls(aie::EInputCodes fwKey, aie::EInputCodes bwKey, aie::EInputCodes lKey, aie::EInputCodes rKey);
	
protected:
	Vector2 m_speed = Vector2(0, 0);
	float m_turnSpeed = 0;
	
	bool m_moveFW, m_moveBW, m_turnL, m_turnR;
	map<eControlCode, aie::EInputCodes> m_controls;

	std::vector<std::unique_ptr<GameEntity>> m_components;
};

