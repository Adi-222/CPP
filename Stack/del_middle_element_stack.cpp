#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int count, int size) {
    // Base case
    if (count == size / 2) {
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();

    // Recursive case
    solve(s, count + 1, size);
    s.push(num);
}

int main() {
    stack<int> s;
    int n;
    
    // Push elements into the stack 's'
    // ...

    int size = s.size();  // Calculate the size of the stack
    int count = 0;

    // Print the original stack (optional)
    cout << "Original Stack: ";
    stack<int> temp = s;  // Create a temporary stack to preserve the original stack
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    solve(s, count, n);

    // Print the modified stack
    cout << "Modified Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
