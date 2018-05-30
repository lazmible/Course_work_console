#include "utils.h"
#include "debug.h"
#include "grammar.cpp.h"

#include <string>

std::list<std::string>                strings;
std::list<std::list<htmlAttribute>>   attributes_lists;
std::list<htmlAttribute>              attributes;

extern int yylineno;
extern int yyleng;
extern int g_LexerColumn;

void CleanUpUtilsStructures()
{
	strings.clear();
	attributes_lists.clear();
	attributes.clear();
}

std::string StrToken(int token)
{
	switch (token)
	{
	    case OPENING_TAG_BRACKET    : { return "OPENING_TAG_BRACKET";    }
	    case CLOSING_TAG_BRACKET    : { return "CLOSING_TAG_BRACKET";    }
	    case ASSIGNMENT             : { return "ASSIGNMENT";             }
	    case SLASH                  : { return "SLASH";                  }
	    case SINGLE_QUOTE_STRING    : { return "SINGLE_QUOTE_STRING";    }
	    case DOUBLE_QUOTE_STRING    : { return "DOUBLE_QUOTE_STRING";    }
	    case TEXT                   : { return "TEXT";                   }
	    case SCRIPT_STARTED         : { return "SCRIPT_STARTED";         }
	    case STYLE_STARTED          : { return "STYLE_STARTED";          }
	    case XML_STARTED            : { return "XML_STARTED";            }
		case DOCTYPE                : { return "DOCTYPE";                }
		case DOCTYPE_HTML_5         : { return "DOCTYPE_HTML_5";         }
		case DOCTYPE_STRICT_1       : { return "DOCTYPE_STRICT_1";       }
		case DOCTYPE_STRICT_2       : { return "DOCTYPE_STRICT_2";       }
		case DOCTYPE_TRANS_1        : { return "DOCTYPE_TRANS_1";        }
		case DOCTYPE_TRANS_2        : { return "DOCTYPE_TRANS_2";        }
		case DOCTYPE_FRAME_1        : { return "DOCTYPE_FRAME_1";        }
		case DOCTYPE_FRAME_2        : { return "DOCTYPE_FRAME_2";        }
		case DOCTYPE_XHTML_STRICT_1 : { return "DOCTYPE_XHTML_STRICT_1"; }
		case DOCTYPE_XHTML_STRICT_2 : { return "DOCTYPE_XHTML_STRICT_2"; }
		case DOCTYPE_XHTML_TRANS_1  : { return "DOCTYPE_XHTML_TRANS_1";  }
		case DOCTYPE_XHTML_TRANS_2  : { return "DOCTYPE_XHTML_TRANS_2";  }
		case DOCTYPE_XHTML_FRAME_1  : { return "DOCTYPE_XHTML_FRAME_1";  }
		case DOCTYPE_XHTML_FRAME_2  : { return "DOCTYPE_XHTML_FRAME_2";  }
		case DOCTYPE_XHTML_1_1_1    : { return "DOCTYPE_XHTML_1_1_1";    }
		case DOCTYPE_XHTML_1_1_2    : { return "DOCTYPE_XHTML_1_1_2";    }
		case DOCTYPE_XHTML          : { return "DOCTYPE_XHTML";          }
		default                     : { return "UNKNOWN TOKEN";          }
	}
}

int Token(void * text, int value)
{
	switch (value)
	{
	    case (SINGLE_QUOTE_STRING)  : { yylval.string_t = GenNewStrW((char*)text); break; }
	    case (DOUBLE_QUOTE_STRING)  : { yylval.string_t = GenNewStrW((char*)text); break; }
	    case (TEXT)                 : { yylval.string_t = GenNewStr((char*)text);  break; }
	}
	DEBUG_MESSAGE(StrToken(value), DEBUG_CODE_LEXER, yylineno, g_LexerColumn);
	g_LexerColumn += yyleng;
	return (value);
}

void * GenNewStr(char * str) // returns pointer to std::string
{
	std::string _str = str;
	strings.push_back(_str);
	return (&(*(--strings.end())));
}

void * GenNewStrW(char * str) // returns pointer to std::string 
{
	std::string _str = str;
	_str.erase(_str.begin());
	_str.erase(--_str.end());
	strings.push_back(_str);
	return (&(*(--strings.end())));
}

void * GenNewAttr(std::string attr, std::string val) // returns pointer to htmlAttribute 
{
	htmlAttribute instance(attr, ATTR_DATABASE, "", val, yylineno, g_LexerColumn);
	attributes.push_back(instance);

	return (&(*(--attributes.end())));
}

void * GenNewAttr(std::string attr) // returns pointer to htmlAttribute 
{
	htmlAttribute instance(attr, ATTR_DATABASE, "", "", yylineno, g_LexerColumn);
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