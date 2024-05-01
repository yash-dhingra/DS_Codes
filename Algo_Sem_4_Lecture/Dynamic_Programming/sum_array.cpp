#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int s=sizeof(arr)/sizeof(arr[0]);
    vector<int> inp_arr(arr,arr+s);
    vector<int> sum_arr;
    int sum=0;
    for(int i=0;i<inp_arr.size();i++){
        sum+=inp_arr[i];
        sum_arr.push_back(sum);
    }

    cout<<"Sum of the array is: "<<*(sum_arr.end()-1)<<endl;

}