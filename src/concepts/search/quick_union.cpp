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