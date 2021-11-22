#pragma once
#include "../../Utils.h"
#include "InputListener.h"

const float JOYSTICK_DEADZONE = 0.13f;

class Input{
public:
	enum MouseState : uint8_t {
		LEFT,
		RIGHT,
		MID
	};

	static bool Init();
	static void Tick();
	static void Release();

	static void GetAxis(float& horizontal, float& vertical);
	static int GetZoom();

private:
	// Listener para escuchar los eventos de Platform
	static InputListener _inputListener;

	// Informacion sobre el input recibido en el frame
	static InputInfo _frameInfo;

	// Referencia al teclado para toda la ejecucion
	static const uint8_t* _keyboard;

	// referencia al GamePad para toda la ejecuci�n
	static SDL_GameController* _controller;
	static int32_t _currentController;
};
