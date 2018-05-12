#include "Document.h"

void htmlDocument::AddOpeningTag(std::string tag_name)
{
	std::vector<std::string> names;
	std::stack<std::string> state_before;

	std::stack<htmlTag> tag_st(this->state_stack);

	while (!tag_st.empty())
	{
		names.push_back(tag_st.top().GetName());
	}
	
	for (auto it = names.rbegin(); it != names.rend(); it++)
	{
		state_before.push(*it);
	}

	htmlTag tag(tag_name, state_before,
		this->available_attributes, this->available_tags);

	this->state_stack.push(tag);
}

void htmlDocument::AddClosingTag(std::string tag_name)
{
	std::string previous_tag_name = this->state_stack.top().GetName();

	if (tag_name != previous_tag_name) { std::cout << "Unequal closing tag: " 
		<< tag_name << "for: " << previous_tag_name; }

	if (!state_stack.empty()) { this->state_stack.pop(); }
	else { std::cout << "Unmatched closing tag: " << tag_name << std::endl; }

}