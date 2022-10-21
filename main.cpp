#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array, int const left, int const middle, int const right)
{
    int const start = middle - left + 1;
    int const end = right - middle;
    vector<int> leftArray (start);
    vector<int> rightArray (end);

    for (int i = 0; i < start; i ++)
        leftArray[i] = array[left + i];

    for (int j = 0; j < end; j ++)
        rightArray[j] = array[middle + 1 + j];

    int startIndex = 0; int endIndex = 0; int indexMerge = left;

    while (startIndex < start and endIndex < end)
    {
        if (leftArray[startIndex] <= rightArray[endIndex])
        {
            array[indexMerge] = leftArray[startIndex];
            startIndex ++;
        }
        else
        {
            array[indexMerge] = rightArray[endIndex];
            endIndex ++;
        }
        indexMerge ++;
    }

    while (startIndex < start)
    {
        array[indexMerge] = leftArray[startIndex];
        startIndex++;
        indexMerge++;
    }

    while (endIndex < end)
    {
        array[indexMerge] = rightArray[endIndex];
        endIndex ++;
        indexMerge ++;
    }


}

void merge_sort(vector <int> &array, int start, int end){
    if (start >= end)
    {
        return;
    }
    auto middle = start + (end - start) / 2;
    merge_sort(array, start, middle);
    merge_sort(array, middle + 1, end);
    merge(array,start, middle, end);
}




int main(){
    int N;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; i ++){
        cin >> list[i];
    }
    merge_sort(list, 0, N - 1);
    for (int i = 0; i < N; i ++){
        cout << list[i] << " ";
    }
}