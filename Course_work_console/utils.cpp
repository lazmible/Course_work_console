#include "utils.h"

std::vector<std::string>                strings;
std::vector<std::vector<htmlAttribute>> attributes_lists;
std::vector<htmlAttribute>              attributes;

void * GenNewStr(char * str) // returns pointer to std::string
{
	std::string _str;
	_str = str;
	strings.push_back(_str);
	return (&(*(--strings.end())));
}

void * GenNewStrW(char * str) // returns pointer to std::string 
{
	std::string _str;
	_str = str;
	_str.erase(_str.begin());
	_str.erase(--_str.end());
	strings.push_back(_str);
	return (&(*(--strings.end())));
}

void * GenNewAttr(std::string attr, std::string val) // returns pointer to htmlAttribute 
{
	htmlAttribute instance(attr, ATTR_DATABASE_HTML5, "", val);
	attributes.push_back(instance);
	return (&(*(--attributes.end())));
}

void * GenNewAttr(std::string attr) // returns pointer to htmlAttribute 
{
	htmlAttribute instance(attr, ATTR_DATABASE_HTML5, "", "");
	attributes.push_back(instance);
	return (&(*(--attributes.end())));
}

void * GenNewAttrList(htmlAttribute * attr) // returns pointer to std::vector<htmlAttribute>
{
	std::vector<htmlAttribute> instance;
	instance.reserve(1000000);
	instance.push_back(*attr);
	attributes_lists.push_back(instance);
	return (&(*(--attributes_lists.end())));
}

void * AppendAttrInList(htmlAttribute * attr, std::vector<htmlAttribute> * lst) // returns pointer to std::vector<htmlAttribute>
{
	lst->push_back(*attr);
	return (lst);
}