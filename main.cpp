#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();
    vector <string> codes;
    ifstream in;
    in.open("codes.txt");
    string x;
    if (in.good()){
        while (!in.eof()){
            getline(in, x);
            codes.push_back(x);
        }
    }
    else{
        cout << "unable to open file";
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << duration.count();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(end - start);
duration.count() references elapsed milliseconds
*/