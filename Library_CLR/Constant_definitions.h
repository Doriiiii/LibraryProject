#pragma once

#include <string>

static const std::string path_books = "Book_list.csv";
static const std::string path_logins = "Login.csv";
static const std::string path_users = "Users.csv";
static const std::string path_history = "History.csv";

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

static const std::string text_borrow_book_history = "BORROW";
static const std::string text_bring_book_hisotry = "BRING OUT";

static const char* date_format = "%d-%02d-%02d %02d:%02d";
