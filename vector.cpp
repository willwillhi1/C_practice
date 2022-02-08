#include <iostream>
#include <vector>

using namespace std;

struct node
{
  int value = 0;
  node *left = NULL;
  node *right = NULL;
};

void plus1_v1(vector<node>*);
vector<node> *plus1_v2(vector<node>*);

int main()
{
    /*vector operator*/
    vector<int> v = {1, 2, 3};
    v.push_back(1);
    v.push_back(2);
    
    cout << "iterator all" << endl;
    
    for(vector<int>:: iterator it = v.begin();it != v.end(); it++)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    cout << "--------------" << endl;
    
    cout << "pop_back" << endl;
    v.pop_back();
    for(vector<int>:: iterator it = v.begin();it != v.end(); it++)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    cout << "--------------" << endl;
    
    cout << "size" << endl;
    cout << v.size() << endl;
    
    cout << "--------------" << endl;
    cout << "empty" << endl;
    //v.empty();
    cout << v.empty() << endl;
    
    cout << "--------------" << endl;
    cout << "insert" << endl;
    v.insert(v.begin()+1, 6);
    for(vector<int>:: iterator it = v.begin();it != v.end(); it++)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    cout << "--------------" << endl;
    cout << "erase" << endl;
    v.erase(v.begin()+1);
    for(vector<int>:: iterator it = v.begin();it != v.end(); it++)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    cout << "--------------" << endl;
    cout << "clear" << endl;
    v.clear();
    cout << "vector's size: " <<v.size() << endl;
    
    
    /* vector pointer pratice */
    
    node n1;
    node n2;
    n1.value = 1;
    n2.value = 2;
    vector<node> *node_v = new vector<node>;
    node_v->push_back(n1);
    node_v->push_back(n2);
    
    cout << (*node_v)[0].value << endl;
    
    /*
    vector<node>::iterator it = node_v->begin();
    cout << (*it).value << endl;
    */
    //v1
    plus1_v1(node_v);
    cout << (*node_v)[0].value << endl;
    
    //v2
    vector<node> *tmp = plus1_v2(node_v);
    cout << (*tmp)[0].value << endl;
    
    //2-dim vector pointer
    
    vector<vector<int>> *v = new vector<vector<int>>;
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    v->push_back(v1);
    v->push_back(v2);
    cout << (*v)[0].at(1) << endl;
    
    return 0;
}

void plus1_v1(vector<node> *v)
{
    for(vector<node>::iterator it = v->begin();it != v->end();it++)
    {
        (*it).value++;
    }
    return;
}

vector<node> *plus1_v2(vector<node> *v)
{
    vector<node> *v1 = v;
    for(vector<node>::iterator it=v1->begin();it != v1->end();it++)
    {
        (*it).value++;
    }
    return v1;
}


