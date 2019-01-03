#include <iostream>
#include <functional>
#include <map>
#include <list>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;

ostream& operator << (ostream &s, const map <string, size_t> &m)
{
    for (auto &i : m) {
        s << "[" << i.first << " : " << i.second << "]";
    }
    return s;
}

int main()
{
    cout << "map training!\n";
    struct dupel {
        string name;
        double amount;
        string country;
    };
    
    list<dupel> dupels {
        {"xxx", 86.0, "USA"},
        {"yyy", 75.6, "USA"},
        {"zzz", 71.2, "USA"},
        {"aaa", 11.1, "SPAIN"},
        {"bbb", 11.2, "SPAIN"},
        {"ccc", 11.3, "SPAIN"},
        {"ddd", 11.4, "SPAIN"},
        {"qqq", 10.1, "FRANCE"},
        {"www", 20.1, "FRANCE"},
    };

    map<string, pair<const dupel, size_t>> dupel_map;

    for (const auto &d : dupels){
        auto[iterator, succes] = dupel_map.try_emplace(d.country, d, 1);
        if (!succes) iterator->second.second += 1;
    }

    for (const auto &[key, value] : dupel_map){
        const auto &[b, count] = value;
        cout << b.country << " : " << count << endl;
    }

    map <string, size_t> m{ {"a", 1}, {"b", 2}, {"c", 3}, {"d", 4} };
    auto xxx(m);
    cout << xxx << endl;
    auto insert_it(end(m));

    for (const auto &s : {"q", "w", "r", "t"}) {
        insert_it = m.insert(insert_it, { s, 111 });
    }
    cout << m << endl;

    auto k1(m.extract("a"));
    auto k2(m.extract("b"));
    swap(k1.key(), k2.key());
    m.insert(move(k1));
    m.insert(move(k2));

    cout << m << endl;
};


