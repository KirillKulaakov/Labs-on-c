#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#ifndef HEADER

#define HEADER

int continue_programm(int* exit);
int choose_form_input_output();
int choose_user(const int& choose);
std::string input_name_of_file_to_output();
std::string input_name_of_file_to_input();
int result(int& inp, int& outp,const int& n, std::string& name_file_input, std::string& name_file_output);
int check_invalide();
int enter_matrix_from_console(std::vector<std::vector<double>>& matrix, const int& n);
int enter_matrix_from_file(std::vector<std::vector<double>>& matrix, const int& n, const std::string& name_file_input);
void sum_the_element(const std::vector<std::vector<double>>& matrix, const int& n, double& sum1, double& sum2, double& sum3);
void output_sum_to_console(const double& sum1, const double& sum2, const double& sum3);
int output_sum_to_file(const double& sum1, const double& sum2, const double& sum3, const std::string name_file_output);
void invalide_value();

#endif