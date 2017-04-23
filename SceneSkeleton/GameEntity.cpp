#include "GameEntity.h"
#include "SpriteNode.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "BoxCollider.h"

#include <iostream>


GameEntity::GameEntity() {
}

GameEntity::GameEntity(aie::Texture * tex, Vector2 renderOrigin) {
	m_baseSprite = tex;
	m_base = std::unique_ptr<SpriteNode>(new SpriteNode(m_baseSprite));
	m_base->setParent(this);

	m_collider = std::unique_ptr<BoxCollider>(new BoxCollider());
	m_collider->setParent(this);
	m_collider->setDebug(true);
}

GameEntity::~GameEntity() {
}

void GameEntity::update(float dt) {
	Node::update(dt);
	m_collider->update(dt);
}

void GameEntity::render(aie::Renderer2D *renderer) {
	m_base->render(renderer);
	if (m_debugDraw) {
		// Draw the sprite's collision box
		renderer->setRenderColour(0xff000040);
		Vector2 colliderPos = m_base->calculateGlobalTransform().getTranslation();
		renderer->drawBox(colliderPos.x, colliderPos.y, getSize().x, getSize().y,
			m_base->getLocRot());
		renderer->setRenderColour(0xffffffff);
	}
	m_collider->render(renderer);
}

void GameEntity::setOrigin(const Vector2 & origin) {
	m_base->setOrigin(origin);
}

Vector2 & GameEntity::getOrigin() {
	return m_base->getOrigin();
}

void GameEntity::setSize(const Vector2 & size) {
	m_base->setSize(size);
}

Vector2 & GameEntity::getSize() {
	return m_base->getSize();
}

bool GameEntity::checkCollision(GameEntity *rhs) {
	static int counter;

	Vector2 colliderPos = m_base->calculateGlobalTransform().getTranslation();
	float colliderRot = m_base->getLocRot();

	Vector2 rhsPos = rhs->m_base->calculateGlobalTransform().getTranslation();
	float rhsRot = rhs->m_base->getLocRot();

	Vector3 P1 = Vector3(rhsPos.x - colliderPos.x, rhsPos.y - colliderPos.y, 1);
	
	

#if 0
	if (colliderPos.x + ((getSize().x / 2) * cosf(colliderRot)) < rhsPos.x - ((getSize().x / 2) * cosf(rhsRot)) ||	//Right->Left collision
		colliderPos.x - ((getSize().x / 2) * cosf(colliderRot)) > rhsPos.x + ((getSize().x / 2) * cosf(rhsRot)))	//Left->Right collision
		return false; // If there is no possible horizontal collision
	if (colliderPos.y + ((getSize().y / 2) * cosf(colliderRot)) < rhsPos.y - ((getSize().y / 2) * cosf(rhsRot)) ||	//Top->Bottom collision
		colliderPos.y - ((getSize().y / 2) * cosf(colliderRot)) > rhsPos.y + ((getSize().y / 2) * cosf(rhsRot)))	//Bottom->top collision
		return false; // If there is no possible vertical collision

	//std::cout << colliderPos.x + ((getSize().x/2) * cosf(colliderRot)) << ", " << //Right edge
	//			 colliderPos.y + ((getSize().y/2) * cosf(colliderRot)) << "\t" << //Top edge
	//			 rhsPos.x - ((getSize().x/2) * cosf(rhsRot)) << ", " << 
	//			 rhsPos.y - ((getSize().y/2) * cosf(rhsRot)) << "\n";
#endif

	//std::cout << "Collison: " << counter++;
	return true;
}