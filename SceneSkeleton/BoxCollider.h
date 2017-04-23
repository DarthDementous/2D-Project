#pragma once
#include "Node.h"
#include <vector>

class BoxCollider : public Node {
public:
	BoxCollider();
	BoxCollider(float width, float height);
	~BoxCollider();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

	void setParent(Node *parent);

	void setSize(const Vector2 &rhs);
	Vector2& getSize();

protected:
	std::vector<Vector2> m_points;
	Vector2 m_size;
};

