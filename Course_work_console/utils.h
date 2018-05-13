#pragma once
#pragma warning( disable:4996 )

#include <iostream>
#include <vector>

std::vector<std::string> strings;

void * GenNewStr(char * str)
{
	std::string _str;
	_str = str;
	strings.push_back(_str);
	return (&(*(--strings.end())));
}

void * GenNewStrW(char * str)
{
	std::string _str;
	_str = str;
	_str.erase(_str.begin());
	_str.erase(--_str.end());
	strings.push_back(_str);
	return (&(*(--strings.end())));
}
