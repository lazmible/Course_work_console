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
%x style
%x xml
%x script_paired
%x style_paired
%x xml_paired

%%
<comment>
{
    "-->"	    { DBG_PRINT("\t[lexer]: Comment ended", "", yylineno); BEGIN(INITIAL);              }
    \n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);                          }
    <<EOF>>		{ std::cout << "\t[lexer]: Unclosed comment\n"; system("pause"); exit(0);           }
    .			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);                              }
}

<script>
{
    "/>"        { DBG_PRINT("\t[lexer]: Script single ended", "", yylineno); BEGIN(INITIAL);        }
    ">"	        { DBG_PRINT("\t[lexer]: Script paired start", "", yylineno); BEGIN(script_paired);  }
    \n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);                          }
    <<EOF>>		{ std::cout << "\t[lexer]: Unclosed comment\n"; system("pause"); exit(0);           }
    .			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);                              }
}

<style>
{
    "/>"        { DBG_PRINT("\t[lexer]: Style single ended", "", yylineno); BEGIN(INITIAL);         }
    ">"	        { DBG_PRINT("\t[lexer]: Style paired start", "", yylineno); BEGIN(style_paired);    }
    \n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);                          }
    <<EOF>>		{ std::cout << "\t[lexer]: Unclosed <style> tag\n"; system("pause"); exit(0);       }
    .			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);                              }
}

<xml>
{
    "/>"        { DBG_PRINT("\t[lexer]: Xml single ended", "", yylineno); BEGIN(INITIAL);           }
    ">"	        { DBG_PRINT("\t[lexer]: Xml paired start", "", yylineno); BEGIN(xml_paired);        }
    \n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);                          }
    <<EOF>>		{ std::cout << "\t[lexer]: Unclosed <xml> tag\n"; system("pause"); exit(0);         }
    .			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);                              }
}

<script_paired>
{
    "</script>"	{ DBG_PRINT("\t[lexer]: Script paired ended", "", yylineno); BEGIN(INITIAL);        }
    \n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);                          }
    <<EOF>>		{ std::cout << "\t[lexer]: Unclosed script tag\n"; system("pause"); exit(0);        }
    .			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);                              }
}

<style_paired>
{
    "</style>"	{ DBG_PRINT("\t[lexer]: Style paired ended", "", yylineno); BEGIN(INITIAL);         }
    \n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);                          }
    <<EOF>>		{ std::cout << "\t[lexer]: Unclosed <style> tag\n"; system("pause"); exit(0);       }
    .			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);                              }
}

<xml_paired>
{
    "</xml>"	{ DBG_PRINT("\t[lexer]: Xml paired ended", "", yylineno); BEGIN(INITIAL);           }
    \n			{ DBG_PRINT("\t[lexer]: Ignoring new line", "", yylineno);                          }
    <<EOF>>		{ std::cout << "\t[lexer]: Unclosed <xml> tag\n"; system("pause"); exit(0);         }
    .			{ DBG_PRINT("\t[lexer]: Ignoring smth", "", yylineno);                              }
}

[ \t\r\f\v\a\n]+                             { }
"!DOCTYPE html"                              { DBG_PRINT("\t[lexer]: DOCTYPE5", "", yylineno);                return Token(yytext, DOCTYPE5);            }
"!DOCTYPE HTML PUBLIC"                       { DBG_PRINT("\t[lexer]: DOCTYPE", "", yylineno);                 return Token(yytext, DOCTYPE);             }
"\"-//W3C//DTD HTML 4.01//EN"\"              { DBG_PRINT("\t[lexer]: DOCTYPEPART2", "", yylineno);            return Token(yytext, DOCTYPEPART2);        }
"\"http://www.w3.org/TR/html4/strict.dtd"\"  { DBG_PRINT("\t[lexer]: DOCTYPEPART3", "", yylineno);            return Token(yytext, DOCTYPEPART3);        }
"\"-//W3C//DTD HTML 4.01 Transitional//EN"\" { DBG_PRINT("\t[lexer]: DOCTYPEPART4", "", yylineno);            return Token(yytext, DOCTYPEPART4);        }
"\"http://www.w3.org/TR/html4/loose.dtd"\"   { DBG_PRINT("\t[lexer]: DOCTYPEPART5", "", yylineno);            return Token(yytext, DOCTYPEPART5);        }
"<script"                                    { DBG_PRINT("\t[lexer]: Script Started", "", yylineno);          BEGIN(script);                             }
"<style"                                     { DBG_PRINT("\t[lexer]: Style Started", "", yylineno);           BEGIN(style);                              }
"<xml"                                       { DBG_PRINT("\t[lexer]: Xml Started", "", yylineno);             BEGIN(xml);                                }
"<!--"                                       { DBG_PRINT("\t[lexer]: Comment Started", "", yylineno);         BEGIN(comment);                            }
"<[".*?"]"                                   { DBG_PRINT("\t[lexer]: Comment Started", "", yylineno);         BEGIN(comment);                            }
"<"                                          { DBG_PRINT("\t[lexer]: OPENING_TAG_BRACKET", "", yylineno);     return Token(yytext, OPENING_TAG_BRACKET); }
">"                                          { DBG_PRINT("\t[lexer]: CLOSING_TAG_BRACKET", "", yylineno);     return Token(yytext, CLOSING_TAG_BRACKET); }
"="                                          { DBG_PRINT("\t[lexer]: ASSIGNMENT", "", yylineno);              return Token(yytext, ASSIGNMENT);          }
"/"                                          { DBG_PRINT("\t[lexer]: SLASH", "", yylineno);                   return Token(yytext, SLASH);               }
\'(?:[^\\']+|\\.)*\'                         { DBG_PRINT("\t[lexer]: SINGLE_QUOTE_STRING", yytext, yylineno); return Token(yytext, SINGLE_QUOTE_STRING); }
\"(?:[^\\"]+|\\.)*\"                         { DBG_PRINT("\t[lexer]: DOUBLE_QUOTE_STRING", yytext, yylineno); return Token(yytext, DOUBLE_QUOTE_STRING); }
[^<>/= ]*                                    { DBG_PRINT("\t[lexer]: TEXT", yytext, yylineno);                return Token(yytext, TEXT);                }
%%