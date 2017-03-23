#include "message_dispatch.hpp"

MailDispatch::MailDispatch()
{
}

void MailDispatch::dispatch(Person person, Message message, std::string from, std::string to)
{
	message.from = from; 
	message.to = to;
	person.insert_message(message);
}