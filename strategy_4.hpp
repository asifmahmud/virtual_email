#ifndef STRATEGY_4_HPP
#define STRATEGY_4_HPP
#include "strategy_3.hpp"
#include <vector>

class forward_strategy_4 : public forward_strategy_3
{
public:
	forward_strategy_4(unsigned int s_num, unsigned int quality_num, unsigned int type_num);
	std::vector<std::string> decide() const;

private:
	unsigned int s_num, quality_num, type_num;
};

#endif //STRATEGY_4_HPP