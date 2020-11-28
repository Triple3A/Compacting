#include <iostream>
#include <vector>

using namespace std;

const char ZERO = '0';
const char NINE = '9';
const string err = "Check your input";

void del(string input, int i, vector <char>& output)
{
    if(i == input.size() - 1)
    {
        output.push_back(input[i]);
        output.push_back('\0');
        return;
    }
    if(input[i] != input[i + 1])
        output.push_back(input[i]);
    del(input, i + 1, output);
}

bool input_check(string in)
{
    for(int i = 0; i < in.size(); i++)
    {
        if(in[i] < ZERO || in[i] > NINE)
            return false;
    }
    return true;
}

int main()
{
    string in;
    vector <string> input;
    vector <char> out;
    while(cin >> in)
        input.push_back(in);
    for(int i = 0; i < input.size(); i++)
    {
        if(input_check(input[i]))
        {
            del(input[i], 0, out);
            for(int j = 0; j < out.size(); j++)
                cout << out[j];
            cout << endl;
        }
        else
            cout << err << endl;
        out.clear();
    }
    return 0;
}
