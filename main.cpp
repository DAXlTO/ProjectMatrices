/** @file */

/*
   FUNDAMENTALS OF COMPUTER PROGRAMMING
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl



#include <iostream>  // input-output stream
#include <fstream>   // file stream
#include <sstream>   // string stream 
#include <iomanip>   // stream manipulators
#include <vector>
#include <filesystem>
#include "functions.h"
#include "structures.h"
#include "functions.cpp"
#include <string.h>


using std::filesystem::exists;
using namespace std;


void help(){
        std::cout <<  std::endl;   
        std::cout << "NAME" << std::endl;   
        std::cout << "             matrix - application to perform matrix operations" << std::endl;   
        std::cout << std::endl;   
        std::cout << "SYNOPSIS" << std::endl;   
        std::cout << "             matrix [OPTION]... [FILE]..." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "DESCRIPTION" << std::endl;   
        std::cout << "             Performs mathematical calculations with one or more matrices (must be stored in a file and is passed as a parameter)." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "-i" << std::endl;   
        std::cout << "             To indicate that the following two parameters are the names of the files containing the matrix." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "-o" << std::endl;   
        std::cout << "             To indicate that the following parameter is the name of the file where you want to save the result." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "-a    (ADDITION)" << std::endl;   
        std::cout << "             To indicate that the operation to be carried out is a sum." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "-s    (SUBTRACTION)" << std::endl;   
        std::cout << "             To indicate that the operation to be carried out is a subtract." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "-m    (MULTIPLICATION)" << std::endl;   
        std::cout << "             To indicate that the operation to be carried out is a multiplication." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "      (TRANSPOSITION)" << std::endl;   
        std::cout << "             No parameter is needed because only a default array is passed in the input." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "AUTHOR" << std::endl;   
        std::cout << "             Written by Daniel Alarcón Nuño." << std::endl;   
        std::cout <<  std::endl;   
        std::cout << "REPORTING BUGS" << std::endl;   
        std::cout << "             Report any translation bugs to <https://github.com/Daxito98/ProjectMatrices>" << std::endl;   
        std::cout <<  std::endl;   
        std::cout <<  std::endl;   
        std::cout <<  std::endl;   




}

/**
 * 
 * 
 * Main views of the programme, responsible for collecting data and calling the model to solve the problem. 
 * 
 */
int main(int argc, char* argv[]){

    if(argc == 1 || strcmp(argv[1], "-h") == 0){
        help();
        exit(0);
    }

    if(argc == 5){
        std::vector<std::string> cmdLineArgs(argv, argv+argc);
        std::vector<std::vector<double>> firstMatrix;
        std::vector<std::vector<double>> solution; 
        std::string fileOutput;
        int counter = 0;
        for(auto& arg : cmdLineArgs){
            if(arg == "-i"){
                if(exists(argv[counter+1])){
                    firstMatrix = read_matrix(argv[counter+1]);
                }else{
                    std::cout << "File " << argv[counter+1] << " not found!" << std::endl;   
                    exit(0);
                }
                
            }
            else if(arg == "-o"){
                fileOutput = argv[counter+1];
            }
            counter++;
        }
        solution = transposition(firstMatrix);
        printMatrix(solution);
        print_matrix(fileOutput,solution);
        exit(0);
    }

    if(argc == 7){
        std::vector<std::string> cmdLineArgs(argv, argv+argc);
        std::vector<std::vector<double>> firstMatrix;
        std::vector<std::vector<double>> secondMatrix;
        std::vector<std::vector<double>> solution; 
        std::string fileOutput;

        int counter = 0;
        for(auto& arg : cmdLineArgs){
            if(arg == "-i"){
                if(exists(argv[counter+1]) && exists(argv[counter+2])){
                    firstMatrix = read_matrix(argv[counter+1]);
                    secondMatrix = read_matrix(argv[counter+2]);
                }else{
                    std::cout << "File " << argv[counter+1] << " not found!" << std::endl;   
                    exit(0);
                }
            }
            else if(arg == "-o"){

                fileOutput = argv[counter+1];
            }
            counter++;
        }

        if(strcmp(argv[6], "-a") == 0){
            if(firstMatrix.size() == secondMatrix.size() && firstMatrix[0].size() == secondMatrix[0].size()){

                solution = addition(firstMatrix, secondMatrix); 
                printMatrix(solution);
                print_matrix(fileOutput,solution);

            }else{
                std::cout << "The matrices have to be of the same size." << std::endl; 
                exit(0);               
            }
        }else if(strcmp(argv[6], "-s") == 0){
            if(firstMatrix.size() == secondMatrix.size() && firstMatrix[0].size() == secondMatrix[0].size()){
                solution = subtraction(firstMatrix, secondMatrix); 
                printMatrix(solution);
                print_matrix(fileOutput,solution);

            }else{
                std::cout << "The matrices have to be of the same size." << std::endl;                
            }
        }else if (strcmp(argv[6], "-m") == 0){
            if(firstMatrix[0].size() == secondMatrix.size()){
                solution = multiplication(firstMatrix, secondMatrix); 
                printMatrix(solution);
                print_matrix(fileOutput,solution);
            }else{
                std::cout << "The size of the matrix has to be MxN and NxM." << std::endl;                
            }
        }
    }else{
        std::cout << "Incorrect paramters!" << std::endl;   
        std::cout << "Type -h if you need help." << std::endl;   
    }
    std::vector<std::string> cmdLineArgs(argv, argv+argc);



    std::vector<std::vector<double>> aux; 
/*
    bool loop = true;
    while (loop){
        
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
       
        }
    }   
    */    
}
