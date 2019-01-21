#pragma once
#include <string>

class User
{
private:
	std::string user_name;
	std::string password;

public:
	User();
	~User();

	
	std::string Get_user_name();
	void Set_user_name(std::string);

	std::string Get_password();
	void Set_password(std::string);
};

