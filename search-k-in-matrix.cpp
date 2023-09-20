/*
Search element k in n*n matrix
*/
#include <iostream>

int main()
{
    // int arr[][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}};

    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    int size = sizeof(arr[0]) / sizeof(int);
    int target = 20, flag = 0;

// Solution 1
// Time Complexity: O(n^2) , Space Complexity: O(1)

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == target)
            {
                flag = 1;
                std ::cout << "Found at: (" << i << "," << j << ")";
            }
        }
    }

    if (flag == 0)
        std ::cout << "Element not present in the array !";

    std ::cout << "\n";

// Solution 2
// Time Complexity: O(logm * logn) , Space Complexity: O(1)
    flag = 0;
    int start = 0, end = size - 1, mid = start + ((end - start) / 2);

    while (start <= end)
    {
        if (target == arr[mid][0])
        {
            std ::cout << "Found at: (" << mid << "," << 0 << ")";
            std ::exit(0);
        }
        else if (target == arr[mid][size - 1])
        {
            std ::cout << "Found at: (" << mid << "," << size - 1 << ")";
            std ::exit(0);
        }
        else if (arr[mid][0] < target && target < arr[mid][size - 1])
        {

            int f_col = 0, e_col = size - 1, mid_col = f_col + ((e_col - f_col) / 2);

            while (f_col <= e_col)
            {
                if (arr[mid][mid_col] == target)
                {
                    flag = 1;
                    std ::cout << "Found at: (" << mid << "," << mid_col << ")";
                    std ::exit(0);
                }
                else if (arr[mid][mid_col] > target)
                    e_col = mid_col - 1;
                else
                    f_col = mid_col + 1;
                mid_col = f_col + ((e_col - f_col) / 2);
            }
        }
        else if (target < arr[mid][0])
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + ((end - start) / 2);
    }

    if (flag == 0)
        std ::cout << "Element not present in the array !";
}

// I learnt a lot of things while working on this code 
