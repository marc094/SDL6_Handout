#ifndef __ModuleSound_H__
#define __ModuleSound_H__

#include "Module.h"
#include "Globals.h"

#define MAX_SOUNDS 20

struct Mix_Chunk;
class _Mix_Music;
typedef _Mix_Music Mix_Music;

class ModuleSound :
	public Module
{
public:
	Mix_Chunk* sounds[MAX_SOUNDS];
	Mix_Music* music;
	uint last_sound = 0;

	bool Init();
	Mix_Chunk* LoadSound(const char* path);
	Mix_Music* LoadMusic(const char* path);
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool PlayMusic();
	void StopMusic(bool pause = false);
	void StopAll();
	bool PlaySound(Mix_Chunk* sound, int loops);
	bool isPlaying();
	bool CleanUp();

	ModuleSound();
	~ModuleSound();
};

#endif // __ModuleSound_H__