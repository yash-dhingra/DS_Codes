#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n=10; // Number whos factorial you'd want

    vector <int> fact;
    fact.push_back(-1);
    fact.push_back(1);
    for(int i=2;i<=n;i++){
        fact.push_back(fact[i-1]*i);
    }
    cout << "Factorial is : " << *(fact.end() - 1) << endl;
}