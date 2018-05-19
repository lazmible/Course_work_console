#pragma once

#include "Tag.h"

class htmlDocument
{
private:

	std::string           filename;
	std::stack<htmlTag>   state_stack;
	db_attr_type          available_attributes;
	db_tag_type           available_tags;

	
//	bool precursory_correct(htmlTag tag);
//	bool attributes_correct(htmlTag tag);
	bool tag_name_is_correct(std::string name);
	

public:
	htmlDocument(std::string file, db_attr_type attr_db, db_tag_type tag_db)
	    : filename(file), available_attributes(attr_db), available_tags(tag_db)
	{
		//std::cout << "Generated document, available tags --> [attributes]:\n";
		//for (auto it : available_tags)
		//{
		//	std::cout << "\t" << it.first << "--> [";
		//	for (auto it_1 : it.second)
		//	{
		//		std::cout << it_1 << " ";
		//	}
		//	std::cout << "]\n";
		//}
		//std::cout << "Generated document, available attributes --> values:\n";
		//for (auto it : available_attributes)
		//{
		//	std::cout << it.first << "-->" << it.second << std::endl;
		//}
	}

	~htmlDocument();


	void AddOpeningTag(std::string tag_name);
	void AddOpeningTag(std::string tag_name, std::vector<htmlAttribute> attrs);
	void AddClosingTag(std::string tag_name);
	void AddSingleTag(std::string tag_name);
	void AddSingleTag(std::string tag_name, std::vector<htmlAttribute> attrs);
	void CheckEndState();
	void AddAttributeToLastTag(std::string attr, std::string val);
};