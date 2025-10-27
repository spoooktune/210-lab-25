#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
    const int W = 10;
    ifstream in;
    string x;

    cout << setw(W) << "Operation" <<
        setw(W) << "Vector" <<
        setw(W) << "List" << 
        setw(W) << "Set" << endl;
    
    cout << setw(W) << "Read";

    // Vector read
    auto start = high_resolution_clock::now();
    vector<string> codesV;
    in.open("codes.txt");
    if (in.good()){
        while (!in.eof()){
            getline(in, x);
            codesV.push_back(x);
        }
    }
    else{
        cout << "unable to open file";
    }
    in.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << setw(W) << duration.count();

    // List read
    start = high_resolution_clock::now();
    list<string> codesL;
    in.open("codes.txt");
    if (in.good()){
        while (!in.eof()){
            getline(in, x);
            codesL.push_back(x);
        }
    }
    else{
        cout << "unable to open file";
    }
    in.close();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << setw(W) << duration.count();

    // Set read
    start = high_resolution_clock::now();
    set<string> codesS;
    in.open("codes.txt");
    if (in.good()){
        while (!in.eof()){
            getline(in, x);
            codesS.insert(x);
        }
    }
    else{
        cout << "unable to open file";
    }
    in.close();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << setw(W) << duration.count() << endl;

    cout << setw(W) << "Sort";
    
    // Vector sort
    start = high_resolution_clock::now();
    sort(codesV.begin(), codesV.end());
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << setw(W) << duration.count();

    // List sort
    start = high_resolution_clock::now();
    codesL.sort();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << setw(W) << duration.count();

    cout << setw(W) << "-1" << endl;

    cout << setw(W) << "Insert";
    
    // Vector insert
    const string y = "TESTCODE";
    start = high_resolution_clock::now();
    // codesV.insert(y, codesV.begin() + codesV.size());
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << setw(W) << duration.count();

    // List insert
    start = high_resolution_clock::now();
    // codesL.insert(y, codesL.begin() + codesL.size());
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << setw(W) << duration.count();

    // Set insert
    start = high_resolution_clock::now();
    codesS.insert(y);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << setw(W) << duration.count();

    return 0;

}

/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(end - start);
duration.count() references elapsed milliseconds
*/