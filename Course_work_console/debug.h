#pragma once
#include <string>
#include <iomanip>
#include <iostream>

/*#define DEBUG_LEVEL_PARSER   
#define DEBUG_LEVEL_LEXER  
#define DEBUG_LEVEL_ENGINE  */ 
							     
#define DEBUG_CODE_PARSER        1
#define DEBUG_CODE_LEXER         2
#define DEBUG_CODE_ENGINE        3
							     
#define ERROR_CODE_DOCUMENT      1
#define ERROR_CODE_TAG           2
#define ERROR_CODE_ATTRIBUTE     3
#define ERROR_CODE_PARSER        4

#define WARNING_CODE_DOCUMENT    1
#define WARNING_CODE_TAG         2
#define WARNING_CODE_ATTRIBUTE   3

#define ALL_WIDTH 14

#define MESSAGE_WIDTH            ALL_WIDTH
#define ERROR_WIDTH              ALL_WIDTH
#define WARNING_WIDTH            ALL_WIDTH
#define LINE_WIDTH               (0)

inline void DEBUG_MESSAGE(std::string msg, int debug_code, int line, int column)
{
	switch (debug_code) 
	{
	    case (DEBUG_CODE_PARSER):  
		{
            #ifdef DEBUG_LEVEL_PARSER
			std::cout << "[" << std::setw(MESSAGE_WIDTH) << "Parser" << std::setw(LINE_WIDTH) << " line:" <<  line << " col:" << column << "] : " << msg << std::endl;
            #endif
			break; 
		}
	    case (DEBUG_CODE_LEXER):   
		{
            #ifdef DEBUG_LEVEL_LEXER
			std::cout << "[" << std::setw(MESSAGE_WIDTH) << "Lexer" << std::setw(LINE_WIDTH) << " line:" << line << " col:" << column << "] : " << msg << std::endl;
            #endif
			break; 
		}
	    case (DEBUG_CODE_ENGINE):  
		{
            #ifdef DEBUG_LEVEL_ENGINE
			std::cout << "[" << std::setw(MESSAGE_WIDTH) << "Engine" << std::setw(LINE_WIDTH) << " line:" << line << " col:" << column << "] : " << msg << std::endl;
            #endif
			break; 
		}
		default:
		{
			return;
		}
	}
}

inline void ERROR_MESSAGE(std::string msg, int error_code, int line, int column)
{
	switch (error_code)
	{
	    case (ERROR_CODE_DOCUMENT):
	    {
			std::cout << "[" << std::setw(ERROR_WIDTH) << "DocumentError" << std::setw(LINE_WIDTH) << " line:" << line << " col:" << column << "] : " << msg << std::endl;
			break;
	    }
	    case (ERROR_CODE_TAG):
	    {
			std::cout << "[" << std::setw(ERROR_WIDTH) << "TagError" << std::setw(LINE_WIDTH) << " line:" << line << " col:" << column << "] : " << msg << std::endl;
			break;
	    }
	    case (ERROR_CODE_ATTRIBUTE):
	    {
			std::cout << "[" << std::setw(ERROR_WIDTH) << "AttributeError" << std::setw(LINE_WIDTH) << " line:" << line << " col:" << column << "] : " << msg << std::endl;
			break;
	    }
		case (ERROR_CODE_PARSER):
		{
			std::cout << "[" << std::setw(ERROR_WIDTH) << "ParserError" << std::setw(LINE_WIDTH) << " line:" << line << " col:" << column << "] : " << msg << std::endl;
			break;
		}
	    default:
	    {
	    	return;
	    }
	}
}

inline void WARNING_MESSAGE(std::string msg, int warning_code, int line, int column)
{
	switch (warning_code)
	{
	    case (WARNING_CODE_DOCUMENT):
	    {
	    	std::cout << "[" << std::setw(WARNING_WIDTH) << "DocumentWarning" << std::setw(LINE_WIDTH) << " line:" <<  line << " col:" << column << "] : " << msg << std::endl;
			break;
	    }
	    case (WARNING_CODE_TAG):
	    {
	    	std::cout << "[" << std::setw(WARNING_WIDTH) << "TagWarning" << std::setw(LINE_WIDTH) << " line:" << line << " col:" << column << "] : " << msg << std::endl;
			break;
	    }
	    case (WARNING_CODE_ATTRIBUTE):
	    {
	    	std::cout << "[" << std::setw(WARNING_WIDTH) << "AttributeWarning" << std::setw(LINE_WIDTH) << " line:" << line << " col:" << column << "] : " << msg << std::endl;
			break;
	    }
	    default:
	    {
	    	return;
	    }
	}
}