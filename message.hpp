#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include <iostream>
#include "message_content.hpp"


class Message
{
public:
	Message(std::string from, std::string to, unsigned int unique_id, unsigned int quality_rating, unsigned int m_type);
	std::string from, to;
	MessageContent message_c(unsigned int unique_id, unsigned int quality_rating, unsigned int m_type);
	int get_id() const;
	std::string return_type() const;
	std::string type;
	unsigned int type_number() const;
	unsigned int quality_number() const;
	void print_info();
	


private:
	unsigned int unique_id, quality_rating, m_type, id;
};



#endif //MESSAGE_HPP