#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game_table.h"
#include "play_card_fcomp.h"
#include "play_card_fuser.h"
#include "score.h"
#include "deal_hand_and_bakhshname.h"
#define EMPTY 4
#define ASCII 65
#define TRUE 1
#define FALSE 0

int main()
{
    /*declear variables and arrays we need.*/
    int card_on_table[4][2] = {{EMPTY, 0}, {EMPTY, 0}, {EMPTY, 0}, {EMPTY, 0}};
    int P1_card[2][11] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int P234_card[6][11] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int team1 = 0, team2 = 0, starter = 0;
    int bakhshname, barg_aval;
    char enter;
    /*start of application*/
    while (TRUE)
    {
        printf("if you are ready press enter!^-^\n");
        fflush(stdin);
        scanf("%c", &enter);
        if (enter == '\n')
        {
            break;
        }
    }
    system("cls");
    /*dealing the cards among players and selecting bakhshname by calling its function*/
    bakhshname = deal_hand_and_bakhshname(card_on_table, P1_card, P234_card);
    system("cls");
    /*start of the game and continue it until a team receive 6 score*/
    while (team1 != 6 && team2 != 6)
    {
        /*laying the cards on the table*/
        if (starter == 0)
        {
            game_table(card_on_table, P1_card, team1, team2);
            barg_aval = play_card_fuser(card_on_table, P1_card, P234_card, bakhshname);
            system("cls");
        }
        else
        {
            barg_aval = play_card_fcomp(starter, card_on_table, P1_card, P234_card, bakhshname, team1, team2);
            system("cls");
        }
        /*calculations of game round points*/
        game_table(card_on_table, P1_card, team1, team2);
        starter = score(&team1, &team2, card_on_table, bakhshname, barg_aval);
        /*get the user's cansent to end the round.*/
        while (TRUE)
        {
            printf("press enter to continue!\n");
            fflush(stdin);
            scanf("%c", &enter);
            if (enter == '\n')
            {
                break;
            }
        }
        system("cls");
    }
    /*annoucing the winner*/
    if (team1 == 6)
    {
        printf("team1:%d , team2:%d your team won this game!:)\n",team1,team2);
    }
    else
    {
        printf("team1:%d , team2:%d team2 won this game!:)\n",team1,team2);
    }
    /*get the user's consent to exit.*/
    while (TRUE)
    {
        printf("press ENTER to exit\n");
        fflush(stdin);
        scanf("%c", &enter);
        if (enter == '\n')
        {
            break;
        }
    }
    /*compile it with gcc play_card_fcomp.c main.c play_card_fuser.c score.c game_table.c deal_hand_and_bakhshname.c -o main  or use executable file*/
    return 0;
}