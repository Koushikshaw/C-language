#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    char name[10];
    int comp = 0;
    int client = 0;
    printf("\t\t ROCK PAPER AND SCISSORS\t\t\n\n");
    printf("Enter your name for the game :");
    scanf("%s", &name);
    printf("\t\tPLAYER DETAILS : \n Player 1 : %s \n Player 2 : Computer\n");
    for (int i = 0; i < 3; i++)
    {
        int v;
        printf("\t\tGAME NO.%d : \nPlayer 1 : %s\n", (i + 1), name);
        printf("Choose Your Option(Enter a number) :\n1.Rock\n2.Paper\n3.Scissors\n ");
        scanf("%d", &v);
        if (v == 1)
        {
            printf("%s chooses Rock\n", name);
            int e = rand() % 3;
            if (e == 0)
            {
                printf("Computer chooses Rock\n");
                printf("Its a Tie\n");
            }
            else if (e == 1)
            {
                printf("Computer chooses Paper\n");
                printf("Computer Wins\n");
                comp++;
            }
            else if (e == 2)
            {
                printf("Computer chooses Scissors\n");
                printf("%s wins\n", name);
                client++;
            }
        }
        else if (v == 2)
        {
            printf("%s chooses Paper\n", name);
            int e = rand() % 3;
            if (e == 0)
            {
                printf("Computer chooses Rock\n");
                printf("%s wins\n", name);
                client++;
            }
            else if (e == 1)
            {
                printf("Computer chooses Paper\n");
                printf("Its a Tie\n");
            }
            else if (e == 2)
            {
                printf("Computer chooses Scissors\n");
                printf("Computer wins\n");
                comp++;
            }
        }
        else if (v == 3)
        {
            printf("%s chooses Scissors\n", name);
            int e = rand() % 3;
            if (e == 0)
            {
                printf("Computer chooses Rock\n");
                printf("Computer Wins\n");
                comp++;
            }
            else if (e == 1)
            {
                printf("Computer chooses Paper\n");
                printf("%s Wins\n", name);
                client++;
            }
            else if (e == 2)
            {
                printf("Computer chooses Scissors\n");
                printf("Its a tie\n");
            }
        }
    }
    int num1, num2;
    num1 = client;
    num2 = comp;
    printf("\t\tTHE FINAL SCORES ARE HERE : \n");
    printf("PLAYER 1: %s scored %d points\n", name, num1);
    printf("PLAYER 2: Computer scored %d points\n", num2);
    if (num1 > num2)
    {
        printf("\t\t%s finally wins the game\n", name);
    }
    else if (num2 > num1)
    {
        printf("\t\tComputer Finally Wins the game\n");
    }
    else
    {
        printf("Its a tie\n");
    }
    printf("The programm is Ending ....\n");
    return 0;
}