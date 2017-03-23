#include <iostream>
#include "strategy_4.hpp"
#include <sstream>

forward_strategy_4::forward_strategy_4(unsigned int s_num, unsigned int quality_num, unsigned int type_num)
:forward_strategy_3(s_num, quality_num), type_num(type_num), quality_num(quality_num)
{
}


std::vector<std::string> forward_strategy_4::decide() const
{
	std::vector<std::string> v;
	std::string quality, type;
	std::ostringstream q;
	std::ostringstream t;
	q << quality_num;
	t << type_num;
	quality = q.str();
	type = t.str();
	v.push_back("forward above q");
	v.push_back(type);
	v.push_back(quality);
	return v;
}