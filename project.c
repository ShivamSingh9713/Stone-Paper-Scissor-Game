#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char char1, char char2)
{
    //For Rock Paper Scissor - Return 1 if c1>c2 and othewise return 0.If c1==c2 it will return -1
    if (char1 == char2)
    {
        return -1;
    }
     else if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }
     else if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }
     else if ((char1 == 's') && (char2 == 'p')) 
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}
int main()
{   
    int Playerscore = 0, Computerscore = 0, temp;
    char Playerchar, Compchar;
    char arr[] = {'r', 'p', 's'};
    printf("===============================================================================================\n\n");
    printf("Wellcome to the Rock-Paper-Scissors Game.\n\n");

    for (int i = 0; i < 3; i++)
    {
        //Taking Player input
        printf("Player Turn:\n");
        printf("Choose 1 for Rock   Choose 2 for Paper   Choose 3 for Scissor\n ");
        scanf("%d", &temp);
        getchar();
        Playerchar = arr[temp - 1];
        printf("You Choose %c\n\n", Playerchar);

        // Generate Computer input
        printf("Computer Turn:\n");
       
        temp = generateRandomNumber(3) + 1;
        Compchar = arr[temp - 1];
        printf("Computer Choose %c\n", Compchar);

        //Compares the scores
        if (greater(Compchar , Playerchar) == 1)
        {
            Computerscore += 1;
        }
        else if (greater(Compchar , Playerchar) == -1)
        {
            Computerscore += 1;
            Playerscore += 1;
        }
        else
        {
           Playerscore += 1;
        }
    
        printf("\t\t\t\t\t\t\t\t\t\tScore Board:\n\t\t\t\t\t\t\t\t\t\tYOU: %d\n\t\t\t\t\t\t\t\t\t\tCPU: %d\n\n", Playerscore, Computerscore);
        printf("=================================================================================================\n");
    }

    if (Playerscore > Computerscore)
    {
        printf("\t\t\t\t******** WOW! You have won the game! ********\n");
    }
    else if (Playerscore < Computerscore)
    {
        printf("\t\t\t\t******** Oh! You have lost the game! ********\n");
    }
    else
    {
        printf("\t\t\t\t******** Game Draw! ********\n");
    }
    return 0;
}