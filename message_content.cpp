#include "message_content.hpp"

MessageContent::MessageContent(unsigned int unique_id, unsigned int quality_rating, unsigned int m_type)
	:unique_id(unique_id), quality_rating(quality_rating), m_type(m_type)
{
	if (m_type == joke + 1)
	{
		base_type = "joke";
	}
	else if (m_type == scheme + 1)
	{
		base_type = "scheme";
	}
	else if (m_type == story + 1)
	{
		base_type = "story";
	}
	else if (m_type == virus + 1)
	{
		base_type = "virus";
	}
}


int MessageContent::get_id() const
{
	return unique_id;
}

//bool MessageContent::operator==(const MessageContent& mc)
//{
//	if (unique_id == mc.unique_id)
//	{
//		return true;
//	}
//	return false;
//}
//
//bool MessageContent::operator<(const MessageContent& mc)
//{
//	if (mc.unique_id < unique_id)
//	{
//		return true;
//	}
//	return false;
//}









