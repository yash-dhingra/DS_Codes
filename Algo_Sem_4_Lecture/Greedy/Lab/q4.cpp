#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define n 6

using namespace std;

int closest_greater(vector<int> arr, int ele)
{
    sort(arr.begin(), arr.end());
    if (arr[arr.size() - 1] < ele)
        return -1;
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= ele)
            break;
    }
    return arr[i];
}

int main()
{
    vector<int> vec1 = {1, 3, 0, 5, 8, 5};
    vector<int> vec2 = {2, 4, 6, 7, 9, 9};

    vector<pair<int, int>> schedule;

    int min_ele = INT_MAX;
    int min_ele2;
    int min_ele_index = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (min_ele > vec1[i])
        {
            min_ele = vec1[i];
            min_ele_index = i;
        }
    }
    schedule.push_back(pair<int, int>(vec1[min_ele_index], vec2[min_ele_index]));
    min_ele2 = vec2[min_ele_index];

    for (int i = 0; i < n; i++)
    {
        int close_gre = closest_greater(vec1, min_ele2);
        if (close_gre == -1)
            break;
        int close_gre_index = find(vec1.begin(), vec1.end(), close_gre) - vec1.begin();
        schedule.push_back(pair<int, int>(vec1[close_gre_index], vec2[close_gre_index]));
        min_ele2 = vec2[close_gre_index];
    }

    for (auto i : schedule)
    {
        cout << i.first << " " << i.second << endl;
    }
}
