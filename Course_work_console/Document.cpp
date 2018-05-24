#include "Document.h"
#include "utils.h"
#include "precedence.h"
#include <list>

extern int yylineno;

void htmlDocument::AddOpeningTag(std::string tag_name, int line)
{	
	DBG("[Engine] Processing opening tag", tag_name);
	if (!tag_name_is_correct(tag_name)) { std::cout << "[DocumentError] Tag with name <" << tag_name << "> " << "does not exist" << std::endl; }
	
	htmlTag tag(tag_name, this->available_attributes, this->available_tags, line);

	check_previous_state(tag);

	if (std::find(TagsWithNoClosing.begin(), TagsWithNoClosing.end(), tag_name) == TagsWithNoClosing.end())
	{
		this->state_stack.push(tag);
	}

	CleanUpUtilsStructures();
}

void htmlDocument::AddOpeningTag(std::string tag_name, std::list<htmlAttribute> attrs, int line)
{

	DBG("[Engine] Processing opening tag", tag_name);

//	for (auto it : attrs) { DBG("[Engine] Attribute added", it.GetName()); }

	if (!tag_name_is_correct(tag_name)) { std::cout << "[DocumentError] Tag with name <" << tag_name << "> " << "does not exist" << std::endl; }

	htmlTag tag(tag_name, this->available_attributes, this->available_tags, line);

	for (auto it : attrs)
	{
		tag.AddAttribute(it.GetName(), it.GetValue());
	}

	check_previous_state(tag);

	if (std::find(TagsWithNoClosing.begin(), TagsWithNoClosing.end(), tag_name) == TagsWithNoClosing.end())
	{
		this->state_stack.push(tag);
	}

	CleanUpUtilsStructures();
}

void htmlDocument::AddClosingTag(std::string tag_name, int line)
{
	DBG("[Engine] Processing closing tag", tag_name);

	if (std::find(TagsWithNoClosing.begin(), TagsWithNoClosing.end(), tag_name) != TagsWithNoClosing.end())
	{
		std::cout << "[TagWarning " << " line: " << line << "]" << " Found closing tag for element, that shuold not have it <" << tag_name << ">" << std::endl;
		return;
	}

	std::string previous_tag_name = this->state_stack.top().GetName();

	if (tag_name != previous_tag_name)
	{
		std::cout << "[TagError " << " line: " << line << "] Unequal closing tag <" << tag_name << "> for <" << previous_tag_name << ">" << " on line: " << line << std::endl;
	}

	if (!this->state_stack.empty()) 
	{
		this->state_stack.pop(); 
	}
	else                            
	{
		std::cout << "[TagError " << " line: " << line << "] Unclosed tag: <" << tag_name << ">" << " on line: " << line << std::endl; 
	}

	CleanUpUtilsStructures();
}

void htmlDocument::AddSingleTag(std::string tag_name, int line)
{
	DBG("[Engine] Processing single tag", tag_name);
	
	if (!tag_name_is_correct(tag_name)) 
	{
		std::cout << "[DocumentError " << " line: " << line << " ] Tag with name <" << tag_name << "> " << "does not exist" << std::endl; 
	}

	htmlTag tag(tag_name, this->available_attributes, this->available_tags, line);
	
	check_previous_state(tag);
	CleanUpUtilsStructures();
}

void htmlDocument::AddSingleTag(std::string tag_name, std::list<htmlAttribute> attrs, int line)
{
	DBG("[Engine] Processing single tag", tag_name);

	if (!tag_name_is_correct(tag_name)) 
	{
		std::cout << "[DocumentError" << " line: " << line << " ] Tag with name <" << tag_name << "> " << "does not exist" << std::endl; 
	}

	htmlTag tag(tag_name, this->available_attributes, this->available_tags);

	for (auto it : attrs)
	{
		tag.AddAttribute(it.GetName(), it.GetValue());
	}

	check_previous_state(tag);
	CleanUpUtilsStructures();
}

bool htmlDocument::tag_name_is_correct(std::string name)
{
	return (this->available_tags.find(name) != available_tags.end());
}

void htmlDocument::check_previous_state(htmlTag tag)
{
	std::stack<htmlTag> current_state_of_doc(this->state_stack);

	bool html_found                       = false;
	bool precedence_correct               = false;
	bool precedence_is_required_to_check  = false;
	bool precedence_is_strict             = false;
	bool allowded_to_be_inside_head       = false;
	bool bad_head_found                   = false;

	std::string precedence_tag;

	if (PrecedenceTags.find(tag.GetName()) != PrecedenceTags.end()) 
	{
		precedence_is_required_to_check  = true;
		precedence_tag                   = PrecedenceTags.find(tag.GetName())->second.first;
		precedence_is_strict             = PrecedenceTags.find(tag.GetName())->second.second;
	}

	
	if (std::find(HeadTagsAllowded.begin(), HeadTagsAllowded.end(), tag.GetName()) != HeadTagsAllowded.end())
	{
		allowded_to_be_inside_head = true;
	}

	if (precedence_is_strict && precedence_tag != current_state_of_doc.top().GetName()) 
	{
		std::cout << "[DocumentError" << " line: " << tag.GetLine() << " ] Tag  <" << tag.GetName() << "> " 
			<< "must be strictly inside element <" << precedence_tag << ">" << std::endl;
	}
	else
	{
		while (!current_state_of_doc.empty())
		{
			if (precedence_is_required_to_check)
			{
				if (precedence_tag == current_state_of_doc.top().GetName())                    { precedence_correct = true; }
			}
			if ("html" == current_state_of_doc.top().GetName())                                { html_found          = true; }
			if ("head" == current_state_of_doc.top().GetName() && !allowded_to_be_inside_head) { bad_head_found      = true; }
			current_state_of_doc.pop();
		}
		if (!precedence_correct && precedence_is_required_to_check)
		{
			std::cout << "[DocumentError" << " line: " << tag.GetLine() << " ] Tag  <" << tag.GetName() << "> "
				<< "must be inside element <" << precedence_tag << ">" << std::endl;
		}
		if (!html_found)
		{
			std::cout << "[DocumentError" << " line: " << tag.GetLine() << " ] Tag  <" << tag.GetName() << "> "
				<< "must be inside element <html>" << std::endl;
		}
		if (bad_head_found)
		{
			std::cout << "[DocumentError" << " line: " << tag.GetLine() << " ] Tag  <" << tag.GetName() << "> "
				<< "cannot be inside element <head>" << std::endl;
		}
		return;
	}
}
