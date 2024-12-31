#include <iostream>
#include <string>
#include <map>
using namespace std;
void str_to_map(string word, map<char, int> &map_word) {
    for (char ch : word) {
        if (map_word.find(ch) != map_word.end()) {
            map_word[ch] ++;
        }
        else {
            map_word[ch] = 0;
        }
    }
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Welcome to our anagrames quiz !!!" << endl;
    cout << "Here you can input two strings and we will guess - is second an anagrame of first or not" << endl;
    cout << "If you want to finish work - input finish" << endl;
    map<char, int> fst_word;
    map<char, int> snd_word;
    string word_one, word_two;
    bool is_anagramme = true;
    cout << "Input first word: ";
    cin >> word_one;
    cout << "Input second word: ";
    cin >> word_two;
    if (sizeof(word_one) != sizeof(word_two)) {
        is_anagramme = false;
    }
    else {
        str_to_map(word_one, fst_word);
        str_to_map(word_two, snd_word);
        for (map<char, int>::iterator it = fst_word.begin();
             it != fst_word.end(); ++it)
        {
            if (snd_word.find(it->first) != snd_word.end()) {
                if (it->second != snd_word[it->first]) {
                    is_anagramme = false;
                    break;
                }
            }
            else {
                is_anagramme = false;
                break;
            }
        }
    }
    if (is_anagramme) {
        cout << "Yes, the second word is anagrame of the first word! " << endl;
    }
    else {
        cout << "NO, the second word is NOT anagrame of the first word! " << endl;
    }
}