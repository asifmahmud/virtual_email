#include <iostream>
#include "person.hpp"


Person::Person(std::string email, std::vector<std::string> contacts, std::vector<int> forward_strategy_list, int send_strategy)
:email(email), contacts(contacts), f_strategy_list(forward_strategy_list), s_strategy(send_strategy), counter(0)
{
	if (f_strategy_list[0] == 1)
	{
		forward_strategy_1 fs_1(1);
		decision = f_decide(&fs_1);
	}
	else if (f_strategy_list[0] == 2)
	{
		forward_strategy_2 fs_2(2, f_strategy_list[1]);
		decision = f_decide(&fs_2);
	}
	else if (f_strategy_list[0] == 3)
	{
		forward_strategy_3 fs_3(3, f_strategy_list[1]);
		decision = f_decide(&fs_3);
	}

	else if (f_strategy_list[0] == 4)
	{
		forward_strategy_4 fs_4(4, f_strategy_list[1], f_strategy_list[2]);
		decision = f_decide(&fs_4);
	}

	else if (f_strategy_list[0] == 5)
	{
		forward_strategy_5 fs_5(5);
		decision = f_decide(&fs_5);
	}
	

	if (s_strategy == 1)
	{
		send_strategy_1 ss_1(1);
		send_decision = s_decide(&ss_1);
	}
	else if (s_strategy == 2)
	{
		send_strategy_2 ss_2(2);
		send_decision = s_decide(&ss_2);
	}
	else if (s_strategy == 3)
	{
		send_strategy_3 ss_3(3);
		send_decision = s_decide(&ss_3);
	}
}


std::string Person::get_id() const
{
	return email;
}



void Person::update_count()
{
	for (auto &i : content_count)
	{
		if (inbox.back().get_id() == i.first)
		{
			i.second++;
			inbox.pop_back();
			return;
		}
	}
	content_count[inbox.back().get_id()] = 1;
}

void Person::get_count()
{
	for (auto &i:inbox)
	{
		content_count[i.get_id()] = 1;
	}
}

unsigned int Person::total()
{
	unsigned int total_messages = 0;
	for (auto &i : content_count)
	{
		total_messages += i.second;
	}
	return total_messages;
}

void Person::print_message_info()
{
	std::cout << "Messages received by " << get_id() << std::endl;
	for (auto &i : content_count)
	{
		std::cout << "  Content#" << i.first << ": " << i.second << std::endl;
	}
	std::cout << "  TOTAL RECEIVED: " << total() << std::endl;
	std::cout << "\n";
}





void Person::insert_message(Message message)
{
	inbox.push_back(message);
}


int Person::get_message_id() const
{
	return inbox[0].get_id();
}


std::vector<std::string> Person::f_decide(ForwardStrategy* f_strategy)
{
	return f_strategy->decide();
}


std::string Person::s_decide(SendStrategy* s_strategy)
{
	return s_strategy->decide();
}


void Person::remove_message()
{
	inbox.erase(inbox.begin());

}


void Person::increase_counter()
{
	++counter;
}

void Person::reset_counter()
{
	if (counter == contacts.size() - 1)
	{
		counter = 0;
	}
}











