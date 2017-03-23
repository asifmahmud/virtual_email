#include "transfer.hpp"
#include <sstream>


bool in(std::vector<std::string>& iterable, Person person)
{
	for (unsigned int i = 0; i < iterable.size(); i++)
	{
		if (person.get_id() == iterable[i])
		{
			return true;
		}
	}
	return false;
}

//#################################################################


bool index_exists(std::vector<Person>& people_list, unsigned int index)
{
	std::vector<bool> v;
	for (unsigned int i = 0; i < people_list.size(); i++)
	{
		if (index < people_list[i].inbox.size())
		{
			v.push_back(true);
		}
		else
		{
			v.push_back(false);
		}
	}
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == true)
		{
			return true;
		}
	}
	return false;
}

//#################################################################


void print_info(Message m)
{
	std::cout << "Message Received!" << std::endl;
	std::cout << "From   : " << m.from << std::endl;
	std::cout << "To     : " << m.to << std::endl;
	std::cout << "Content: ID#" << m.get_id() << " " << "(Type#" << m.type_number() << ")" << std::endl;
	std::cout << "=============================== " << std::endl;
	std::cout << " \n";

}

//#################################################################



void insert_message(Message& m, Person& from, Person& to)
{
	m.from = from.get_id();
	m.to = to.get_id();
	to.insert_message(m);
	to.update_count();
	print_info(m);
}



//#################################################################


void message_send(std::vector<Person>& people_list, Person& p, 
					unsigned int index, std::string condition, unsigned int quality = 0, unsigned int type = 0)
{
	if (index < p.inbox.size())
	{
		Message m = p.inbox[index];

		if (condition == "all")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]))
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "sender all")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.from != people_list[i].get_id())
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "next all")
		{
			std::cout << "counter is: " << p.counter << std::endl;

			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && people_list[i].get_id() == p.contacts[p.counter])
				{
					insert_message(m, p, people_list[i]);
					p.increase_counter();
					p.reset_counter();
					break;
				}
			}
		}

		else if (condition == "joke all")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.return_type() == "joke")
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "joke sender")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.return_type() == "joke" && 
					m.from != people_list[i].get_id())
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "next joke")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && people_list[i].get_id() == p.contacts[p.counter] &&
					m.return_type() == "joke")
				{
					insert_message(m, p, people_list[i]);
					p.increase_counter();
					p.reset_counter();
					break;
				}
			}
		}

		else if (condition == "scheme all")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.return_type() == "scheme")
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "scheme sender")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.return_type() == "scheme" &&
					m.from != people_list[i].get_id())
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "next scheme")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && people_list[i].get_id() == p.contacts[p.counter] &&
					m.return_type() == "scheme")
				{
					insert_message(m, p, people_list[i]);
					p.increase_counter();
					p.reset_counter();
					break;
				}
			}
		}


		else if (condition == "stories all")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.return_type() == "story")
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "stories sender")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.return_type() == "story" &&
					m.from != people_list[i].get_id())
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "next story")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && people_list[i].get_id() == p.contacts[p.counter] &&
					m.return_type() == "story")
				{
					insert_message(m, p, people_list[i]);
					p.increase_counter();
					p.reset_counter();
					break;
				}
			}
		}

		else if (condition == "virus all")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.return_type() == "virus")
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}


		else if (condition == "virus sender")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.return_type() == "virus" &&
					m.from != people_list[i].get_id())
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "next virus")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && people_list[i].get_id() == p.contacts[p.counter] &&
					m.return_type() == "virus")
				{
					insert_message(m, p, people_list[i]);
					p.increase_counter();
					p.reset_counter();
					break;
				}
			}
		}

		else if (condition == "forward above all")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.quality_number() >= quality)
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}


		else if (condition == "forward above sender")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.quality_number() >= quality && 
					m.from != people_list[i].get_id())

				{
					insert_message(m, p, people_list[i]);
				}
			}
		}


		else if (condition == "forward above next")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && people_list[i].get_id() == p.contacts[p.counter] &&
					m.quality_number() >= quality)
				{
					insert_message(m, p, people_list[i]);
					p.increase_counter();
					p.reset_counter();
					break;
				}
			}
		}


		else if (condition == "forward above q all")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.type_number() == type && m.quality_number() >= quality)
				{
					insert_message(m, p, people_list[i]);
				}
			}
		}

		else if (condition == "forward above q sender")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && m.quality_number() >= quality && m.type_number() == type &&
					m.from != people_list[i].get_id())

				{
					insert_message(m, p, people_list[i]);
				}
			}
		}


		else if (condition == "forward above q next")
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				if (in(p.contacts, people_list[i]) && people_list[i].get_id() == p.contacts[p.counter] &&
					m.quality_number() >= quality && m.type_number() == type)
				{
					insert_message(m, p, people_list[i]);
					p.increase_counter();
					p.reset_counter();
					break;
				}
			}
		}

		else if (condition == "never")
		{
		}

	}

}

