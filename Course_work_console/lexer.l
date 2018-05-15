%option yylineno
%option nounistd
%option noyywrap

DOUBLE_QUOTE_STRING     "\""[^<\"]*"\""
SINGLE_QUOTE_STRING     "\'"[^<\']*"\'"
HEXCHARS                "#"[a-f0-9A-F]+ 
DECCHARS                [0-9]+"%"?
OPENING_TAG             "<"[^<]+">"
CLOSING_TAG             "</"[^<]+">"
    
%{
    #include <stdio.h>
    #include <io.h>
    #include <string>
    #include "utils.h"
    #include "grammar.cpp.h"
    #pragma warning( disable:4996 )
    #pragma warning( disable:5033 )
%}

%%

[ \t\r\f\v\a\n]+       {                                                                                                                                       }
"<!--"(.|\n)*?"-->"    { /*printf("\t[lexer]: HTML_COMMENT\n");*/                                                            return HTML_COMMENT;              }
"<!["(.|\n)*?"]>"      { /*printf("\t[lexer]: HTML_CONDITIONAL_COMMENT\n");*/                                                return HTML_CONDITIONAL_COMMENT;  }
"<"                    { /*printf("\t[lexer]: OPENING_TAG_BRACKET\n");*/                                                     return OPENING_TAG_BRACKET;       }
">"                    { /*printf("\t[lexer]: CLOSING_TAG_BRACKET\n");*/                                                     return CLOSING_TAG_BRACKET;       }
"="                    { /*printf("\t[lexer]: ASSIGNMENT\n");*/                                                              return ASSIGNMENT;                }
"/"                    { /*printf("\t[lexer]: SLASH\n");*/                                                                   return SLASH;                     }
{SINGLE_QUOTE_STRING}  { /*printf("\t[lexer]: SINGLE_QUOTE_STRING: %s\n", yytext);*/  yylval.string_t = GenNewStrW(yytext);  return SINGLE_QUOTE_STRING;       }
{DOUBLE_QUOTE_STRING}  { /*printf("\t[lexer]: DOUBLE_QUOTE_STRING: %s\n", yytext);*/  yylval.string_t = GenNewStrW(yytext);  return DOUBLE_QUOTE_STRING;       }
{HEXCHARS}             { /*printf("\t[lexer]: HEXCHARS\n");*/                                                                return HEXCHARS;                  }
[^<>/= ]*              { /*printf("\t[lexer]: TEXT\n");*/                             yylval.string_t = GenNewStr(yytext);   return TEXT;                      }
%%