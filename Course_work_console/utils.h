#pragma once
#pragma warning( disable:4996 )

#include <iostream>
#include <vector>
#include "Document.h"
#include "html_attr_val_db.h"
#include "html_tag_db.h"

#ifdef _DEBUG
#define DBG_PRINT(a,b,c) { std::cout << a << " : " << b << " line: " << c << std::endl; }
#else
#define DBG_PRINT(a,b,c)
#endif

void * GenNewStr(char * str);                                                     // returns pointer to std::string
void * GenNewStrW(char * str);                                                    // returns pointer to std::string
void * GenNewAttr(std::string attr, std::string val);                             // returns pointer to htmlAttribute 
void * GenNewAttr(std::string attr);                                              // returns pointer to htmlAttribute
void * GenNewAttrList(htmlAttribute * attr);                                      // returns pointer to std::vector<htmlAttribute>
void * AppendAttrInList(htmlAttribute * attr, std::vector<htmlAttribute> * lst);  // returns pointer to std::vector<htmlAttribute>