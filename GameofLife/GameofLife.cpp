#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Copies one array to another.
void copyArr(int array1[52][102], int array2[52][102])
{
	for (int j = 0; j < 52; j++)
	{
		for (int i = 0; i < 102; i++)
			array2[j][i] = array1[j][i];
	}
}

//Life function --- Move from stack to heap ---
void life(int array[52][102], char choice)
{
	
	int temp[52][102]; //Make this preprocessor
	copyArr(array, temp);
	for (int j = 1; j < 51; j++)
	{
		for (int i = 1; i < 101; i++)
		{
			if (choice == 'r')
			{
				
				int count = 0;
				count = array[j - 1][i] +
						array[j - 1][i - 1] +
						array[j][i - 1] +
						array[j + 1][i - 1] +
						array[j + 1][i] +
						array[j + 1][i + 1] +
						array[j][i + 1] +
						array[j - 1][i + 1];
				//The cell dies.
				if (count < 2 || count > 3)
					temp[j][i] = 0;
				//The cell stays the same.
				if (count == 2)
					temp[j][i] = array[j][i];
				//The cell either stays alive, or is "born".
				if (count == 3)
					temp[j][i] = 1;
			}

			else if (choice == 'l')
			{
			
				
				int count = 0;
				count = array[j - 1][i] +
					array[j][i - 1] +
					array[j + 1][i] +
					array[j][i + 1];
				//The cell dies.  
				if (count < 2 || count > 3)
					temp[j][i] = 0;
				//The cell stays the same.
				if (count == 2)
					temp[j][i] = array[j][i];
				//The cell either stays alive, or is "born".
				if (count == 3)
					temp[j][i] = 1;
			}
		}
	}
	//Copies the completed temp array back to the main array. Investigate this
	copyArr(temp, array);
}


bool compare(int array1[52][102], int array2[52][102])
{
	int count = 0;
	for (int j = 0; j < 52; j++)
	{
		for (int i = 0; i < 102; i++)
		{
			if (array1[j][i] == array2[j][i])
				count++;
		}
	}
	
	//the dimensions of the array multiplied together.
	if (count == 52 * 102)
		return true;
	else
		return false;
}

//. A live cell is marked by a '*', and a dead or vacant cell by a '#'.
void print(int array[52][102])
{
	for (int j = 1; j < 51; j++)
	{
		for (int i = 1; i < 101; i++)
		{
			if (array[j][i] == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int gen0[52][102];
	int todo[52][102];
	int backup[52][102];
	char neighborhood;
	char again;
	char cont;
	bool comparison;
	string decoration;

	//Instructions
	cout 
		<< endl << "The rules of the \"Game of Life\" are as follows:" << endl
		<< endl << "1. Any live cell with fewer than two live neighbors dies, as if caused by under-population."
		<< endl << "2. Any live cell with two or three live neighbors lives on to the next generation."
		<< endl << "3. Any live cell with more than three live neighbors dies, as if by overcrowding."
		<< endl << "4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction." << endl
		<< endl << "The initial configuration (Generation 0) of the board is determined randomly."
		<< endl << "Every hundred Generations you will get the option to end or continue the simulation."
		<< endl << "If a system becomes \"stable\" (meaning the system does not change from one"
		<< endl << "generation to the next), the simulation will end automatically." << endl << endl;
	//Continue.
	do
	{
		//Loop to check for proper inputs.
		do
		{
			cout << "Which way would you like to use (r or l): ";
			cin >> neighborhood;
		} while (neighborhood != 'r' && neighborhood != 'l');
		
		//gives me a warning
		system("clear");
		int i = 0;
		
		do
		{
			//Generates random state of the game board.
			srand(time(NULL));
			//array is 102 x 52
			for (int j = 1; j < 51; j++)
			{
				for (int i = 1; i < 101; i++)
					gen0[j][i] = rand() % 2;
			}
			//How big the decoration should be.
			if (i < 10)
				decoration = "#############";
			else if (i >= 10 && i < 100)
				decoration = "##############";
			else if (i >= 100 && i < 1000)
				decoration = "###############";
			else if (i >= 1000 && i < 10000)
				decoration = "################";
			else
				decoration = "#################";
			//Prints the generation.
			cout << decoration << endl << "Generation " << i
				<< ":" << endl << decoration << endl << endl;
			//Initializes the arrays by copying the gen0 array to the todo array.
			if (i == 0)
				copyArr(gen0, todo);
			copyArr(todo, backup);
			print(todo);
			life(todo, neighborhood);
			i++;
			//Pauses the system for 1/10 of a second in order to give the screen time to refresh.
			system("sleep .1"); // ----  Do this using delta time ----
			//Checks whether the generation is a multiple of 100 to ask the user if they want to continue the simulation. 
			if (i % 100 == 1 && i != 1)
			{
				cout << endl;
				//Loop to check for proper inputs.
				do
				{
					cout << "Would you like to continue this simulation? (y/n): ";
					cin >> cont;
				} while (cont != 'y' && cont != 'n');
				if (cont == 'n')
					break;
			}
			//Compares the current generation with a backup generation.
			comparison = compare(todo, backup);
			if (comparison == false)
				system("clear"); //gives me a warning ---- Find a better way ---- 
			if (comparison == true)
				cout << endl;
		} while (comparison == false);
		//Loop to check for proper inputs.
		do
		{
			cout << "Would you like to run another simulation? (y/n): ";
			cin >> again;
		} while (again != 'y' && again != 'n');
	} while (again == 'y');
	return 0;
}