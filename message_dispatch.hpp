#include "person.hpp"

class MailDispatch
{
public:
	MailDispatch();
	void dispatch(Person person, Message message, std::string from, std::string to);
};