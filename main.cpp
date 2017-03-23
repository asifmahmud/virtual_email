#include <iostream>
#include <fstream>
#include <string>
#include "person.hpp"
#include <sstream>
#include "strategy_3.hpp"
#include "transfer.hpp"

std::vector<std::string> input_parser(std::ifstream& file, unsigned int num)
{
	std::vector<std::string> info_list;
	for (unsigned int i = 0; i < num; i++)
	{
		std::string temp;
		std::getline(file, temp);
		info_list.push_back(temp);
	}
	return info_list;
}


//###################################################################


int convert_to_int(std::string value)
{
	int int_val;
	std::istringstream convert(value);
	convert >> int_val;
	return int_val;
}

//###################################################################


std::vector<int> int_modifier(std::vector<std::string>& string_list)
{
	std::vector<int> s_list;
	for (unsigned int i = 0; i < string_list.size(); i++)
	{
		int int_val;
		std::istringstream convert(string_list[i]);
		convert >> int_val;
		s_list.push_back(int_val);
	}
	return s_list;
}

//###################################################################

std::string trim(std::string& s)
{
	size_t p = s.find_first_not_of(" \t");
	s.erase(0, p);

	p = s.find_last_not_of(" \t");
	if (std::string::npos != p)
	{
		s.erase(p + 1);
	}
	return s;
}

//###################################################################


std::vector<std::string> split_string(std::string& string)
{
	std::vector<std::string> v;
	std::istringstream iss(string);
	std::string sub;
	while (iss)
	{
		iss >> sub;
		v.push_back(sub);
	}
	return v;
}

//###################################################################

std::vector<std::string> create_contacts(std::string& string)
{
	std::vector<std::string> contacts;
	auto v = split_string(string);
	for (unsigned int i = 1; i < v.size(); i++)
	{
		contacts.push_back(v[i]);
	}
	return contacts;
}

//###################################################################

std::vector<unsigned int> unique_id_generator(unsigned int range)
{
	std::vector<unsigned int> v;
	for (unsigned int i = 1; i < range + 1; ++i)
	{
		v.push_back(i);
	}
	return v;
}

//###################################################################


Message create_message(std::string& info, unsigned int id)
{
	auto v = split_string(info);
	Message m(v[2], v[3], id, convert_to_int(v[1]), convert_to_int(v[0]));
	return m;
}
 

//###################################################################


void add_message(std::vector<Person>& people_list, std::vector<std::string>& message_info, unsigned int range)
{
	auto id_list = unique_id_generator(range);
	for (unsigned int i = 0; i < people_list.size(); i++)
	{
		for (unsigned int j = 0; j < message_info.size(); j++)
		{
			Message message = create_message(message_info[j], id_list[j]);
			if (message.to == people_list[i].get_id())
			{
				people_list[i].insert_message(message);
				people_list[i].update_count();
				print_info(message);
			}
		}
	}
}

//###################################################################


void simulator(std::string file)
{
	std::ifstream input_file(file);
	if (input_file.is_open())
	{
		std::ifstream& input_stream = input_file;
		std::string temp;
		std::getline(input_file, temp);
		int people_num = convert_to_int(temp);


		//CREATING PEOPLE FOR SIMULATION
		std::vector <Person> people_list;
		for (int i = 0; i < people_num; i++)
		{
			auto people_info = input_parser(input_stream, 4);
			auto v = create_contacts(people_info[1]);
			std::string t = trim(people_info[2]);
			std::vector<std::string> mod = split_string(t);
			auto strategy_list = int_modifier(mod);
			int send_strategy = convert_to_int(trim(people_info[3]));
			Person p(people_info[0], v, strategy_list, send_strategy);
			people_list.push_back(p);
		}

		//SETTING UP PEOPLES' INBOXES BEFORE SIMULATION
		std::string number_of_messages;
		std::getline(input_stream, number_of_messages);
		unsigned int message_num = convert_to_int(number_of_messages);
		std::vector<std::string> message_info = input_parser(input_stream, message_num);
		auto id_list = unique_id_generator(message_num);
		add_message(people_list, message_info, message_num);  //SETUP COMPLETE

		//BEGIN SIMULATION

		transfer_messages(people_list);

		for (auto &i : people_list)
		{
			i.print_message_info();
		}

		input_file.close();
	}

	else
	{
		std::cout << "Sorry, couldn't open file!" << std::endl;
	}
}


//###################################################################


int main(int argc, char** argv)
{
	simulator("input.txt");
	return 0;
}






