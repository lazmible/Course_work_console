#include "Attribute.h"
#include "debug.h"

static bool is_user_defined_attribute(std::string name)
{
	if (name.length() < 6)   { return false; }
	std::string templ = name.substr(0, 5);
	if (templ == "data-")    { return true;  }
	else                     { return false; }
}

bool htmlAttribute::check_value()
{
	auto result = values_database.find(this->name);
	if (result != values_database.end())
	{
		std::regex name_template(result->second);
		std::smatch match;

		return std::regex_match(this->value, match, name_template);
	}
	else { return false; }
}

void htmlAttribute::CheckState()
{
	if (!this->check_value() && !is_user_defined_attribute(this->name)) 
	{
		ERROR_MESSAGE("Unexpected Attribute value <" + this->value + "> for attribute <" + this->name + ">", ERROR_CODE_ATTRIBUTE, this->line, this->column);
	}
}