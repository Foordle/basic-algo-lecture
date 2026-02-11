#include <bits/stdc++.h>
using namespace std;

int n, k;

struct Jewel {
    int weight;
    int price;

    bool operator<(const Jewel& jewel) const {
        if (price != jewel.price) return price < jewel.price;
        else return weight > jewel.weight;
    }
};
multiset<Jewel> jewels;
multiset<int> bags;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        Jewel temp;
        cin >> temp.weight >> temp.price;
        jewels.insert(temp);

    }
    for (int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        bags.insert(c);
    }

    long long sum = 0;

    for (auto jewelsIt = jewels.rbegin(); jewelsIt != jewels.rend(); ++jewelsIt) {
        if (bags.empty()) break;
        auto bagIt = bags.lower_bound(jewelsIt -> weight);

        if (bagIt != bags.end()) {
            sum += jewelsIt -> price;
            bags.erase(bagIt);
        }

    }

    cout<< sum << '\n';

    return 0;
}