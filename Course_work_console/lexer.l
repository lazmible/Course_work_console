%option yylineno
%option nounistd
%option noyywrap

DOUBLE_QUOTE_STRING     "\""[^<\"]*"\""
SINGLE_QUOTE_STRING     "\'"[^<\']*"\'"
HEXCHARS                "#"[a-f0-9A-F]+ 
DECCHARS                [0-9]+"%"?
    
%{
    #include <stdio.h>
    #include <io.h>
    #include "grammar.cpp.h"
    #pragma warning( disable:4996 )
    #pragma warning( disable:5033 )
%}

%%

[ \t\r\f\v\a\n]+ {};
"<!--".*?"-->"         { printf("HTML_COMMENT\n");             return HTML_COMMENT;              }
"<![".*?"]>"           { printf("HTML_CONDITIONAL_COMMENT\n"); return HTML_CONDITIONAL_COMMENT;  }
"<"                    { printf("OPENING_TAG_BRACKET\n");      return OPENING_TAG_BRACKET;       }
">"                    { printf("CLOSING_TAG_BRACKET\n");      return CLOSING_TAG_BRACKET;       }
"/"                    { printf("SLASH\n");                    return SLASH;                     }
"="                    { printf("ASSIGNMENT\n");               return ASSIGNMENT;                }
{SINGLE_QUOTE_STRING}  { printf("SINGLE_QUOTE_STRING\n");      return SINGLE_QUOTE_STRING;       }
{DOUBLE_QUOTE_STRING}  { printf("DOUBLE_QUOTE_STRING\n");      return DOUBLE_QUOTE_STRING;       }
{HEXCHARS}             { printf("HEXCHARS\n");                 return HEXCHARS;                  }
^<+                    { printf("TEXT\n");                     return TEXT;                      }
[a-zA-Z]+              { printf("TAG_NAME to TEXT\n");         return TEXT;                      }
%%