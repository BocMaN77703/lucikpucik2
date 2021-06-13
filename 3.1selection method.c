#include <stdio.h>
#include <stdbool.h>
int main()
{
    int number;
    FILE* file;
    fpos_t position1, position2, tempPosition;
    int number1, number2, tempNumber;
    bool isQuite = false, isExit = false;

    file = fopen ("Text.txt", "w+");
    printf("\t\t\tFile initialization\n");
    if (!(file = fopen("Text.txt", "w+")))
    {
        puts("File was not created\n");
        return 0;
    }
    rewind(file);
    printf("Enter a number\n");
    scanf("%d", &number);
    while (number != 999)
    {
        fprintf(file, "%2d", number);
        printf("Enter a number\n");
        scanf("%d", &number);
        if (number == 999)
        {
            break;
        }

    }
//    fclose(file);

//    file = fopen("Text.txt", "r");
    rewind(file);
    while (!feof(file))
    {
        fscanf(file, "%d", &number);
        printf("%2d", number);
    }
//    fclose(file);

//    file = fopen("Text.txt", "r+");
    rewind(file);
    while(!isQuite)
    {
        fgetpos(file, &position1);
        fscanf(file, "%d", &number1);
        if (feof(file))
        {
            isQuite = true;
        }
        tempNumber = number1;
        tempPosition = position1;
        while (!isExit)
        {
            fgetpos(file, &position2);
            fscanf(file, "%d", &number2);
            if (tempNumber > number2)
            {
                tempPosition = position2;
                tempNumber = number2;
            }
            if(feof(file))
            {
                isExit = true;
            }

        }
         if (number1 != tempNumber)
        {
            fsetpos(file, &tempPosition);
            fprintf(file, "%2d", number1);
            fsetpos(file, &position1);
            fprintf(file, "%2d", tempNumber);
        }
        position1+=2;
         isExit = false;
        fsetpos(file, &position1);
    }
//    fclose(file);

    printf("\n");

//    file = fopen("Text.txt", "r");
    rewind(file);
    while (!feof(file))
    {
        fscanf(file, "%d", &number);
        printf("% d", number);
    }
    fclose(file);
    return 0;
}