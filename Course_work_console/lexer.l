%option yylineno
%option nounistd
%option noyywrap
    
%{
    #include <stdio.h>
    #include <io.h>
    #include <string>
    #include "utils.h"
    #include "grammar.cpp.h"
    #pragma warning( disable:4996 )
    #pragma warning( disable:5033 )
%}

%x comment
%x script

%%

<comment>
{
"-->"		{  BEGIN(INITIAL);                                             }
\n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);     }
<<EOF>>		{ DBG_PRINT("\t[lexer]: Unclosed comment line", "", yylineno); }
.			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);         }
}

<script>
{
"</script>"	{  BEGIN(INITIAL);                                           }
\n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);   }
<<EOF>>		{ DBG_PRINT("\t[lexer]: Unclosed script tag", "", yylineno); }
.			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);       }
}


[ \t\r\f\v\a\n]+                    { }
"<!--"                              { DBG_PRINT("\t[lexer]: Comment Started", "", yylineno);          BEGIN(comment);  }
"<script".*?">"                     { DBG_PRINT("\t[lexer]: Script Started", "", yylineno);          BEGIN(script);  }
"<"                                 { DBG_PRINT("\t[lexer]: OPENING_TAG_BRACKET", "", yylineno);                                             return OPENING_TAG_BRACKET;       }
">"                                 { DBG_PRINT("\t[lexer]: CLOSING_TAG_BRACKET", "", yylineno);                                             return CLOSING_TAG_BRACKET;       }
"="                                 { DBG_PRINT("\t[lexer]: ASSIGNMENT", "", yylineno);                                                      return ASSIGNMENT;                }
"/"                                 { DBG_PRINT("\t[lexer]: SLASH", "", yylineno);                                                           return SLASH;                     }
\'(?:[^\\']+|\\.)*\'                { DBG_PRINT("\t[lexer]: SINGLE_QUOTE_STRING", yytext, yylineno);  yylval.string_t = GenNewStrW(yytext);  return SINGLE_QUOTE_STRING;       }
\"(?:[^\\"]+|\\.)*\"                { DBG_PRINT("\t[lexer]: DOUBLE_QUOTE_STRING", yytext, yylineno);  yylval.string_t = GenNewStrW(yytext);  return DOUBLE_QUOTE_STRING;       }
[^<>/= ]*                           { DBG_PRINT("\t[lexer]: TEXT", yytext, yylineno);                 yylval.string_t = GenNewStr(yytext);   return TEXT;                      }
%%