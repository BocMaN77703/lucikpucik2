#include <stdio.h>
#include <stdbool.h>
#include <io.h>
int main()
{
    int number;
    FILE* file;
    fpos_t position1, position2;
    int number1, number2;
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
    rewind(file);
    position1 = filelength(fileno(file));
    fseek(file, 2, 0);
    while (!isQuite)
    {
        fgetpos(file, &position1);
        fscanf(file, "%d", &number1);
        if (feof(file))
        {
            isQuite = true;
        }
        position2 = position1-2;
        fsetpos(file, &position2);
        while(position2>=0)
        {
//            isQuite = false;
            fgetpos(file, &position2);
            fscanf(file, "%d", &number2);
            if(feof(file))
                break;
            if(number2>number1)
            {
                position2+=2;
                fsetpos(file, &position2);
                fprintf(file, "%2d", number2);
                position2-=2;
            }
            else
            {
//                isQuite = true;
                    break;
            }
            position2 -=2;
            if(position2 >= 0)
            {
                fsetpos(file, &position2);
            }
        }
        position2 +=2;
        fsetpos(file, &position2);
        fprintf(file, "%2d", number1);
        position1 +=2;
        if(position1>=filelength(fileno(file)))
        {
            isQuite = true;
        }
        fsetpos(file, &position1);
    }



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
