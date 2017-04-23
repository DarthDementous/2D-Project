#include "SpriteNode.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Utility.h>


SpriteNode::SpriteNode() {
}

SpriteNode::SpriteNode(aie::Texture * tex) {
	m_sprite = tex;
	m_size = Vector2(tex->getWidth(), tex->getHeight());
}

SpriteNode::~SpriteNode() {
}

void SpriteNode::render(aie::Renderer2D * renderer) {
	if (m_sprite == nullptr) return;

	Matrix3 gTransform = calculateGlobalTransform();
	Vector2 scale = Vector2(gTransform[0].magnitude(), gTransform[1].magnitude());
	float rot = gTransform.getRotationZ();
	Vector2 pos = gTransform.getTranslation();

	renderer->drawSprite(m_sprite, pos.x, pos.y, m_size.x, m_size.y, rot, 0, m_origin.x, m_origin.y);
}

void SpriteNode::setSize(const Vector2 & size) {
	m_size = size;
}

Vector2& SpriteNode::getSize() {
	return m_size;
}

void SpriteNode::setOrigin(const Vector2 & origin) {
	m_origin = origin;
}

Vector2 & SpriteNode::getOrigin() {
	return m_origin;
}
