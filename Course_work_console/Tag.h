#pragma once

#include "Attribute.h"

class htmlTag
{
private:
	std::string name;
	std::vector<htmlAttribute> attribute_list;
	std::vector<std::string> precursory_tags;

	std::vector<std::string> valid_attribute_names_list;
	std::stack<std::string> state_before;

	const /*db_attr_type*/ std::map<std::string, std::string> &  attribute_database;
	const /*db_tag_type*/  std::map<std::string, std::vector<std::string>>&  tag_database;

	std::vector<error> check_precursory();
	bool check_name();
	bool check_attr_name(std::string name);

public:
	htmlTag
	(
		std::string              nm,
		std::stack<std::string>  st,
		const db_attr_type &     attr_db,
		const db_tag_type  &     tag_db
	);

	std::string GetName() { return name; }
	
	//std::vector<error> CheckState();
	void AddAttribute(std::string name, std::string val);
	
};