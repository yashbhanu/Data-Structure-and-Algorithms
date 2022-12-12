#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// a map is a data structure which stores data in key:value pairs
// insertion, deletion & searching in map is done in O(1) time complexity

int main() {

    //creation
    unordered_map<string, int> m;

    //insertion
    // 1
    pair<string,int> pair1 = make_pair("yash", 3);
    m.insert(pair1);

    // 2
    pair<string,int> pair2("bhanu", 2);
    m.insert(pair2);

    // 3
    m["name"] = 1;

    
    //updation
    m["name"] = 2;

    //search
    cout << m["name"] << endl;
    cout << m.at("yash") << endl;

    // cout << m.at("unknownkey") << endl;      //throw an error bcz "unknownkey" doesnt exists
    cout << m["unknownkey"] << endl;        // will create an entry and output 0
    cout << m.at("unknownkey") << endl;     // output 0

    //to check present or not
    cout << m.count("bro") << endl;         // if present then output will be 1 , else 0
    
    //size
    cout << m.size() << endl;

    //erase
    m.erase("yash"); 
    cout << m.size() << endl;


    //print all values in map
    // 1. for loop
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    // 2. iterator
    unordered_map<string, int> ::iterator it = m.begin();       //iterator it which starts from map's beginning (m.begin())
    //loop over map
    while (it != m.end())   
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    

return 0;
}