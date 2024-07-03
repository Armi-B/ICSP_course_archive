#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game_table_e1.h"
#define EMPTY 4
#define ASCII 65
#define TRUE 1
#define FALSE 0
#define DOR_AVAL 5
#define DOR_DOVOM 4
#define DOR_SEVOM 2
#define NUM_OF_CARDS 11

void shuffle_card(int *card);
int deal_hand_and_bakhshname_e1(int card_on_table[][2], int P1_cards[][NUM_OF_CARDS], int P234_cards[][NUM_OF_CARDS], int set_score1, int set_score2)
{
    /*declear variables and arrays we need.*/
    int i, j, k, bakhshname = EMPTY;
    /*a whole deck of card*/
    int deck_of_cards[4][NUM_OF_CARDS] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
    int shuffled_card[44];
    shuffle_card(shuffled_card);
    /*Deal five cards to the user and get the bakhshname from*/
    for (i = 0; i < DOR_AVAL; i++)
    {
        int row = shuffled_card[i] / NUM_OF_CARDS;
        int col = shuffled_card[i] % NUM_OF_CARDS;
        P1_cards[0][i] = row;
        P1_cards[1][i] = deck_of_cards[row][col];
    }
    game_table_e1(card_on_table, P1_cards, 0, 0, set_score1, set_score2);
    printf("choose a bakhshname(only capital letter)!\n");
    /*Only the bakhshname that is available in the user's hand is allowed*/
    while (bakhshname == EMPTY)
    {
        char user_choose;
        fflush(stdin);
        scanf("%c", &user_choose);
        bakhshname = (int)user_choose - ASCII;
        int flag = FALSE;
        for (j = 0; j < DOR_AVAL; j++)
        {
            if (P1_cards[0][j] == bakhshname)
            {
                flag = TRUE;
                break;
            }
        }
        if (flag == FALSE)
        {
            bakhshname = EMPTY;
            printf("invalid choice, choose another\n");
        }
    }
    /*Deal the rest of the cards*/
    for (k = 1; k < 4; k++)
    {
        for (j = 0; j < DOR_AVAL; j++)
        {
            int row = shuffled_card[k * DOR_AVAL + j] / NUM_OF_CARDS;
            int col = shuffled_card[k * DOR_AVAL + j] % NUM_OF_CARDS;
            P234_cards[k * 2 - 2][j] = row;
            P234_cards[k * 2 - 1][j] = deck_of_cards[row][col];
        }
    }
    for (i = 20; i < 24; i++)
    {
        int row = shuffled_card[i] / NUM_OF_CARDS;
        int col = shuffled_card[i] % NUM_OF_CARDS;
        P1_cards[0][i - 15] = row;
        P1_cards[1][i - 15] = deck_of_cards[row][col];
    }
    for (k = 1; k < 4; k++)
    {
        for (j = 0; j < 4; j++)
        {
            int row = shuffled_card[(k - 1) * 4 + 24 + j] / NUM_OF_CARDS;
            int col = shuffled_card[(k - 1) * 4 + 24 + j] % NUM_OF_CARDS;
            P234_cards[k * 2 - 2][j + 5] = row;
            P234_cards[k * 2 - 1][j + 5] = deck_of_cards[row][col];
        }
    }
    for (i = 36; i < 38; i++)
    {
        int row = shuffled_card[i] / NUM_OF_CARDS;
        int col = shuffled_card[i] % NUM_OF_CARDS;
        P1_cards[0][i - 27] = row;
        P1_cards[1][i - 27] = deck_of_cards[row][col];
    }
    for (k = 1; k < 4; k++)
    {
        for (j = 0; j < 2; j++)
        {
            int row = shuffled_card[(k - 1) * 2 + 38 + j] / NUM_OF_CARDS;
            int col = shuffled_card[(k - 1) * 2 + 38 + j] % NUM_OF_CARDS;
            P234_cards[k * 2 - 2][j + 9] = row;
            P234_cards[k * 2 - 1][j + 9] = deck_of_cards[row][col];
        }
    }
    /*returning the value of bakhshname as 0, 1, 2, and 3 */
    return bakhshname;
}

void shuffle_card(int *card)
{
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--)
    {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}