#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Welcome to our registration offcice !!!" << endl;
    cout << "Here you can get in line - just input your surname or type Next for call next in line" << endl;
    cout << "If you want to finish work - input finish" << endl;
    map<string, int> queue_map;
}