//NAME: Burmau Garba
//Class: CSC 362

/*
                                        INTRODUCTIONS
    THIS PROGRAM TEST THE ABILITY TO USE LOGIC AND ALSO READ AND WRITE FILES IN C-LANGUAGE 
    IT CAN SCRAMBLE CHARACTERS IN A FILE AND MAKE THEM SORT OF ENCRYPTED SORT OF. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //DECLEARED ALL NECESSARY VARIABLES
    char x;
    int counter = 0, skip;
    float number_of_inp_char = -2, number_of_outp_char = -2;
    float result;

    //get the files AND READ AND WRITE THEM RESPECTIVELY
    FILE *inputFile = fopen("infile3.txt", "r");
    FILE *outFile = fopen("outFile.txt", "w");
    //ask the user for skip count
    printf("Enter the skip counter here: ");
    scanf("%d", &skip);

    //LOOP THROUGH THE FILE TILL THE END OF FILE AND PUT ASCII IN X
    while ((x = getc(inputFile)) != -1)
    {
        number_of_inp_char++; //INCREMENT THE NUMBER OF CHARACTERS IN INPUT FILES
        //CHECK IF ITS AN ALPHANUMERIC CHARACTER
        if (isalnum(x))
        {
            //CHECK IF THE COUNTER IS NOT MORE THAN SKIP NUM
            if (counter < skip)
            {
                counter++;             //INCREMENT SKIP
                number_of_outp_char++; //INCREMENT NUMBER OF CHARACTER IN THE OUTPUT FILES
                putc(x, outFile);      //PUT CHARACTER IN OUTPUT FILE
            }
            else
            {
                counter = 0;
            }
        }
        else
        {
            //PUT CHARACTER IN OUTPUT FILE AND INCREASE COUNTER BY ONE
            putc(x, outFile);
            number_of_outp_char++;
        }
    }
    //get the result of the two outcomes in percentages
    result = number_of_outp_char / number_of_inp_char * 100;
    //print the output and close the files
    printf("Size of infile.txt: %.0f\nSize of outfile.txt: %.0f\n", number_of_inp_char, number_of_outp_char);
    printf("File size change: %.2f%%", result);
    fclose(outFile);
    fclose(inputFile);
}

//                      FILE ONE
//Enter the skip counter here: 5
//Size of infile.txt : 133
//Size of outfile.txt : 117
//File size change : 87.97 % %

//                      FILE TWO
//Enter the skip counter here: 7
//Size of infile.txt : 662
//Size of outfile.txt : 602
//File size change : 90.94 % %

//                      FILE THREE
//Enter the skip counter here: 3
//Size of infile.txt : 662
//Size of outfile.txt : 541
//File size change : 81.72 % %