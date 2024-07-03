#include <stdio.h>
#define EMPTY 4
#define ASCII 65
#define NUM_OF_CARDS 11

void game_table_e1(int card_on_table[4][2], int P1_cards[2][NUM_OF_CARDS], int team1, int team2, int set_score1, int set_score2)
{
  int state_sign, k;
  /*Printing the game table with or without cards on it*/
  for (int j = 0; j < 21; j++)
  {
    if (j == 10)
    {
      printf("          P2");
    }
    else
    {
      printf("            ");
    }
    for (int i = 0; i < 52; i++)
    {
      if (j == 0 || j == 20)
      {
        if (i == 25)
        {
          printf("P");
        }
        else if (i == 26 && j == 0)
        {
          printf("3");
        }
        else if (i == 26 && j == 20)
        {
          printf("1");
        }
        else
        {
          printf(" ");
        }
      }
      else if (j == 1 || j == 19)
      {
        printf("-");
      }
      else
      {
        if (i == 0 || i == 51)
        {
          printf("|");
        }
        if (j == 2 && i == 24)
        {
          state_sign = 2;
        }
        else if (j == 18 && i == 24)
        {
          state_sign = 0;
        }
        else if (j == 10 && i == 1)
        {
          state_sign = 1;
        }
        else if (j == 10 && i == 48)
        {
          state_sign = 3;
        }
        else
        {
          state_sign = EMPTY;
        }
        if (state_sign != EMPTY && card_on_table[state_sign][0] != EMPTY)
        {
          printf("%c%2d", card_on_table[state_sign][0] + ASCII, card_on_table[state_sign][1]);
          i += 2;
        }
        else
        {
          printf(" ");
        }
      }
    }
    if (j == 10)
    {
      printf("P4");
    }
    /*show scores*/
    else if (j == 1)
    {
      printf("   team1  round:%d  set point:%d", team1, set_score1);
    }
    else if (j == 19)
    {
      printf("   team2:  round:%d  set point:%d", team2, set_score2);
    }
    printf("\n");
  }
  /*printing User cards*/
  printf("\n\n\n cards | ");
  for (int k = 0; k < NUM_OF_CARDS; k++)
  {
    if (P1_cards[0][k] != EMPTY)
    {
      printf("%c%2d | ", P1_cards[0][k] + ASCII, P1_cards[1][k]);
    }
    else
    {
      printf("    | ");
    }
  }
  printf("\n       ");
  for (k = 0; k < 67; k++)
  {
    printf("-");
  }
  /*Give each card a sign*/
  printf("\n signs | ");
  for (k = 0; k < NUM_OF_CARDS; k++)
  {
    printf(" %2d | ", k);
  }
  printf("\n");
}