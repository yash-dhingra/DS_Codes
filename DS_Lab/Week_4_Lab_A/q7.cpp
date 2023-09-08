#include <iostream>
#include <string>

using namespace std;

void rem(string str)
{
    int len = str.length();
    string out;

    //    Remove the spaces

    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
            continue;
        out += str[i];
    }

    str = out;
    out = "";
    len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (str[i + 1] == str[i])
        {
            int count = 0;
            for (int j = i; j < len; j++)
            {
                if (str[i] == str[j])
                    count++;
                else
                    break;
            }
            //            cout<< "Count: "<<count<<endl;
            out += str[i];
            out += to_string(count);
            i += count - 1;
        }

        else
        {
            out += str[i];
        }
    }
    cout << out << endl;
}

int main()
{
    rem("asd ddfghjdff kj");

    string str = " ";
}
