#include "Attribute.h"

inline const std::string err_attr_name(std::string name)
{
	return ("Error invalid attribute name <" + name + ">");
}

inline const std::string err_attr_val(std::string val, std::string name)
{
	return ("Error invalid attribute value <" + val + "> for attribute <" + name + ">");
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

std::vector<error> htmlAttribute::CheckState()
{
	std::vector<error> result;

	//if (!this->check_name())  { result.push_back(error(0, 0, 0, err_attr_name(this->name)));             }
	//if (!this->check_value()) { result.push_back(error(0, 0, 0, err_attr_val(this->value, this->name))); }

	if (!this->check_value()) { std::cout << "[AttributeError] Invalid Attribute value: <" << this->value << "> for attribute <" << this->name << ">" << std::endl; }

	return result;
}