#pragma once
#include "SDL_render.h"
//class SDL_Texture;

class Image {
public:
	Image(SDL_Texture* surf);
	SDL_Texture* getTexture() const;
private:
	SDL_Texture* imageb;
};