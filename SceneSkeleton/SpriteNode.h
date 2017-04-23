#pragma once
#include "Node.h"
namespace aie {
	class Texture;
	class Renderer2D;
}

class SpriteNode : public Node {
public:
	SpriteNode();
	SpriteNode(aie::Texture *tex);
	virtual ~SpriteNode();

	void render(aie::Renderer2D *renderer);

	void setSize(const Vector2 &size);
	Vector2& getSize();

	void setOrigin(const Vector2 &origin);
	Vector2& getOrigin();

	//bool checkCollision()

protected:
	aie::Texture *m_sprite;
	Vector2 m_size, m_origin = Vector2(0.5, 0.5);
};

