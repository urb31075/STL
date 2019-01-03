#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
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

    /*const auto odd([] (int i) { return i % 2 == 0; });
    const auto erase_iterator = remove_if(begin(v), end(v), odd);
    v.erase(erase_iterator, end(v));
    cout << v << endl;*/

    v.shrink_to_fit();
    cout << v << endl;
    
    vector<int> w{ 123, 456, 789, 100, 200, 300};
    const auto p = find(begin(w), end(w), 456);
    *p = w.back();
    w.pop_back();
    cout << w << endl;
    try {
        cout << w.at(20) << endl;
    } catch(const std::out_of_range &e){
        cout << "Error! " << e.what() << endl;
    }

    assert(false == is_sorted(begin(w), end(w)));
    sort(begin(w), end(w));
    assert(true == is_sorted(begin(w), end(w)));
    cout << w << endl;
    const auto insert_pos = lower_bound(begin(w), end(w), 500);
    w.insert(insert_pos, 500);
    cout << w << endl;
}
