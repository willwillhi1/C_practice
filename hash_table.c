#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct dict{
    string name;
    int id;
    dict(string name, int id):name(name),id(id){}; 
};

class Hash_table{
private:
    int size;
    vector<list<dict>> table;
    int hash_value(string s);
    int hashfunc(string s);
public:
    Hash_table():size(){};
    Hash_table(int n):size(n){
        table.resize(n);
    }
    void insert(dict data);
    void del(string s);
    int search(string s);
    void displayall();
};

int Hash_table::search(string s){
    int index = hashfunc(s);
    for (list<dict>::iterator it = table[index].begin(); it != table[index].end(); it++){
        if((*it).name == s){
            return (*it).id;
        }
    }
    return 0;
}

void Hash_table::del(string s){
    int index = hashfunc(s);
    for (list<dict>::iterator it = table[index].begin(); it != table[index].end(); it++){
        if((*it).name == s){
            table[index].erase(it);
        }
    }
}

void Hash_table::insert(dict data){
    int index = hashfunc(data.name);
    table[index].push_front(data);
}

int Hash_table::hash_value(string s){
    int exp = 5;
    int i = 1;
    int value = 0;
    for (int j = 0; j < s.size(); j++){
        value += s[j]*i;
        i = i*exp; 
    }
    return value;
}

int Hash_table::hashfunc(string s){
    return (hash_value(s) % this->size);
}

void Hash_table::displayall(){
    for (int i = 0; i < table.size(); i++){
        cout << "slot#" << i << ": ";
        for (list<dict>::iterator it = table[i].begin(); it != table[i].end(); it++){
            cout << "(" << (*it).id << "," << (*it).name << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

using namespace std;

int main()
{
    Hash_table hash(5);
    hash.insert(dict("will", 1));
    hash.insert(dict("Bryant", 2));
    hash.insert(dict("Webber", 3));
    hash.insert(dict("Arenas", 4));
    hash.insert(dict("Davis", 5));
    hash.insert(dict("Kidd", 6));
    hash.displayall();

    return 0;
}
