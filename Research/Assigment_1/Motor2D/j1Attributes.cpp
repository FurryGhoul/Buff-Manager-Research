#include "j1Attributes.h"



j1Attributes::j1Attributes()
{

}


j1Attributes::~j1Attributes()
{
}

bool j1Attributes::Awake(pugi::xml_node& config)
{
	vit = config.child("vitality").attribute("value").as_float(35);
	sta = config.child("stamina").attribute("value").as_float(25);
	def = config.child("defense").attribute("value").as_float(30);
	dex = config.child("dexterity").attribute("value").as_float(25);
	str = config.child("strength").attribute("value").as_float(25);
	intl = config.child("intelligence").attribute("value").as_float(15);

	return true;
}

float j1Attributes::GetDef()
{
	return def;
}
float j1Attributes::GetDex()
{
	return dex;
}
float j1Attributes::GetVit()
{
	return vit;
}
float j1Attributes::GetStr()
{
	return str;
}
float j1Attributes::GetIntl()
{
	return intl;
}
float j1Attributes::GetSta()
{
	return sta;
}