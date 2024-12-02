#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double p(const double x);

int main()
{
    double q_start, q_end;
    int n;
    cout << "q_start = "; cin >> q_start;
    cout << "q_end = "; cin >> q_end;
    cout << "n = "; cin >> n;

    double dq = (q_end - q_start) / n;
    double q = q_start;

    cout << "+------------+-----------------------+" << endl;
    cout << "|     q      |          z            |" << endl;
    cout << "+------------+-----------------------+" << endl;

    while (q <= q_end)
    {
        double z = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(q));
        cout << "| " << setw(10) << fixed << setprecision(4) << q
            << " | " << setw(21) << fixed << setprecision(8) << z << " |" << endl;

        q += dq;
    }

    cout << "+------------+-----------------------+" << endl;

    return 0;
}

double p(const double x)
{
    if (abs(x) >= 1)
        return (sin(x) + cos(x)) / (1 + exp(-x));
    else
    {
        double S = 0;
        double term = 1;
        int j = 0;

        while (j < 4)
        {
            S += term;
            j++;
            term *= (-x * x) / ((2 * j - 1) * (2 * j));
        }

        return S;
    }
}
