#ifndef STRATEGY_1_HPP
#define STRATEGY_1_HPP
#include <vector>
#include "strategy.hpp"


class forward_strategy_1 : public ForwardStrategy
{
public:
	forward_strategy_1(unsigned int s_num);
	std::vector<std::string> decide() const;

private:
	int s_num;
};


class send_strategy_1 : public SendStrategy
{
public:
	send_strategy_1(int s_num);
	std::string decide() const;

private:
	int s_num;
};


#endif //STRATEGY_1_HPP