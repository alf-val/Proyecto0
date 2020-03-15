#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define BOARD_SIZE 5
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_board(char board[BOARD_SIZE][BOARD_SIZE]){
    int cell = 0;
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE]){
    //board = board;
    char winner = '-';
    int contador = 1;

    for(int i = 0; i < BOARD_SIZE; i++){
      contador = 1;
      for(int j = 1; j < BOARD_SIZE; j++){
        if (board[i][j] == board[i][0] && board[i][j] != '-'){
          contador++;
        }
      }
      if (contador == BOARD_SIZE){
        winner = board[i][0];
      }
    }

    for(int i = 0; i < BOARD_SIZE; i++){
      contador = 1;
      for(int j = 1; j < BOARD_SIZE; j++){
        if (board[j][i] == board[0][i] && board[j][i] != '-'){
          contador++;
        }
      }
      if (contador == BOARD_SIZE){
        winner = board[0][i];
      }
    }

    contador = 1;
    for(int i = 1; i < BOARD_SIZE; i++){
      if (board[i][i] == board[0][0] && board[i][i] != '-'){
        contador++;
        printf("Contador: %d\n", contador );
      }
      if (contador == BOARD_SIZE){
        winner = board[0][0];
      }
    }

    contador = 1;
    for(int i = 1; i < BOARD_SIZE; i++){
      if (board[i][BOARD_SIZE - 1 - i] == board[0][BOARD_SIZE - 1] && board[0][BOARD_SIZE - 1] != '-'){
        contador++;
      }
      if (contador == BOARD_SIZE){
        winner = board[0][BOARD_SIZE - 1];
      }
    }

    return winner;
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE]){
    //board = board;
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] == '-'){
                return true;
            }
        }
    }

    return false;
}

int main(void){
    printf("TicTacToe \n");

    char board[BOARD_SIZE][BOARD_SIZE];
    // char board[BOARD_SIZE][BOARD_SIZE] = {
    //     { '-', '-', '-' },
    //     { '-', '-', '-' },
    //     { '-', '-', '-' }
    // };

    for (int i = 0; i < BOARD_SIZE; i++){
      for (int j = 0; j < BOARD_SIZE; j++){
        board[i][j] = '-';
      }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
