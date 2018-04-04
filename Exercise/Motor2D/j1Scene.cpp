#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Colliders.h"
#include "j1Pathfinding.h"
#include "j1Scene.h"
#include "j1Entities.h"
#include "j1Attributes.h"
#include "j1BuffManager.h"
#include "Player.h"
#include "j1Gui.h"
#include "UIButton.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	bool ret = true;
	Map_1 = true;
	Map_2 = false;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	//Camera Movement--------------------------------------
	
	win_height = App->win->screen_surface->h;
	win_width = App->win->screen_surface->w;

	App->colliders->AddCollider({ 0,800,5000,20 }, COLLIDER_FLOOR);
	App->colliders->AddCollider({ 1500,0,20,1000 }, COLLIDER_WALL);

	//TODO 1: Discomment those lines onece all attributes are coreactly loaded
	App->gui->AddElementText(0.010*App->win->screen_surface->w, 0.0075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, "Defense:", true, true);
	//App->gui->AddElementText(0.17*App->win->screen_surface->w, 0.0075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, def_string, true, true);
	App->gui->AddElementText(0.38*App->win->screen_surface->w, 0.0075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, "Dexterity:", true, true);
	//App->gui->AddElementText(0.57*App->win->screen_surface->w, 0.0075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, dex_string, true, true);
	App->gui->AddElementText(0.72*App->win->screen_surface->w, 0.0075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, "Stamina:", true, true);
	//App->gui->AddElementText(0.9*App->win->screen_surface->w, 0.0075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, sta_string, true, true);
	App->gui->AddElementText(0.010*App->win->screen_surface->w, 0.075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, "Strength:", true, true);
	//App->gui->AddElementText(0.18*App->win->screen_surface->w, 0.075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, str_string, true, true);
	App->gui->AddElementText(0.33*App->win->screen_surface->w, 0.075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, "Vitality:", true, true);
	//App->gui->AddElementText(0.50*App->win->screen_surface->w, 0.075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, vit_string, true, true);
	App->gui->AddElementText(0.65*App->win->screen_surface->w, 0.075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, "Inteligence:", true, true);
	//App->gui->AddElementText(0.9*App->win->screen_surface->w, 0.075*App->win->screen_surface->h, TEXT, 2, 255, 255, 0, this, intl_string, true, true);

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	BROFILER_CATEGORY("PreUpdate_Scene1 ", Profiler::Color::Orchid)
		
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	BROFILER_CATEGORY("Update_Scene1 ", Profiler::Color::MediumOrchid)


	if (App->input->GetKey(SDL_SCANCODE_F11) == KEY_DOWN)
	{
		if (App->Cap_on)
		{
			App->Cap_on = false;
		}
		else
		{
			App->Cap_on = true;
		}
	}	

	sprintf_s(def_string, 256, "%.2f", App->attributes->def);
	sprintf_s(dex_string, 256, "%.2f", App->attributes->dex);
	sprintf_s(vit_string, 256, "%.2f", App->attributes->vit);
	sprintf_s(sta_string, 256, "%.2f", App->attributes->sta);
	sprintf_s(str_string, 256, "%.2f", App->attributes->str);
	sprintf_s(intl_string, 256, "%.2f", App->attributes->intl);

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	BROFILER_CATEGORY("PosUpdate_Scene1 ", Profiler::Color::DarkOrchid)
	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		exit = false;

	return exit;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	App->entities->CleanUp();
	App->colliders->CleanUp();
	App->map->CleanUp();
	App->pathfinding->CleanUp();

	return true;
}

//go to the begining
void j1Scene::StartCurrentScene()
{
	App->entities->player->original_pos.x = 60;
	App->entities->player->original_pos.y = 215;
	App->render->camera.x = 0;
	App->render->camera.y = 0;
}

//Change to scene 2
void j1Scene::ChangeScene(int x, int y)
{
	CleanUp();
	
	if (Map_1 && App->entities->player->Curr_map==1)
	{
		Map_1 = false;
		Map_2 = true;

		App->scene->Start();
		App->pathfinding->Start();
		App->entities->player->original_pos.y = y;
		App->entities->player->original_pos.x = x;
		App->render->camera.x = 0;
		App->render->camera.y = 0;
		App->entities->player->Curr_map = 2;
		App->entities->Start();
	}
	else
	{
		Map_1 = true;
		Map_2 = false;

		App->scene->Start();
		App->pathfinding->Start();
		App->entities->player->original_pos.y = y;
		App->entities->player->original_pos.x = x;
		App->render->camera.x = 0;
		App->render->camera.y = 0;
		App->entities->player->Curr_map = 1;
		App->entities->Start();
	}
}

bool j1Scene::GUIEvent(UIEvents eventType, UIElements* element)
{
	switch (eventType)
	{
	case MOUSE_ENTER:
		
		break;
	case MOUSE_LEAVE:
		
		break;

	case MOUSE_CLICK:
		
		break;

	case MOUSE_STOP_CLICK:
		
		break;

	default:
		break;
	}
	return true;
}
