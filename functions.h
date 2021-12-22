/** @file */

/*
   FUNDAMENTALS OF COMPUTER PROGRAMMING

   lecture 7

 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


/** The function prints a matrix of random numbers in a file
  @param FILE_NAME  file name :-)
  @param ROWS       number of rows
  @param COLS       number of columns
 */
void  print_matrix (const std::string & FILE_NAME, const int ROWS, const int COLS);

/** The function reads a matrix of numbers from a text file.
  @param FILE_NAME file name 
  @return a matrix of doubles*/
std::vector<std::vector<double>>  read_matrix(const std::string & FILE_NAME);

/**
 * 
 * 
 */
std::vector<std::vector<double>>  addition(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2);

/**
 * 
 * 
 */
std::vector<std::vector<double>>  subtraction(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2);

/**
 * 
 * 
 */
std::vector<std::vector<double>>  multiplication(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2);

/**
 * 
 * 
 */
std::vector<std::vector<double>>  transposition(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2);


#endif

