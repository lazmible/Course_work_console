#pragma once
#include <iostream>

class error
{
private:
	const std::size_t line;
	const std::size_t start, end;
	const std::string err_msg;
public:
	error(std::size_t ln, std::size_t st, std::size_t en, std::string msg)
		: line(ln), start(st), end(en), err_msg(msg) {}
	const std::string GetMsg() const { return err_msg; }
};