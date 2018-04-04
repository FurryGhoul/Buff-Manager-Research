#include "j1BuffManager.h"
#include "Player.h"
#include "j1Attributes.h"
#include "j1Timer.h"
#include "j1Input.h"
#include "p2Point.h"
#include "p2Log.h"

j1BuffManager::j1BuffManager()
{
}


j1BuffManager::~j1BuffManager()
{
}

bool j1BuffManager::Start()	
{
	org_def = App->attributes->def;
	org_dex = App->attributes->dex;
	org_str = App->attributes->str;
	org_sta = App->attributes->sta;
	org_vit = App->attributes->vit;
	org_intl = App->attributes->intl;

	LOG("Loading Stats");
	return true;
}

bool j1BuffManager::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		increase_buff(DEF, 10);
	}

	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		increase_buff_percentage(DEF, 50);
	}

	//TODO 3: Create the condition so when that we press 3 we obtain the buff for 5 seconds
	//Hint 1: Use class j1Timer to calculate the necessary time
	//Hint 2: There should be a condition to activate the buff and one to make it wear off



	return true;
}

void j1BuffManager::increase_buff(Stats stat, float bonus)
{
	switch (stat)
	{
	case VIT:
		App->attributes->vit += bonus;
		break;
	case DEF:
		App->attributes->def += bonus;
		break;
	case DEX:
		App->attributes->dex += bonus;
		break;
	case STR:
		App->attributes->str += bonus;
		break;
	case INTL:
		App->attributes->intl += bonus;
		break;
	case STA:
		App->attributes->sta += bonus;
		break;
	}
}

void j1BuffManager::increase_buff_percentage(Stats stat, float bonus_percentage)
{
	if (bonus_percentage > MIN_PERCENTAGE && bonus_percentage < MAX_PERCENTAGE)
	{
		switch (stat)
		{
		case VIT:
			App->attributes->vit += App->attributes->vit*(bonus_percentage/100);
			break;
		case DEF:
			App->attributes->def += App->attributes->def*(bonus_percentage / 100);
			break;
		case DEX:
			App->attributes->dex += App->attributes->dex*(bonus_percentage / 100);
			break;
		case STR:
			App->attributes->str += App->attributes->str*(bonus_percentage / 100);
			break;
		case INTL:
			App->attributes->intl += App->attributes->intl*(bonus_percentage / 100);
			break;
		case STA:
			App->attributes->sta += App->attributes->sta*(bonus_percentage / 100);
			break;
		}
	}
	else
	{
		LOG("Unvalid porcentage value");
	}
}

void j1BuffManager::decrease_buff_timed(Stats stat, float bonus)
{
	//TODO 2: Fill the function so that when it is called it substracts the active bonus from the stats

}

void j1BuffManager::decrease_buff_timed_percentage(Stats stat, float bonus_percentage)
{
	if (bonus_percentage > MIN_PERCENTAGE && bonus_percentage < MAX_PERCENTAGE)
	{
		switch (stat)
		{
		case VIT:
			App->attributes->vit -= org_vit*(bonus_percentage / 100);
			break;
		case DEF:
			App->attributes->def -= org_def*(bonus_percentage / 100);
			break;
		case DEX:
			App->attributes->dex -= org_dex*(bonus_percentage / 100);
			break;
		case STR:
			App->attributes->str -= org_str*(bonus_percentage / 100);
			break;
		case INTL:
			App->attributes->intl -= org_intl*(bonus_percentage / 100);
			break;
		case STA:
			App->attributes->sta -= org_sta*(bonus_percentage / 100);
			break;
		}
	}
	else
	{
		LOG("Unvalid porcentage value");
	}
}
