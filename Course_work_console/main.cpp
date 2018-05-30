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
	std::string error_message(err);

	std::cout << "***************************************************************" << std::endl;
	std::cout << "Parser stopped with fatal syntax error." << std::endl;
	std::cout << "line: " << yylineno << std::endl;
	std::cout << "Reason: " << (error_message == "parse error" ? "Unnamed syntax error" : error_message) << std::endl;
	std::cout << "***************************************************************" << std::endl;
	return -1;
}

extern FILE * yyin;

htmlDocument doc("l", ATTR_DATABASE, TAG_DB);


int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		std::cout << "Invalid arguments. Usage:\n" << argv[0] << "<filename>" << std::endl;
	}

	yyin = fopen(argv[1], "r");
	if (!yyin) { std::cout << "Error opening file." << std::endl; }
	yyparse();
	
	doc.end();
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
