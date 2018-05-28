#include "Document.h"
#include "utils.h"
#include "precedence.h"
#include "debug.h"
#include <list>

extern int yylineno;

std::string str_tolower(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
	return s;
}

bool tag_can_not_be_closed(std::string name)
{
	return (std::find(TagsCanBeNonClosed.begin(), TagsCanBeNonClosed.end(), name) != TagsCanBeNonClosed.end());
}

void htmlDocument::AddOpeningTag(std::string tag_name, int line)
{
	tag_name = str_tolower(tag_name);
	if (tag_name == "html") { this->html_was = true; }
	if (tag_name == "title") { this->title_was = true; }

	DEBUG_MESSAGE("Processing opening tag - " + tag_name, DEBUG_CODE_ENGINE, line);

	if (!tag_name_is_correct(tag_name)) 
	{
		ERROR_MESSAGE("Tag with name <" + tag_name + "> does not exist", ERROR_CODE_DOCUMENT, line);
	}
	htmlTag tag(tag_name, this->available_attributes, this->available_tags, line);
	check_previous_state(tag, line);
	if (std::find(TagsWithNoClosing.begin(), TagsWithNoClosing.end(), tag_name) == TagsWithNoClosing.end())
	{
		this->state_stack.push(tag);
	}
	CleanUpUtilsStructures();
}

void htmlDocument::AddOpeningTag(std::string tag_name, std::list<htmlAttribute> attrs, int line)
{
	tag_name = str_tolower(tag_name);
	if (tag_name == "html") { this->html_was = true; }
	if (tag_name == "title") { this->title_was = true; }

	DEBUG_MESSAGE("Processing opening tag - " + tag_name, DEBUG_CODE_ENGINE, line);

	if (!tag_name_is_correct(tag_name)) 
	{
		ERROR_MESSAGE("Tag with name <" + tag_name + "> does not exist", ERROR_CODE_DOCUMENT, line);
	}

	htmlTag tag(tag_name, this->available_attributes, this->available_tags, line);
	for (auto it : attrs)
	{
		tag.AddAttribute(it.GetName(), it.GetValue());
	}
	check_previous_state(tag, line);
	if (std::find(TagsWithNoClosing.begin(), TagsWithNoClosing.end(), tag_name) == TagsWithNoClosing.end())
	{
		this->state_stack.push(tag);
	}
	CleanUpUtilsStructures();
}

void htmlDocument::AddClosingTag(std::string tag_name, int line)
{
	tag_name = str_tolower(tag_name);

	DEBUG_MESSAGE("Processing closing tag - " + tag_name, DEBUG_CODE_ENGINE, line);

	if (std::find(TagsWithNoClosing.begin(), TagsWithNoClosing.end(), tag_name) != TagsWithNoClosing.end())
	{
		WARNING_MESSAGE("Found closing tag for element, that should not have it <" + tag_name + ">", WARNING_CODE_TAG, line);
		return;
	}
	std::string previous_tag_name;
	while (true)
	{
		if (!state_stack.empty())
		{
			previous_tag_name = this->state_stack.top().GetName();
			if (tag_name != previous_tag_name && !tag_can_not_be_closed(previous_tag_name))
			{
				ERROR_MESSAGE("Unequal closing tag <" + tag_name + "> for <" + previous_tag_name + ">", ERROR_CODE_TAG, line);
				break;
			}
			else
			{
				this->state_stack.pop();
				break;
			}
		}
		else
		{
			ERROR_MESSAGE("Unclosed tag : <" + tag_name + ">", ERROR_CODE_TAG, line);
			break;
		}
	}
	CleanUpUtilsStructures();
}

void htmlDocument::AddSingleTag(std::string tag_name, int line)
{
	tag_name = str_tolower(tag_name);
	if (tag_name == "html") { this->html_was = true; }
	if (tag_name == "title") { this->title_was = true; }

	DEBUG_MESSAGE("Processing single tag - " + tag_name, DEBUG_CODE_ENGINE, line);

	if (!tag_name_is_correct(tag_name))
	{
		ERROR_MESSAGE("Unexpected tag name: <" + tag_name + ">", ERROR_CODE_DOCUMENT, line);
	}
	htmlTag tag(tag_name, this->available_attributes, this->available_tags, line);
	check_previous_state(tag, line);
	CleanUpUtilsStructures();
}

void htmlDocument::AddSingleTag(std::string tag_name, std::list<htmlAttribute> attrs, int line)
{
	tag_name = str_tolower(tag_name);

	DEBUG_MESSAGE("Processing single tag - " + tag_name, DEBUG_CODE_ENGINE, line);

	if (!tag_name_is_correct(tag_name))
	{
		ERROR_MESSAGE("Unexpected tag name: <" + tag_name + ">", ERROR_CODE_DOCUMENT, line);
	}
	htmlTag tag(tag_name, this->available_attributes, this->available_tags, line);
	for (auto it : attrs)
	{
		tag.AddAttribute(it.GetName(), it.GetValue());
	}
	check_previous_state(tag, line);	
	CleanUpUtilsStructures();
}

bool htmlDocument::tag_name_is_correct(std::string name)
{
	return (this->available_tags.find(name) != available_tags.end());
}

void htmlDocument::check_previous_state(htmlTag tag, int line)
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
		ERROR_MESSAGE("Tag <" + tag.GetName() + "> " + "must be strictly inside element <" + precedence_tag + ">", ERROR_CODE_DOCUMENT, line);
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
			ERROR_MESSAGE("Tag <" + tag.GetName() + "> " + "must be strictly inside element <" + precedence_tag + ">", ERROR_CODE_DOCUMENT, line);
		}
		if (!html_found && tag.GetName() != "html")
		{
			ERROR_MESSAGE("Tag <" + tag.GetName() + "> " + "must be strictly inside element <html>", ERROR_CODE_DOCUMENT, line);
		}
		if (bad_head_found)
		{
			ERROR_MESSAGE("Tag <" + tag.GetName() + "> " + "must be strictly inside element <head>", ERROR_CODE_DOCUMENT, line);
		}
		return;
	}
}
