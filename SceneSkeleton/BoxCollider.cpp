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
	Matrix3& gMat = m_parent->calculateGlobalTransform();
	float rot = gMat.getRotationZ();
	float halfWidth = m_parent->getSize().x / 2;
	float halfHeight = m_parent->getSize().y / 2;
	float radius = sqrt((halfWidth*halfWidth) + (halfHeight*halfHeight));

	Vector2 pos = gMat.getTranslation();

	m_points[0]->translate(Vector2(pos.x + getSize().x / 2, pos.y + getSize().y / 2));
	m_points[1]->translate(Vector2(pos.x + getSize().x / 2, pos.y - getSize().y / 2));
	m_points[2]->translate(Vector2(pos.x - getSize().x / 2, pos.y - getSize().y / 2));
	m_points[3]->translate(Vector2(pos.x - getSize().x / 2, pos.y + getSize().y / 2));

	//m_points[0]->translate(Vector2(radius * cosf(rot), radius * sinf(rot)));
	//m_points[1]->translate(Vector2(radius * cosf(rot), -radius * sinf(rot)));
	//m_points[2]->translate(Vector2(-radius * cosf(rot), -radius * sinf(rot)));
	//m_points[3]->translate(Vector2(-radius * cosf(rot), radius * sinf(rot)));
}

void BoxCollider::render(aie::Renderer2D * renderer) {
	if (m_debugDraw && m_points.size() > 0) {
		//Matrix3 gTransform = calculateGlobalTransform();
		
		

		renderer->setRenderColour(0x00ff0080);
		for (size_t i = 0; i < m_points.size(); ++i) {
			Vector2 pos = m_points[i]->getTransform().getTranslation();
			renderer->drawBox(pos.x, pos.y, 5, 5);
		}

		//renderer->setRenderColour(0xff0000f0);
		//renderer->drawLine(pos.x + m_points[0].x, pos.y + m_points[0].y, pos.x + m_points[1].x, pos.y + m_points[1].y);	//East
		//renderer->drawLine(pos.x + m_points[1].x, pos.y + m_points[1].y, pos.x + m_points[2].x, pos.y + m_points[2].y);	//South
		//renderer->drawLine(pos.x + m_points[2].x, pos.y + m_points[2].y, pos.x + m_points[3].x, pos.y + m_points[3].y);	//West
		//renderer->drawLine(pos.x + m_points[3].x, pos.y + m_points[3].y, pos.x + m_points[0].x, pos.y + m_points[0].y);	//North
		
		renderer->setRenderColour(0xffffffff);
	}
}

void BoxCollider::setParent(Node * parent) {
	Node::setParent(parent);
	setSize(parent->getSize());

	m_points.push_back(std::unique_ptr<Node>(new Node()));
	m_points.push_back(std::unique_ptr<Node>(new Node()));
	m_points.push_back(std::unique_ptr<Node>(new Node()));
	m_points.push_back(std::unique_ptr<Node>(new Node()));

	Vector2 pos = getLocPos();

	m_points[0]->translate(Vector2(pos.x + getSize().x / 2, pos.y + getSize().y / 2));
	m_points[1]->translate(Vector2(pos.x + getSize().x / 2, pos.y - getSize().y / 2));
	m_points[2]->translate(Vector2(pos.x - getSize().x / 2, pos.y - getSize().y / 2));
	m_points[3]->translate(Vector2(pos.x - getSize().x / 2, pos.y + getSize().y / 2));
}

void BoxCollider::setSize(const Vector2 & rhs) {
	m_size = rhs;
}

Vector2 & BoxCollider::getSize() {
	return m_size;
}
