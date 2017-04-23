#pragma once
#include "Node.h"
#include <vector>

class BoxCollider : public Node {
public:
	BoxCollider();
	BoxCollider(float width, float height);
	~BoxCollider();

protected:
	std::vector<Vector2> m_points;
};

