#include <stdio.h>
#include <string.h>

int main()
{
    char line[1000];
    while (fgets(line, sizeof(line), stdin))
    {
        char* token = strtok(line, " \n");
        //Refer to the usage of the strtok()
        //Be aware of its potential risks in multi-threaded environments
        double sum = 0;
        int count = 0;
        int valid = 1;
        while (token != NULL)
        {
            if (strcmp(token, "A") == 0) sum += 4;
            else if (strcmp(token, "B") == 0) sum += 3;
            else if (strcmp(token, "C") == 0) sum += 2;
            else if (strcmp(token, "D") == 0) sum += 1;
            else if (strcmp(token, "F") == 0) sum += 0;
            else
            {
                valid = 0;
                break;
            }
            count++;
            token = strtok(NULL, " \n");
        }
        if (!valid || count == 0)
            printf("Unknown\n");
        else
            printf("%.2f\n", sum / count);
    }
    return 0;
}