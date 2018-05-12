%{
	#include <iostream>
    #pragma warning( disable:4996 )
    #pragma warning( disable:5033 )
	
    int  yyerror (const char * err);
    int  yylex   ();
	extern FILE  * yyin;
%}

//%union
//{
//    class htmlDocument  *  document_t   ;
//    class htmlTag       *  tag_t        ;
//    class htmlAttribute *  attribute_t  ;
//    const char          *  string_t     ;
//}

//%type<document_t>   document
//%type<tag_t>        tag
//%type<attribute_t>  attribute
//%type<string_t>     string

%token HTML_COMMENT HTML_CONDITIONAL_COMMENT DOUBLE_QUOTE_STRING SINGLE_QUOTE_STRING HEXCHARS TEXT TAG_NAME
OPENING_TAG_BRACKET CLOSING_TAG_BRACKET SLASH ASSIGNMENT

%start htmlDocument

%%

htmlDocument
    :  
    | htmlElement
    | htmlDocument htmlElement
    | htmlComment
    ;

htmlElement
    : htmlOpeningBracket htmlTagName htmlAttributes htmlClosingBracket htmlContent htmlOpeningBracket htmlSlash htmlTagName htmlClosingBracket
    | htmlOpeningBracket htmlTagName htmlAttributes htmlSlash htmlClosingBracket
    | htmlOpeningBracket htmlTagName htmlAttributes htmlClosingBracket
    | htmlOpeningBracket htmlTagName htmlClosingBracket htmlContent htmlOpeningBracket htmlSlash htmlTagName htmlClosingBracket 
    | htmlOpeningBracket htmlTagName htmlSlash htmlClosingBracket
    | htmlOpeningBracket htmlTagName htmlClosingBracket
    ;

htmlComment
    : HTML_COMMENT
    | HTML_CONDITIONAL_COMMENT 
    ;

htmlContent
    : TEXT 
    ;

htmlAttributes
    : htmlAttribute
    | htmlAttribute htmlAttributes
    ;

htmlAttribute 
    : htmlAttributeName ASSIGNMENT htmlAttributeValue
    ;
    | htmlAttributeName

htmlAttributeValue
    : SINGLE_QUOTE_STRING
    | DOUBLE_QUOTE_STRING
    ;

htmlTagName
    : TEXT  
    ;

htmlAttributeName
    : TEXT
    ;

htmlOpeningBracket
    : OPENING_TAG_BRACKET 
    ;

htmlClosingBracket
    : CLOSING_TAG_BRACKET 

htmlSlash
    : SLASH 
    ;

%%