#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string document;
    string word;
    int found;
    int count = 0;

    getline(cin, document);
    getline(cin, word);
    
    found = document.find(word);
    
    while (found != string::npos) {
        count++;
        found = document.find(word, found + word.size());
    }
    cout << count << '\n';

    return 0;
}