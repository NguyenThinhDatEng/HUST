#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/*
10970.8     10970.8     1                       0           0
10655.2     10655.2     1           -315.6      -94.68      94.68
10829.3     10675.836   0.11853     174.1       -14.046     118.506
*/

// define variables
int N;            // number of days
double result[8]; // save the elements in table
double smoothing_parameter = 0.3;

// Procedures
void input();

auto simple_exponential_smoother(double pre_smoothed, double discount_factor, double error);
auto discount_factor(double Q, double D);
auto error(double currentData, double pre_smoothed);
auto smoothed_error(double error, double pre_smoothed_error);
auto deviation(double error, double pre_deviation);

void solve();
void display(double *result);

// main function
int main()
{
    input();
    solve();
    return 0;
}

// Implementation
void input()
{
    do
    {
        cout << "Enter number of days (N > 0): ";
        cin >> N;
    } while (N < 1);
    cout << endl;
}

auto simple_exponential_smoother(double pre_smoothed, double discount_factor, double error)
{
    double smoothed = pre_smoothed + discount_factor * error;
    return smoothed;
}

auto discount_factor(double Q, double D)
{
    return abs(Q / D);
}

auto error(double currentData, double pre_smoothed)
{
    return currentData - pre_smoothed;
}

auto smoothed_error(double error, double pre_smoothed_error)
{
    return smoothing_parameter * error + (1 - smoothing_parameter) * pre_smoothed_error;
}

auto deviation(double error, double pre_deviation)
{
    return smoothing_parameter * abs(error) + (1 - smoothing_parameter) * pre_deviation;
}

void solve()
{
    double Dow_Jones;
    // first day
    cout << "1: ";
    cin >> Dow_Jones;
    result[1] = result[4] = 1;
    result[2] = result[3] = Dow_Jones;
    result[6] = result[7] = 0;
    display(result);
    // the following days
    for (int i = 2; i <= N; i++)
    {
        cout << i << ": Dow Jones index = ";
        cin >> Dow_Jones;
        result[5] = error(Dow_Jones, result[3]);                                  // Error
        result[6] = smoothed_error(result[5], result[6]);                         // Q
        result[7] = deviation(result[5], result[7]);                              // D
        result[4] = discount_factor(result[6], result[7]);                        // λ
        result[3] = simple_exponential_smoother(result[3], result[4], result[5]); // Smoothed
        result[2] = Dow_Jones;
        result[1] = i; // Day
        display(result);
    }
}

void display(double *result)
{
    // Format table titles
    cout << setw(15) << left << "Day";
    cout << setw(15) << left << "Dow Jones";
    cout << setw(15) << left << "Smoothed";
    cout << setw(15) << left << "Alpha";
    cout << setw(15) << left << "Error";
    cout << setw(15) << left << "Q";
    cout << setw(15) << left << "D" << endl;

    cout << setfill('-');
    cout << setw(100) << "-" << endl;

    // reset fill by ' '
    cout << setfill(' ');

    // show information
    if (result[1] > 1)
        for (int i = 1; i <= 7; i++)
        {
            cout << setw(15) << left << result[i];
        }
    else
    {
        for (int i = 1; i <= 4; i++)
        {
            cout << setw(15) << left << result[i];
        }
        cout << setw(15) << left << "";
        for (int i = 6; i <= 7; i++)
        {
            cout << setw(15) << left << result[i];
        }
    }
    cout << '\n'
         << '\n';
}