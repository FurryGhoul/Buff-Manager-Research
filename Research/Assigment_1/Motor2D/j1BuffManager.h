
#include "SDL/include/SDL.h"

#include "j1Module.h"
#include "j1Input.h"
#include "p2DynArray.h"
#include "p2Point.h"


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
	void increase_buff_timed(Stats stat, float bonus);

private:

	Stats			stats_val;
};

