#pragma once
#include <vector>
#include <string>

class String_tokenizer
{
public:
	String_tokenizer();
	~String_tokenizer();

	static std::vector<std::string>* split(const char *str, char c);
};

