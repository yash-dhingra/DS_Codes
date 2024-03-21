#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
#define I 40

using namespace std;

map<string, vector<int>>::iterator max_ratio(map<string, vector<int>> &data)
{
    map<string, vector<int>>::iterator iter, iter_ret;
    int temp_max = data.begin()->second[2];
    iter_ret = data.begin();
    for (iter = data.begin(); iter != data.end(); iter++)
    {
        if (iter->second[2] > temp_max)
        {
            temp_max = iter->second[2];
            iter_ret = iter;
        }
    }
    iter_ret->second[2] = INT_MIN;
    return iter_ret;
}

int main()
{
    map<string, vector<int>> data;
    map<string, vector<int>> shop;

    data.insert(pair<string, vector<int>>("Redmi Note 9", {10, 20000}));
    data.insert(pair<string, vector<int>>("Samsung Galaxy M12", {5, 10500}));
    data.insert(pair<string, vector<int>>("One Plus 5", {26, 89000}));
    data.insert(pair<string, vector<int>>("Realme Narzo 20 Pro", {8, 4000}));
    data.insert(pair<string, vector<int>>("Xiaomi Poco M3", {12, 23000}));

    map<string, vector<int>>::iterator iter;
    iter = data.begin();

    // Lets calculate and put the ratio of all the elements in vec[2]
    for (; iter != data.end(); iter++)
    {
        int temp_ratio = iter->second[1] / iter->second[0];
        iter->second.push_back(temp_ratio);
    }

    // Now We'll have to find the max ratio
    int items_needed = I;
    while (items_needed > 0)
    {
        map<string, vector<int>>::iterator max_data = max_ratio(data);
        // Check if Count < items_needed
        if (max_data->second[0] <= items_needed)
        {
            shop.insert(pair<string, vector<int>>(max_data->first, max_data->second));
            items_needed -= max_data->second[0];
            max_data->second[0] = 0;
        }
        else
        {
            vector<int> temp_iter = max_data->second;
            temp_iter[0] = items_needed;
            shop.insert(pair<string, vector<int>>(max_data->first, temp_iter));
            max_data->second[0] -= items_needed;
            items_needed = 0;
        }
    }

    map<string, vector<int>>::iterator iterr;
    for (iterr = shop.begin(); iterr != shop.end(); iterr++)
    {
        cout << iterr->first << " - " << iterr->second[0] << endl;
    }
}