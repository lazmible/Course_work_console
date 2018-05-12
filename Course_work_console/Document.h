#pragma once

#include "Tag.h"

class htmlDocument
{
private:
	std::string           filename;
	std::stack<htmlTag>   state_stack;
	db_attr_type          available_attributes;
	db_tag_type           available_tags;

	/*
	bool precursory_correct(htmlTag tag);
	bool attributes_correct(htmlTag tag);
	bool name_correct(htmlTag tag);

	bool ProcessOpeningTag(htmlTag tag);
	bool ProcessClosingTag(htmlTag tag);
	*/

public:
	htmlDocument
	(
		std::string    file,
		db_attr_type   attr_db, 
		db_tag_type    tag_db
	)
	: filename(file) {}
	~htmlDocument() {} ;
	//void OpenSourseFile();
	//void Execute();

	void AddOpeningTag(std::string tag_name);
	void AddClosingTag(std::string tag_name);
};