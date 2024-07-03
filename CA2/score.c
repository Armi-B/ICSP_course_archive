#include <stdio.h>
#define EMPTY 4

int score(int *team1, int *team2, int card_on_table[][2], int bakhshname, int barg_aval)
{
    /*declear variables and arrays we need.*/
    int round_winner = 0;
    int tedad_bakhshname = 0, kandid_bord[2][4] = {{EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0}};
    int j = 0;
    /*check the presence of bakhshname on the table*/
    for (int i = 0; i < 4; i++)
    {
        if (card_on_table[i][0] == bakhshname)
        {
            tedad_bakhshname++;
            kandid_bord[0][j] = i;
            kandid_bord[1][j] = card_on_table[i][1];
            j++;
        }
    }
    /*according to the number of bakhshnames and barg_avals and the order of the project, determine the winner of the round.*/
    if (tedad_bakhshname == 1)
    {
        round_winner = kandid_bord[0][0];
    }
    else if (tedad_bakhshname > 1)
    {
        int most_one = 0;
        for (int k = 0; k < 4; k++)
        {
            if (kandid_bord[1][k] > most_one)
            {
                most_one = kandid_bord[1][k];
                round_winner = kandid_bord[0][k];
            }
        }
    }
    else
    {
        int most_one = 0;
        for (int i = 0; i < 4; i++)
        {
            if (card_on_table[i][1] > most_one && card_on_table[i][0] == barg_aval)
            {
                most_one = card_on_table[i][1];
                round_winner = i;
            }
        }
    }
    /*add one point to the winner team and announce it to the user*/
    if (round_winner % 2 == 0)
    {
        *team1 += 1;
        printf("your team won this round!\n");
    }
    else if (round_winner % 2 == 1)
    {
        *team2 += 1;
        printf("you didnt win this round!\n");
    }
    for (int m = 0; m < 4; m++)
    {
        card_on_table[m][0] = EMPTY;
        card_on_table[m][1] = 0;
    }
    /*return the number of the winner to the main function as the starter of next possible round*/
    return round_winner;
}