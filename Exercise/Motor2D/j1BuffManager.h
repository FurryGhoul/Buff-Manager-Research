
#include "SDL/include/SDL.h"

#include "j1Module.h"
#include "j1Input.h"
#include "j1Timer.h"
#include "p2DynArray.h"
#include "p2Point.h"

#define MAX_STAT 999
#define MAX_PERCENTAGE 100
#define MIN_PERCENTAGE 0

enum Stats
{
	VIT,
	STA,
	DEF,
	DEX,
	STR,
	INTL
};

class j1BuffManager : public j1Module
{
public:
	j1BuffManager();

	~j1BuffManager();

	bool Start();

	bool Update(float dt);

	void increase_buff(Stats stat, float bonus);
	void increase_buff_percentage(Stats stat, float percentage_bonus);
	void decrease_buff_timed(Stats stat, float bonus);
	void decrease_buff_timed_percentage(Stats stat, float percentage_bonus);

public:

	bool pressed_3 = false;
	bool pressed_4 = false;

	float org_def = 0;
	float org_dex = 0;
	float org_str = 0;
	float org_sta = 0;
	float org_vit = 0;
	float org_intl = 0;

private:

	Stats			stats_val;
	j1Timer			clock;
	j1Timer			clock2;

};

