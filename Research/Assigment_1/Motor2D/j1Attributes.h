#include "j1Module.h"


class j1Attributes : public j1Module
{
public:
	j1Attributes();
	~j1Attributes();

	bool Awake(pugi::xml_node&);

	float GetDef();
	float GetDex();
	float GetVit();
	float GetStr();
	float GetIntl();
	float GetSta();

public:

	float				vit;
	float				sta;
	float				def;
	float				dex;
	float				str;
	float				intl;

	int				f_vit;
	int				f_sta;
	int				f_def;
	int				f_dex;
	int				f_str;
	int				f_intl;
};

