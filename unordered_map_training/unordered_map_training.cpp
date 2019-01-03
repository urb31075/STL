#include <iostream>
#include <functional>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;

struct coord {
    int x;
    int y;
};

namespace std
{
    template<>
    struct hash<coord>
    {
        using  argument_type = coord;
        using  result_type = size_t;
        result_type operator()(const argument_type &c) const {
            return  static_cast<result_type>(c.x) + static_cast<result_type>(c.y);
        }
    };
};

ostream& operator << (ostream &s, const unordered_map <coord, int> &m)
{
    for (auto &i : m) {
        s << "[" << i.first.x << "..."<< i.first.y << " : " << i.second << "]";
    }
    return s;
}

bool operator == (const coord &l, const coord &r){
    return l.x == r.x && l.y == r.y;
}

int main()
{
    cout << "unordered map training!\n";
    unordered_map<coord, int> m{ {{0, 0}, 1}, {{0, 1}, 2}, {{2, 1}, 3} };
    cout << m << endl;
}