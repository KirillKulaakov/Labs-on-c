#include <iostream>
#include <string>

#ifndef HEADER

#define HEADER

int choose_form_input_output();
int continue_programm(int*);
int choose_user(const int&);
int check_invalide();
std::string input_name_of_file_to_output();
std::string input_name_of_file_to_input();
int result(int&, int&, int&, std::string&, std::string&);
void delete_the_sequence(std::string&);
void input_from_console_str(std::string& str, const int& n);
int input_from_file_str(std::string& str, std::string& name_file_input);
void output_str_to_console(const std::string& str);
int output_str_to_file(const std::string& str, const std::string& name_file_output);
int check_length_string(const std::string& str, const int& n);
void invalide_value();

#endif