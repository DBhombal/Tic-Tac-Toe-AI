#include <stdio.h>
#include <conio.h>

char mark;
char grid[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int hasStarted,player,choice, i, winMove;

//Will print the game board with marks and labels
void board()
{
	// if(hasStarted == 1)
		// system("cls");   
	
	printf("   Tic Tac Toe\n\n");
	//Printf("You are X | CPU is O\n\n\n");

	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", grid[1], grid[2], grid[3]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", grid[4], grid[5], grid[6]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", grid[7], grid[8], grid[9]);

	printf("     |     |     \n\n");

	hasStarted = 1;
}

void start()
{
	char name[100];
	printf("Enter your name  | Press Enter when you are done \n\n");
	fgets(name, sizeof(name), stdin);
	printf("Hello %s\n\n\n", name);
}

/************************************************************************
1 = finished game               0 = Cpu                  -1 = In progress
************************************************************************/
int winCheck()
{
	//Horizontal Check
	if (grid[1] == grid[2] && grid[2] == grid[3])
		return 1;
	else if (grid[4] == grid[5] && grid[5] == grid[6])
		return 1;
	else if (grid[7] == grid[8] && grid[8] == grid[9])
		return 1;

	//Vertical Check
	else if (grid[1] == grid[4] && grid[4] == grid[7])
		return 1;
	else if (grid[2] == grid[5] && grid[5] == grid[8])
		return 1;
	else if (grid[3] == grid[6] && grid[6] == grid[9])
		return 1;

	//Diagonal Check
	else if (grid[1] == grid[5] && grid[5] == grid[9])
		return 1;
	else if (grid[7] == grid[5] && grid[5] == grid[3])
		return 1;

	//Tie Check
	//Checks if all 9 positions have been changed from the numbers without a winner
	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3'
		&& grid[4] != '4' && grid[5] != '5' && grid[6] != '6'
		&& grid[7] != '7' && grid[8] != '8' && grid[9] != '9')
		return 0;

	//Keeps the game running
	else
		return -1;
}


void winTurn()
{
	//Will check for a winning move every turn
	winMove = 1; 

	/********************************************************
	There are 8 combinations in which one can win
	And 24 possible ways it can happen (3 different tiles per)
	All of which need to be covered
	********************************************************/

	if (winMove == 1)
	{
		//Row 1 Horizontal Check
		if ((grid[1] == 'O' && grid[2] == 'O') && grid[3] == '3')
		{
			grid[3] = mark;
			winMove = 1;
		}

		else if ((grid[1] == 'O' && grid[3] == 'O') && grid[2] == '2')
		{
			grid[2] = mark;
			winMove = 1;
		}
		else if ((grid[2] == 'O' && grid[3] == 'O') && grid[1] == '1')
		{
			grid[1] = mark;
			winMove = 1;
		}


		//Row 2 Horizontal Check
		else if ((grid[4] == 'O' && grid[5] == 'O') && grid[6] == '6')
		{
			grid[6] = mark;
			winMove = 1;
		}

		else if ((grid[4] == 'O' && grid[6] == 'O') && grid[5] == '5')
		{
			grid[5] = mark;
			winMove = 1;
		}

		else if ((grid[5] == 'O' && grid[6] == 'O') && grid[4] == '4')
		{
			grid[4] = mark;
			winMove = 1;
		}


		//Row 3 Horizontal Check
		else if ((grid[7] == 'O' && grid[8] == 'O') && grid[9] == '9')
		{
			grid[9] = mark;
			winMove = 1;
		}

		else if ((grid[7] == 'O' && grid[9] == 'O') && grid[8] == '8')
		{
			grid[8] = mark;
			winMove = 1;
		}

		else if ((grid[8] == 'O' && grid[9] == 'O') && grid[7] == '7')
		{
			grid[7] = mark;
			winMove = 1;
		}


		//Column 1 Vertical Check
		else if ((grid[1] == 'O' && grid[4] == 'O') && grid[7] == '7')
		{
			grid[7] = mark;
			winMove = 1;
		}

		else if ((grid[1] == 'O' && grid[7] == 'O') && grid[4] == '4')
		{
			grid[4] = mark;
			winMove = 1;
		}

		else if ((grid[4] == 'O' && grid[7] == 'O') && grid[1] == '1')
		{
			grid[1] = mark;
			winMove = 1;
		}

		//Column 2 Vertical Check
		else if ((grid[2] == 'O' && grid[5] == 'O') && grid[8] == '8')
		{
			grid[8] = mark;
			winMove = 1;
		}

		else if ((grid[2] == 'O' && grid[8] == 'O') && grid[5] == '5')
		{
			grid[5] = mark;
			winMove = 1;
		}

		else if ((grid[5] == 'O' && grid[8] == 'O') && grid[2] == '2')
		{
			grid[2] = mark;
			winMove = 1;
		}

		//Column 3 Vertical Check
		else if ((grid[3] == 'O' && grid[6] == 'O') && grid[9] == '9')
		{
			grid[9] = mark;
			winMove = 1;
		}

		else if ((grid[3] == 'O' && grid[9] == 'O') && grid[6] == '6')
		{
			grid[6] = mark;
			winMove = 1;
		}

		else if ((grid[6] == 'O' && grid[9] == 'O') && grid[3] == '3')
		{
			grid[3] = mark;
			winMove = 1;
		}

		//Diagonal 1 ,5, 9 Check
		else if ((grid[1] == 'O' && grid[5] == 'O') && grid[9] == '9')
		{
			grid[9] = mark;
			winMove = 1;
		}

		else if ((grid[1] == 'O' && grid[9] == 'O') && grid[5] == '5')
		{
			grid[5] = mark;
			winMove = 1;
		}

		else if ((grid[5] == 'O' && grid[9] == 'O') && grid[1] == '1')
		{
			grid[1] = mark;
			winMove = 1;
		}

		//Diagonal 3, 5, 7 Check
		else if ((grid[3] == 'O' && grid[5] == 'O') && grid[7] == '7')
		{
			grid[7] = mark;
			winMove = 1;
		}

		else if ((grid[3] == 'O' && grid[7] == 'O') && grid[5] == '5')
		{
			grid[5] = mark;
			winMove = 1;
		}

		else if ((grid[5] == 'O' && grid[7] == 'O') && grid[3] == '3')
		{
			grid[3] = mark;
			winMove = 1;
		}
		else //Ensures that both winTurn() and winStop() do not both execute
			winMove = 0;
	}
}

