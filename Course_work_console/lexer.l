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

%%

[ \t\r\f\v\a\n]+                    { }
"<!--"                              { DBG_PRINT("\t[lexer]: Comment Started", "", yylineno);          PushIgnore();                          return COMMENT_START;  }
"-->"                               { DBG_PRINT("\t[lexer]: Comment Ended", "", yylineno);            PopIgnore();                           return COMMENT_END;    }
"<"                                 { DBG_PRINT("\t[lexer]: OPENING_TAG_BRACKET", "", yylineno);                                             return OPENING_TAG_BRACKET;       }
">"                                 { DBG_PRINT("\t[lexer]: CLOSING_TAG_BRACKET", "", yylineno);                                             return CLOSING_TAG_BRACKET;       }
"="                                 { DBG_PRINT("\t[lexer]: ASSIGNMENT", "", yylineno);                                                      return IgnoreModeOn() ? IGNORE : ASSIGNMENT;                }
"/"                                 { DBG_PRINT("\t[lexer]: SLASH", "", yylineno);                                                           return SLASH;                     }
\'(?:[^\\']+|\\.)*\'                { DBG_PRINT("\t[lexer]: SINGLE_QUOTE_STRING", yytext, yylineno);  yylval.string_t = GenNewStrW(yytext);  return IgnoreModeOn() ? IGNORE : SINGLE_QUOTE_STRING;       }
\"(?:[^\\"]+|\\.)*\"                { DBG_PRINT("\t[lexer]: DOUBLE_QUOTE_STRING", yytext, yylineno);  yylval.string_t = GenNewStrW(yytext);  return IgnoreModeOn() ? IGNORE : DOUBLE_QUOTE_STRING;       }
[^<>/= ]*                           { DBG_PRINT("\t[lexer]: TEXT", yytext, yylineno);                 yylval.string_t = GenNewStr(yytext);   return TEXT;                      }
%%