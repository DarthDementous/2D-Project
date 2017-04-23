#include "SceneSkeletonApp.h"
#include <Texture.h>
#include <Font.h>
#include <Input.h>
#include <Utility.h>

#include "ResourceManager.h"

#include "Settings.h"

#include "Node.h"
#include "GameEntity.h"
#include "Tank.h"

#include <iostream>

#pragma region Constructor/Destructor
SceneSkeletonApp::SceneSkeletonApp() {

}

SceneSkeletonApp::~SceneSkeletonApp() {

}
#pragma endregion

#pragma region Initialisers
void SceneSkeletonApp::initTextures() {
	m_textureList[TANK_BASE_TEX] = ResourceManager::loadSharedResource<aie::Texture>("./textures/tankBlue.png");
	m_textureList[TANK_TURRET_TEX] = ResourceManager::loadSharedResource<aie::Texture>("./textures/barrelBlue.png");
	m_textureList[BOULDER_TEX] = ResourceManager::loadSharedResource<aie::Texture>("./textures/rock_large.png");
}
#pragma endregion

bool SceneSkeletonApp::startup() {
	m_2dr = std::unique_ptr<aie::Renderer2D>(new aie::Renderer2D());

	initTextures();

	tank = std::unique_ptr<Tank>(new Tank(m_textureList[TANK_BASE_TEX].get(), m_textureList[TANK_TURRET_TEX].get()));
	tank->setControls(aie::INPUT_KEY_W, aie::INPUT_KEY_S, aie::INPUT_KEY_A, aie::INPUT_KEY_D);
	tank->setTurretControls(aie::INPUT_KEY_Q, aie::INPUT_KEY_E);
	tank->translate(Vector2(300, 300));
	m_nodes.push_back(tank.get());

	rock = std::unique_ptr<GameEntity>(new GameEntity(m_textureList[BOULDER_TEX].get()));
	rock->translate(Vector2(1000, 800));
	m_nodes.push_back(rock.get());

	//tank->setDebug(true);
	//rock->setDebug(true);

	return true;
}

void SceneSkeletonApp::shutdown() {
}

void SceneSkeletonApp::update(float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	MCOORD currentMousePos;
	input->getMouseXY(&currentMousePos.x, &currentMousePos.y);

	tank->updateControls(input);
	tank->updateTurretControls(input);

	tank->checkCollision(rock.get());

	rock->translate(Vector2(0.01f, 0));
	rock->rotate(0.001f);
	rock->update(deltaTime);

	for (size_t i = 0; i < m_nodes.size(); ++i)
		m_nodes[i]->update(deltaTime);
}

void SceneSkeletonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dr->begin();

	// Render all of the nodes
	for (size_t i = 0; i < m_nodes.size(); ++i) {
		m_nodes[i]->render(m_2dr.get());
	}

	// done drawing sprites
	m_2dr->end();
}