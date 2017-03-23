#include "strategy_1.hpp"


forward_strategy_1::forward_strategy_1(unsigned int s_num) : s_num(s_num) {}

std::vector<std::string> forward_strategy_1::decide() const 
{ 
	std::vector<std::string> v;
	v.push_back("forward all messages");
	return v;
}


send_strategy_1::send_strategy_1(int s_num) : s_num(s_num) {}
std::string send_strategy_1::decide() const { return "forward all members"; }

