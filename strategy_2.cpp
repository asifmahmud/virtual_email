#include "strategy_2.hpp"

forward_strategy_2::forward_strategy_2(unsigned int s_num, unsigned int type_num)
	:forward_strategy_1(s_num), s_num(s_num), type_num(type_num)
{
}

std::vector<std::string> forward_strategy_2::decide() const
{
	std::vector<std::string> v;
	if (type_num == 1)		{ v.push_back("forward all jokes"); return v;}
	else if (type_num == 2) { v.push_back("forward all schemes"); return v; }
	else if (type_num == 3) { v.push_back("forward all stories"); return v; }
	else if (type_num == 4) { v.push_back("forward all virus"); return v; }
}


send_strategy_2::send_strategy_2(unsigned int s_num)
	:send_strategy_1(s_num), s_num(s_num)
{
}

std::string send_strategy_2::decide() const
{
	return "forward except sender";
}