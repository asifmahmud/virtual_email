#include <iostream>
#include "strategy_3.hpp"
#include <sstream>

forward_strategy_3::forward_strategy_3(unsigned int s_num, unsigned int quality_num)
:forward_strategy_1(s_num), s_num(s_num), quality_num(quality_num)
{
}

std::vector<std::string> forward_strategy_3::decide() const
{
	std::vector<std::string> v;
	std::string temp;
	std::ostringstream convert;
	convert << quality_num;
	temp = convert.str();
	v.push_back("forward above");
	v.push_back(temp);
	return v;
}


send_strategy_3::send_strategy_3(unsigned int s_num)
:send_strategy_1(s_num), s_num(s_num)
{
}

std::string send_strategy_3::decide() const
{
	return "forward_to_next";
}










