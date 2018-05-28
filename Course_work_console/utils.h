#pragma once
#pragma warning( disable:4996 )

#include <iostream>
#include <vector>
#include "Document.h"
#include "html_attr_val_db.h"
#include "html_tag_db.h"

#define SCRIPT_STARTED  (-5)
#define STYLE_STARTED   (-4)
#define XML_STARTED     (-3)
#define COMMENT_STARTED (-2)

void * GenNewStr(char * str);                                                     // returns pointer to std::string
void * GenNewStrW(char * str);                                                    // returns pointer to std::string
void * GenNewAttr(std::string attr, std::string val);                             // returns pointer to htmlAttribute 
void * GenNewAttr(std::string attr);                                              // returns pointer to htmlAttribute
void * GenNewAttrList(htmlAttribute * attr);                                      // returns pointer to std::list<htmlAttribute>
void * AppendAttrInList(htmlAttribute * attr, std::list<htmlAttribute> * lst);    // returns pointer to std::list<htmlAttribute>
int    Token(void * text, int value);
void   CleanUpUtilsStructures();

#define _DEBUG

inline void DBG_PRINT(std::string message, std::string value, int line)
{
#ifdef _DEBUG
	std::cout <<  message << " : " << value << " line: " << line << std::endl;
#endif
}
