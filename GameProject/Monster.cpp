#pragma once

#include <iostream>
#include <time.h>

#include "Monster.h"

Monster::Monster(float lif, float att, float def, float gold, const char (sym)) 
	: life(lif), attack(att), defence(def), gold(gold), symbol (sym)
{ }
