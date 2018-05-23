#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <regex>
#include <list>
#include <initializer_list>

#include "error.h"

#define DEBUG_LEVEL_2

#ifdef DEBUG_LEVEL_2 
    #define DBG(a, b) { std::cout << a << " : " << b << std::endl; }
#else
    #define DBG(a, b)
#endif

typedef std::map<std::string, std::string> db_attr_type;
typedef std::map<std::string, std::vector<std::string>> db_tag_type;

class htmlAttribute
{
private:
	std::string name;
	std::string value;
	std::string error_message;

	std::vector<std::string> names_database;
	std::map<std::string, std::string> values_database;

	bool check_value();
	bool check_name();

public:
	//htmlAttribute(std::string _name, const std::initializer_list<std::pair<std::string, std::string>> & val_db, std::string err, std::string val)
	//	: name(_name), values_database(val_db.begin(), val_db.end()), error_message(err), value(val) 
	//{

	//}

	htmlAttribute(std::string _name, const std::map<std::string, std::string> & val_db, std::string err, std::string val)
		: name(_name), values_database(val_db), error_message(err), value(val)
	{

	}

	/*htmlAttribute(const htmlAttribute & other) {}*/

	void CheckState();
	const std::string GetName()  const { return (name); }
	const std::string GetValue() const { return (value); }
	void SetName(std::string _name) { name = _name; }
	void SetValue(std::string _value) { value = _value; }
};

