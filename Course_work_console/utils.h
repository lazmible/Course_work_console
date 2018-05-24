#pragma once
#pragma warning( disable:4996 )

#include <iostream>
#include <vector>
#include "Document.h"
#include "html_attr_val_db.h"
#include "html_tag_db.h"

void * GenNewStr(char * str);                                                     // returns pointer to std::string
void * GenNewStrW(char * str);                                                    // returns pointer to std::string
void * GenNewAttr(std::string attr, std::string val);                             // returns pointer to htmlAttribute 
void * GenNewAttr(std::string attr);                                              // returns pointer to htmlAttribute
void * GenNewAttrList(htmlAttribute * attr);                                      // returns pointer to std::vector<htmlAttribute>
void * AppendAttrInList(htmlAttribute * attr, std::list<htmlAttribute> * lst);   // returns pointer to std::vector<htmlAttribute>
int    Token(void * text, int value);
void   CleanUpUtilsStructures();

inline void DBG_PRINT(std::string message, std::string value, int line)
{
#ifdef _DEBUG
	std::cout <<  message << " : " << value << " line: " << line << std::endl;
#endif
}
