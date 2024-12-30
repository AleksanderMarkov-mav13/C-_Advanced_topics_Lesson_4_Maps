#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Welcome to our phone guide!!!" << endl;
    map<string, string> ph_guide_map;

    cout << "Here you can input your request - add or get name of abonent or phone number" << endl;
    cout << "If you want to finish work - input finish" << endl;
    bool work_flag = true;
    do {
        cout << "Input your request " << endl;
        string input;
        string a_name, ph_num;
        getline(cin, input);
        bool add_request = false;
        bool name_exist = false;
        bool phn_exist = false;
        for (char ch : input) {
            if (ch == ' ') {
            add_request = true;
            continue;
            }
            if ((ch >= '0' && ch <= '9') || ch == '-') {
                ph_num += ch;
                phn_exist = true;
            }
            if ((ch >= 'A' && ch <= 'z')) {
                a_name += ch;
                name_exist = true;
            }
        }
        if (a_name == "finish") {
            work_flag = false;
            cout << "Working of programme has finished!" << endl; 
        }
        else if (add_request && phn_exist && name_exist) {
            ph_guide_map[ph_num] = a_name;
        }
        else if (phn_exist && !add_request) {
            if (ph_guide_map.find(ph_num) != ph_guide_map.end()) {
                cout << "Abonent of this phone number is " << ph_guide_map[ph_num] << endl;
            }
            else {
                cout << "Abonent of this phone number not found!";
            }
        }
        else if (name_exist && !add_request) {
            for (const auto &line : ph_guide_map) {
                if (line.second == a_name) {
                    cout << line.second << " has phone number " << line.first << endl;
                }
            }
        }
    } while (work_flag);
}