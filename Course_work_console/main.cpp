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

extern FILE *                                  yyin;
extern std::vector<std::string>                strings;
extern std::vector<std::vector<htmlAttribute>> attributes_lists;
extern std::vector<htmlAttribute>              attributes;

htmlDocument doc("l", ATTR_DATABASE_HTML5, TAG_DATABASE);

int main()
{
	
	std::map<std::string, std::vector<std::string>> kek = TAG_DATABASE;
	strings.reserve(1000000);
	attributes_lists.reserve(1000000);
	attributes.reserve(1000000);
	yyin = fopen("input.html", "r");
	if (!yyin) { std::cout << "Error opening file." << std::endl; }
	yyparse();
	
	/*
	std::map<std::string, std::string> test_db(ATTR_DATABASE_HTML5);
	
	for (auto [key, value] : test_db)
	{
		try
		{
			std::regex re(value);
			std::smatch kek;
			//std::cout << std::regex_match(test, kek, re) << std::endl;
		}
		catch (std::regex_error)
		{
			std::cout << "regex error on key: " << key << std::endl;
		}
	}
	*/
	system("pause");
	return 0;
}


// Ошибки: 
// не распознает пустой контент (<kek> </kek>) --> Наверное из-за того, что он игнорирует пробелы
// 