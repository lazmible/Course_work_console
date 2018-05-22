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

    extern int yyerror(const char * err);
%}

%x comment
%x script

%%

<comment>
{
"-->"		{  BEGIN(INITIAL);                                                                        }
\n			{ std::cout << "\t[lexer]: Ignoring new line" << "| on line: " << yylineno << std::endl;  }
<<EOF>>		{ std::cout << "\t[lexer]: Unclosed comment line\n"; system("pause"); exit(0);            }
.			{ std::cout << "\t[lexer]: Ignoring smth" << "| on line: " << yylineno << std::endl;      }
}

<script>
{
"</script>"	{  BEGIN(INITIAL);                                                                        }
\n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);                                }
<<EOF>>		{  std::cout << "\t[lexer]: Unclosed script tag\n"; system("pause"); exit(0);             }
.			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);                                    }
}


[ \t\r\f\v\a\n]+                    { }
"<!--"                              { DBG_PRINT("\t[lexer]: Comment Started", "", yylineno);         BEGIN(comment);                                     }
"<script".*?">"                     { DBG_PRINT("\t[lexer]: Script Started", "", yylineno);          BEGIN(script);                                      }
"<"                                 { DBG_PRINT("\t[lexer]: OPENING_TAG_BRACKET", "", yylineno);     return Token(yylval.string_t, OPENING_TAG_BRACKET); }
">"                                 { DBG_PRINT("\t[lexer]: CLOSING_TAG_BRACKET", "", yylineno);     return Token(yylval.string_t, CLOSING_TAG_BRACKET); }
"="                                 { DBG_PRINT("\t[lexer]: ASSIGNMENT", "", yylineno);              return Token(yylval.string_t, ASSIGNMENT);          }
"/"                                 { DBG_PRINT("\t[lexer]: SLASH", "", yylineno);                   return Token(yylval.string_t, SLASH);               }
\'(?:[^\\']+|\\.)*\'                { DBG_PRINT("\t[lexer]: SINGLE_QUOTE_STRING", yytext, yylineno); return Token(yylval.string_t, SINGLE_QUOTE_STRING); }
\"(?:[^\\"]+|\\.)*\"                { DBG_PRINT("\t[lexer]: DOUBLE_QUOTE_STRING", yytext, yylineno); return Token(yylval.string_t, DOUBLE_QUOTE_STRING); }
[^<>/= ]*                           { DBG_PRINT("\t[lexer]: TEXT", yytext, yylineno);                return Token(yylval.string_t, TEXT);                }
%%