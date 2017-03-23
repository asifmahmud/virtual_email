#ifndef STRATEGY_2_HPP
#define STRATEGY_2_HPP
#include "strategy_1.hpp"

class forward_strategy_2 : public forward_strategy_1
{
public:
	std::vector<std::string> decide() const;
	forward_strategy_2(unsigned int s_num, unsigned int type_num);

private:
	unsigned int s_num, type_num;
};



class send_strategy_2 : public send_strategy_1
{
public:
	std::string decide() const;
	send_strategy_2(unsigned int s_num);

private:
	unsigned int s_num;
};




#endif //STRATEGY_2_HPP