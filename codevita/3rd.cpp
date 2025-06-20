#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> substrings(n);
    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
        cin >> substrings[i] >> cost[i];
    }

    string mainString;
    cin >> mainString;

    int mainLength = mainString.length();

    vector<int> dp(mainLength + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i <= mainLength; i++) {
        if (dp[i] == INT_MAX) continue;

        for (size_t j = 0; j < substrings.size(); j++) {
            string sub = substrings[j];
            int temp = cost[j];

            if (i + static_cast<int>(sub.length()) <= mainLength && 
                mainString.substr(i, sub.length()) == sub) {
                dp[i + static_cast<int>(sub.length())] = 
                    min(dp[i + static_cast<int>(sub.length())], dp[i] + temp);
            }
        }
    }

    int result = dp[mainLength];
    if (result == INT_MAX) {
        cout << "Impossible" << endl;
    } else {
        cout <<result<< endl;
    }

    return 0;
}
