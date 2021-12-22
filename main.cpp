/** @file */

/*
   FUNDAMENTALS OF COMPUTER PROGRAMMING

   lecture 7: streams + structures
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
            if(firstMatrix[0].size() == secondMatrix.size()){
                            aux = transposition(firstMatrix, secondMatrix); 
                            printMatrix(aux);
        }          
    }
            
}
