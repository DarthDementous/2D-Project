#pragma once
#include <Matrix3.h>
#include <Vector2.h>

namespace aie {
	class Renderer2D;
}

class Node {
public:
	Node();
	//Node(float x, float y);
	virtual ~Node();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

	virtual void setSize(const Vector2 &size);
	virtual Vector2& getSize();

	virtual void setParent(Node *parent);

	Matrix3& getTransform();
	Matrix3 calculateGlobalTransform() const;

	void translate(const Vector2 &pos);
	void rotate(float radians);
	void setRotation(float radians);

	// Get local coordinates
	Vector2 getLocPos();
	// Get local rotation amount
	float getLocRot();

	void setDebug(bool flag);

protected:
	Node *m_parent = nullptr;
	Matrix3 m_local;
	bool m_debugDraw = false;
};