#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <regex>
#include <list>
#include <initializer_list>
#include <cctype>


typedef std::map<std::string, std::string>              db_attr_type;
typedef std::map<std::string, std::vector<std::string>> db_tag_type;

class htmlAttribute
{
private:
	std::string name;
	std::string value;
	std::size_t line;

	std::vector<std::string> names_database;
	std::map<std::string, std::string> values_database;

	bool check_value();
	bool check_name();

public:

	htmlAttribute(std::string _name, const std::map<std::string, std::string> & val_db,
		std::string err, std::string val, int _line)
		: name(_name), values_database(val_db), value(val), line(_line)
	{}

	void CheckState();
	const std::string GetName()  const { return (name); }
	const std::string GetValue() const { return (value); }
	void SetName(std::string _name) { name = _name; }
	void SetValue(std::string _value) { value = _value; }
};

