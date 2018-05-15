#include "Tag.h"

inline std::string attr_tag_err(std::string tag_name, std::string attr_name)
{
	return ("Error, invalid attribute <" + attr_name + "> pushed to tag <" + tag_name + ">");
}

htmlTag::htmlTag(std::string nm, std::stack<std::string> st, const db_attr_type & attr_db, const db_tag_type & tag_db)
	: name(nm), state_before(st), attribute_database(attr_db), tag_database(tag_db)
{
	if (tag_database.find(this->name) != tag_database.end())
	{
		valid_attribute_names_list = tag_database.find(this->name)->second;
	}
	else
	{
	//	std::cout << "Tag: " << this->name << " does not exists in database" << std::endl;
	}
}

std::vector<error> htmlTag::check_attributes() 
{
	std::vector<error> result;
	for (auto attr : attribute_list)
	{
		bool attr_found = false;
		for (auto valid_attr : valid_attribute_names_list)
		{
			if (valid_attr == attr.GetName()) { break; attr_found = true; }
		} 
		if (!attr_found) { result.push_back(error(0, 0, 0, attr_tag_err(this->name, attr.GetName()))); }
	}
	return result;
}

std::vector<error> htmlTag::check_precursory()
{
	std::stack<std::string> valid_state;
	for (auto it : precursory_tags) { valid_state.push(it); }

	return {};
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
	if (check_attr_name(name))
	{
		htmlAttribute attribute(name, this->attribute_database, "", val);
		attribute.CheckState();
	}
	else
	{
		std::cout << "[AttributeError] Invalid Attribute name: <" << name << ">" << " for tag <" << this->name << ">" << std::endl;
	}
}