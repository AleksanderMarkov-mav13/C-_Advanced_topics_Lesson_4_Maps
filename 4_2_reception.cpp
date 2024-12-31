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
    bool empty_queue = true;
    while (true) {
        if (empty_queue) {
            cout << "Type your surname " << endl;
        }
        else {
            cout << "Type your surname or next " << endl;
        }
        string input;
        cin >> input;
        if (input == "finish" || input == "FINISH") {
            cout << "The programme has finished running!";
            break;
        }
        else if (input == "next" || input == "NEXT" || input == "Next") {
            map<string, int>::iterator it = queue_map.begin();
            if (queue_map.begin() == queue_map.end()) {
                cout << "The line is already empty!!!" << endl;
                empty_queue = true;
            }
            else {
                cout << it->first << endl;
                if (queue_map[it->first] > 0) {
                    queue_map[it->first]--;
                } 
                else {
                    queue_map.erase(it->first);
                }
            }
        }
        else {
            if (queue_map.find(input) != queue_map.end()) {
                queue_map[input] ++;
            }
            else {
                pair<string, int> oPair(input, 0);
                queue_map.insert(oPair);
            }
            empty_queue = false;
        }
   }
}