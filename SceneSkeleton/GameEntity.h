#pragma once
#include "Node.h"
#include <memory>

class BoxCollider;
class SpriteNode;
namespace aie {
	class Texture;
}

class GameEntity : public Node {
public:
	GameEntity();
	GameEntity(aie::Texture *tex, Vector2 renderOrigin = Vector2(0.5, 0.5));
	virtual ~GameEntity();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

	void setOrigin(const Vector2 &origin);
	Vector2& getOrigin();

	void setSize(const Vector2 &size);
	Vector2& getSize();

	bool checkCollision(GameEntity *rhs);

protected:
	std::unique_ptr<SpriteNode> m_base;
	aie::Texture *m_baseSprite = nullptr;
	std::unique_ptr<BoxCollider> m_collider;
};

