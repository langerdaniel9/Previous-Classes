#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30
#define MAX_NUMBER_OF_STEPS 30

/// Header File ///

// Project Members: Daniel Langer, Alan George, and Kenneth Procacci //

//--------------------------------
typedef struct coord
{
    int x;
    int y;
} coord;

char *mazeArray;
int *deedArray;
int *pheromoneArray;

int x_dim = 0, y_dim = 0;
coord currentPos;
int priority = 0;
int steps = 0;
int deedTotal = 0;
int srandCall = 0;

int left = 0, right = 0, up = 0, down = 0;

coord stack[MAX_SIZE];
int stackPosition = 0;

FILE *output;
FILE *input;
FILE *intelligence;
//--------------------------------

// 17 main functions //
void MARK();

void MOVE_F();

void MOVE_B();

void MOVE_L();

void MOVE_R();

int CWL();

int CWR();

int CWF();

int CWB();

void PUSH();

void POP();

coord PEEK();

void CLEAR();

void BACKTRACK();

void BJPI();

void CJPI();

void RP();
//--------------------------------

// Other functions //
void findDims();

void createArrays();

void scan();

void findStart();

void checkIfOnDeed();

void printMaze();

void printDeed();

void printPheromone();

void finished();
//--------------------------------
