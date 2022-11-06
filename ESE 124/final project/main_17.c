#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/// 17 - Functions File ///

// Project Members: Daniel Langer, Alan George, and Kenneth Procacci //

void MARK()
{
	pheromoneArray[currentPos.x + currentPos.y * x_dim] = 1;
	fprintf(output, "MARK\t\tMarked spot (%i, %i)\n", currentPos.x, currentPos.y);
}

void MOVE_F()
{
	// Move up one spot (↑) and mark previous square
	if (steps < MAX_NUMBER_OF_STEPS)
	{
		if (CWF())
		{
			steps++;
			MARK();
			currentPos.y -= 1;
			fprintf(output, "MOVE_F\t\tMoved up to (%i, %i) | Step Count = %i\n", currentPos.x, currentPos.y, steps);
			checkIfOnDeed();
		}
	}
}

void MOVE_B()
{
	// Move down one spot (↓) and mark previous square
	if (steps < MAX_NUMBER_OF_STEPS)
	{
		if (CWB())
		{
			steps++;
			MARK();
			currentPos.y += 1;
			fprintf(output, "MOVE_B\t\tMoved down to (%i, %i) | Step Count = %i\n", currentPos.x, currentPos.y, steps);
			checkIfOnDeed();
		}
	}
}

void MOVE_L()
{
	// Move left one spot (←) and mark previous square
	if (steps < MAX_NUMBER_OF_STEPS)
	{
		if (CWL())
		{
			steps++;
			MARK();
			currentPos.x -= 1;
			fprintf(output, "MOVE_L\t\tMoved left to (%i, %i) | Step Count = %i\n", currentPos.x, currentPos.y, steps);
			checkIfOnDeed();
		}
	}
}

void MOVE_R()
{
	// Move right one spot (→) and mark previous square
	if (steps < MAX_NUMBER_OF_STEPS)
	{
		if (CWR())
		{
			steps++;
			MARK();
			currentPos.x += 1;
			fprintf(output, "MOVE_R\t\tMoved right to (%i, %i) | Step Count = %i\n", currentPos.x, currentPos.y, steps);
			checkIfOnDeed();
		}
	}
}

int CWL() // check left
{
	if (mazeArray[(currentPos.x + (currentPos.y * x_dim)) - 1] == ' ' && pheromoneArray[(currentPos.x + (currentPos.y * x_dim)) - 1] == 0)
	{
		fprintf(output, "CWL\t\tLeft of (%i, %i) is empty\n", currentPos.x, currentPos.y);
		left = 1;
		return 1;
	}
	fprintf(output, "CWL\t\tLeft of (%i, %i) is occupied\n", currentPos.x, currentPos.y);
	left = 0;
	return 0;
}

int CWR() // check right
{
	if (mazeArray[(currentPos.x + (currentPos.y * x_dim)) + 1] == ' ' && pheromoneArray[(currentPos.x + (currentPos.y * x_dim)) + 1] == 0)
	{
		fprintf(output, "CWR\t\tRight of (%i, %i) is empty\n", currentPos.x, currentPos.y);
		right = 1;
		return 1;
	}
	fprintf(output, "CWR\t\tRight of (%i, %i) is occupied\n", currentPos.x, currentPos.y);
	right = 0;
	return 0;
}

int CWF() // check up
{
	if (mazeArray[(currentPos.x + (currentPos.y * x_dim)) - x_dim] == ' ' && pheromoneArray[(currentPos.x + (currentPos.y * x_dim)) - x_dim] == 0)
	{
		fprintf(output, "CWF\t\tUp of (%i, %i) is empty\n", currentPos.x, currentPos.y);
		up = 1;
		return 1;
	}
	fprintf(output, "CWF\t\tUp of (%i, %i) is occupied\n", currentPos.x, currentPos.y);
	up = 0;
	return 0;
}

int CWB() // check down
{
	if (mazeArray[(currentPos.x + (currentPos.y * x_dim)) + x_dim] == ' ' && pheromoneArray[(currentPos.x + (currentPos.y * x_dim)) + x_dim] == 0)
	{
		fprintf(output, "CWB\t\tDown of (%i, %i) is empty\n", currentPos.x, currentPos.y);
		down = 1;
		return 1;
	}
	fprintf(output, "CWB\t\tDown of (%i, %i) is occupied\n", currentPos.x, currentPos.y);
	down = 0;
	return 0;
}

void PUSH()
{
	// If stack is full, clear it and continue adding the value
	if (stackPosition == MAX_SIZE)
	{
		CLEAR();
	}
	// Add a value to the top of the stack
	int i;
	stack[stackPosition] = currentPos;
	stackPosition++;
	fprintf(output, "PUSH\t\tPushed (%i, %i) to stack\n", currentPos.x, currentPos.y);
	fprintf(output, "Stack is now: ");
	for (i = 0; i < stackPosition; i++)
	{
		coord stackPos = stack[i];
		fprintf(output, "(%i, %i) ", stackPos.x, stackPos.y);
	}
	fprintf(output, "\n");
}

