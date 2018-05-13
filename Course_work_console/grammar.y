%{
	#include <iostream>
    #include <string>
	#include "Document.h"

    #pragma warning( disable:4996 )
    #pragma warning( disable:5033 )
	
    int  yyerror (const char * err);
    int  yylex   ();
	extern FILE  * yyin;
    extern htmlDocument doc;
%}

%union
{
    void *  string_t     ;
}


%token HTML_COMMENT HTML_CONDITIONAL_COMMENT   HEXCHARS  
OPENING_TAG_BRACKET CLOSING_TAG_BRACKET SLASH ASSIGNMENT OPENING_TAG CLOSING_TAG


%token<string_t> DOUBLE_QUOTE_STRING SINGLE_QUOTE_STRING TEXT TAG_NAME 

%type<string_t> htmlAttributeValue htmlAttribute

%start htmlDocument

%%

htmlDocument
    :  
    | htmlElement
    | htmlDocument htmlElement
    | htmlComment
    ;

htmlElement
    : htmlTagOpen 
    | htmlTagClose                                
    | htmlTagSingle
    | TEXT                        
    ;

htmlTagOpen
    : OPENING_TAG_BRACKET TEXT htmlAttributeList CLOSING_TAG_BRACKET { std::cout << "\t[parser]: found opening tag - " << *((std::string*)($2)) << std::endl; doc.AddOpeningTag(*((std::string*)($2))); }
    | OPENING_TAG_BRACKET TEXT CLOSING_TAG_BRACKET                   { std::cout << "\t[parser]: found opening tag - " << *((std::string*)($2)) << std::endl; doc.AddOpeningTag(*((std::string*)($2))); }
    ;

htmlTagClose
    : OPENING_TAG_BRACKET SLASH TEXT CLOSING_TAG_BRACKET   { std::cout << "\t[parser]: found closing tag - " << *((std::string*)($3)) << std::endl; doc.AddClosingTag(*((std::string*)($3))); }
    ;

htmlTagSingle
    : OPENING_TAG_BRACKET TEXT htmlAttributeList SLASH CLOSING_TAG_BRACKET 
    | OPENING_TAG_BRACKET TEXT SLASH CLOSING_TAG_BRACKET
    ;

htmlComment
    : HTML_COMMENT
    | HTML_CONDITIONAL_COMMENT 
    ;

htmlAttributeList
    : htmlAttribute
    | htmlAttributeList htmlAttribute
    ;

htmlAttribute 
    : TEXT ASSIGNMENT htmlAttributeValue { std::cout << "\t[parser]: found attribute with value - " << *((std::string*)($1)) << " = " << *((std::string*)($3)) << std::endl; }
    | TEXT                               { std::cout << "\t[parser]: found attribute - " << *((std::string*)($1)) << std::endl; }
    ;

htmlAttributeValue
    : SINGLE_QUOTE_STRING 
    | DOUBLE_QUOTE_STRING 
    ;

%%