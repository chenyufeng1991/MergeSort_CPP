//
//  main.cpp
//  MergeSort_C++
//
//  Created by chenyufeng on 9/24/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 *  归并排序时间复杂度O(nlogn),空间复杂度O(1),是一种稳定的排序
 */

void MergeSort(vector<int> &vec,int left, int right, vector<int> &temp);
void MergeArray(vector<int> &vec, int left, int mid, int right, vector<int> &temp);

int main(int argc, const char * argv[])
{
    int arr[] = {4,2,7,1,0,9};
    vector<int>vectorArray(arr, arr + sizeof(arr) / sizeof(int));
    vector<int>temp(6);
    MergeSort(vectorArray, 0, 5, temp);

    vector<int>::iterator vectorIte;
    for (vectorIte = vectorArray.begin(); vectorIte != vectorArray.end(); vectorIte++)
    {
        cout << *vectorIte << " ";
    }

    return 0;
}

void MergeArray(vector<int> &vec, int left, int mid, int right, vector<int> &temp)
{
    int i = left,j = mid;
    int m = mid + 1,n = right;
    int k = 0;

    while (i <= j && m <= n)
    {
        if (vec[i] <= vec[m])
        {
            temp[k++] = vec[i++];
        }
        else
        {
            temp[k++] = vec[m++];
        }
    }

    while (i <= j)
    {
        temp[k++] = vec[i++];
    }

    while (m <= n)
    {
        temp[k++] = vec[m++];
    }

    for (int i = 0; i < k; i++)
    {
        vec[left + i] = temp[i];
    }
}

void MergeSort(vector<int> &vec,int left, int right, vector<int> &temp)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(vec, left, mid, temp);
        MergeSort(vec, mid + 1, right, temp);
        MergeArray(vec, left, mid, right, temp);
    }
}




