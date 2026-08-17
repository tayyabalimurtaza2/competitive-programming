#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int cht[26] = {};
    for (char c : s)
    {
        cht[c - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < 26; i++)
    {
        if (cht[i] % 2 != 0)
            ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
}