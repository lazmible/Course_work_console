#include "grammar.cpp.h"
#include "lexer.h"

#include "Attribute.h"
#include "Tag.h"
#include "Document.h"

#include "html_attr_val_db.h"
#include "html_tag_db.h"

#pragma warning( disable:4996 ) // disable unsafe fopen error
#pragma warning( disable:5033 ) // disabe register warning from bison.simple

extern int yyparse();
int yylex();

extern int yylineno;

int yyerror(const char * err)
{
	std::cout << std::endl << err << " on line: " << yylineno <<std::endl;
	return -1;
}

extern FILE * yyin;
htmlDocument doc("l", ATTR_DATABASE_HTML5, TEST);
extern std::vector<std::string> strings;


int main()
{
	strings.reserve(10000000);
	yyin = fopen("input.txt", "r");
	yyparse();
	//std::string test("2м772сл12чб2ю2нг4жв';l32;'4l434of  32c23 4cu420 cu0qwpufasjr");
	//std::regex re(".+");
	//std::smatch kek;
	//std::cout << std::regex_match(test, kek, re) << std::endl;

	//doc.AddOpeningTag("html");
	//doc.AddOpeningTag("a");
	//doc.AddAttributeToLastTag("accesskey", "1");
	//doc.AddClosingTag("html");


	//doc.CheckEndState();
	system("pause");
	return 0;
}


// Ошибки: 
// не распознает пустой контент (<kek> </kek>) --> Наверное из-за того, что он игнорирует пробелы
// 