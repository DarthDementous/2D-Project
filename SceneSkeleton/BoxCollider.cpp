#include "BoxCollider.h"
#include <Vector2.h>
#include <Renderer2D.h>

#include <iostream>

BoxCollider::BoxCollider() {
}

BoxCollider::BoxCollider(float width, float height) {
	
}

BoxCollider::~BoxCollider() {
}

void BoxCollider::update(float dt) {
	for (size_t i = 0; i < m_points.size(); ++i) {
		m_points[i] = m_local * m_points[i];
	}
}

void BoxCollider::render(aie::Renderer2D * renderer) {
	if (m_debugDraw && m_points.size() > 0) {
		Matrix3 gTransform = calculateGlobalTransform();
		Vector2 pos = gTransform.getTranslation();

		renderer->setRenderColour(0x00ff0080);
		for (size_t i = 0; i < m_points.size(); ++i)
			renderer->drawBox(pos.x + m_points[i].x, pos.y + m_points[i].y, 5, 5);

		renderer->setRenderColour(0xff0000f0);
		renderer->drawLine(pos.x + m_points[0].x, pos.y + m_points[0].y, pos.x + m_points[1].x, pos.y + m_points[1].y);	//East
		renderer->drawLine(pos.x + m_points[1].x, pos.y + m_points[1].y, pos.x + m_points[2].x, pos.y + m_points[2].y);	//South
		renderer->drawLine(pos.x + m_points[2].x, pos.y + m_points[2].y, pos.x + m_points[3].x, pos.y + m_points[3].y);	//West
		renderer->drawLine(pos.x + m_points[3].x, pos.y + m_points[3].y, pos.x + m_points[0].x, pos.y + m_points[0].y);	//North
		
		renderer->setRenderColour(0xffffffff);
	}
}

void BoxCollider::setParent(Node * parent) {
	Node::setParent(parent);
	setSize(parent->getSize());

	m_points.push_back(Vector2(getSize().x / 2, getSize().y / 2));
	m_points.push_back(Vector2(getSize().x / 2, -getSize().y / 2));
	m_points.push_back(Vector2(-getSize().x / 2, -getSize().y / 2));
	m_points.push_back(Vector2(-getSize().x / 2, getSize().y / 2));
}

void BoxCollider::setSize(const Vector2 & rhs) {
	m_size = rhs;
}

Vector2 & BoxCollider::getSize() {
	return m_size;
}
