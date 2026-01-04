#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * Algorithm Challenge – Level 3 | #12  Typical Matrices Check (Element-by-Element Comparison)
 *
 * This program generates two 3×3 matrices filled with random numbers, prints both matrices, then checks whether they are "typical".
 *
 * Typical matrices mean that:
 * - Both matrices have the exact same values
 * - Values are located in the same positions (row & column)
 *
 * Unlike previous challenges that relied on abstraction (sum comparison), this algorithm performs a direct, cell-by-cell comparison.
 *
 * This challenge reinforces:
 * - Deep understanding of matrix structure
 * - Element-wise comparison logic
 * - Early loop termination for efficiency
 * - Precision in algorithm design
 */

// Function to generate a random number within a given range
int RandNumbr(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fills a 3x3 matrix with random values
void FillMatrxWithRandNums(int arr[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++) // Traverse rows
    {
        for (short j = 0; j < Colms; j++) // Traverse columns
        {
            arr[i][j] = RandNumbr(1, 9); // Assign random number to each cell
        }
    }
}

// Prints matrix values in two-digit formatted style
void PrintMatrix(int arr[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            printf(" %0*d ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

// Checks if two matrices are identical element by element
bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            // If any corresponding element differs, matrices are not typical
            if (Matrix1[i][j] != Matrix2[i][j])
                return false; // Early exit for efficiency
        }
    }
    return true; // All elements matched
}

int main()
{
    srand((unsigned)time(NULL)); // Seed random number generator (once)

    int Matrix1[3][3], Matrix2[3][3];

    FillMatrxWithRandNums(Matrix1, 3, 3);
    cout << "Matrix 1:\n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrxWithRandNums(Matrix2, 3, 3);
    cout << "\nMatrix 2:\n";
    PrintMatrix(Matrix2, 3, 3);

    if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
        cout << "\nYes, Both Matrices are Typical.";
    else
        cout << "\nNo, Matrices are Not Typical.";

    return 0;
}
