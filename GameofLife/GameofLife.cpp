#include <iostream>
#include <vector>


using namespace std;

const int GRID_SIZE = 40;

void firstInit(vector<vector<bool> >&);
void secondInit(vector<vector<bool> >&);
void thirdInit(vector<vector<bool> >&);
void fourthInit(vector<vector<bool> >&);

void printGrid(vector<vector<bool> >&);
int getNeighbours(int, int, vector<vector<bool> >&);
int getState(bool, int);


int showMenu()
{



    cout << "\nPlease chooes which seed pattern to start from:" << endl;
    cout << "    1. Square " << endl;
    cout << "    2. Blinker " << endl;
    cout << "    3. Octagon " << endl;
    cout << "    4. Glider" << endl;

    cout << endl;

    int choice = 1;
    cin >> choice;

    return choice;
}

int main()

{
    cout << "Starting Game Of Life " << endl;

    int pattern = showMenu();

    int numberGenerations = 10;
    cout << "Please Enter the number of generations:" << endl;
    cin >> numberGenerations;

    // second array using vectors
    vector<vector<bool> > theGrid(GRID_SIZE, vector<bool>(GRID_SIZE, 0));       
    vector<vector<bool> > tmpGrid(GRID_SIZE, vector<bool>(GRID_SIZE, 0));       

    switch (pattern)
    {
    case 1: firstInit(theGrid);
        break;

    case 2: secondInit(theGrid);
        break;

    case 3: thirdInit(theGrid);
        break;

    case 4: fourthInit(theGrid);
        break;

    default:firstInit
           (theGrid);
        break;
    }

    printGrid(theGrid);
    cout << "Simulation starting in soon" << endl;
    

    for (int x = 0; x < numberGenerations; x++)                   // Begin Game
    {
        //For each cell
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {

                int local_n = getNeighbours(i, j, theGrid);         
                bool survival = getState(theGrid[i][j], local_n);   
                tmpGrid[i][j] = survival;                           

            }
        }
        printGrid(tmpGrid);                                         
        theGrid = tmpGrid;                                         

                                               
    }

    return 0;
}

void firstInit(vector<vector<bool> >& grid)
{
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;

    cout << "Set one." << endl;
}

void secondInit(vector<vector<bool> >& grid)
{

    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    cout << "Set two ." << endl;
}

void thirdInit(vector<vector<bool> >& grid)
{

    grid[1][2] = 1;
    grid[1][5] = 1;

    grid[2][1] = 1;
    grid[2][3] = 1;
    grid[2][4] = 1;
    grid[2][6] = 1;

    grid[3][2] = 1;
    grid[3][5] = 1;

    grid[4][2] = 1;
    grid[4][5] = 1;

    grid[5][1] = 1;
    grid[5][3] = 1;
    grid[5][4] = 1;
    grid[5][6] = 1;

    grid[6][2] = 1;
    grid[6][5] = 1;

    cout << "Set Three ." << endl;

}


void fourthInit(vector<vector<bool> >& grid)
{

    // NEEDS GRID SIZE OF 40
    grid[5][1] = 1;
    grid[5][2] = 1;
    grid[6][1] = 1;
    grid[6][2] = 1;

    grid[5][11] = 1;
    grid[6][11] = 1;
    grid[7][11] = 1;

    grid[4][12] = 1;
    grid[8][12] = 1;

    grid[3][13] = 1;
    grid[9][13] = 1;

    grid[3][14] = 1;
    grid[9][14] = 1;

    grid[6][15] = 1;

    grid[4][16] = 1;
    grid[8][16] = 1;

    grid[5][17] = 1;
    grid[6][17] = 1;
    grid[7][17] = 1;

    grid[6][18] = 1;

    grid[3][21] = 1;
    grid[4][21] = 1;
    grid[5][21] = 1;

    grid[3][22] = 1;
    grid[4][22] = 1;
    grid[5][22] = 1;

    grid[2][23] = 1;
    grid[6][23] = 1;

    grid[1][25] = 1;
    grid[2][25] = 1;
    grid[6][25] = 1;
    grid[7][25] = 1;

    grid[3][35] = 1;
    grid[4][35] = 1;
    grid[3][36] = 1;
    grid[4][36] = 1;

    cout << "Set four." << endl;

}


void printGrid(vector<vector<bool> >& grid)
{
    cout << endl;

    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j])
            {
                cout << " x ";
            }
            else
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
}

int getNeighbours(int i, int j, vector<vector<bool> >& grid)
{
    int count = 0;

    if ((i > 0) && (j > 0))                         //  Left
    {
        if (grid[i - 1][j - 1]) {
            count++;
        }
    }

    if (i > 0)                                      //  Mid
    {
        if (grid[i - 1][j]) {
            count++;
        }
    }

    if ((i > 0) && (j < GRID_SIZE - 1))               //  Right
    {
        if (grid[i - 1][j + 1]) {
            count++;
        }
    }

    if ((j > 0))                                    // Mid Left
    {
        if (grid[i][j - 1]) {
            count++;
        }
    }

    if (j < GRID_SIZE - 1)                            // Mid Right
    {
        if (grid[i][j + 1]) {
            count++;
        }
    }

    if ((j > 0) && (i < GRID_SIZE - 1))               // Bottom Left
    {
        if (grid[i + 1][j - 1]) {
            count++;
        }
    }

    if (i < GRID_SIZE - 1)                            // Bottom Mid
    {
        if (grid[i + 1][j]) {
            count++;
        }
    }

    if ((i < GRID_SIZE - 1) && (j < GRID_SIZE - 1))     // Bottom Right
    {
        if (grid[i + 1][j + 1]) {
            count++;
        }
    }

    return count;
}

int getState(bool current_state, int n)
{
    if (current_state && (n < 2)) {
        return 0;
    }
    else if (current_state && (n == 2 || n == 3))
    {
        return 1;
    }
    else if (current_state && (n > 3))
    {
        return 0;
    }
    else if ((current_state == 0) && (n == 3))
    {
        return 1;
    }

    return current_state;
}