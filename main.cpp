#include <iostream>
#include "tree.hpp"
using namespace std;

int main()
{
    tree_t tree;
    char op;
    while (cin >> op && op != 'q') {
        int number;
        switch (op) {
            case '+':
                if (cin >> number) {
                    tree.insert(number);
                    tree.print(cout);
                }
                else {
                    cout << "error"<<'\n';
                    exit(0);
                }
                break;
            case '?':
                if (cin >> number) {
                    bool tmp = tree.find(number);
                    if (tmp) {
                        cout << "true" << '\n';
                    }
                    else {
                        cout << "false" << '\n';
                    }
                }
                else {
                    cout << "error"<<'\n';;
                    exit(0);
                }
                break;
            case '=':
                tree.print(cout);
                break;
        }
        
    }
    
    return 0;
}

