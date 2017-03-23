#ifndef STRATEGY_3_HPP
#define STRATEGY_3_HPP
#include "strategy_2.hpp"

class forward_strategy_3 : public forward_strategy_1
{
public:
	forward_strategy_3(unsigned int s_num, unsigned int quality_num);
	std::vector<std::string> decide() const;

private:
	unsigned int s_num, quality_num;
};



class send_strategy_3 : public send_strategy_1
{
public:
	send_strategy_3(unsigned int s_num);
	std::string decide() const;

private:
	unsigned int s_num;
};



#endif //STRATEGY_3_HPP