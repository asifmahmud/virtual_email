#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include "message.hpp"
#include "strategy_3.hpp"
#include "strategy_4.hpp"
#include "strategy_5.hpp"

class Person
{
public:
	Person(std::string email, std::vector<std::string> contacts, std::vector<int> forward_strategy_list, int send_strategy);
	std::map <unsigned int, unsigned int> content_count;
	std::string get_id() const;
	void get_count();
	void store_id();
	void update_count();
	void insert_message(Message message);
	int get_message_id() const;
	void print_message_info();
	void remove_message();
	std::vector<Message> inbox;
	std::vector<std::string> f_decide(ForwardStrategy* f_strategy);
	std::string s_decide(SendStrategy* s_strategy);
	std::string send_decision;
	std::vector<std::string> decision;
	std::vector<std::string> contacts;
	unsigned int counter;
	void increase_counter();
	void reset_counter();

private:
	std::string email;
	unsigned int contact_num;
	
	std::vector<unsigned int> id_list;
	std::vector<int> f_strategy_list;
	int s_strategy;
	unsigned int total();
};






#endif //PERSON_HPP