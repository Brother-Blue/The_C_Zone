/* ====================================
 File name: exerc_2_8.c
 Date: 2021-02-02
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Demonstration code: [6197]
 ====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

int human_choice(int pile);

void write_winner(int player);

int play_again();

/* ---------------- Logic ----------------*/

int computer_choice(int pile);

int toggle(int player);

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
  int pile,    /* This is how many coins we have */
      player,  /* Who is playing? */
      n_coins; /* Number of coins taken */
  
  pile = MAX_COINS; /* Set start values (= init) */
  player = HUMAN;

  srand(time(0)); /* Setup random */
  printf("\n\n-----------------------------------------\n  ~~~~ Welcome to NIM by Group 30 ~~~~~\n-----------------------------------------\n\n");

  /* 
   *  Program main loop 
   */
  while (true)
  {
    // prints the amount of coins in pile
    printf("There are %d coins in the pile\n\n", pile);
    //checks if player is == HUMAN, if it is call the human_choice function else call the computer_choice function
    if (player == HUMAN)
    {
      n_coins = human_choice(pile);
      printf("You took %d coins\n", n_coins);
    }
    else
    {
      n_coins = computer_choice(pile);
      printf("Computer took %d coins\n", n_coins);
    }
    //updates the value of pile
    pile -= n_coins;
    // checks if pile is <=1 and prints the winner if it is.
    if (pile <= 1)
    {
      write_winner(player);
      //calls the play_again function and either continues the game or breaks out of the loop.
      if (play_again()) {
        pile = MAX_COINS;
        player = HUMAN;
        continue;
      } else {
        break;
      }
    }
    else
    {
      player = toggle(player);
    }
  }
  /*
   * end main loop
   */
  printf("\n\n-----------------------------------------\n   ~~~~~   Thanks for playing   ~~~~~ \n-----------------------------------------\n\n");

  return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/

void clear_stdin()
{
  while (getchar() != '\n')
  {
    ;
  }
}

// Convert chars to int values
int charToInt(char c)
{
  return (int)c - '0';
}

int human_choice(int pile)
{
  char choice[2];
  while (1)
  {
    // Get user input
    printf("Enter your choice (1-3):\n>> ");
    fgets(choice, 2, stdin);
    // Convert the number char to an int
    int c = charToInt(choice[0]);
    clear_stdin();
    // Verify it is a valid input
    if (c < 1 || c > 3 || c > pile-1)
    {
      printf("The value must be between 1-3 and less than the pile.\n");
      continue;
    }
    else
    {
      return c;
    }
  }
}
// calculates and returns the computers choice
int computer_choice(int pile)
{
  //returns 1,2 or 3 unless pile is <=4 in which case it will return the best choice, eg. pile=4 return =3 
  int compChoice = rand() % 3 + 1; // Between 1-3
  return pile <= 4 ? pile - 1 : compChoice;
}

//prints the winner of the game
void write_winner(int player)
{
  if (player == HUMAN)
  {
    printf("The human wins!\n");
  }
  else
  {
    printf("The computer wins!\n");
  }
}

int play_again()
{
  char choice[2];
  while (1)
  {
    printf("Do you wish to play again?\nWrite n/N to exit, or any key to play again.\n");
    fgets(choice, 2, stdin);
    clear_stdin();
    if (choice[0] == 'n' || choice[0] == 'N')
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
}

int toggle(int player)
{
  return player == HUMAN ? 1 : 0;
}
