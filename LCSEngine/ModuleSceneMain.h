#ifndef __MODULESCENEMAIN_H__
#define __MODULESCENEMAIN_H__

#include "Module.h"

class Shader;
class AssetTexture;
class GameObject;

class ModuleSceneMain : public Module
{
public:
	ModuleSceneMain(bool active = true);
	~ModuleSceneMain();

	bool init() override;
	bool start() override;
	update_status preUpdate(float deltaTime);
	update_status update(float deltaTime);
	bool cleanUp() override;
	void clearGameObjects(); 
	void preUpdateGameObjects();
	void draw();
	void drawGameObjects(GameObject* gameObject);
	void drawGrid();
	void swapDefaultShader();
	void checkVisibleItems();

public:
	AssetTexture * checkers = nullptr;
	AssetTexture* lenna = nullptr;
	AssetTexture* chocobo = nullptr;
	AssetTexture* beer = nullptr;
	AssetTexture* actual = nullptr;
	Shader* shader = nullptr;
	GameObject* root = nullptr;
	GameObject* currentObject = nullptr;

	bool drawZbuffer = false;
};
#endif //__MODULESCENEMAIN_H__
