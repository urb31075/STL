#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
ostream& operator << (ostream &s, const vector<int> &v)
{
    for (auto &i : v) {
        i == v.back() ? s << i << " back " : s << i << ", ";
    }
    return s;
}


int main()
{
    cout << "vector training!\n"; 
    vector<int> v {1, 2, 3, 2, 5, 2, 6, 2, 4, 8};
    cout << v.front() << endl;
    cout << v.back() << endl;

    cout << v << endl;
    const auto erase_iterator = remove(begin(v), end(v), 2);
    cout << v << endl;
    v.erase(erase_iterator, end(v));
    cout << v << endl;

    const auto odd([] (int i) {
        return i % 2 == 0;
    });

    /*const auto erase_iterator = remove_if(begin(v), end(v), odd);
    v.erase(erase_iterator, end(v));
    cout << v << endl;*/
    v.shrink_to_fit();
    cout << v << endl;
}
