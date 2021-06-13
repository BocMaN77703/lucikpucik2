//------Дано 2 бинарных файла. Один из них отсортирован по возрастанию, второй - по убыванию. Записать всё в третий файл по убыванию без дополнительных
массивов.-------------------------------------------





#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int inputValidation();

int main()
{
    FILE* firstFile, *secondFile, *resultFile;
    int amountOfNumbers, tempNumber, number, index = 0, flag = 0;

    //initialization first file
    firstFile = fopen("First_File.bin", "wb");
    if (firstFile == NULL)
    {
        printf("File was not opened\n");
        return 0;
    }
    printf("Enter a amount of numbers\n");
    amountOfNumbers = inputValidation();
    while(index < amountOfNumbers)
    {
        number = inputValidation();
        if (index == 0)
        {
            flag = fwrite(&number, sizeof(int), 1, firstFile);
            if (flag != 1)
            {
                printf("Failed to read number\n");
            }
            else
            {
                index++;
                tempNumber = number;
            }
        }
        else
        {
            while (tempNumber > number)
            {
                printf("Enter a number bigger than previous\n");
                number = inputValidation();
            }
            flag = fwrite(&number, sizeof(int), 1, firstFile);
            if (flag != 1)
            {
                printf("Failed to read number\n");
            }
            else
            {
                index++;
                tempNumber = number;
            }

        }
    }
    fclose(firstFile);

    //output content from file


    firstFile = fopen("First_File.bin", "rb");
    if (firstFile == NULL)
    {
        perror("Error occured while opening file\n");
        exit(0);
    }
    rewind(firstFile);
    int n, indicator = 0;
    printf("Your numbers: \n");
    rewind(firstFile);
    while(!feof(firstFile) && fread(&n, sizeof(int), 1, firstFile) == 1 )
    {
        printf(" %d ", n);
    }
    printf("\n");
    fclose(firstFile);


    //initialization second file
    index = 0;
    secondFile = fopen("Second_File.bin", "wb");
    if (secondFile == NULL)
    {
        printf("File was not opened\n");
        return 0;
    }
    printf("Enter a amount of numbers\n");
    amountOfNumbers = inputValidation();
    while(index < amountOfNumbers)
    {
        number = inputValidation();
        if (index == 0)
        {
            flag = fwrite(&number, sizeof(int), 1, secondFile);
            if (flag != 1)
            {
                printf("Failed to read number\n");
            }
            else
            {
                index++;
                tempNumber = number;
            }
        }
        else
        {
            while (tempNumber < number)
            {
                printf("Enter a number smaller than previous\n");
                number = inputValidation();
            }
            flag = fwrite(&number, sizeof(int), 1, secondFile);
            if (flag != 1)
            {
                printf("Failed to read number\n");
            }
            else
            {
                index++;
                tempNumber = number;
            }

        }
    }
    fclose(secondFile);


    //output content from second file

    secondFile = fopen("Second_File.bin", "rb");
    if (secondFile == NULL)
    {
        perror("Error occured while opening file\n");
        exit(0);
    }
    rewind(secondFile);
    n, indicator = 0;
    printf("Your numbers: \n");
    rewind(secondFile);
    while(!feof(secondFile) && fread(&n, sizeof(int), 1, secondFile) == 1 )
    {
        printf(" %d ", n);
    }
    printf("\n");
    fclose(secondFile);

    //-------------------------------------------------------sort
     printf("Result\n");

    firstFile = fopen ("First_File.bin", "rb");
    secondFile = fopen ("Second_File.bin", "rb");
    resultFile = fopen ("Result_File.bin", "wb");
    if (secondFile == NULL || firstFile == NULL || resultFile == NULL)
    {
        printf ("Error occured while opening file\n");
        return 0;
    }
    int i = 2;
    fpos_t check;
    int number1, number2, result, size = sizeof(int);
    fseek(firstFile, -size, SEEK_END);
    fgetpos(firstFile, &check);
    fread(&number1, sizeof(int), 1, firstFile);
    fread(&number2, sizeof(int), 1, secondFile);
    while(check >= 0)
    {
        while(check >= 0 && number1>number2)
        {
            fwrite(&number1, sizeof(int), 1, resultFile);
            fseek(firstFile, -size*i, SEEK_END);
            fgetpos(firstFile, &check);
            if (check <= 0)
            {
                break;
            }
            fread(&number1, sizeof(int), 1, firstFile);
            i++;
        }
        while (!feof(secondFile) && number2>=number1)
        {
            fwrite(&number2, sizeof(int), 1, resultFile);
            fread(&number2, sizeof(int), 1, secondFile);
        }
        if (feof(secondFile))
        {
            break;
        }
    }
    while (!feof(secondFile))
    {
        fwrite(&number2, sizeof(int), 1, resultFile);
        fread(&number2, sizeof(int), 1, secondFile);
    }
    while(check>=0)
    {
        fwrite(&number1, sizeof(int), 1, resultFile);
        fseek(firstFile, -size*i, SEEK_END);
        fgetpos(firstFile, &check);
        if (check <= 0)
        {
            break;
        }
        fread(&number1, sizeof(int), 1, firstFile);
        i++;
    }
    fclose(resultFile);
    fclose(secondFile);
    fclose(firstFile);

    //output content from result file

    resultFile = fopen("Result_File.bin", "rb");
    if (resultFile == NULL)
    {
        perror("Error occured while opening file\n");
        exit(0);
    }
    rewind(resultFile);
    n, indicator = 0;
    printf("Result: \n");
    rewind(resultFile);
    while(!feof(resultFile) && fread(&n, sizeof(int), 1, resultFile) == 1 )
    {
        printf(" %d ", n);
    }
    printf("\n");
    fclose(resultFile);
    return 0;
}

int inputValidation()
{
    int number;
    char c;
    while (scanf("%d%c", &number, &c) !=2 || c != '\n')
    {
        rewind(stdin);
        printf("Please try again\n");
    }
    return number;
}