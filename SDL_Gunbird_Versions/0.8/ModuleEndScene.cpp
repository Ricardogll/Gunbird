#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleScoreScreen.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEndScene.h"
#include "ModuleSaveScore.h"
#include "ModulePlayer.h"

ModuleEndScene::ModuleEndScene()
{
	//CHARACTERS EXPRESSIONS
	ash_scene1.x = 3;
	ash_scene1.y = 3 ;
	ash_scene1.w = 213;
	ash_scene1.h = 121;

	ash_scene2.x = 218;
	ash_scene2.y = 3;
	ash_scene2.w = 213;
	ash_scene2.h = 121;

	ash_scene3.x = 433;
	ash_scene3.y = 3;
	ash_scene3.w = 213;
	ash_scene3.h = 121;

	yuan_nang_scene1.x = 5;
	yuan_nang_scene1.y = 128;
	yuan_nang_scene1.w = 139;
	yuan_nang_scene1.h = 128;

	yuan_nang_scene2.x = 153;
	yuan_nang_scene2.y = 128;
	yuan_nang_scene2.w = 139;
	yuan_nang_scene2.h = 128;

	yuan_nang_scene3.x = 294;
	yuan_nang_scene3.y = 128;
	yuan_nang_scene3.w = 322;
	yuan_nang_scene3.h = 128;

	yuan_nang_scene4.x = 523;
	yuan_nang_scene4.y = 128;
	yuan_nang_scene4.w = 208;
	yuan_nang_scene4.h = 128;

	valnus_scene1.x = 6;
	valnus_scene1.y = 261;
	valnus_scene1.w = 224;
	valnus_scene1.h = 128;

	valnus_scene2.x = 232;
	valnus_scene2.y = 261;
	valnus_scene2.w = 224;
	valnus_scene2.h = 128;

	valnus_scene3.x = 458;
	valnus_scene3.y = 261;
	valnus_scene3.w = 224;
	valnus_scene3.h = 128;

	marion_scene1.x = 3;
	marion_scene1.y = 521; 
	marion_scene1.w = 171;
	marion_scene1.h = 128;

	marion_scene2.x = 185;
	marion_scene2.y = 531;
	marion_scene2.w = 140;
	marion_scene2.h = 118;

	marion_scene3.x = 329;
	marion_scene3.y = 521;
	marion_scene3.w = 171;
	marion_scene3.h = 121;

	tetsu_scene1.x = 4;
	tetsu_scene1.y = 391;
	tetsu_scene1.w = 222;
	tetsu_scene1.h = 128;

	tetsu_scene2.x = 228;
	tetsu_scene2.y = 391;
	tetsu_scene2.w = 222;
	tetsu_scene2.h = 128;

	tetsu_scene3.x = 452;
	tetsu_scene3.y = 391;
	tetsu_scene3.w = 183;
	tetsu_scene3.h = 128;

	tetsu_scene4.x = 638;
	tetsu_scene4.y = 391;
	tetsu_scene4.w = 222;
	tetsu_scene4.h = 128;

	rabbit_scene1.x = 509;
	rabbit_scene1.y = 559;
	rabbit_scene1.w = 71;
	rabbit_scene1.h = 90;


	//TEXTS
	text_ash.x = 1;
	text_ash.y = 1;
	text_ash.w = 200;
	text_ash.h = 41;

	text_marion.x = 1;
	text_marion.y = 50;
	text_marion.w = 200;
	text_marion.h = 55;

	text_yuan_nang.x = 1;
	text_yuan_nang.y = 197;
	text_yuan_nang.w = 200;
	text_yuan_nang.h = 41;

	text_tetsu.x = 1;
	text_tetsu.y = 246;
	text_tetsu.w = 200;
	text_tetsu.h = 55;

	text_valnus.x = 1;
	text_valnus.y = 148;
	text_valnus.w = 200;
	text_valnus.h = 41;

	text_rabbit.x = 1;
	text_rabbit.y = 113;
	text_rabbit.w = 200;
	text_rabbit.h = 27;

	text_ash_tetsu1.x = 424;
	text_ash_tetsu1.y = 38;
	text_ash_tetsu1.w = 200;
	text_ash_tetsu1.h = 41;

	text_ash_tetsu2.x = 424;
	text_ash_tetsu2.y = 89;
	text_ash_tetsu2.w = 200;
	text_ash_tetsu2.h = 27;

	text_ash_valnus1.x = 1;
	text_ash_valnus1.y = 309;
	text_ash_valnus1.w = 200;
	text_ash_valnus1.h = 41;

	text_ash_valnus2.x = 1;
	text_ash_valnus2.y = 358;
	text_ash_valnus2.w = 200;
	text_ash_valnus2.h = 41;

	text_ash_valnus3.x = 1;
	text_ash_valnus3.y = 409;
	text_ash_valnus3.w = 200;
	text_ash_valnus3.h = 27;

	text_valnus_marion1.x = 1;
	text_valnus_marion1.y = 444;
	text_valnus_marion1.w = 200;
	text_valnus_marion1.h = 41;

	text_valnus_marion2.x = 212;
	text_valnus_marion2.y = 1;
	text_valnus_marion2.w = 200;
	text_valnus_marion2.h = 41;

	text_valnus_yuan1.x = 212;
	text_valnus_yuan1.y = 52;
	text_valnus_yuan1.w = 200;
	text_valnus_yuan1.h = 41;

	text_valnus_yuan2.x = 212;
	text_valnus_yuan2.y = 103;
	text_valnus_yuan2.w = 200;
	text_valnus_yuan2.h = 41;

	text_valnus_yuan3.x = 212;
	text_valnus_yuan3.y = 152; 
	text_valnus_yuan3.w = 200;
	text_valnus_yuan3.h = 41;

	text_valnus_tetsu1.x = 212; 
	text_valnus_tetsu1.y = 203;
	text_valnus_tetsu1.w = 200;
	text_valnus_tetsu1.h = 27;

	text_valnus_tetsu2.x = 212;
	text_valnus_tetsu2.y = 238;
	text_valnus_tetsu2.w = 200;
	text_valnus_tetsu2.h = 13;

	text_marion_yuan1.x = 212;
	text_marion_yuan1.y = 260;
	text_marion_yuan1.w = 200;
	text_marion_yuan1.h = 27;

	text_marion_yuan2.x = 212;
	text_marion_yuan2.y = 296;
	text_marion_yuan2.w = 200;
	text_marion_yuan2.h = 27;

	text_marion_yuan3.x = 212;
	text_marion_yuan3.y = 333;
	text_marion_yuan3.w = 200;
	text_marion_yuan3.h = 27;

	text_ash_yuan1.x = 212;
	text_ash_yuan1.y = 368;
	text_ash_yuan1.w = 200;
	text_ash_yuan1.h = 27;

	text_ash_yuan2.x = 212;
	text_ash_yuan2.y = 405;
	text_ash_yuan2.w = 200;
	text_ash_yuan2.h = 41;

	text_tetsu_yuan1.x = 212;
	text_tetsu_yuan1.y = 456;
	text_tetsu_yuan1.w = 200;
	text_tetsu_yuan1.h = 27;

	text_tetsu_yuan2.x = 424;
	text_tetsu_yuan2.y = 1;
	text_tetsu_yuan2.w = 200;
	text_tetsu_yuan2.h = 27;

	text_ash_marion1.x = 424;
	text_ash_marion1.y = 126;
	text_ash_marion1.w = 200;
	text_ash_marion1.h = 55;

	text_ash_marion2.x = 424;
	text_ash_marion2.y = 192;
	text_ash_marion2.w = 202;
	text_ash_marion2.h = 27;

	text_marion_tetsu1.x = 424;
	text_marion_tetsu1.y = 229;
	text_marion_tetsu1.w = 204;
	text_marion_tetsu1.h = 41;

	text_marion_tetsu2.x = 424;
	text_marion_tetsu2.y = 278;
	text_marion_tetsu2.w = 200;
	text_marion_tetsu2.h = 27;
	   

	//MIRROR
	mirror.PushBack({ 138, 920, 95, 60  });  
	mirror.PushBack({ 248, 921, 95, 60 });
	mirror.PushBack({ 355, 923, 95 , 60 });
	mirror.PushBack({ 459, 924, 95, 60 });
	mirror.PushBack({ 572, 924, 95, 60 });
	mirror.PushBack({ 686, 924, 95, 60 });
	mirror.PushBack({ 798 , 927, 95, 60 });
	mirror.speed = 0.15f;

	break_mirror.PushBack({ 28, 917, 95, 60 });

	screen_sky.x = 603;
	screen_sky.y = 544;
	screen_sky.w = 416;
	screen_sky.h = 112;

	screen_up.x = 785;
	screen_up.y = 11;
	screen_up.w = 224;
	screen_up.h = 128;

	screen_down.x = 785;
	screen_down.y = 251;
	screen_down.w = 224;
	screen_down.h = 80;

	animation = &break_mirror;
}

