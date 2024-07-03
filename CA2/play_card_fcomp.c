#include <stdio.h>
#include "game_table.h"
#define EMPTY 4
#define ASCII 65

int play_card_fcomp(int starter, int card_on_table[][2], int P1_cards[][11], int P234_cards[][11], int bakhshname, int team1, int team2)
{
    /*declear variables and arrays we need.*/
    int j;
    int tedad_na_bakhshname = 0, na_bakhshnameha[2][10];
    int i = (starter + 1) % 4;
    /*In this round, the computer plays the first card and we first separate the cards that are not bakhshname*/
    for (j = 0; j < 11; j++)
    {
        if (P234_cards[2 * starter - 2][j] != bakhshname && P234_cards[2 * starter - 2][j] != EMPTY)
        {
            na_bakhshnameha[tedad_na_bakhshname][1] = P234_cards[2 * starter - 1][j];
            na_bakhshnameha[tedad_na_bakhshname][0] = P234_cards[2 * starter - 2][j];
            tedad_na_bakhshname++;
        }
    }
    /*According to the order of the project, we throw the card of the first player,The symbol of this card is called "barg-aval" during the code*/
    if (tedad_na_bakhshname == 0)
    {
        int most_one = 0;
        for (j = 0; j < 11; j++)
        {
            if (P234_cards[2 * starter - 1][j] > most_one)
            {
                most_one = P234_cards[2 * starter - 1][j];
                card_on_table[starter][0] = P234_cards[2 * starter - 2][j];
                card_on_table[starter][1] = most_one;
            }
        }
    }
    else
    {
        int most_one = 0;
        for (j = 0; j < tedad_na_bakhshname; j++)
        {
            if (na_bakhshnameha[j][1] > most_one)
            {
                most_one = na_bakhshnameha[j][1];
                card_on_table[starter][0] = na_bakhshnameha[j][0];
                card_on_table[starter][1] = most_one;
            }
        }
    }
    /*We receive or select the rest of the cards in clockwise order*/
    while (i != starter)
    {
        /*selecting card*/
        if (i != 0)
        {
            int most_one = 0;
            for (j = 0; j < 11; j++)
            {
                if (P234_cards[2 * i - 2][j] == card_on_table[starter][0] && P234_cards[2 * i - 1][j] > most_one)
                {
                    most_one = P234_cards[2 * i - 1][j];
                    card_on_table[i][0] = P234_cards[2 * i - 2][j];
                    card_on_table[i][1] = most_one;
                }
            }
            int most_bakhshname = 0;
            if (card_on_table[i][0] == EMPTY)
            {
                for (j = 0; j < 11; j++)
                {
                    if (P234_cards[2 * i - 2][j] == bakhshname && P234_cards[2 * i - 1][j] > most_bakhshname)
                    {
                        card_on_table[i][0] = bakhshname;
                        card_on_table[i][1] = P234_cards[2 * i - 1][j];
                        most_bakhshname = P234_cards[2 * i - 1][j];
                    }
                }
            }
            if (card_on_table[i][0] == EMPTY)
            {
                int least_one = 12;
                for (j = 0; j < 11; j++)
                {
                    if (P234_cards[2 * i - 1][j] < least_one && P234_cards[2 * i - 2][j] != EMPTY)
                    {
                        least_one = P234_cards[2 * i - 1][j];
                        card_on_table[i][0] = P234_cards[2 * i - 2][j];
                        card_on_table[i][1] = least_one;
                    }
                }
            }
        }
        /*Receive and place the first player's card*/
        else
        {
            game_table(card_on_table, P1_cards, team1, team2);
            printf("play your card!\n");
            int P1_choice;
            while (card_on_table[0][0] == EMPTY)
            {
                fflush(stdin);
                scanf("%d", &P1_choice);
                if (P1_choice < 11 && P1_choice > -1)
                {
                    if (P1_cards[0][P1_choice] == EMPTY)
                    {
                        printf("this card is not available, play another.\n");
                        continue;
                    }
                    else if (P1_cards[0][P1_choice] != card_on_table[starter][0])
                    {
                        int tedad_barg_aval = 0;
                        for (j = 0; j < 11; j++)
                        {
                            if (P1_cards[0][j] == card_on_table[starter][0])
                            {
                                tedad_barg_aval++;
                                break;
                            }
                        }
                        /*if the player has barg_aval cards, he must throw one of them, otherwise he is allowed to throw anything else*/
                        if (tedad_barg_aval != 0)
                        {
                            printf("choose a card with %c sign!\n", card_on_table[starter][0] + ASCII);
                            continue;
                        }
                        else
                        {
                            card_on_table[0][0] = P1_cards[0][P1_choice];
                            card_on_table[0][1] = P1_cards[1][P1_choice];
                            P1_cards[0][P1_choice] = EMPTY;
                            P1_cards[1][P1_choice] = 0;
                        }
                    }
                    else
                    {
                        card_on_table[0][0] = P1_cards[0][P1_choice];
                        card_on_table[0][1] = P1_cards[1][P1_choice];
                        P1_cards[0][P1_choice] = EMPTY;
                        P1_cards[1][P1_choice] = 0;
                    }
                }
                else
                {
                    printf("invalid number!\n");
                }
            }
        }
        i = (i + 1) % 4;
    }
    /*clear the selected cards from the player's hands and replace them with the agreed amount of E0*/
    for (int k = 1; k < 4; k++)
    {
        for (j = 0; j < 11; j++)
        {
            if (card_on_table[k][0] == P234_cards[2 * k - 2][j] && card_on_table[k][1] == P234_cards[2 * k - 1][j])
            {
                P234_cards[2 * k - 2][j] = EMPTY;
                P234_cards[2 * k - 1][j] = 0;
                break;
            }
        }
    }
    /*returning barg_aval value*/
    return card_on_table[starter][0];
}