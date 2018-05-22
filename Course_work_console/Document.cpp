#include "Document.h"
#include "utils.h"

#include <list>

extern int                                   yylineno;
extern std::list<std::string>                strings;
extern std::list<std::list<htmlAttribute>>   attributes_lists;
extern std::list<htmlAttribute>              attributes;

void htmlDocument::AddOpeningTag(std::string tag_name)
{	
	DBG("[Engine] Processing opening tag", tag_name);
	if (!tag_name_is_correct(tag_name)) { std::cout << "[DocumentError] Tag with name <" << tag_name << "> " << "does not exist" << std::endl; }

	std::vector<std::string> names;
	std::stack<std::string> state_before;

	std::stack<htmlTag> tag_st(this->state_stack);

	while (!tag_st.empty())
	{
		names.push_back(tag_st.top().GetName());
		tag_st.pop();
	}

	for (auto it = names.rbegin(); it != names.rend(); it++)
	{
		state_before.push(*it);
	}

	htmlTag tag(tag_name, state_before, this->available_attributes, this->available_tags);

	this->state_stack.push(tag);
	
}

void htmlDocument::AddOpeningTag(std::string tag_name, std::list<htmlAttribute> attrs)
{
	
	DBG("[Engine] Processing opening tag", tag_name);
	this->AddOpeningTag(tag_name);
	for (auto it : attrs)
	{
		this->AddAttributeToLastTag(it.GetName(), it.GetValue());
	}
	strings.clear();
	attributes_lists.clear();
	attributes.clear();
}

void htmlDocument::AddClosingTag(std::string tag_name)
{
	
	DBG("[Engine] Processing closing tag", tag_name);
	std::string previous_tag_name = this->state_stack.top().GetName();

	if (tag_name != previous_tag_name)
	{
		std::cout << "[Tag Error] Unequal closing tag <" << tag_name << "> for <" << previous_tag_name << ">" << std::endl;
	}

	if (!state_stack.empty()) { this->state_stack.pop(); }
	else { std::cout << "[Tag Error] Unclosed tag: <" << tag_name << ">" << std::endl; }
	
}

void htmlDocument::AddSingleTag(std::string tag_name)
{
	DBG("[Engine] Processing single tag", tag_name);
	if (!tag_name_is_correct(tag_name)) { std::cout << "[DocumentError] Tag with name <" << tag_name << "> " << "does not exist" << std::endl; }

	std::vector<std::string> names;
	std::stack<std::string> state_before;

	std::stack<htmlTag> tag_st(this->state_stack);

	while (!tag_st.empty())
	{
		names.push_back(tag_st.top().GetName());
		tag_st.pop();
	}

	for (auto it = names.rbegin(); it != names.rend(); it++)
	{
		state_before.push(*it);
	}

	htmlTag tag(tag_name, state_before, this->available_attributes, this->available_tags);
	
}

void htmlDocument::AddSingleTag(std::string tag_name, std::list<htmlAttribute> attrs)
{
	DBG("[Engine] Processing single tag", tag_name);
	this->AddSingleTag(tag_name);
	//for (auto it : attrs)
	//{
	//	this->AddAttributeToLastTag(it.GetName(), it.GetValue());
	//}
	strings.clear();
	attributes_lists.clear();
	attributes.clear();
}

void htmlDocument::CheckEndState()
{
	if (!this->state_stack.empty())
	{
		std::cout << "Unclosed tags:\n";
		while (!this->state_stack.empty())
		{
			std::cout << "\t" << "<" << this->state_stack.top().GetName() << ">" << std::endl;
			this->state_stack.pop();
		}
	}
}

void htmlDocument::AddAttributeToLastTag(std::string attr, std::string val)
{
	if (!state_stack.empty())
	{
		auto tag = state_stack.top();
		//std::cout << "Adding attribute to tag: <" << tag.GetName() << ">: " << attr << " with value: " << val << std::endl;;
		state_stack.pop();
		tag.AddAttribute(attr, val);
		state_stack.push(tag);
	}
}

bool htmlDocument::tag_name_is_correct(std::string name)
{
	return (this->available_tags.find(name) != available_tags.end());
}

htmlDocument::~htmlDocument()
{
	//this->CheckEndState();
}