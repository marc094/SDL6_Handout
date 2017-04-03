#include "ModuleSceneIntro.h"
#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSpace.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSound.h"
#include "SDL\include\SDL.h"



ModuleSceneIntro::ModuleSceneIntro()
{
}


ModuleSceneIntro::~ModuleSceneIntro()
{
}

bool ModuleSceneIntro::Init() {
	intro_time_s = 5.0f;

	return true;
}

bool ModuleSceneIntro::Start() {
	bool ret = true;
	transitioning = false;
	background = App->textures->Load("rtype/intro.png");
	bg_music = App->sound->LoadSound("rtype/intro.ogg");
	start_fx = App->sound->LoadSound("rtype/starting.wav");
	App->sound->PlaySound(bg_music, -1);

	if (background == nullptr)
		ret = false;

	return ret;
}

update_status ModuleSceneIntro::Update() {
	unsigned int curent_time_ms = SDL_GetTicks();
	if (curent_time_ms >= (unsigned int)intro_time_s * 1000 && transitioning == false) {
		App->fade->FadeToBlack(this, App->scene_space, 2.0f);
		App->sound->PlaySound(start_fx, 0);
		transitioning = true;
	}

	App->render->Blit(background, 0, -24, nullptr);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp() {
	bool ret = true;
	App->sound->StopAll();
	if (!App->textures->Unload(background))
		ret = false;

	return ret;
}