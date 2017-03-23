#include "strategy.hpp"
#include <vector>

class forward_strategy_5 : public ForwardStrategy
{

public:
	forward_strategy_5(unsigned int s_num) : s_num(s_num) {}
	std::vector<std::string> decide() const {std::vector<std::string> v; v.push_back("never"); return v; }

private:
	unsigned int s_num;
};