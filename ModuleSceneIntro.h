#ifndef __ModuleSceneIntro_H__
#define __ModuleSceneIntro_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModuleSceneIntro :
	public Module
{
private:
	SDL_Texture* background;
	Mix_Chunk* bg_music;
	Mix_Chunk* start_fx;
	float intro_time_s = 0.0f;

public:
	bool Init();
	bool Start();
	update_status Update();
	bool CleanUp();

	ModuleSceneIntro();
	~ModuleSceneIntro();
};


#endif // !__ModuleSceneIntro_H__