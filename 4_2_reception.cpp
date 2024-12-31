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
    // int count_queue = -1;
    bool work_flag = true;
    while (true) {
        cout << "Type your surname or next " << endl;
        string input;
        cin >> input;
        if (input == "finish" || input == "FINISH") {
            cout << "The programme has finished running!";
            break;
        }
        else if (input == "next" || input == "NEXT") {
            map<string, int>::iterator it = queue_map.begin();
            string queue_one = it->first;
            cout << queue_one << endl;
            if (queue_map[queue_one] > 0) {
                queue_map[queue_one]--;
            } 
            else {
                queue_map.erase(queue_one);
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
        }
   }
}