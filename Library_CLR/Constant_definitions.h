#pragma once

#include <string>

static const std::string books_path = "Book_list.csv";
static const std::string logins_path = "Login.csv";
static const std::string users_path = "Users.csv";

static const int code_add_book = 1;
static const int code_delete_book = 2;
static const int code_borrow_book = 3;
static const int code_bring_book = 4;
static const int code_add_person = 5;
static const int code_delete_person = 6;

static const std::string text_add_book = "Book ADDED";
static const std::string text_delete_book = "Book REMOVED";
static const std::string text_borrow_book = "Book BORROWED";
static const std::string text_bring_book = "Book BROUGHT OUT";
static const std::string text_add_person = "User ADDED";
static const std::string text_delete_person = "User REMOVED";
