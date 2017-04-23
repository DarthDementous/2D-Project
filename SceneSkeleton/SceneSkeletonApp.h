#pragma once
#include <memory>
#include <vector>
#include <map>
#include "Application.h"
#include "Renderer2D.h"
#include "Settings.h"
class Node;
class Tank;
class GameEntity;

class SceneSkeletonApp : public aie::Application {
public:

	SceneSkeletonApp();
	virtual ~SceneSkeletonApp();

	void initTextures();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();


protected:
	std::unique_ptr<aie::Renderer2D>	m_2dr;
	std::map<eTexID, std::shared_ptr<aie::Texture>> m_textureList;

	std::vector<Node*> m_nodes;

	std::unique_ptr<Tank> tank;
	std::unique_ptr<GameEntity> rock;
};