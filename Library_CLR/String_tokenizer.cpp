#include "String_tokenizer.h"



String_tokenizer::String_tokenizer()
{
}


String_tokenizer::~String_tokenizer()
{
}

std::vector<std::string>* String_tokenizer::split(const char *str, char c)
{
	std::vector<std::string>* to_return = new std::vector<std::string>();

	do
	{
		const char *begin = str;

		while (*str && *str != c)
			++str;

		if (begin != str)
		{
			to_return->push_back(std::string(begin, str));
		}
	} while (0 != *str++);

	return to_return;
}
