#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char x;
    int counter = 0, skip = 5;

    char c[2] = "s";
    char *p = &c[2];
    printf("%s", p);

    //get the files
    FILE *inputFile = fopen("infile.txt", "r");
    FILE *outFile = fopen("outFile.txt", "w");

    while ((x = getc(inputFile)) != -1)
    {

        if (counter < skip)
        {
            putc(x, outFile);
            counter++;
        }
        else
        {
            if (ispunct(x) || isspace(x) || x == '\n')
            {
                putc(x, outFile);
            };
            counter = 0;
        };
    };
    fclose(outFile);
    fclose(inputFile);
}
