#include <stdio.h>
#define EMPTY 4
#define ASCII 65

int play_card_fuser(int card_on_table[][2], int P1_cards[][11], int P234_cards[][11], int bakhshname)
{
    /*In this round, the user plays the first card and we first resive his choice*/
    printf("play your card!\n");
    int P1_choice, j;
    while (card_on_table[0][0] == EMPTY)
    {
        fflush(stdin);
        scanf("%d", &P1_choice);
        if (P1_choice < 11 && P1_choice > -1)
        {
            /*The player is free to play any card he has,the symbol of this card is called "barg-aval" during the code*/
            if (P1_cards[0][P1_choice] == EMPTY)
            {
                printf("this card is not available, play another.\n");
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
            printf("invalid number!\n");
        }
    }
    /*according to barg_aval, choose the cards of other players*/
    for (int i = 1; i < 4; i++)
    {
        int most_one = 0;
        for (j = 0; j < 11; j++)
        {
            if (P234_cards[2 * i - 2][j] == card_on_table[0][0] && P234_cards[2 * i - 1][j] > most_one)
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
    /*clear the selected cards from the player's hands and replace them with the agreed amount of E0*/
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (card_on_table[i][0] == P234_cards[2 * i - 2][j] && card_on_table[i][1] == P234_cards[2 * i - 1][j])
            {
                P234_cards[2 * i - 2][j] = EMPTY;
                P234_cards[2 * i - 1][j] = 0;
                break;
            }
        }
    }
    /*return barg_aval value*/
    return card_on_table[0][0];
}