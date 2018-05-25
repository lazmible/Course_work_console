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

htmlDocument doc("l", ATTR_DATABASE, TAG_DB);

int main()
{
	std::map<std::string, std::vector<std::string>> kek = TAG_DB;

	yyin = fopen("input.html", "r");
	if (!yyin) { std::cout << "Error opening file." << std::endl; }
	yyparse();
	
	//std::map<std::string, std::string> test_db(ATTR_DATABASE);
	
	//for (auto & [key, value] : test_db)
	//{
	//	try
	//	{
	//		std::regex re(value);
	//		std::smatch kek;
	//		//std::cout << std::regex_match(test, kek, re) << std::endl;
	//	}
	//	catch (std::regex_error)
	//	{
	//		std::cout << "regex error on key: " << key << std::endl;
	//	}
	//}
	
	system("pause");
	return 0;
}
