My name is [Ivan Drofiak Villarejo](https://github.com/FurryGhoul), I'm a student in the [Degree in Videogames at the UPC in the CITM](https://www.citm.upc.edu/ing/estudis/graus-videojocs/). This content is generated for the research of seocnd year's Project 2, under the supervision of lecturer [Ricardo Pillosu](https://es.linkedin.com/in/ricardpillosu).

# Buff Manager

## What is a buff?

In videogames, usually in MMORPGs, we find certain cases where our character has a change in his stats or attributes, whether this change increases or decreases them, this term is called status effect. 

In this case of a buff, this is the status effect which results in a positive change in your stats or attributes. This change can be the consequence of various in-game factors, such as the player casting a spell, using an object, interacting with props and NPCs…. While having a buff the player acquires a condition related to the factor causing it, for example: if a mage cast a magic armour spell over the player his defence stat will increase. 

The effect of each buff will dependent on where it came from. As mentioned before buffs have to have a source to their effects and have a certain sense for the player to understand. So buffs will modify stats depending on this, food will usually give you health or stamina, potion will raise certain attributes momentarily, certain location maybe boost your speed...

<p align="center"> 
<img src="https://i.imgur.com/w03iHKC.jpg" width="600">
</p>

## Why are buffs important?

More than asking ourselves what’s the importance of buffs, it is better to explain the overall importance on status effects which include both buffs and debuffs. 

Status change can open a wide variety of playstyle and preferences towards the player when building a character or facing a situation.  The way in which a player decides to manages those effects in which attributes he wishes to buff give a wide window for strategy.
Another factor to take into account is the sensation we can transmit by using them properly. It can give the player the sensation of improvement or overpower when using buffs on himself, and can also give the sense of inferiority when facing a boss or strong foe if it uses a debuff on the player. 

The problem with using buffs and debuffs is that it can cause the wrong sensation and there wouldn’t be any type of difference between them and stats gained by equipment. 

<p align="center"> 
<img src="https://i.imgur.com/y2jRsx2.jpg" width="600">
</p>

## Types of buffs

While all buff are essentially the same thing, as they all change stats (some more than others), they do come in different forms. They can be categorized in those categories and subcategories: single target, group target, single stat, multi-stat , percentage, permanent and timed.

### Single/Multi Target

First of all, when applying status effect there has to be taken in mind whether it is going for one single player or a group of them. Many buffs can work as both, the can be applied for one target but depending on the position of the other characters, it can apply to them as well. For example: healing circle, normally for groups but it can be applied to one character as well. 

<p align="center"> 
<img src="https://i.imgur.com/uEORDx9.jpg" width="500">
</p>

### Single/Multi Stat

The name itself is pretty straightforward; there are buffs that only change one attribute or many of them. Normally in videogames buffs tend to increase just one, all of them or a select group which lead to a specific building of our character. 

### Percentage or Numerical

Stats change can be calculated through the addition or subtraction of a certain numeric amount or by a percentage amount. Buff don’t always increase stats in a certain amount, they sometime depend on the raw values. For example: this item will increase 10% of your current attack power (90 to 99).  

### Durable

Status change can either be temporal or permanent. Some buff are meant to last forever or until certain event occurs (stats increased with location bonuses), while other have certain duration (magic aura grant by a spell or potion). 

<p align="center"> 
<img src="https://i.imgur.com/xgrLaKg.jpg" width="500">
</p>

### Stackable

A more recent type of buff would be the stackable meaning that, the buff apllied can be re applied until it reaches the limit programmed. Each of this stacks will modify more and more the player’s stats, as these stacks increase. 

## Attribute Class

In order to apply a buff manger to our code there has to be some attributes related to the character or entities to play around with which will give a sense to the system. In order to do so we can create a base class for attributes where we will load each value from a XML and create simple function to get them.

This class will store the initial stats and is from where we will access to all the values and attributes to implemented in the different modules where they are needed, such as the player or buff manager module. The attributes will already be loaded with an initial value which will increase or decrease depending on the buff implanted. The change of these values will be done through bonuses applied in the buff manger module.

```markdown
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
```

## Buff Manager Module

This is the main core of the system; from here we will manage all status effects that will be applied towards the attributes loaded in the attribute class. Here is where all the operation and cases happen and return the new upcoming values. 

This class contains the functions to operate with the values and cover all the cases of the buffs, but it also contains extra variables. Those extra variables are limits to the percentages one can introduce in one function so it stays between 0% and 100%; as well as an `enum` with all the cases of the attributes. 

### Percentage and Numerical Fucntions

As mentioned before there are 2 types of operations when adding the bonus of the buff to the original stats, by percentage increase or a numerical increase which involves a simple sum of both values.

The numerical function receives a stat to modify and the amount by which the original value of this stat will increase or decrease. The function is composed of a switch system which manages the case for each attribute with the `enum`, and changes the original stat by the new one by adding the bonus. 

The percentage function works with the same input arguments as the numerical one and the same switch system. The difference with the other one is that this function does the operation by multiplying the original value by the decimal percentage (%/100) and adding in to the original value to obtain the buffed stat. 

```markdown
void j1BuffManager::increase_buff(Stats stat, float bonus)
{
	switch (stat)
	{
	case VIT:
		App->attributes->vit += bonus;
		break;
	}
}
```

```markdown
void j1BuffManager::increase_buff_percentage(Stats stat, float bonus_percentage)
{
	if (bonus_percentage > MIN_PERCENTAGE && bonus_percentage < MAX_PERCENTAGE)
	{
		switch (stat)
		{
		case VIT:
			App->attributes->vit += App->attributes->vit*(bonus_percentage / 100);
			break;
		}
	}
}
```

### Timed Functions

Both function from the previous segment work with the same system in the timed functions, same input argument and switch system. The only change in these functions is that the bonus that is going to be added has to ware off after a certain period of time. 

In this case we need to add a clock or timer form the j1Timer module. The first thing to do is to initialize the clock, which will be on seconds. After having the clock start running there has to be a condition for each case in the switch, so when the buff reaches its limit of duration it goes off. This means that the conditions will subtract the bonus form the original stat regarding whether it is a numeric operation or a percentage one. 

```markdown
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
```

# Info Links

[Time Related State Effects](https://www.gamedev.net/forums/topic/622135-time-related-state-effects-buffsdebuffs-what-are-manageable-code-designs/)

[Flexible Buff/Debuff System](https://gamedev.stackexchange.com/questions/29982/whats-a-way-to-implement-a-flexible-buff-debuff-system)

[RPG Attribute System](https://gamedevelopment.tutsplus.com/tutorials/using-the-composite-design-pattern-for-an-rpg-attributes-system--gamedev-243)


