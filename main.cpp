/** @file */

/*
   FUNDAMENTALS OF COMPUTER PROGRAMMING
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

using namespace std;

#include <iostream>  // input-output stream
#include <fstream>   // file stream
#include <sstream>   // string stream 
#include <iomanip>   // stream manipulators
#include <vector>

#include "functions.h"
#include "structures.h"
#include "functions.cpp"
#include<string.h>


/**
 * 
 * 
 * Main views of the programme, responsible for collecting data and calling the model to solve the problem. 
 * 
 */
int main(){
    std::cout << "Enter the name of the file containing the first matrix (including the extension)" << std::endl;
    std::string matrix1;
    cin >> matrix1; 

    std::cout << "Enter the name of the file containing the second matrix (including the extension)" << std::endl;
    std::string matrix2;
    cin >> matrix2; 

    std::vector<std::vector<double>> firstMatrix = read_matrix(matrix1);
    std::vector<std::vector<double>> secondMatrix = read_matrix(matrix2);
    std::vector<std::vector<double>> aux; 

    bool loop = true;
    while (loop){
        int x = menu();
        if (x == 0){
            loop = false;
        }
        else if (x == 1){
            if(firstMatrix.size() == secondMatrix.size() && firstMatrix[0].size() == secondMatrix[0].size()){
                aux = addition(firstMatrix, secondMatrix); 
                printMatrix(aux);
            }else{
                std::cout << "The matrices have to be of the same size." << std::endl;                
            }
        }
        else if (x == 2){
            if(firstMatrix.size() == secondMatrix.size() && firstMatrix[0].size() == secondMatrix[0].size()){
                aux = subtraction(firstMatrix, secondMatrix); 
                printMatrix(aux);
            }else{
                std::cout << "The matrices have to be of the same size." << std::endl;                
            }
        }
        else if(x == 3){
            if(firstMatrix[0].size() == secondMatrix.size()){
                aux = multiplication(firstMatrix, secondMatrix); 
                printMatrix(aux);
            }
        }
        else{
            std::cout << "Which matrix do you want to transpose? (1-2) " << std::endl;
            int option;
            cin >> option;
            if(option == 1){
              aux = transposition(firstMatrix);
              printMatrix(aux);
            }else{
            aux = transposition(secondMatrix);
            printMatrix(aux);
            }
        }
        if(x > 0){
            std::cout << "Do you want to save the result in a file? (Y/n) " << std::endl;
            std::string option;
            cin >> option;
            if(option.compare("Y") == 0){
                std::cout << "What do you want to call the file? " << std::endl;
                std::string name;
                cin >> name;
                print_matrix(name,aux);
            }
        }
    }       
}
