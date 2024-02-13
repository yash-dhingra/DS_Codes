#include <iostream>
#include <vector>
using namespace std;

// Function to print the subsets that sum up to the target
void subsetSum(vector<int> &nums, int target, vector<int> &subset, int index)
{
    // If the target is reached, print the subset
    if (target == 0)
    {
        cout << "Subset found: ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // If the target becomes negative or all elements are processed
    if (target < 0 || index == nums.size())
    {
        return;
    }

    // Include the current element in the subset
    subset.push_back(nums[index]);
    subsetSum(nums, target - nums[index], subset, index + 1);

    // Exclude the current element from the subset
    subset.pop_back();
    subsetSum(nums, target, subset, index + 1);
}

int main()
{
    vector<int> nums = {2, 4, 6, 8, 10};
    int target = 10;
    vector<int> subset;

    cout << "Subsets with sum " << target << " are:" << endl;
    subsetSum(nums, target, subset, 0);

    return 0;
}
