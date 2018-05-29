%option yylineno
%option nounistd
%option noyywrap
    
%{
    #include <stdio.h>
    #include <io.h>
    #include <string>
    #include "utils.h"
    #include "debug.h"
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
    "-->"	    { DEBUG_MESSAGE("COMMENT ENDED", DEBUG_CODE_LEXER, yylineno);  BEGIN(INITIAL);                  }
    \n			{ DEBUG_MESSAGE("INGNORE NEW LINE", DEBUG_CODE_LEXER, yylineno);                                }
    <<EOF>>		{ ERROR_MESSAGE("Unclosed comment", ERROR_CODE_DOCUMENT, yylineno);  system("pause"); exit(0);  }
    .			{ DEBUG_MESSAGE("INGORING SOMETHING", DEBUG_CODE_LEXER, yylineno);                              }
}

<script>
{
    "/>"        { DEBUG_MESSAGE("SCRIPT SINGLE ENDED", DEBUG_CODE_LEXER, yylineno);  BEGIN(INITIAL);                 }
    ">"	        { DEBUG_MESSAGE("SCRIPT PAIRED START", DEBUG_CODE_LEXER, yylineno); BEGIN(script_paired);            }
    \n			{ DEBUG_MESSAGE("INGNORE NEW LINE", DEBUG_CODE_LEXER, yylineno);                                     }
    <<EOF>>		{ ERROR_MESSAGE("Unclosed <script> tag", ERROR_CODE_DOCUMENT, yylineno);  system("pause"); exit(0);  }
    .			{ DEBUG_MESSAGE("INGORING SOMETHING", DEBUG_CODE_LEXER, yylineno);                                   }
}

<style>
{
    "/>"        { DEBUG_MESSAGE("STYLE SINGLE ENDED", DEBUG_CODE_LEXER, yylineno); BEGIN(INITIAL);                  }
    ">"	        { DEBUG_MESSAGE("SCRIPT PAIRED START", DEBUG_CODE_LEXER, yylineno); BEGIN(style_paired);            }
    \n			{ DEBUG_MESSAGE("INGNORE NEW LINE", DEBUG_CODE_LEXER, yylineno);                                    }
    <<EOF>>		{ ERROR_MESSAGE("Unclosed <style> tag", ERROR_CODE_DOCUMENT, yylineno);  system("pause"); exit(0);  }
    .			{ DEBUG_MESSAGE("INGORING SOMETHING", DEBUG_CODE_LEXER, yylineno);                                  }
}

<xml>
{
    "/>"        { DEBUG_MESSAGE("XML SINGLE ENDED", DEBUG_CODE_LEXER, yylineno); BEGIN(INITIAL);                   }
    ">"	        { DEBUG_MESSAGE("XML PAIRED START", DEBUG_CODE_LEXER, yylineno); BEGIN(xml_paired);                }
    \n			{ DEBUG_MESSAGE("INGNORE NEW LINE", DEBUG_CODE_LEXER, yylineno);                                   }
    <<EOF>>		{ ERROR_MESSAGE("Unclosed <xml> tag", ERROR_CODE_DOCUMENT, yylineno);  system("pause"); exit(0);   }
    .			{ DEBUG_MESSAGE("INGORING SOMETHING", DEBUG_CODE_LEXER, yylineno);                                 }
}

<script_paired>
{
    "</script>"	{ DEBUG_MESSAGE("SCRIPT PAIRED ENDED", DEBUG_CODE_LEXER, yylineno); BEGIN(INITIAL);                  }
    \n			{ DEBUG_MESSAGE("INGNORE NEW LINE", DEBUG_CODE_LEXER, yylineno);                                     }
    <<EOF>>		{ ERROR_MESSAGE("Unclosed <script> tag", ERROR_CODE_DOCUMENT, yylineno);  system("pause"); exit(0);  }
    .			{ DEBUG_MESSAGE("INGORING SOMETHING", DEBUG_CODE_LEXER, yylineno);                                   }
}

<style_paired>
{
    "</style>"	{ DEBUG_MESSAGE("STYLE PAIRED ENDED", DEBUG_CODE_LEXER, yylineno); BEGIN(INITIAL);                  }
    \n			{ DEBUG_MESSAGE("INGNORE NEW LINE", DEBUG_CODE_LEXER, yylineno);                                    }
    <<EOF>>		{ ERROR_MESSAGE("Unclosed <style> tag", ERROR_CODE_DOCUMENT, yylineno);  system("pause"); exit(0);  }
    .			{ DEBUG_MESSAGE("INGORING SOMETHING", DEBUG_CODE_LEXER, yylineno);                                  }
}

