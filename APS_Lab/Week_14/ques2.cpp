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

    string str = "ilikesum";
    vector<string> init_dict;
    vector<string> dict;
    init_dict.push_back("i");
    init_dict.push_back("like");
    init_dict.push_back("sam");
    init_dict.push_back("sung");
    init_dict.push_back("samsung");
    init_dict.push_back("mobile");
    init_dict.push_back("ice");
    init_dict.push_back("cream");
    init_dict.push_back("icecream");
    init_dict.push_back("man");
    init_dict.push_back("go");
    init_dict.push_back("mango");
    map<int, string> mid_dict;

    for (int i = 0; i < init_dict.size(); i++)
    {
        mid_dict.insert(pair<int, string>(init_dict[i].length(), init_dict[i]));
    }
    map<int, string>::iterator mid_dict_iter = mid_dict.begin();

    while (mid_dict_iter != mid_dict.end())
    {
        dict.push_back(mid_dict_iter->second);
        mid_dict_iter++;
    }

    reverse(dict.begin(), dict.end());

    for (int i = 0; i < dict.size(); i++)
    {
        int temp = rabinkarp(str, str.length(), dict[i], dict[i].length());
        if (temp != -1)
        {
            str.erase(temp, dict[i].length());
        }
    }

    if (str == "")
        cout << "Possible" << endl;
    else
        cout << "Not Possible" << endl;
}
