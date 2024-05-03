// C++ program to illustrate the size() function
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <climits>
using namespace std;

int hashh(string str, int str_len)
{
    int hashh = 0;
    int mul = 1;
    for (int i = 0; i < str_len; i++)
    {
        hashh += mul * str[i];
        mul *= 10;
    }
    return hashh;
}

int rabinkarp(string str, int str_len, string pat, int pat_len)
{

    int hash_pat = hashh(pat, pat_len);
    int iter_hash = hashh(str.substr(0, pat_len), str.substr(0, pat_len).length());

    vector<long unsigned int> hashgrid;
    hashgrid.push_back(iter_hash);

    int j = pat_len;
    int i = 1;
    while (j < str_len)
    {
        hashgrid.push_back((hashgrid[i - 1] - str[i - 1]) / 10 + str[j] * (pow(10, (pat_len - 1))));
        //        hashgrid.push_back(hashh(str.substr(i,pat_len),str.substr(i,pat_len).length()));
        i++;
        j++;
    }

    for (int i = 0; i < hashgrid.size(); i++)
    {
        if (hashgrid[i] == hash_pat)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    string str = "abcdef";
    string pat = "cde";

    cout << "Sub String Found At: " << rabinkarp(str, str.length(), pat, pat.length()) << endl;
    //    cout << str.substr(0,3);
}
