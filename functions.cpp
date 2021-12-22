/** @file */

#include <chrono>
#include <random>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "functions.h"



void print_matrix(const std::string& FILE_NAME, std::vector<std::vector<double>> matrix)
{
	std::ofstream file (FILE_NAME); // output file stream + open 
	if (file) // Is the file open? Can we write into the file?
	{ 
		for (int r = 0; r < matrix.size(); r++) // for each row 
		{
			for (int c = 0; c < matrix[0].size(); c++) // for each column in a row 
			{
				file << matrix[r][c] << " ";
			}
			// the row has been printed
			file << std::endl;
		}
	}
}

std::vector<std::vector<double>> read_matrix(const std::string& FILE_NAME){
	std::vector<std::vector<double>> matrix; 

	std::ifstream file (FILE_NAME);  // input file stream + open
	if (file)
	{
		std::string line; // string!!!
		while (getline(file, line))
		{
			//             std::cout << "[" << line << "]" << std::endl;

			std::stringstream ss;
			ss << line;

			std::vector<double> row; // the blue vector
			double number;
			while(ss >> number)
			{
				//                 std::cout << "[" << number << "]";
				row.push_back(number);
			}

			//  std::cout << std::endl;
			matrix.push_back(row);
		}
	}

	return matrix;
}

std::vector<std::vector<double>>  addition(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){

	std::vector<std::vector<double>> aux = matrix1; 

	for (std::size_t row = 0; row < matrix1.size();  row++)  // for each row
	{
		for (std::size_t col = 0; col < matrix1[row].size(); col++)   // for each column
		{
			aux[row][col] = matrix1[row][col] + matrix2[row][col];
		}
		std::cout << std::endl;
	}

	return aux;
}


std::vector<std::vector<double>>  subtraction(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){
	std::vector<std::vector<double>> aux = matrix1; 

	for (std::size_t row = 0; row < matrix1.size();  row++)  // for each row
	{
		for (std::size_t col = 0; col < matrix1[row].size(); col++)   // for each column
		{
			aux[row][col] = matrix1[row][col] - matrix2[row][col];
		}
		std::cout << std::endl;
	}
	
	return aux;
}

std::vector<std::vector<double>>  multiplication(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){
	std::vector<std::vector<double>> aux(matrix1.size(), vector<double> (matrix1.size(), 0)); 

	for (std::size_t row = 0; row < matrix1.size();  row++){
		for (std::size_t col = 0; col < matrix2[0].size(); col++){
			int sum = 0;
			for(int x = 0; x <matrix1[0].size();x++){
				sum += matrix1[row][x]*matrix2[x][col];
			}
		aux[row][col] = sum;
		}
		std::cout << std::endl;
	}
	
	return aux;
}

std::vector<std::vector<double>>  transposition(std::vector<std::vector<double>> matrix){
	std::vector<std::vector<double>> aux(matrix[0].size(), vector<double> (matrix.size(), 0));

	for (std::size_t row = 0; row < matrix.size();  row++){
		for (std::size_t col = 0; col < matrix[0].size(); col++){
			aux[col][row] = matrix[row][col];
		}
		std::cout << std::endl;
	}
	return aux;
}

int menu(){
 	std::cout << "Choose an option (0-4): " << std::endl;
	std::cout << "0.- Exit " << std::endl;
 	std::cout << "1.- Add two matrices " << std::endl;
 	std::cout << "2.- Subtract two matrices " << std::endl;
 	std::cout << "3.- Multiplying two matrices " << std::endl;
 	std::cout << "4.- Transpose a matrix " << std::endl;

    int option;
    cin >> option; 
	return option;
}

void printMatrix( std::vector<std::vector<double>> aux){
    for (std::size_t row = 0; row < aux.size();  row++){
        for (std::size_t col = 0; col < aux[row].size(); col++){
            std::cout << aux[row][col] << " ";
        }
        std::cout << std::endl;
    }
	std::cout << std::endl;
}






