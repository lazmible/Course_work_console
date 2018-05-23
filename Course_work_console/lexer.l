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


[ \t\r\f\v\a\n]+                             { }
"!DOCTYPE html"                              { DBG_PRINT("\t[lexer]: DOCTYPE5", "", yylineno);                return Token(yytext, DOCTYPE5);            }
"!DOCTYPE HTML PUBLIC"                       { DBG_PRINT("\t[lexer]: DOCTYPE", "", yylineno);                 return Token(yytext, DOCTYPE);             }
"\"-//W3C//DTD HTML 4.01//EN"\"              { DBG_PRINT("\t[lexer]: DOCTYPEPART2", "", yylineno);            return Token(yytext, DOCTYPEPART2);        }
"\"http://www.w3.org/TR/html4/strict.dtd"\"  { DBG_PRINT("\t[lexer]: DOCTYPEPART3", "", yylineno);            return Token(yytext, DOCTYPEPART3);        }
"\"-//W3C//DTD HTML 4.01 Transitional//EN"\" { DBG_PRINT("\t[lexer]: DOCTYPEPART4", "", yylineno);            return Token(yytext, DOCTYPEPART4);        }
"\"http://www.w3.org/TR/html4/loose.dtd"\"   { DBG_PRINT("\t[lexer]: DOCTYPEPART5", "", yylineno);            return Token(yytext, DOCTYPEPART5);        }
"<!--"                                       { DBG_PRINT("\t[lexer]: Comment Started", "", yylineno);         BEGIN(comment);                            }
"<script".*?">"                              { DBG_PRINT("\t[lexer]: Script Started", "", yylineno);          BEGIN(script);                             }
"<"                                          { DBG_PRINT("\t[lexer]: OPENING_TAG_BRACKET", "", yylineno);     return Token(yytext, OPENING_TAG_BRACKET); }
">"                                          { DBG_PRINT("\t[lexer]: CLOSING_TAG_BRACKET", "", yylineno);     return Token(yytext, CLOSING_TAG_BRACKET); }
"="                                          { DBG_PRINT("\t[lexer]: ASSIGNMENT", "", yylineno);              return Token(yytext, ASSIGNMENT);          }
"/"                                          { DBG_PRINT("\t[lexer]: SLASH", "", yylineno);                   return Token(yytext, SLASH);               }
\'(?:[^\\']+|\\.)*\'                         { DBG_PRINT("\t[lexer]: SINGLE_QUOTE_STRING", yytext, yylineno); return Token(yytext, SINGLE_QUOTE_STRING); }
\"(?:[^\\"]+|\\.)*\"                         { DBG_PRINT("\t[lexer]: DOUBLE_QUOTE_STRING", yytext, yylineno); return Token(yytext, DOUBLE_QUOTE_STRING); }
[^<>/= ]*                                    { DBG_PRINT("\t[lexer]: TEXT", yytext, yylineno);                return Token(yytext, TEXT);                }
%%