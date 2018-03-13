#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__

#include "ElementGameUI.h"

class UILabel;
class UIImage;

enum State
{
	IDLE,
	HOVER,
	CLICK,
	DISABLED
};

class UIButton : public ElementGameUI
{
public:
	UIButton(GameObject* parent, int x, int y, int h, int w, bool isVisible = true);
	~UIButton();
	void drawGUI() override;
	void deleteElementButton();
	void update();

public:
	State state = IDLE;
	UIImage* activeImage = nullptr;

private:
	UILabel* label = nullptr;
	UIImage* background = nullptr;
	UIImage* hover = nullptr;
	UIImage* pressed = nullptr;
	UIImage* disabled = nullptr;
};

#endif //__UIBUTTON_H__