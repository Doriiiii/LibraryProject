#include "No_file_exception.h"




No_file_exception::No_file_exception(std::string msg)
{
	message = msg;
}

No_file_exception::~No_file_exception()
{
}

std::string No_file_exception::what()
{
	return message;
}
