#include "User.h"


#pragma region ctor
User::User()
{
	user_name = "";
	password = "";
}

User::~User()
{
}
#pragma endregion

std::string User::Get_user_name()
{
	return user_name;
}

void User::Set_user_name(std::string u_name)
{
	user_name = u_name;
}

std::string User::Get_password()
{
	return password;
}

void User::Set_password(std::string pass)
{
	password = pass;
}


