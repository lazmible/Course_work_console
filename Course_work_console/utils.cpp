#include "utils.h"
#include "grammar.cpp.h"

#include <initializer_list>

std::list<std::string>                strings;
std::list<std::list<htmlAttribute>>   attributes_lists;
std::list<htmlAttribute>              attributes;

int Token(void * text, int value)
{
	//switch (value)
	//{
	//    case (SINGLE_QUOTE_STRING): { yylval.string_t = GenNewStrW((char*)text); break; }
	//    case (DOUBLE_QUOTE_STRING): { yylval.string_t = GenNewStrW((char*)text); break; }
	//    case (TEXT):                { yylval.string_t = GenNewStr((char*)text);  break; }
	//}
	return (value);
}

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
	//std::initializer_list<std::pair<std::string, std::string>> a = ATTR_DATABASE_HTML5;
	htmlAttribute instance(attr, { {"a", "a" }, {"a", "a"} }, "", val);
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
	std::list<htmlAttribute> instance;
	instance.push_back(*attr);
	attributes_lists.push_back(instance);
	return (&(*(--attributes_lists.end())));
}

void * AppendAttrInList(htmlAttribute * attr, std::list<htmlAttribute> * lst) // returns pointer to std::vector<htmlAttribute>
{
	lst->push_back(*attr);
	return (lst);
}