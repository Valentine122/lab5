#include <iostream>
#include <math.h>
#include <conio.h>
#define _USE_MATH_DEFINES

#define n 5
#define m 5

using namespace std;

class Matrix
{
private:
    double dArr[m];
public:
    friend void inputarray(Matrix Arr[]);
    friend void outputarray(Matrix Arr[]);
    friend void sortarray(Matrix  Arr[]);
    friend void calcarray(Matrix Arr[]);
};

void inputarray(Matrix  Arr[])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cout << "[" << i + 1 << "][" << j + 1  << "] = ";
            cin >> Arr[i].dArr[j];
        }
}
void outputarray(Matrix  Arr[])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << Arr[i].dArr[j] << "\t";
        }
        cout << endl;
    }
}
void sortArray(Matrix  arr[])
{
    for (int i = 0; i < n; i++)
    {
        for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
        {
            for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
            {
                int LeftBlockIterator = 0;
                int RightBlockIterator = 0;
                int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < n) ? RightBorder : n;
                int* SortedBlock = new int[RightBorder - LeftBorder];

                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
                {
                    if (arr[LeftBorder + LeftBlockIterator].dArr[i] < arr[MidBorder + RightBlockIterator].dArr[i])
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].dArr[i];
                        LeftBlockIterator++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].dArr[i];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].dArr[i];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].dArr[i];
                    RightBlockIterator++;
                }

                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                {
                    arr[LeftBorder + MergeIterator].dArr[i] = SortedBlock[MergeIterator];
                }
                delete SortedBlock;

            }

        }
    }
}
void calcarray(Matrix Arr[]) {
    double sum[n];
    for (int i = 0; i < n; i++) {
        sum[i] = 0;
    }

    double average[n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum[i] += Arr[i].dArr[j];
        }
        average[i] = sum[i] / n;
        cout << "Average of " << i + 1 << "row: " << average[i] << endl;
        cout << "Sum of " << i + 1 << "row: " << sum[i] << endl;
    }
    int mult = 1;
    for (int i = 0; i < n; i++) {
        mult = mult*average[i];
    }
    cout << "mult: " << mult << endl;


}



int main()
{
    Matrix  Array[n];
    cout << "Enter elements of matrix:\n" << endl;
    inputarray(Array);
    cout << "\nYour matrix:\n" << endl;
    outputarray(Array);
    sortarray(Array);
    cout << "\nSorted matrix:\n" << endl;
    outputarray(Array);
    cout << "\nCalculations:\n" << endl;
    calcarray(Array);
}
