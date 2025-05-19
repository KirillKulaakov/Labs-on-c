#ifndef HEADER


#define HEADER

#include <iostream>
#include <string>
#include "258_const.h"

int choose_form_input_output();
int continue_programm(int*);
int choose_user(const int&);
std::string input_name_of_file_to_output();
std::string input_name_of_file_to_input();
int result(int&, int&, std::string&, std::string&);
void delete_the_sequence(std::string&);
int input_from_console_str(std::string& str, int& n);
int input_from_file_str(std::string& str, std::string& name_file_input, int& n);
void output_str_to_console(const std::string& str);
int output_str_to_file(const std::string& str, const std::string& name_file_output);
int check_length_string(const std::string& str, const int& n);
void invalide_value();


template <typename Type>
int check_invalide(Type& stream) {
  using namespace CONST;
  char ch;
  if constexpr (std::is_same<Type, std::ifstream>::value || std::is_same<Type, std::fstream>::value) {
    if (!(stream.get(ch)) || ch == '\n') return SUCCESS;
    return ERROR;
  } 
  else {
    if (!(stream.get(ch))) return SUCCESS;
    while(ch != '\n') {
        if (ch != ' ') return ERROR;
        stream.get(ch);
    }
  }
  return SUCCESS;
}

#endif