#include "message.hpp"

Message::Message(std::string from, std::string to, unsigned int unique_id, unsigned int quality_rating, unsigned int m_type)
	:from(from), to(to), unique_id(unique_id), quality_rating(quality_rating), m_type(m_type)
{
	MessageContent message_c(unique_id, quality_rating, m_type);
	type = message_c.base_type;
	id = message_c.get_id();
}


int Message::get_id() const
{
	return id;
}


std::string Message::return_type() const
{
	return type;
}

unsigned int Message::type_number() const
{
	return m_type;
}

unsigned int Message::quality_number() const
{
	return quality_rating;
}