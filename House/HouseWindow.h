#ifndef HOUSEWINDOW_H_
#define HOUSEWINDOW_H_
#include "Window.h"
#include "Model.h"
#include "Texture.h"

class HouseWindow: public Window
{
private:
	Model _house_model;
	Texture _house_texture {"Houses.png"};
	double _angle = 0.0;

public:
	static constexpr int WINDOW_WIDTH = 1024;
	static constexpr int WINDOW_HEIGHT = 768;

	virtual void update() override;
	virtual void render() override;
	virtual void setupGL() override;

public:
	HouseWindow();
	virtual ~HouseWindow() = default;
};

#endif /* HOUSEWINDOW_H_ */