//Will attempt to stop the player from putting down 3 in a row
void winStop()
{
	/********************************************************
	There are 8 combinations in which one can win
	And 24 possible ways it can happen (3 different tiles per)
	All of which need to be covered
	********************************************************/

	if (winMove == 0)
	{
		//Row 1 Horizontal Check
		if ((grid[1] == 'X' && grid[2] == 'X') && grid[3] == '3')
			grid[3] = mark;

		else if ((grid[1] == 'X' && grid[3] == 'X') && grid[2] == '2')
			grid[2] = mark;

		else if ((grid[2] == 'X' && grid[3] == 'X') && grid[1] == '1')
			grid[1] = mark;



		//Row 2 Horizontal Check
		else if ((grid[4] == 'X' && grid[5] == 'X') && grid[6] == '6')
			grid[6] = mark;


		else if ((grid[4] == 'X' && grid[6] == 'X') && grid[5] == '5')
			grid[5] = mark;


		else if ((grid[5] == 'X' && grid[6] == 'X') && grid[4] == '4')
			grid[4] = mark;



		//Row 3 Horizontal Check
		else if ((grid[7] == 'X' && grid[8] == 'X') && grid[9] == '9')
			grid[9] = mark;


		else if ((grid[7] == 'X' && grid[9] == 'X') && grid[8] == '8')
			grid[8] = mark;

		else if ((grid[8] == 'X' && grid[9] == 'X') && grid[7] == '7')
			grid[7] = mark;



		//Column 1 Vertical Check
		else if ((grid[1] == 'X' && grid[4] == 'X') && grid[7] == '7')
			grid[7] = mark;


		else if ((grid[1] == 'X' && grid[7] == 'X') && grid[4] == '4')
			grid[4] = mark;


		else if ((grid[4] == 'X' && grid[7] == 'X') && grid[1] == '1')
			grid[1] = mark;



		//Column 2 Vertical Check
		else if ((grid[2] == 'X' && grid[5] == 'X') && grid[8] == '8')
			grid[8] = mark;


		else if ((grid[2] == 'X' && grid[8] == 'X') && grid[5] == '5')
			grid[5] = mark;


		else if ((grid[5] == 'X' && grid[8] == 'X') && grid[2] == '2')
			grid[2] = mark;


		//Column 3 Vertical Check
		else if ((grid[3] == 'X' && grid[6] == 'X') && grid[9] == '9')
			grid[9] = mark;


		else if ((grid[3] == 'X' && grid[9] == 'X') && grid[6] == '6')
			grid[6] = mark;


		else if ((grid[6] == 'X' && grid[9] == 'X') && grid[3] == '3')
			grid[3] = mark;


		//Diagonal 1 ,5, 9 Check
		else if ((grid[1] == 'X' && grid[5] == 'X') && grid[9] == '9')
			grid[9] = mark;


		else if ((grid[1] == 'X' && grid[9] == 'X') && grid[5] == '5')
			grid[5] = mark;


		else if ((grid[5] == 'X' && grid[9] == 'X') && grid[1] == '1')
			grid[1] = mark;



		//Diagonal 3, 5, 7 Check
		else if ((grid[3] == 'X' && grid[5] == 'X') && grid[7] == '7')
			grid[7] = mark;


		else if ((grid[3] == 'X' && grid[7] == 'X') && grid[5] == '5')
			grid[5] = mark;


		else if ((grid[5] == 'X' && grid[7] == 'X') && grid[3] == '3')
			grid[3] = mark;
		else 
			winMove = -1;
	}
}

