#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game_table_e1.h"
#include "play_card_fcomp_e1.h"
#include "play_card_fuser.h"
#include "score.h"
#include "deal_hand_and_bakhshname_e1.h"
#define EMPTY 4
#define ASCII 65
#define TRUE 1
#define FALSE 0

int main()
{

    int card_on_table[4][2] = {{EMPTY, 0}, {EMPTY, 0}, {EMPTY, 0}, {EMPTY, 0}};
    int P1_card[2][11] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int P234_card[6][11] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int team1 = 0, team2 = 0, starter = 0, set_score1 = 0, set_score2 = 0;
    int bakhshname, barg_aval, i;
    char enter;
    /*start a game*/
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
    for (i = 0; i < 5; i++)
    {
        /*start rounds*/
        team1 = 0;
        team2 = 0;
        system("cls");
        bakhshname = deal_hand_and_bakhshname_e1(card_on_table, P1_card, P234_card, set_score1, set_score2);
        system("cls");
        while (team1 != 6 && team2 != 6)
        {
            /*play each round and play cards*/
            if (starter == 0)
            {
                game_table_e1(card_on_table, P1_card, team1, team2, set_score1, set_score2);
                barg_aval = play_card_fuser(card_on_table, P1_card, P234_card, bakhshname);
                system("cls");
            }
            else
            {
                barg_aval = play_card_fcomp_e1(starter, card_on_table, P1_card, P234_card, bakhshname, team1, team2, set_score1, set_score2);
                system("cls");
            }
            /*calculate each round's score*/
            game_table_e1(card_on_table, P1_card, team1, team2, set_score1, set_score2);
            starter = score(&team1, &team2, card_on_table, bakhshname, barg_aval);
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
        /*calculate each set's score*/
        if (team2 == 6)
        {
            if (team1 == 0)
            {
                set_score2 += 2;
            }
            else
            {
                set_score2++;
            }
            printf("team1:%d , team2:%d team2 won this set!:)\n", team1, team2);
        }
        else if (team1 == 6)
        {
            if (team2 == 0)
            {
                set_score1 += 2;
            }
            else
            {
                set_score1++;
            }
            {
                printf("team1:%d , team2:%d your team won this set!:)\n", team1, team2);
            }
        }
        bakhshname = EMPTY;
        for (int j = 0; j < 4; j++)
        {
            card_on_table[j][0] = EMPTY;
            card_on_table[j][1] = 0;
        }
        for (int k = 0; k < 11; k++)
        {
            P1_card[0][k] = EMPTY;
            P1_card[1][k] = 0;
            P234_card[0][k] = EMPTY;
            for (int j = 1; j < 4; j++)
            {
                P234_card[2 * j - 2][k] = EMPTY;
                P234_card[2 * j - 1][k] = 0;
            }
        }
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
    }
    /*print the game result*/
    if (set_score1 > set_score2)
    {
        printf("your team won this game!");
    }
    else
    {
        printf("team2 won this game!");
    }
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
    /*compile it with gcc play_card_fcomp_e1.c main-e1.c play_card_fuser.c score.c game_table_e1.c deal_hand_and_bakhshname_e1.c -o main-e1  or use executable file*/
    return 0;
}