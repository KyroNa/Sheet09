// Sheet09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS //To use strtok instead of strtok_s
#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;



void F1(int *A, int *B, int* C) 
{ 
    int D; 
    D = *A; 
    *A = *B; 
    *B = *C; 
    *C = D; 
}

int GetValues(char *Text, double *Values)
{
    int nValues = 0;


    // Splits str[] according to given delimiters.
    // and returns next token. It needs to be called
    // in a loop to get all tokens. It returns NULL
    // when there are no more tokens.
    //char* strtok(char str[], const char* delims);

    char* Pch = strtok(Text, " ");
    cout << "Printing the String:\n";
    while(Pch != NULL) //NULL here means the end of the string
    {
        cout << Pch << "\n";
        Values[nValues] = stod(Pch);
        nValues++;
        Pch = strtok(NULL, " "); //NULL here means no new strings passed so keep tokenizing the last passed string
    }
    


    return nValues;
}

//Implemnting our own strtok function
char* mystrtok(char* s, char d)
{
    // Stores the state of string
    static char* input = NULL;

    // Initialize the input string
    if (s != NULL)
        input = s;

    // Case for final token
    if (input == NULL)
        return NULL;

    // Stores the extracted string
    char* result = new char[strlen(input) + 1];
    int i = 0;

    // Start extracting string and
    // store it in array
    for (; input[i] != '\0'; i++) {

        // If delimiter is not reached
        // then add the current character
        // to result[i]
        if (input[i] != d)
            result[i] = input[i];

        // Else store the string formed
        else {
            result[i] = '\0';
            input = input + i + 1;
            return result;
        }
    }

    // Case when loop ends
    result[i] = '\0';
    input = NULL;

    // Return the resultant pointer
    // to the string
    return result;
}

int main()
{

    /*
    //Probem 1
    int X = 3; 
    int *P = &X; 
    cout << *P << '\t' << P << '\t' << &X << '\t' << &P;
    */

    /*
    //Problem 2
    int M[] = { 3,4,5,2 }; 
    int *P; 
    P = M; 
    cout << *P << '\t' //M[0]
        << *(P + 1) << '\t' //M[1] 
        << P[2] << '\t' //M[2]
        << *(M + 3) << endl; //M[3] 
    P = M; 
    cout << P << '\t' 
        << (P + 1) << '\t' 
        << &P[2] << '\t' 
        << (M + 3) << endl; 
    P = &M[3]; 
    cout << *P << '\t' 
        << (P - M) << '\t' 
        <<(*P - *M) << "\t"
        << sizeof(M[0]) << '\t'
        << (int)P - (int)M << endl;
     */
    
    /*
    //Problem 3
    int X = 7, Y = 8, Z = 2;
    cout << X << '\t' << Y << '\t' << Z << endl;
    F1(&X, &Y, &Z);
    cout << X << '\t' << Y << '\t' << Z << endl;
    */

    /*
    //Problem 4
    float F[] = { 1.2, 3.4, 7.1, 3.1 };
    float *P = F;
    cout << *P << '\t' << endl;
    P++;
    cout << *P << '\t' << endl;
    P += 2;
    cout << *P << '\t' << endl;
    */

    
    //Problem 5 & 6 check functions 
    char Text[] = "7672.28 276763.22 0.767 1.2878 772.2 1878 152 0.0123";
    double Values[100];
    int nValues;
    
    nValues = GetValues(Text, Values);

    cout << "\nPrinting the array of doubles:\n";
    for (int i = 0; i < nValues; i++)
        cout << Values[i] << endl;
    

    /*
    //Problem 7
    int size;
    cout << "Insert size of 1d array: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Insert array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >>  arr[i];
    }

    cout << "The created array: \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << setw(4);
    }

    delete[] arr; //don't forget to delete the dynamic array for memory deallocation
    */
    
    //Problem 8
    int size1, size2;
    cout << "Insert size of 2d array: ";
    cin >> size1 >> size2;
    int* arr = new int[size1 * size2];
    cout << "Insert array elements:\n";
    for (int i = 0; i < size1; i++)
    {
        for(int j = 0; j < size2; j++)
            cin >> arr[i*size2 + j];
    }

    cout << "The created array: \n";
    for (int i = 0; i < size1; i++)
    {
        cout << setw(4);
        for (int j = 0; j < size2; j++)
            cout << arr[i*size2 + j] << setw(4);
        cout << endl;
    }

    delete[] arr; //don't forget to delete the dynamic array for memory deallocation
    
}

