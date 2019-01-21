#pragma once
#include <exception>
#include <string>

class No_file_exception :
	public std::exception
{
private:
	std::string message;
public:
	No_file_exception(std::string msg);
	~No_file_exception();

	std::string what();
};

