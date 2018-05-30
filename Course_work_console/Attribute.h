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
	std::size_t column;

	std::vector<std::string> names_database;
	std::map<std::string, std::string> values_database;

	bool check_value();
	bool check_name();

public:

	htmlAttribute(std::string _name, const std::map<std::string, std::string> & val_db,
		std::string err, std::string val, int _line, int _column)
		: name(_name), values_database(val_db), value(val), line(_line), column(_column)
	{}

	void CheckState();
	const std::string GetName()  const { return (name); }
	const std::string GetValue() const { return (value); }
	void SetName(std::string _name) { name = _name; }
	void SetValue(std::string _value) { value = _value; }

	htmlAttribute & operator = (const htmlAttribute & other)
	{
		name = other.name;
		value = other.value;
		line = other.line;
		column = other.column;
		names_database = other.names_database;
		values_database = other.values_database;

		return (*this);
	}
};

