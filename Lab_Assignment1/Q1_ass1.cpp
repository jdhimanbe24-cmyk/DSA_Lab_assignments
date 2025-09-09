// develop a menu driven program to 1.CREATE 2.DISPLAY 3.INSERT 4.DELETE 5.LINEAR SEARCH 6.EXIT
#include <iostream>
using namespace std;

#define MAX 100

class ArrayOps {
    int arr[MAX], n;
public:
    ArrayOps() { n = 0; }

    void create() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) cin >> arr[i];
    }

    void display() {
        if (n == 0) { cout << "Array is empty!\n"; return; }
        cout << "Array elements: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void insert() {
        int pos, val;
        cout << "Enter position (0-based index): "; cin >> pos;
        cout << "Enter value: "; cin >> val;
        if (pos < 0 || pos > n) { cout << "Invalid position!\n"; return; }
        for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
        arr[pos] = val;
        n++;
    }

    void remove() {
        int pos;
        cout << "Enter position to delete (0-based index): "; cin >> pos;
        if (pos < 0 || pos >= n) { cout << "Invalid position!\n"; return; }
        for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
        n--;
    }

    void linearSearch() {
        int key;
        cout << "Enter value to search: "; cin >> key;
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) { cout << "Found at position " << i << endl; return; }
        }
        cout << "Not found!\n";
    }
};

int main() {
    ArrayOps obj;
    int choice;
    do {
        cout << "\n——MENU——\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.insert(); break;
            case 4: obj.remove(); break;
            case 5: obj.linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;

}
