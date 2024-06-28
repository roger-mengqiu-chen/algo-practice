#include <iostream>


class QuickUnion {
private:
    int* id;
    int size;
    int root(int i) {
        while (i != id[i]) {
            i = id[i];
        }
        return i;
    }
public:
    QuickUnion(int n) : size(n) {
        id = new int[n];
        for(int i = 0; i < n; i++) {
            id[i] = i;
        }
    }

    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    void connect(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

    ~QuickUnion() {
        delete[] id;
    }
};


class WeightedQuickUnion {
private:
    int* id;
    int* size_id;
    int size;

    int root(int i) {
        while(id[i] != i) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
public:
    WeightedQuickUnion(int n) : size(n) {
        id = new int[n];
        size_id = new int[n];
        for(int i = 0; i < n; i++) {
            id[i] = i;
            size_id[i] = 1;
        }
    }

    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    void weighted_union(int a, int b) {
        int root_a = root(a);
        int root_b = root(b);

        if(size_id[root_a] < size_id[root_b]) {
            // if subset of root_a is smaller, attach subset of root_a to root_b
            id[root_a] = id[root_b];
            size_id[root_b] += size_id[root_a];
        }
        else {
            id[root_b] = id[root_a];
            size_id[root_a] += size_id[root_b];
        }
    }
};

int main() {
    WeightedQuickUnion u = WeightedQuickUnion(10);
    u.weighted_union(1, 3);
    u.weighted_union(3, 4);
    u.weighted_union(8, 9);
    std::cout << u.connected(1, 4) << std::endl;
    std::cout << u.connected(1, 9) << std::endl;
}
