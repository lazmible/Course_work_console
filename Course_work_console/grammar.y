%{
	#include <iostream>
    #include <string>
	#include "Document.h"
    #include "utils.h"

    #pragma warning( disable:4996 )
    #pragma warning( disable:5033 )
	
    int  yyerror (const char * err);
    int  yylex   ();
	extern FILE  * yyin;
    extern int yylineno;
    extern htmlDocument doc;
%}

%union
{
    void *  string_t     ;
}


%token HTML_COMMENT HTML_CONDITIONAL_COMMENT    
OPENING_TAG_BRACKET CLOSING_TAG_BRACKET SLASH ASSIGNMENT SCRIPT IGNORE COMMENT_START COMMENT_END


%token<string_t> DOUBLE_QUOTE_STRING SINGLE_QUOTE_STRING TEXT TAG_NAME

%type<string_t> htmlAttributeValue htmlAttribute htmlAttributeList  

%start htmlDocument

%%

htmlDocument
    :  
    | htmlElement
    | htmlDocument htmlElement
    | htmlComment
    | htmlDocument htmlComment
    | htmlContent
    | htmlDocument htmlContent
    ;

htmlElement
    : htmlTagOpen 
    | htmlTagClose                                
    | htmlTagSingle                      
    ;

htmlTagOpen
    : OPENING_TAG_BRACKET TEXT htmlAttributeList CLOSING_TAG_BRACKET { DBG_PRINT("\t[parser]: found opening tag",*((std::string*)($2)), yylineno); doc.AddOpeningTag(*((std::string*)($2)),*((std::vector<htmlAttribute>*)($3))); }
    | OPENING_TAG_BRACKET TEXT CLOSING_TAG_BRACKET                   { DBG_PRINT("\t[parser]: found opening tag",*((std::string*)($2)), yylineno); doc.AddOpeningTag(*((std::string*)($2)));                                      }
    ;

htmlTagClose
    : OPENING_TAG_BRACKET SLASH TEXT CLOSING_TAG_BRACKET   { DBG_PRINT("\t[parser]: found closing tag",*((std::string*)($3)),yylineno); doc.AddClosingTag(*((std::string*)($3))); }
    ;

htmlTagSingle
    : OPENING_TAG_BRACKET TEXT htmlAttributeList SLASH CLOSING_TAG_BRACKET { DBG_PRINT("\t[parser]: found single tag",*((std::string*)($2)),yylineno); doc.AddSingleTag(*((std::string*)($2))); } 
    | OPENING_TAG_BRACKET TEXT SLASH CLOSING_TAG_BRACKET
    ;

htmlAttributeList
    : htmlAttribute                           { ($$) = GenNewAttrList(((htmlAttribute*)($1)));                                        }
    | htmlAttributeList htmlAttribute         { ($$) = AppendAttrInList(((htmlAttribute*)($2)), ((std::vector<htmlAttribute>*)($1))); }
    ;

htmlAttribute 
    : TEXT ASSIGNMENT htmlAttributeValue { DBG_PRINT("\t[parser]: found attribute with value",*((std::string*)($1)) + " = " + *((std::string*)($3)), yylineno); ($$) = GenNewAttr(*((std::string*)($1)), *((std::string*)($3))); }
    | TEXT                               { DBG_PRINT("\t[parser]: found attribute",*((std::string*)($1)), yylineno); ($$) = GenNewAttr(*((std::string*)($1))); }
    ;

htmlAttributeValue
    : SINGLE_QUOTE_STRING 
    | DOUBLE_QUOTE_STRING
    | TEXT 
    ;

htmlComment
    : COMMENT_START htmlContent COMMENT_END
    | COMMENT_START COMMENT_END 
    ;

htmlContent
    : OPENING_TAG_BRACKET
    | CLOSING_TAG_BRACKET
    | ASSIGNMENT
    | SLASH
    | TEXT
    | IGNORE
    | htmlContent OPENING_TAG_BRACKET
    | htmlContent CLOSING_TAG_BRACKET
    | htmlContent ASSIGNMENT
    | htmlContent SLASH
    | htmlContent TEXT
    | htmlContent IGNORE
    ;
%%