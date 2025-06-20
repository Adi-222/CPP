#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int numEmployees, numConnections;
    cin >> numEmployees >> numConnections;

    vector<vector<int>> employeeFriends(numEmployees);
    for (int i = 0; i < numConnections; ++i) {
        int emp1, emp2;
        cin >> emp1 >> emp2;
        employeeFriends[emp1].push_back(emp2);
        employeeFriends[emp2].push_back(emp1);
    }

    int targetRoster;
    cin >> targetRoster;

    vector<int> employeeStatus(numEmployees, 1);
    int totalInOffice = numEmployees;
    int dayCount = 1;

    while (totalInOffice < targetRoster) {
        vector<int> nextStatus(numEmployees, 0);
        for (int emp = 0; emp < numEmployees; ++emp) {
            int isWorkingToday = employeeStatus[emp];
            int friendsInOffice = 0;

            for (int friendId : employeeFriends[emp]) {
                friendsInOffice += employeeStatus[friendId];
            }

            if (isWorkingToday == 1) {
                nextStatus[emp] = (friendsInOffice == 3) ? 1 : 0;
            } else {
                nextStatus[emp] = (friendsInOffice < 3) ? 1 : 0;
            }
        }

        employeeStatus = nextStatus;
        totalInOffice = 0;
        for (int status : employeeStatus) {
            totalInOffice += status;
        }
        dayCount++;
    }

    cout <<dayCount;
    return 0;
}
