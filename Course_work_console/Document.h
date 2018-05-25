#pragma once

#include "Tag.h"

class htmlDocument
{
private:

	std::stack<htmlTag>   state_stack;
	db_attr_type          available_attributes;
	db_tag_type           available_tags;
	
	bool tag_name_is_correct(std::string name);
	void check_previous_state(htmlTag tag);

public:
	htmlDocument(std::string file, db_attr_type attr_db, db_tag_type tag_db)
		: available_attributes(attr_db), available_tags(tag_db)
	{}

	~htmlDocument() {}

	void AddOpeningTag(std::string tag_name, int line);
	void AddOpeningTag(std::string tag_name, std::list<htmlAttribute> attrs, int line);
	void AddClosingTag(std::string tag_name, int line);
	void AddSingleTag(std::string tag_name, int line);
	void AddSingleTag(std::string tag_name, std::list<htmlAttribute> attrs, int line);
};