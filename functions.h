/** @file */

/*
   FUNDAMENTALS OF COMPUTER PROGRAMMING


 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


/** The function prints a matrix of random numbers in a file
  @param FILE_NAME  file name :-)
  @param matrix       matrix to save
 */
void  print_matrix (const std::string & FILE_NAME, std::vector<std::vector<double>> matrix);

/** The function reads a matrix of numbers from a text file.
  @param FILE_NAME file name 
  @return a matrix of doubles*/
std::vector<std::vector<double>>  read_matrix(const std::string & FILE_NAME);

/** The function is in charge of adding two matrices together
  @param matrix1 first matrix   
  @param matrix2  second matrix
  @return a matrix with the solution
 */
std::vector<std::vector<double>>  addition(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2);

/** The function is in charge of subtracting two matrices together
  @param matrix1 first matrix   
  @param matrix2  second matrix
  @return a matrix with the solution

 */
std::vector<std::vector<double>>  subtraction(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2);

/** The function takes care of the multiplication of two matrices
  @param matrix1 first matrix   
  @param matrix2  second matrix
  @return a matrix with the solution
 */
std::vector<std::vector<double>>  multiplication(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2);

/** The function is in charge of transposing a matrix
  @param matrix matrix to transpose
  @return a matrix with the solution
 */
std::vector<std::vector<double>>  transposition(std::vector<std::vector<double>> matrix);


#endif