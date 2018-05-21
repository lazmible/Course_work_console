#include "utils.h"

std::vector<std::string>                strings;
std::vector<std::vector<htmlAttribute>> attributes_lists;
std::vector<htmlAttribute>              attributes;

static std::stack<char> g_IgnoreStack;
static std::vector<std::string> g_IgnoreTags = { "script", "style", "xml", };

void PushIgnore()
{
	std::cout << "******************************PUSH IGNORE******************************" << std::endl;
	g_IgnoreStack.push(1);
}

void PopIgnore()
{
	std::cout << "******************************POP IGNORE******************************" << std::endl;
	g_IgnoreStack.pop();
}

bool IgnoreModeOn()
{
	return (!g_IgnoreStack.empty());
}

int CheckOpeningTagNameForIgnore(std::string name)
{
	for (auto it : g_IgnoreTags)
	{
		if (name == it) 
		{
			if (IgnoreModeOn())
			{
				PushIgnore();
				return TAG_IGNORE_BUT_MODE_ON; 
			}
			else                
			{
				PushIgnore();
				return TAG_IGNORE;             
			} 
		}
	}
	return TAG_NOT_IGNORE;
	
}

int CheckClosingTagNameForIgnore(std::string name)
{
	for (auto it : g_IgnoreTags)
	{
		if (name == it) 
		{
			PopIgnore(); 
			if (IgnoreModeOn()) 
			{ 
				return TAG_IGNORE_BUT_MODE_ON; 
			}
			else 
			{ 
				return TAG_IGNORE; 
			}
		}
	}
	return TAG_NOT_IGNORE;
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