ModuleEndScene::~ModuleEndScene()
{}

// Load assets
bool ModuleEndScene::Start()
{
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	scroll = 0;
	cont_left = 0;
	cont_right = 0;
	cont_mirror = 0;
	cont_rabbit = 0;
	time = 0;

//	App->audio->PlayMusic("assets/audio/music/gunbird-013_Stage_Clear.ogg");
	music = App->audio->LoadWAV("assets/audio/sound/gunbird-013_Stage_Clear.wav");

	LOG("Loading scenes assets");
	bool ret = true;
	graphics = App->textures->Load("assets/UI/characters_expressions.png");
	graphics_text = App->textures->Load("assets/UI/characters_text.png");

	App->audio->PlayWAV(music);

	return ret;
}

bool ModuleEndScene::CleanUp()
{
	//LOG("Destroying SDL audio");
//	App->audio->StopMusic();
	App->audio->UnloadWAV(music);

	LOG("Unloading score screen");
	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleEndScene::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &screen_up, 0.75f);
	App->render->Blit(graphics, scroll, 128, &screen_sky, 0.75f);
	App->render->Blit(graphics, 0, 240, &screen_down, 0.75f);

	//SKY SCROLL
	if (scroll == -192)
		scroll = 0;
	else
		scroll--;

	if (cont_mirror < 66)
		cont_mirror ++;

	//SCROLL MIRROR
	if (cont_mirror == 66)
		animation = &mirror;

	App->render->Blit(graphics, 24, -60 + cont_mirror, &(animation->GetCurrentFrame()));	

	//TIME
	time++;


	//ONE PLAYER
	if (App->savescore->saveCharacter[0] == ASH && App->savescore->saveCharacter[1] == NO_CHARACTER)  {
		if (cont_left < 206)
			cont_left += 3;
		App->render->Blit(graphics, 11, 119, &ash_scene1, 0.75f);
		App->render->Blit(graphics_text, -190 + cont_left, 249, &text_ash, 0.75f);
		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	} 

	if (App->savescore->saveCharacter[0] == YUAN_NANG && App->savescore->saveCharacter[1] == NO_CHARACTER) {
		if (cont_left < 206)
			cont_left += 3;
		App->render->Blit(graphics, 48, 112, &yuan_nang_scene1, 0.75f);
		App->render->Blit(graphics_text, -190 + cont_left, 249, &text_yuan_nang, 0.75f);
		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if (App->savescore->saveCharacter[0] == MARION && App->savescore->saveCharacter[1] == NO_CHARACTER) {
		if (cont_left < 206)
			cont_left += 3;

		if (time < 300) {
			App->render->Blit(graphics, 27, 112, &marion_scene1, 0.75f);
			App->render->Blit(graphics_text, -190 + cont_left, 249, &text_marion, 0.75f);
		}
		if (time >= 300) {
			if (cont_right < 214)
				cont_right += 3;
			if (cont_rabbit < 90)
				cont_rabbit += 3;
			App->render->Blit(graphics, 27, 112, &marion_scene1, 0.75f);
			App->render->Blit(graphics, 130, 240 - cont_rabbit, &rabbit_scene1, 0.75f);
			App->render->Blit(graphics, 0, 240, &screen_down, 0.75f);
			App->render->Blit(graphics_text, 230 - cont_right, 249, &text_rabbit, 0.75f);
		}
		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if (App->savescore->saveCharacter[0] == TETSU && App->savescore->saveCharacter[1] == NO_CHARACTER) {
		if (cont_left < 206)
			cont_left += 3;
		App->render->Blit(graphics, 1, 112, &tetsu_scene1, 0.75f);
		App->render->Blit(graphics_text, -190 + cont_left, 249, &text_tetsu, 0.75f);
		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if (App->savescore->saveCharacter[0] == VALNUS && App->savescore->saveCharacter[1] == NO_CHARACTER) {
		if (cont_left < 206)
			cont_left += 3;
		App->render->Blit(graphics, 0, 112, &valnus_scene1, 0.75f);
		App->render->Blit(graphics_text, -190 + cont_left, 249, &text_valnus, 0.75f);
		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	//TWO PLAYERS
	if ((App->savescore->saveCharacter[0] == ASH && App->savescore->saveCharacter[1] == TETSU) || (App->savescore->saveCharacter[0] == TETSU && App->savescore->saveCharacter[1] == ASH)) {
		App->render->Blit(graphics, 9 - cont_right, 119, &ash_scene2, 0.75f);
		App->render->Blit(graphics, 225 - cont_right, 112, &tetsu_scene4, 0.75f);
		App->render->Blit(graphics_text, 240 - cont_right, 249, &text_ash_tetsu2, 0.75f);

		if (time < 240)
			App->render->Blit(graphics_text, -190 + cont_left, 249, &text_ash_tetsu1, 0.75f);

		if (time >= 240) {
			if (cont_right < 224)
				cont_right += 4;
		}

		if (cont_left < 206)
			cont_left += 3;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == YUAN_NANG && App->savescore->saveCharacter[1] == MARION) || (App->savescore->saveCharacter[0] == MARION && App->savescore->saveCharacter[1] == YUAN_NANG)) {
		App->render->Blit(graphics, 240 - cont_right, 112, &yuan_nang_scene4, 0.75f);
		if (time < 320) {
			App->render->Blit(graphics_text, 240 - cont_right, 249, &text_marion_yuan2, 0.75f);
			App->render->Blit(graphics, 32 - cont_right, 122, &marion_scene2, 0.75f);
		}

		if (time < 160) {
			App->render->Blit(graphics_text, -190 + cont_left, 249, &text_marion_yuan1, 0.75f);
		}

		if (time >= 160 && time <= 320) {
			if (cont_right < 224)
				cont_right += 4;
			cont_left = 0;
		}

		if (time > 320) {
			if (cont_right > 0)
				cont_right -= 4;
			App->render->Blit(graphics_text, -190 + cont_left, 249, &text_marion_yuan3, 0.75f);
			App->render->Blit(graphics, 27 - cont_right, 122, &marion_scene3, 0.75f);
		}

		if (cont_left < 206)
			cont_left += 4;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == ASH && App->savescore->saveCharacter[1] == VALNUS) || (App->savescore->saveCharacter[0] == VALNUS && App->savescore->saveCharacter[1] == ASH)) {
		App->render->Blit(graphics, -224 + cont_left, 112, &valnus_scene2, 0.75f);
		if (time < 320) {
			App->render->Blit(graphics_text, -208 + cont_left, 249, &text_ash_valnus2, 0.75f);
			App->render->Blit(graphics, 11 + cont_left, 119, &ash_scene1, 0.75f);
		}

		if (time < 160) {
			App->render->Blit(graphics_text, 240 - cont_right, 249, &text_ash_valnus1, 0.75f);
		}

		if (time >= 160 && time <= 320) {
			if (cont_left < 224)
				cont_left += 4;
			cont_right = 0;
		}

		if (time > 320) {
			if (cont_left > 0)
				cont_left -= 4;
			App->render->Blit(graphics_text, 240 - cont_right, 249, &text_ash_valnus3, 0.75f);
			App->render->Blit(graphics, 235 - cont_right, 119, &ash_scene2, 0.75f);
		}

		if (cont_right < 224)
			cont_right += 4;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == YUAN_NANG && App->savescore->saveCharacter[1] == VALNUS) || (App->savescore->saveCharacter[0] == VALNUS && App->savescore->saveCharacter[1] == YUAN_NANG)) {
		App->render->Blit(graphics, 224 - cont_right, 112, &yuan_nang_scene3, 0.75f);
		if (time < 320) {
			App->render->Blit(graphics_text, 240 - cont_right, 249, &text_valnus_yuan2, 0.75f);
			App->render->Blit(graphics, 0 - cont_right, 112, &valnus_scene1, 0.75f);
		}

		if (time < 160) {
			App->render->Blit(graphics_text, -190 + cont_left, 249, &text_valnus_yuan1, 0.75f);
		}

		if (time >= 160 && time <= 320) {
			if (cont_right < 224)
				cont_right += 4;
			cont_left = 0;
		}

		if (time > 320) {
			if (cont_right > 0)
				cont_right -= 4;
			App->render->Blit(graphics_text, -190 + cont_left, 249, &text_valnus_yuan3, 0.75f);
			App->render->Blit(graphics, 0 - cont_right, 112, &valnus_scene1, 0.75f);
		}

		if (cont_left < 206)
			cont_left += 4;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == TETSU && App->savescore->saveCharacter[1] == VALNUS) || (App->savescore->saveCharacter[0] == VALNUS && App->savescore->saveCharacter[1] == TETSU)) {
		App->render->Blit(graphics, 1 - cont_right, 112, &tetsu_scene2, 0.75f);
		App->render->Blit(graphics, 224 - cont_right, 112, &valnus_scene3, 0.75f);
		App->render->Blit(graphics_text, 240 - cont_right, 249, &text_valnus_tetsu2, 0.75f);

		if (time < 240)
			App->render->Blit(graphics_text, -190 + cont_left, 249, &text_valnus_tetsu1, 0.75f);

		if (time >= 240) {
			if (cont_right < 224)
				cont_right += 4;
		}

		if (cont_left < 206)
			cont_left += 3;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == MARION && App->savescore->saveCharacter[1] == VALNUS) || (App->savescore->saveCharacter[0] == MARION && App->savescore->saveCharacter[1] == VALNUS)) {
		App->render->Blit(graphics, -224 + cont_left, 112, &valnus_scene1, 0.75f);
		App->render->Blit(graphics_text, -208 + cont_left, 249, &text_valnus_marion2, 0.75f);
		App->render->Blit(graphics, 27 + cont_left, 112, &marion_scene1, 0.75f);

		if (time < 240) {
			App->render->Blit(graphics_text, 240 - cont_right, 249, &text_valnus_marion1, 0.75f);
		}

		if (time >= 240) {
			if (cont_left < 224)
				cont_left += 4;
		}

		if (cont_right < 224)
			cont_right += 4;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == ASH && App->savescore->saveCharacter[1] == YUAN_NANG) || (App->savescore->saveCharacter[0] == YUAN_NANG && App->savescore->saveCharacter[1] == ASH)) {
		App->render->Blit(graphics, -176 + cont_left, 112, &yuan_nang_scene2, 0.75f);
		App->render->Blit(graphics_text, -208 + cont_left, 249, &text_ash_yuan2, 0.75f);
		App->render->Blit(graphics, 11 + cont_left, 119, &ash_scene2, 0.75f);

		if (time < 240) {
			App->render->Blit(graphics_text, 240 - cont_right, 249, &text_ash_yuan1, 0.75f);
		}

		if (time >= 240) {
			if (cont_left < 224)
				cont_left += 4;
		}

		if (cont_right < 224)
			cont_right += 4;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == TETSU && App->savescore->saveCharacter[1] == YUAN_NANG) || (App->savescore->saveCharacter[0] == YUAN_NANG && App->savescore->saveCharacter[1] == TETSU)) {
		App->render->Blit(graphics, -176 + cont_left, 112, &yuan_nang_scene1, 0.75f);
		App->render->Blit(graphics_text, -208 + cont_left, 249, &text_tetsu_yuan2, 0.75f);
		App->render->Blit(graphics, 21 + cont_left, 112, &tetsu_scene3, 0.75f);

		if (time < 240) {
			App->render->Blit(graphics_text, 240 - cont_right, 249, &text_tetsu_yuan1, 0.75f);
		}

		if (time >= 240) {
			if (cont_left < 224)
				cont_left += 4;
		}

		if (cont_right < 224)
			cont_right += 4;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == ASH && App->savescore->saveCharacter[1] == MARION) || (App->savescore->saveCharacter[0] == MARION && App->savescore->saveCharacter[1] == ASH)) {
		App->render->Blit(graphics, -213 + cont_left, 119, &ash_scene1, 0.75f);
		App->render->Blit(graphics_text, -213 + cont_left, 249, &text_ash_marion2, 0.75f);
		App->render->Blit(graphics, 27 + cont_left, 112, &marion_scene1, 0.75f);

		if (time < 240) {
			App->render->Blit(graphics_text, 240 - cont_right, 249, &text_ash_marion1, 0.75f);
		}

		if (time >= 240) {
			if (cont_left < 224)
				cont_left += 4;
		}

		if (cont_right < 224)
			cont_right += 4;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	if ((App->savescore->saveCharacter[0] == TETSU && App->savescore->saveCharacter[1] == MARION) || (App->savescore->saveCharacter[0] == MARION && App->savescore->saveCharacter[1] == TETSU)) {
		App->render->Blit(graphics, -192 + cont_left, 122, &marion_scene2, 0.75f);
		App->render->Blit(graphics_text, -208 + cont_left, 249, &text_marion_tetsu2, 0.75f);
		App->render->Blit(graphics, 1 + cont_left, 112, &tetsu_scene1, 0.75f);

		if (time < 240) {
			App->render->Blit(graphics_text, 235 - cont_right, 249, &text_marion_tetsu1, 0.75f);
		}

		if (time >= 240) {
			if (cont_left < 224)
				cont_left += 4;
		}

		if (cont_right < 224)
			cont_right += 4;

		if (time == TIME_END_SCENE) {
			App->fade->FadeToBlack(this, App->scorescreen, 1);
		}
	}

	/*if ((App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN || App->input->keyboard[SDL_SCANCODE_BACKSPACE] || App->input->gamepad.START == CONTROLLER_STATE::BUTTON_DOWN == KEY_STATE::KEY_DOWN) && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->scorescreen, 1);
	}*/


	return UPDATE_CONTINUE;
}