void POP()
{
	// Remove the element at the top of the stack
	int i;
	stackPosition--;
	fprintf(output, "\tPOP Popped top of stack\n");
	fprintf(output, "Stack is now: ");
	for (i = 0; i < stackPosition; i++)
	{
		coord stackPos = stack[i];
		fprintf(output, "(%i, %i) ", stackPos.x, stackPos.y);
	}
	fprintf(output, "\n");
}

coord PEEK()
{
	// Return the value at the top of the stack
	int i;
	fprintf(output, "\tPEEK Peeked (%i, %i) from top of stack\n", stack[stackPosition - 1].x, stack[stackPosition - 1].y);
	return stack[stackPosition - 1];
}

void CLEAR()
{
	// Remove all elements currently stored in the stack
	stackPosition = 0;
	int i;
	fprintf(output, "CLEAR\t\tCleared stack\n");
	fprintf(output, "Stack is now: ");
	for (i = 0; i < stackPosition; i++)
	{
		coord stackPos = stack[i];
		fprintf(output, "(%i, %i) ", stackPos.x, stackPos.y);
	}
	fprintf(output, "\n");
}

void BACKTRACK()
{
	// Only gets called if there are no more immediate possible moves, so if there is nothing stored in the stack then there are no moves left at all
	if (stackPosition == 0)
	{
		MARK();
		finished();
	}
	if (steps < MAX_NUMBER_OF_STEPS)
	{
		steps++;
		MARK();
		fprintf(output, "BACKTRACK\tUsing PEEK:\n");
		coord jumpTo = PEEK();
		fprintf(output, "BACKTRACK\tUsing POP:\n");
		POP();
		currentPos.x = jumpTo.x, currentPos.y = jumpTo.y;
		fprintf(output, "BACKTRACK\tMoving back to peeked position (%i, %i) | Step Count = %i\n", currentPos.x, currentPos.y, steps);
	}
}

void BJPI()
{
	if (steps < MAX_NUMBER_OF_STEPS)
	{
		if (CWL() == 1)
		{
			MARK();
			// i represents the number of spaces jumped over, or the number of consecutive CW functions used
			int i = 1;

			while (mazeArray[(currentPos.x + (currentPos.y * x_dim)) - i] == ' ' && pheromoneArray[(currentPos.x + (currentPos.y * x_dim)) - i] == 0)
			{
				i++;
			}
			currentPos.y -= i;
			checkIfOnDeed();
			steps++;

			return;
		}
		else if (CWR() == 1)
		{
			MARK();
			int i = 1;
			while (mazeArray[(currentPos.x + (currentPos.y * x_dim)) + i] == ' ' && pheromoneArray[(currentPos.x + (currentPos.y * x_dim)) + i] == 0)
			{
				i++;
			}
			currentPos.y += i;
			checkIfOnDeed();
			steps++;

			return;
		}
		else if (CWF() == 1)
		{
			MARK();
			int i = 1;
			while (mazeArray[(currentPos.x + (currentPos.y * x_dim)) - (x_dim * i)] == ' ' && pheromoneArray[(currentPos.x + (currentPos.y * x_dim)) - (x_dim * i)] == 0)
			{
				i++;
			}
			currentPos.x += i;
			checkIfOnDeed();
			steps++;

			return;
		}
		else if (CWB() == 1)
		{
			MARK();
			int i = 1;
			while (mazeArray[(currentPos.x + (currentPos.y * x_dim)) + (x_dim * i)] == ' ' && pheromoneArray[(currentPos.x + (currentPos.y * x_dim)) + (x_dim * i)] == 0)
			{
				i++;
			}
			currentPos.x -= i;
			checkIfOnDeed();
			steps++;

			return;
		}

		fprintf(output, "BJPI ()\n");
	}
}

void CJPI()
{
	// If there are more than 1 possible moves, save this coordinate to come back to later
	if (left + up + right + down > 1)
	{
		fprintf(output, "Multiple paths detected\n");
		PUSH();
	}
	if (steps < MAX_NUMBER_OF_STEPS)
	{
		if (left)
		{
			MOVE_L;
		}
		else if (right)
		{
			MOVE_R;
		}
		else if (up)
		{
			MOVE_F;
		}
		else if (down)
		{
			MOVE_B;
		}
	}
}

void RP()
{

	int i;
	for (i = 0; i < t; i++)
	{
		// Parse through line and execute that action
	}
}
