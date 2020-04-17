#include<iostream>
#include<cstring>

using namespace std;

// Using Fenwick Tree
class BinaryIndexedTree {
    private:
        long long *Table;
        int Size;    
    public:
        BinaryIndexedTree(int size) {
            Table = new long long[size + 1];
            memset(Table, 0, sizeof(Table));
            Size = size + 1;
        }

        long long getSum(int index) {
            long long sum = 0;
            while(index > 0) {
                sum += Table[index];
                index -= (index & (-index));
            }
            return sum;
        }

        void update(int index, int value) {
            while(index < Size) {
                Table[index] += value;
                index += (index & (-index));
            }
        }

        long long rangeSum(int index1, int index2) {
            long long a, b;
            a = getSum(index1 - 1);
            b = getSum(index2);
            return b - a;
        }
};

int main() {
    int n, q, index1, index2;
    string operation;
    cin >> n >> q;
    BinaryIndexedTree BIT(n);
    while(q--) {
        cin >> operation >> index1 >> index2;
        if(operation == "find")
            cout << BIT.rangeSum(index1, index2) << "\n";
        else 
            BIT.update(index1, index2);
    }
    return 0;
}