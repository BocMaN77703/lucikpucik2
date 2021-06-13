//--------------------------Дано 2 текстовых файла, отсортированных по возрастанию. Сделать один, отсортированный по убыванию.



#include <stdio.h>

int main()
{
    FILE* firstFile, * secondFile, * resultFile;
    int number1, number2, resultNumber;
    fpos_t check1, check2;
    int i1 = 1;
    int i2 = 1;

    // First file initialization
//    printf("\t\t\tFirst File initialization\n");
//    firstFile = fopen("FirstFile.txt", "w+");
//    rewind(firstFile);
//    printf("Enter a number\n");
//    scanf("%d", &number1);
//    while (number1 != 999)
//    {
//        fprintf(firstFile, "%3d", number1);
//        printf("Enter a number\n");
//        scanf("%d", &number1);
//        if (number1 == 999)
//        {
//            break;
//        }
//
//    }
//    fclose(firstFile);
//
//    //Second File initialization
//    printf("\t\t\tSecond File initialization\n");
//    secondFile = fopen("SecondFile.txt", "w+");
//    rewind(secondFile);
//    printf("Enter a number\n");
//    scanf("%d", &number2);
//    while (number2 != 999)
//    {
//        fprintf(secondFile, "%3d", number2);
//        printf("Enter a number\n");
//        scanf("%d", &number2);
//        if (number2 == 999)
//        {
//            break;
//        }
//
//    }
//    fclose(secondFile);

    //result File
    printf("\t\t\tResult file\n");
    firstFile = fopen("FirstFile.txt", "r");
    secondFile = fopen("SecondFile.txt", "r");
    resultFile = fopen("Result2.txt", "w+");
    if (resultFile == NULL)
    {
        printf("File was not created\n");
        return 0;
    }
    rewind(resultFile);
    fseek(firstFile, -3 * i1, SEEK_END);
    fseek(secondFile, -3 * i2, SEEK_END);
    i1++;
    i2++;
    fgetpos(firstFile, &check1);
    fgetpos(secondFile, &check2);
    fscanf(firstFile, "%d", &number1);
    fscanf(secondFile, "%d", &number2);
    while (check1 > 0 && check2 > 0)
    {
        while (number1 > number2)
        {
            fprintf(resultFile, "%3d", number1);
            fseek(firstFile, -3 * i1, SEEK_END);
            fgetpos(firstFile, &check1);
            if (check1 < 0)
            {
                break;
            }
            fscanf(firstFile, "%d", &number1);
            i1++;
        }
        while (number1 <= number2)
        {
            fprintf(resultFile, "%3d", number2);
            fseek(secondFile, -3 * i2, SEEK_END);
            fgetpos(secondFile, &check2);
            if (check2 < 0)
            {
                break;
            }
            fscanf(secondFile, "%d", &number2);
            i2++;
        }
    }
    while (check1 > 0)
    {
        fprintf(resultFile, "%3d", number1);
        fseek(firstFile, -3 * i1, SEEK_END);
        fgetpos(firstFile, &check1);
        if (check1 < 0)
        {
            break;
        }
        fscanf(firstFile, "%d", &number1);
        i1++;
    }
    while (check2 > 0)
    {
        fprintf(resultFile, "%3d", number2);
        fseek(secondFile, -3 * i2, SEEK_END);
        fgetpos(secondFile, &check2);
        if (check2 < 0)
        {
            break;
        }
        fscanf(secondFile, "%d", &number2);
        i2++;
    }
    fclose(resultFile);
    fclose(secondFile);
    fclose(firstFile);

    /*resultFile = fopen("Result.txt", "r");
    rewind(resultFile);
    while (!feof(resultFile))
    {
        fscanf(resultFile, "%d", &resultNumber);
    }
    fclose(resultFile);*/
    return 0;
}
