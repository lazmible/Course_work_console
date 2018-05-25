#pragma once

#include "Attribute.h"

class htmlTag
{
private:
	std::string                   name;
	std::vector<htmlAttribute>    attribute_list;
	std::vector<std::string>      valid_attribute_names_list;
	std::size_t                   line;

	const db_attr_type  &  attribute_database;
	const db_tag_type   &  tag_database;

	bool check_name();
	bool check_attr_name(std::string name);
	void init();

public:
	htmlTag
	(
		std::string              nm,
		const db_attr_type &     attr_db,
		const db_tag_type  &     tag_db,
		std::size_t              _line
	) : name(nm), attribute_database(attr_db), tag_database(tag_db), line(_line)

	{ init(); }

	std::string GetName() { return name; }
	std::size_t GetLine() { return line; }
	void AddAttribute(std::string name, std::string val);
	
};