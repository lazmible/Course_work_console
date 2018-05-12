
%{
#include "errno.h"
#include "gram.tab.h"

extern void print_error(const char *msg, ...);

char *file;
int line;

void file_input(const char *file) {
	file = strdup(file);
	line = 1;
	yyin = fopen(file, "rb");
	if (!yyin) print_error("Can not open %s (%s)", file, strerror(errno));
}

int line_count() {
	return line;
}

%}

%option outfile="lex.yy.c"
%option noyywrap
%x long_comment
%x atom_quoted

%%

[ \t\r\f\v\a]+			/* Ignore */
%[^\n]*				/* Ignore */
\n				line++;
"/*"				BEGIN(long_comment);
"'"				BEGIN(atom_quoted);
or				return OR;
and				return AND;
is				return IS;
mod				return MOD;
rem 				return REM;

[0-9]+("."?[0-9]+)?		return NUMBER;
[_A-Z][_A-Za-z0-9]*	 	return VAR;
[a-z][_A-Za-z0-9]*		return ATOM;
\"[^\n"]*\"			return STRING;

":-"				return IMPLICAT;
"-->"				return IMPLICAT;
"+"				return PLUS;
"-"				return MINUS;
"*"				return MUL;
"/"				return DIV;
">"				return LARGE;
"<"				return SMALL;
"=<"				return SMALLEQU;
">="				return LARGEEQU;
"=="				return EQU;
"\\=="				return NONEQU;
"="				return UNIFI;
">>"				return RSHIFT;
"<<"				return LSHIFT;
"**"				return MULMUL;
"\\+"				return NOT;
"->"				return IFTHEN;
";"				return SEM;
"=:="				return SYNTEQU;
"//"				return IDIV;
"?-"				return IMPLICAT;

[(){}\[\]|!;,.]			return yytext[0]; 
.				print_error("Unknown symbol, at line:%d", line_count());

<long_comment>
{
	"*/"			BEGIN(0);	
	\n			line++; 
	.			{/*ignore*/}	
	<<EOF>>			print_error("Unclosed comment, at line:%d", line_count());
}

<atom_quoted>
{
	"'"			BEGIN(0); return ATOM;	
	\n			print_error("Incorrect atom name, \"'\" is expected, at line:%d", line_count());
	<<EOF>>			print_error("Incorrect atom name, \"'\" is expected, at line:%d", line_count());
	.			{ /*ignore*/ }
}

%%
//RDIV
//SMALL
//SOFTCUT
//STRUCTEQU
//AFTER
//AFTEREQU
//BEFORE
//BEFOREEQU

