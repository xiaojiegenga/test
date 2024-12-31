#include <iostream>
#include <unordered_map>

using namespace std;



int main(void){
    unordered_map<int, string> map;
    map[12836] = "John";
    map[23456] = "Mary";
    map[34567] = "Tom";     
    map[45678] = "Jane";
    map[56789] = "David";

    string name = map[12836];
    cout << "name is: " << name << endl;
    map.erase(23456);
    cout << "size of map is:" << map.size() << endl;

    for(auto kv: map){
        cout << kv.first << "->" << kv.second << endl;
    }

    return 0;
}