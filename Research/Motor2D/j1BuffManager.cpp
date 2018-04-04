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

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && pressed_3 == false)
	{
		pressed_3 = true;
		increase_buff(VIT, 10);
		clock.Reset();
		clock.Start();
	}

	if (clock.ReadSec() >= 5 && pressed_3 == true)
	{
		pressed_3 = false;
		decrease_buff_timed(VIT, 10);
	}

	if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN && pressed_4 == false)
	{
		pressed_4 = true;
		increase_buff_percentage(VIT, 50);
		clock2.Reset();
		clock2.Start();
	}

	if (clock2.ReadSec() >= 5 && pressed_4 == true)
	{
		pressed_4 = false;
		decrease_buff_timed_percentage(VIT, 50);
	}
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
	switch (stat)
	{
	case VIT:
		App->attributes->vit -= bonus;
		break;
	case DEF:
		App->attributes->def -= bonus;
		break;
	case DEX:
		App->attributes->dex -= bonus;
		break;
	case STR:
		App->attributes->str -= bonus;
		break;
	case INTL:
		App->attributes->intl -= bonus;
		break;
	case STA:
		App->attributes->sta -= bonus;
		break;
	}
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
