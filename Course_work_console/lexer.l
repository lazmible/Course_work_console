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

[ \t\r\f\v\a\n]+       {                                                                                                                                         }
"<!--"(.|\n)*?"-->"    { DBG_PRINT("\t[lexer]: HTML_COMMENT", "", yylineno)                                                    return HTML_COMMENT;              }
"<!["(.|\n)*?"]>"      { DBG_PRINT("\t[lexer]: HTML_CONDITIONAL_COMMENT", "", yylineno)                                        return HTML_CONDITIONAL_COMMENT;  }
"<"                    { DBG_PRINT("\t[lexer]: OPENING_TAG_BRACKET", "", yylineno)                                             return OPENING_TAG_BRACKET;       }
">"                    { DBG_PRINT("\t[lexer]: CLOSING_TAG_BRACKET", "", yylineno)                                             return CLOSING_TAG_BRACKET;       }
"="                    { DBG_PRINT("\t[lexer]: ASSIGNMENT", "", yylineno)                                                      return ASSIGNMENT;                }
"/"                    { DBG_PRINT("\t[lexer]: SLASH", "", yylineno)                                                           return SLASH;                     }
{SINGLE_QUOTE_STRING}  { DBG_PRINT("\t[lexer]: SINGLE_QUOTE_STRING", yytext, yylineno)  yylval.string_t = GenNewStrW(yytext);  return SINGLE_QUOTE_STRING;       }
{DOUBLE_QUOTE_STRING}  { DBG_PRINT("\t[lexer]: DOUBLE_QUOTE_STRING", yytext, yylineno)  yylval.string_t = GenNewStrW(yytext);  return DOUBLE_QUOTE_STRING;       }
[^<>/= ]*              { DBG_PRINT("\t[lexer]: TEXT", yytext, yylineno)                 yylval.string_t = GenNewStr(yytext);   return TEXT;                      }
%%