<xml_paired>
{
    "</xml>"	{ DEBUG_MESSAGE("XML PAIRED ENDED", DEBUG_CODE_LEXER, yylineno); BEGIN(INITIAL);                      }
    \n			{ DEBUG_MESSAGE("INGNORE NEW LINE", DEBUG_CODE_LEXER, yylineno);                                      }
    <<EOF>>		{ ERROR_MESSAGE("Unclosed <xml> tag", ERROR_CODE_DOCUMENT, yylineno);  system("pause"); exit(0);      }
    .			{ DEBUG_MESSAGE("INGORING SOMETHING", DEBUG_CODE_LEXER, yylineno);                                    }
}

[ \t\r\f\v\a\n]+                                              { }
"\!DOCTYPE html PUBLIC"                                       {  return Token(yytext, DOCTYPE_XHTML);             }
"\!DOCTYPE HTML PUBLIC"                                       {  return Token(yytext, DOCTYPE);                   }
"\!DOCTYPE html"                                              {  return Token(yytext, DOCTYPE_HTML_5);            }
"\"-//W3C//DTD HTML 4.01//EN"\"                               {  return Token(yytext, DOCTYPE_STRICT_1);          }
"\"http://www.w3.org/TR/html4/strict.dtd"\"                   {  return Token(yytext, DOCTYPE_STRICT_2);          }
"\"-//W3C//DTD HTML 4.01 Transitional//EN"\"                  {  return Token(yytext, DOCTYPE_TRANS_1);           }
"\"http://www.w3.org/TR/html4/loose.dtd"\"                    {  return Token(yytext, DOCTYPE_TRANS_2);           }
"\"-//W3C//DTD HTML 4.01 Frameset//EN"\"                      {  return Token(yytext, DOCTYPE_FRAME_1);           }
"\"http://www.w3.org/TR/html4/frameset.dtd"\"                 {  return Token(yytext, DOCTYPE_FRAME_2);           }
"\"-//W3C//DTD XHTML 1.0 Strict//EN"\"                        {  return Token(yytext, DOCTYPE_XHTML_STRICT_1);    }
"\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"\"       {  return Token(yytext, DOCTYPE_XHTML_STRICT_2);    }
"\"-//W3C//DTD XHTML 1.0 Transitional//EN"\"                  {  return Token(yytext, DOCTYPE_XHTML_TRANS_1);     }
"\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"\" {  return Token(yytext, DOCTYPE_XHTML_TRANS_2);     }
"\"-//W3C//DTD XHTML 1.0 Frameset//EN"\"                      {  return Token(yytext, DOCTYPE_XHTML_FRAME_1);     }
"\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd"\"     {  return Token(yytext, DOCTYPE_XHTML_FRAME_2);     }
"\"-//W3C//DTD XHTML 1.1//EN"\"                               {  return Token(yytext, DOCTYPE_XHTML_1_1_1);       }
"\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd"\"            {  return Token(yytext, DOCTYPE_XHTML_1_1_2);       }
"<script"                                                     {  Token(yytext, SCRIPT_STARTED);   BEGIN(script);  }
"<style"                                                      {  Token(yytext, STYLE_STARTED);    BEGIN(style);   }
"<xml"                                                        {  Token(yytext, XML_STARTED);      BEGIN(xml);     }
"<!--["                                                       {  Token(yytext, COMMENT_STARTED);  BEGIN(comment); }
"<!--"                                                        {  Token(yytext, COMMENT_STARTED);  BEGIN(comment); }
"<"                                                           {  return Token(yytext, OPENING_TAG_BRACKET);       }
">"                                                           {  return Token(yytext, CLOSING_TAG_BRACKET);       }
"="                                                           {  return Token(yytext, ASSIGNMENT);                }
"/"                                                           {  return Token(yytext, SLASH);                     }
\'(?:[^\\']+|\\.)*\'                                          {  return Token(yytext, SINGLE_QUOTE_STRING);       }
\"(?:[^\\"]+|\\.)*\"                                          {  return Token(yytext, DOUBLE_QUOTE_STRING);       }
[^<>/= \n]*                                                   {  return Token(yytext, TEXT);                      }
%%