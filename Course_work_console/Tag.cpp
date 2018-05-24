#include "Tag.h"
#include "precedence.h"

static bool is_user_defined_attribute(std::string name)
{
	if (name.length() < 6) { return false; }
	std::string templ = name.substr(0, 5);
	if (templ == "data-")  { return true;  }
	else                   { return false; }
}

void htmlTag::init()
{
	if (tag_database.find(this->name) != tag_database.end())
	{
		valid_attribute_names_list = tag_database.find(this->name)->second;
	}
	else
	{
		std::cout << "[TagError line: " << this->line << "] Unexpexted Tag name: <" << this->name << ">" << std::endl;
	}
}

bool htmlTag::check_name()
{
	return (tag_database.find(this->name) != tag_database.end());
}

bool htmlTag::check_attr_name(std::string name)
{
	if (tag_database.find(this->name) != tag_database.end())
	{
		auto entry = tag_database.find(this->name);

		return (std::find(entry->second.begin(), entry->second.end(), name) != entry->second.end());
	}
}

void htmlTag::AddAttribute(std::string name, std::string val)
{
	if (check_attr_name(name) || is_user_defined_attribute(name))
	{
		htmlAttribute attribute(name, this->attribute_database, "", val, this->line);
		attribute.CheckState();
	}
	else
	{
		std::cout << "[TagError line: " << this->line << " ] Unexpected Attribute name <" << name << ">" << " for tag <" << this->name << ">" << std::endl;
	}
}