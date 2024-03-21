#include <iostream>
#include <vector>
#define V 5

using namespace std;

int count(vector<int> arr, int ele)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (ele == arr[i])
            count++;
    }
    return count;
}

int min_ele(vector<int> arr)
{
    int temp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[temp] > arr[i])
        {
            temp = i;
        }
    }
    return temp;
}

bool is_allowed(vector<vector<int>> isdanger, vector<int> temp_container, int element)
{
    for (int i = 0; i < temp_container.size(); i++)
    {
        if (isdanger[temp_container[i]][element] == 1)
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> isdanger = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0}};

    vector<int> disposed(V, 0);
    vector<vector<int>> containers;

    // Lets Calculate Count of Elements which can't be mixed
    vector<int> isdangercount;
    for (auto i : isdanger)
    {
        isdangercount.push_back(count(i, 1));
    }

    while (count(disposed, 1) != V)
    {
        int ele = min_ele(isdangercount);

        vector<int> temp_container;
        temp_container.push_back(ele);
        disposed[ele] = 1;

        for (int i = 0; i < V; i++)
        {
            if (!disposed[i] && is_allowed(isdanger, temp_container, i))
            {
                temp_container.push_back(i);
                disposed[i] = 1;
            }
        }

        containers.push_back(temp_container);

        // Update isdangercount
        for (int i = 0; i < V; i++)
        {
            if (disposed[i])
            {
                isdangercount[i] = INT_MAX;
            }
        }
    }

    // Outputting the containers
    for (int i = 0; i < containers.size(); i++)
    {
        cout << "Container " << i + 1 << ": ";
        for (int j = 0; j < containers[i].size(); j++)
        {
            cout << containers[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
