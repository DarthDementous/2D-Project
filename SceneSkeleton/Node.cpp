#include "Node.h"
#include <Renderer2D.h>

Node::Node() {
}

Node::~Node() {
}

void Node::update(float dt) {
}

void Node::render(aie::Renderer2D * renderer) {
	if (m_debugDraw) {
		Matrix3 gTransform = calculateGlobalTransform();
		Vector2 pos = gTransform.getTranslation();
		float rot = gTransform.getRotationZ();

		renderer->drawBox(pos.x, pos.y, 10, 12, rot);
	}
}

void Node::setSize(const Vector2 & size) {
}

Vector2 & Node::getSize() {
	return Vector2();
}

void Node::setParent(Node * parent) {
	m_parent = parent;
}

Matrix3 & Node::getTransform() {
	return m_local;
}

Matrix3 Node::calculateGlobalTransform() const {
	if (m_parent == nullptr) return m_local;

	return m_parent->calculateGlobalTransform() * m_local;
}

void Node::translate(const Vector2 & pos) {
	Matrix3 translation = Matrix3::createTranslation(pos);
	m_local = m_local * translation;
}

void Node::rotate(float radians) {
	Matrix3 rotation = Matrix3::createRotation(radians);
	m_local = m_local * rotation;
}

void Node::setRotation(float radians) {
	m_local.setRotateZ(radians);
}

Vector2 Node::getLocPos() {
	return m_local.getTranslation();
}

float Node::getLocRot() {
	return m_local.getRotationZ();
}

void Node::setDebug(bool flag) {
	m_debugDraw = flag;
}