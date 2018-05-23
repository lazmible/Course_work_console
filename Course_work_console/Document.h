#pragma once

#include "Tag.h"

class htmlDocument
{
private:

	std::string           filename;
	std::stack<htmlTag>   state_stack;
	db_attr_type          available_attributes;
	db_tag_type           available_tags;

	
	bool precedence_correct(htmlTag tag);
	bool tag_name_is_correct(std::string name);
	

public:
	htmlDocument(std::string file, db_attr_type attr_db, db_tag_type tag_db)
	    : filename(file), available_attributes(attr_db), available_tags(tag_db)
	{

	}

	~htmlDocument() {}

	void AddOpeningTag(std::string tag_name);
	void AddOpeningTag(std::string tag_name, std::list<htmlAttribute> attrs);
	void AddClosingTag(std::string tag_name);
	void AddSingleTag(std::string tag_name);
	void AddSingleTag(std::string tag_name, std::list<htmlAttribute> attrs);
};