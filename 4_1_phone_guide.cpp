#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Input your request" << endl;
    string input;
    string a_name, ph_num;
    getline(cin, input);
    bool add_request = false;
    for (char ch : input)
    {
        if (ch == ' ')
        {
            add_request = true;
            continue;
        }
        if ((ch >= '0' && ch <= '9') || ch <= '-')
        {
            ph_num += ch;
        }
        if ((ch >= 'A' && ch <= 'z'))
        {
            a_name += ch;
        }
    }
    cout << "Abonent: " << a_name << " " << ph_num;
}