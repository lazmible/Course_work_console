#include "Attribute.h"

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
	if (!this->check_value()) 
	{
		std::cout << "[AttributeError] Unexpected Attribute value: <" << this->value << "> for attribute <" << this->name << ">" << std::endl; 
	}
}