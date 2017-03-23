#ifndef MESSAGE_CONTENT_HPP
#define MESSAGE_CONTENT_HPP
#include <iostream>

class MessageContent
{
public:
	MessageContent(unsigned int unique_id, unsigned int quality_rating, unsigned int m_type);
	enum message_type{ joke, scheme, story, virus };
	unsigned int unique_id, quality_rating, m_type;
	int get_id() const;
	std::string base_type;
	//bool operator==(const MessageContent& mc);
	//bool operator<(const MessageContent& mc);
	
private:

	
};






#endif //MESSAGE_CONTENT_HPP