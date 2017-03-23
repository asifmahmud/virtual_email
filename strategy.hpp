#ifndef STRATEGY_HPP
#define STRATEGY_HPP
#include <string>
class ForwardStrategy
{
public:
	virtual std::vector<std::string> decide() const = 0;
	virtual ~ForwardStrategy() = default;
};



class SendStrategy
{
public:
	virtual std::string decide() const = 0;
	virtual ~SendStrategy() = default;
};


#endif //STRATEGY_HPP