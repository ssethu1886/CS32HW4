#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "WordTree.h"
using namespace std;

int main(int argc, const char * argv[]) {

    WordTree w;
    w.add("Harry");
    w.add("Niall");
    w.add("Niall");
    w.add("Liam");
    w.add("Louis");
    w.add("Harry");
    w.add("Niall");
    w.add("Zayn");
    cout << w;
    cout << endl;
    WordTree w3(w);
    w3.add("cat");
    cout << w3;
    cout << endl;
    w3 = w;
    cout << endl;
    cout << w;
    cout << w.distinctWords();
    cout << w.totalWords();
    

    return 0;
}
