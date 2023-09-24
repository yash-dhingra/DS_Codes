#include <iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,56,7,9};
    int len=sizeof(arr)/sizeof(arr[0]);
    int check=9;
    for(int i=0;i<len;i++){
        if(check==arr[i]){
            cout << "Present"<<endl;
            return 0;
        }

    }
    cout << "Not Present"<<endl;
}