//#################################################################


void strategy_1(std::vector<Person>& people_list, Person& p, unsigned int index)
{
	if (p.decision[0] == "forward all messages")
	{
		if (p.send_decision == "forward all members")
		{
			message_send(people_list, p, index, "all");
		}

		else if (p.send_decision == "forward except sender")
		{
			message_send(people_list, p, index, "sender all");
		}

		else if (p.send_decision == "forward_to_next")
		{
			message_send(people_list, p, index, "next all");
		}
	}
}


//#################################################################


void strategy_2(std::vector<Person>& people_list, Person& p, unsigned int index)
{
	if (p.decision[0] == "forward all jokes")
	{

		if (p.send_decision == "forward all members")
		{
			message_send(people_list, p, index, "joke all");
		}

		else if (p.send_decision == "forward except sender")
		{
			message_send(people_list, p, index, "joke sender");
		}

		else if (p.send_decision == "forward_to_next")
		{
			message_send(people_list, p, index, "next joke");
		}
	}

	else if (p.decision[0] == "forward all schemes")
	{
		if (p.send_decision == "forward all members")
		{
			message_send(people_list, p, index, "scheme all");
		}

		else if (p.send_decision == "forward except sender")
		{
			message_send(people_list, p, index, "scheme sender");
		}

		else if (p.send_decision == "forward_to_next")
		{
			message_send(people_list, p, index, "next scheme");
		}
	}

	else if (p.decision[0] == "forward all stories")
	{
		if (p.send_decision == "forward all members")
		{
			message_send(people_list, p, index, "stories all");
		}

		else if (p.send_decision == "forward except sender")
		{
			message_send(people_list, p, index, "stories sender");
		}

		else if (p.send_decision == "forward_to_next")
		{
			message_send(people_list, p, index, "next story");
		}
	}

	else if (p.decision[0] == "forward all virus")
	{
		if (p.send_decision == "forward all members")
		{
			message_send(people_list, p, index, "virus all");
		}

		else if (p.send_decision == "forward except sender")
		{
			message_send(people_list, p, index, "virus sender");
		}

		else if (p.send_decision == "forward_to_next")
		{
			message_send(people_list, p, index, "next virus");
		}
	}
}


//#################################################################


void strategy_3(std::vector<Person>& people_list, Person& p, unsigned int index)
{
	if (p.decision[0] == "forward above")
	{
		int val;
		std::istringstream ss(p.decision[1]);
		ss >> val;

		if (p.send_decision == "forward all members")
		{
			message_send(people_list, p, index, "forward above all", val);
		}

		else if (p.send_decision == "forward except sender")
		{
			message_send(people_list, p, index, "forward above sender", val);
		}

		else if (p.send_decision == "forward_to_next")
		{
			message_send(people_list, p, index, "forward above next", val);
		}
	}
}

//#################################################################


void strategy_4(std::vector<Person>& people_list, Person& p, unsigned int index)
{
	if (p.decision[0] == "forward above q")
	{
		int q, t;
		std::istringstream ss(p.decision[1]);
		std::istringstream s2(p.decision[2]);
		ss >> q;
		s2 >> t;

		if (p.send_decision == "forward all members")
		{
			message_send(people_list, p, index, "forward above q all", q, t);
		}

		else if (p.send_decision == "forward except sender")
		{
			message_send(people_list, p, index, "forward above q sender", q, t);
		}

		else if (p.send_decision == "forward_to_next")
		{
			message_send(people_list, p, index, "forward above q next", q, t);
		}
		
	}
}


//#################################################################


void strategy_5(std::vector<Person>& people_list, Person& p, unsigned int index)
{
	if (p.decision[0] == "never")
	{
		message_send(people_list, p, index, "never");
	}
}




//####################################################################

void transfer_messages(std::vector<Person>& people_list)
{
	unsigned int temp = 0;
	while (true)
	{
		if (index_exists(people_list, temp))
		{
			for (unsigned int i = 0; i < people_list.size(); i++)
			{
				strategy_1(people_list, people_list[i], temp);
				strategy_2(people_list, people_list[i], temp);
				strategy_3(people_list, people_list[i], temp);
				strategy_4(people_list, people_list[i], temp);
				strategy_5(people_list, people_list[i], temp);
			}
		}

		else
		{
			break;
		}
		++temp;
	}
}