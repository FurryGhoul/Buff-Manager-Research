#include "j1Attributes.h"



j1Attributes::j1Attributes()
{

}


j1Attributes::~j1Attributes()
{
}

bool j1Attributes::Awake(pugi::xml_node& config)
{
	//TODO 1: load the xml attribute to the corresponding ones in the attribute class

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