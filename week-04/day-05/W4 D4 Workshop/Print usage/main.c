#include <stdio.h>
#include <stdlib.h>      //struktúrát létre kell hozni!!! Ez a következõ feladat!
#include <string.h>
#include <conio.h>

void exit(int status);

/*typedef struct Pont {
    char a;
} Pont;
*/

/*void clrscr()
{
    system("@cls||clear");   //Letisztítja a kijelzõt miután az elsõ commandot megadom.
}
*/
void *File(char fp);

int main(void)
{

    printf("*/Todo application\n");
    printf("====================\n");
    printf("Commands:\n");
    printf(" -a   Adds a new task\n");
    printf(" -wr  Write current todos to file\n");
    printf(" -rd  Read todos from a file\n");
    printf(" -l   Lists all the tasks\n");
    printf(" -e   Empty the list\n");
    printf(" -r   Removes a task\n");
    printf(" -c   Completes a task\n");
    printf(" -p   Add priority to a task\n");
    printf(" -lp  Lists all the tasks by priority\n");

    while (1) {

        char buffer[100];
        char* p;
        FILE* fp;
        FILE *fptr;

        printf("Give me your command: ");
        gets(&buffer);
        printf("Your command is: %s\n", buffer);
                                                    //Az strstr() -el keresek rá a -a ra
        if (strstr(buffer, "-a") != NULL) {        //HA NEM A NULL MEGOLDÁST HASZNÁLOM char* pos = strstr(str, substr);  EZ ALÁ: if(pos)
            printf("you entered a vaild option: ");
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
                printf("%s\n", p);
            }
        }

        else if (strstr(buffer, "-wr") != NULL) {
            printf("you entered a vaild option: ");
            fp = fopen("todo.txt", "w");
            fprintf(fptr,"%s",buffer);
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
                printf("%s\n", p);
            }
        }

        else if (strstr(buffer, "-rd") != NULL) {
            printf("you entered a vaild option!");
            fptr = fopen("todo.txt", "r");
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
                printf("%s\n", p);
            }
        }

        else if (strstr(buffer, "-l") != NULL) {
            printf("List by number\n====================\n");
            printf("Num  |  Tasks\n 1\t- Walk the dog\n");
            printf(" 2   \t- Buy milk\n");
            printf(" 3   \t- Do homework\n");
            printf(" 4   \t- Do something\n");
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
                printf("%s\n", p);
            }
        }

        else if (strstr(buffer, "-e") != NULL) {
            printf("you entered a vaild option!");
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
                printf("%s\n", p);
            }
        }

        else if (strstr(buffer, "-r") != NULL) {
            printf("you entered a vaild option!");
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
            printf("%s\n", p);
            }
        }

        else if (strstr(buffer, "-c") != NULL) {
            printf("you entered a vaild option!");
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
                printf("%s\n", p);
            }
        }

        else if (strstr(buffer, "-p") != NULL) {
            printf("you entered a vaild option!");
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
                printf("%s\n", p);
            }
        }

        else if (strstr(buffer, "-lp") != NULL) {
            printf("you entered a vaild option!");
            for (p = strtok(buffer, strstr); p; p = strtok(NULL, strstr)) {
                printf("%s\n", p);
            }
        } else {
            printf("You entered an invaild option!\n");
        fclose(fp);
        exit(0);
        }

   // system("@cls||clear");

    }

    exit(0);

    return 0;
}
