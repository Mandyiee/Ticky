#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define clearScreen printf("\e[1;1H\e[2J");
#define waitSmall sleep(5);
char board[3][3];
int count = 0;

void printBoard (void);
void choosePlayer(char *player, char *computer);
void computer_play (char move);
void printCurrentBoard (void);
void player_play (char move);
void initializeBoard (void);
char checkWinner();
void showInstructions (void);

int main() {
    clearScreen;
    
    initializeBoard();
    showInstructions();
    
    waitSmall;
    clearScreen;
    
    printBoard();
    
    waitSmall;
    clearScreen;
    
    char computer;
    char player;
    choosePlayer(&player,&computer);
    
    if (computer == 'X') {

        while (count < 9)
        {
          
            computer_play(computer); 
            printCurrentBoard();
            printf("\n Player %c just played \n", computer);
            player_play(player);
            printCurrentBoard();
            printf("\n Player %c just played \n", player);
            //printf("\n %d \n",count);
            
            char winner = checkWinner();
            if (winner != '*') {
              break;
            }
            waitSmall;
          clearScreen;
        }
        
       char winner = checkWinner();
       if (winner == '*') {
        printf("\n It's a tie \n");
        return 0;
       }
       else {
        printf(" \n Player %c wins this round \n", winner);
       }
    } else {

        while (count < 9)
        {
          
            player_play(player);
            printCurrentBoard();
            printf("\n Player %c just played \n", player);
            computer_play(computer); 
            printCurrentBoard();
            printf("\n Player %c just played \n", computer);
            //printf("\n %d \n",count);
            
            char winner = checkWinner();
            if (winner != '*') {
              break;
            }
            waitSmall;
          clearScreen;
        }
        char winner = checkWinner();
       if (winner == '*') {
        printf("\n It's a tie \n");
        return 0;
       }
       else {
        printf("\n Player %c wins this round \n", winner);
        return 0;
       }

    }

}



void initializeBoard (void) {
for (int x = 0; x < 3; x++) {  
 for (int y = 0; y < 3; y++)
 {
     board[x][y] = '*';
  } 
     }
     return;
}

void printBoard (void) {
  printf("Sample Board \n");
  printf(" X | O | X \n");
  printf("------------\n");
  printf(" X | O | X \n");
  printf("------------\n");
  printf(" X | O | X \n");
  printf("\n Read \n");
  return;
}

void printCurrentBoard (void) {
printf("\n");
printf("\n");
printf("------------\n");
 for (int x = 0; x < 3; x++) {
    printf("|");
 for (int y = 0; y < 3; y++)
 {
    printf(" %c |", board[x][y]);
 }
 printf("\n");
  printf("------------\n");
    
 }
return;
}


void choosePlayer(char *player, char *computer) {
    printf("\n Pick A Player \n Pick X or O \n");
   
    scanf("%c",player);

    *computer = (*player == 'X'? 'O' : 'X');

    return;
}

void computer_play (char move) {
    srand(time(NULL));

    
 while (true)
 {
    int x = rand() % 3;
    int y = rand() % 3;

    if (board[x][y] == '*') {
        board[x][y] = move;
        break;
    }
 }   
 count++;
return;
}

void player_play (char move) {
    
printf("\n Input A Location \n");
    
 while (true)
 {
    int x;
    int y;
    scanf("%d-%d", &x, &y);
    
    x--;
    y--;
    
    if (board[x][y] == '*') {
        board[x][y] = move;
        break;
    }

    printf("That move is invalid \n");
 }   
 count++;
return;
}

char checkWinner() {
     //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return '*';
}

void showInstructions (void) {
  printf("\n Hello \n");
  printf("\n This Is A Game Of Tic-Tac-Toe \n");
  printf("\n Use This Keys to Move Around \n");
  printf("  X  |  O  |  X \n");
  printf(" 1-1 | 1-2 | 1-3 \n");
  printf("----------------\n");
  printf("----------------\n");
  printf("  X  |  O  |  X \n");
  printf(" 2-1 | 2-2 | 2-3 \n");
  printf("----------------\n");
  printf("----------------\n");
  printf("  X  |  O  |  X \n");
  printf(" 3-1 | 3-2 | 3-3 \n");
  printf("\n Read \n");
}
