#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {1, 20, -10, 4, 5};
    int s = sizeof(arr) / sizeof(arr[0]);
    vector<int> inp_arr(arr, arr + s);
    vector<int> min_arr;
    vector<int> max_arr;
    min_arr.push_back(inp_arr[0]);
    max_arr.push_back(inp_arr[0]);
    for (int i = 1; i < inp_arr.size(); i++)
    {
        // For Minimum Array 
        if(inp_arr[i]<min_arr[i-1]){
            min_arr.push_back(inp_arr[i]);
        }
        else{
            min_arr.push_back(min_arr[i-1]);
        }

        if (inp_arr[i] > max_arr[i - 1])
        {
            max_arr.push_back(inp_arr[i]);
        }
        else
        {
            max_arr.push_back(max_arr[i - 1]);
        }
    }

    cout << "Smallest Element of the array is: " << *(min_arr.end() - 1) << endl;
    cout << "Biggest Element of the array is: " << *(max_arr.end() - 1) << endl;
}