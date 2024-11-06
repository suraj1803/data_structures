#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to compute forward difference table
void forwardDifferenceTable(vector<vector<double>>& table, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    }
}

// Function to apply Newton's forward interpolation
double newtonForwardInterpolation(const vector<double>& x, const vector<vector<double>>& table, double value, int n) {
    double result = table[0][0];
    double u = (value - x[0]) / (x[1] - x[0]); // Calculating u
    double u_term = u;

    for (int i = 1; i < n; i++) {
        result += (u_term * table[0][i]) / factorial(i);
        u_term *= (u - i); // Update u term for next iteration
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n);
    vector<vector<double>> table(n, vector<double>(n, 0.0));

    cout << "Enter the values of x and y:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> table[i][0];
    }

    forwardDifferenceTable(table, n);

    double value;
    cout << "Enter the value to interpolate: ";
    cin >> value;

    double result = newtonForwardInterpolation(x, table, value, n);
    cout << fixed << setprecision(6) << "Interpolated value at " << value << " is " << result << endl;

    return 0;
}