void cpuTurn()
{
	//CPU prioritizes the winning move
	winTurn();

	//Forces the CPU to take certain moves to avoid defeat
	winStop(); 

	//Checks to see if winStop() made a turn
	if (winMove == -1) //If false that means an precise move was made instead and it is no longer the CPU's turn
	{
		choice = rand() % 9;

		if (choice == 1 && grid[1] == '1')
			grid[1] = mark;
		
		else if (choice == 2 && grid[2] == '2')
			grid[2] = mark;
		
		else if (choice == 3 && grid[3] == '3')
			grid[3] = mark;
		
		else if (choice == 4 && grid[4] == '4')
			grid[4] = mark;
		
		else if (choice == 5 && grid[5] == '5')
			grid[5] = mark;
		
		else if (choice == 6 && grid[6] == '6')
			grid[6] = mark;
		
		else if (choice == 7 && grid[7] == '7')
			grid[7] = mark;
		
		else if (choice == 8 && grid[8] == '8')
			grid[8] = mark;
		
		else if (choice == 9 && grid[9] == '9')
			grid[9] = mark;
		else //Happens only if the cpu gets unlucky and picks a 0 or a taken tile
			cpuTurn();
	}
	i = winCheck();
}

void main()
{
	//Unless the CPU or the player are about to win, CPU turns will be random
	srand(time(NULL));
	int r = rand();
	
	//Allows the player to go first
	if (hasStarted == 0)
		player = 1;

	i = -1;

	//Intro message and name check
	start();
	char line[sizeof(char) * 256];
	do
	{
		board();
		
		if (player % 2)
		{
			player = 1;
			mark = 'X';
		}
		else
		{
			player = 2;
			mark = 'O';
		}
prompt:
		printf("Enter a number and hit enter: \n");
		if(fgets(line, sizeof line, stdin) == NULL)
		{
			printf("Invalid selection");
			goto prompt;
		}
		choice = strtol(line, NULL, 10);

		//Will be checking to see if anybody has claimed the spot that is chosen

		if (choice == 1 && grid[1] == '1')
				grid[1] = mark;
			
		else if (choice == 2 && grid[2] == '2') 
				grid[2] = mark;
			
		else if (choice == 3 && grid[3] == '3')
				grid[3] = mark;
			
		else if (choice == 4 && grid[4] == '4')
				grid[4] = mark;
			
		else if (choice == 5 && grid[5] == '5')
				grid[5] = mark;
			
		else if (choice == 6 && grid[6] == '6')
				grid[6] = mark;
			
		else if (choice == 7 && grid[7] == '7')
				grid[7] = mark;
			
		else if (choice == 8 && grid[8] == '8')
				grid[8] = mark;
			
		else if (choice == 9 && grid[9] == '9')
				grid[9] = mark;
			
		else 
		{
			printf("Invalid selection\n");
			goto prompt;
		}
		i = winCheck();

		//Checks to see if the game has ended before the cpu takes its turn
		if (i == 1)
			break; //Leaves the loop
		else if (i == 0)
			break; //Leaves the loop

		player++; //Sets it to the Cpu's turn

		if (player % 2)
		{
			player = 1;
			mark = 'X';
		}
		else
		{
			player = 2;
			mark = 'O';
		}	
			cpuTurn();
			player++;	
	} while (i == -1);

	//Prints the board with the game results
	board();

	if (i == 1)
	{
		if (player == 1)
			printf("You Win!\n\n");
		else
			printf("You Lose\n\n");
	}
	else if (i == 0)
		printf("ITS A TIE\n\n");
}