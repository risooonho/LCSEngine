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
	bool cleanUp() override;
	void omaeWaMouShindeiru();
	void draw();
	void drawGrid();

public:
	AssetTexture * checkers = nullptr;
	AssetTexture* lenna = nullptr;
	AssetTexture* chocobo = nullptr;
	AssetTexture* beer = nullptr;
	AssetTexture* actual = nullptr;
	Shader* shader = nullptr;
	GameObject* root = nullptr;
	GameObject* currentObject = nullptr;
};
#endif //__MODULESCENEMAIN_H__
