#include <iostream>
#include <vector>
using namespace std;

float f(vector<float> q) {
    return 500 * 20 / q[0] + 5 * q[0] / 2 +
        100 * 10 / q[1] + 10 * q[1] / 2 +
        200 * 5 / q[2] + 4 * q[2] / 2 +
        150 * 3 / q[3] + 2 * q[3] / 2 +
        400 * 7 / q[4] + 20 * q[4] / 2;
}

float f_delta(vector<float> q, float delta, int n) {
    q[n] = q[n] + delta;
    return f(q);
}

vector<float> sum(vector<float>q1, vector<float>q2, int n) {
    for (int i = 0; i < n; i++)
        q1[i] = q1[i] + q2[i];
    return q1;
}

vector<float> dif(vector<float>q1, vector<float>q2, int n) {
    for (int i = 0; i < n; i++)
        q1[i] = q1[i] - q2[i];
    return q1;
}

vector<float> mul(vector<float>q, float k, int n) {
    for (int i = 0; i < n; i++)
        q[i] = q[i] * k;
    return q;
}

void print(vector<float>q, int n) {
    for (int i = 0; i < n; i++)
        cout << 'q' << i + 1 << " = " << q[i] << endl;
}

int main()
{
    float e, delta, delta1, k;
    int m = 1;
    vector <float> q0(5), q1(5), q2(5), q3(5);

    cout << "Enter q1" << endl;
    cin >> q0[0];
    cout << "Enter q2" << endl;
    cin >> q0[1];
    cout << "Enter q3" << endl;
    cin >> q0[2];
    cout << "Enter q4" << endl;
    cin >> q0[3];
    cout << "Enter q5" << endl;
    cin >> q0[4];
    cout << "Enter accuracy" << endl;
    cin >> e;
    cout << "Enter delta" << endl;
    cin >> delta;
    k = 1;

    do {
        delta1 = delta;
        do {
            q1 = q0;
            for (int i = 0; i < 5; i++) {
                if (f_delta(q1, delta, i) < f(q1))
                    q1[i] = q1[i] + delta;
                else
                    if (f_delta(q1, -delta, i) < f(q1))
                        q1[i] = q1[i] - delta;
            }

            if (q1 == q0)
                delta = delta / 2;
        } while ((q1 == q0) && (delta >= e));

        q2 = q0;
        q3 = q1;

        while (f(q3) < f(q2)) {
            q2 = q3;
            q3 = sum(q2, mul(dif(q1, q0, 5), k, 5), 5);
        }

        q0 = q2;
        cout << "i = " << m << endl;
        cout << "q = " << q2[0] << ' ' << q2[1] << ' ' << q2[2] << ' ' << q2[3] << ' ' << q2[4] << endl;
        cout << "delta = " << delta1 << endl << endl;
        m++;
    } while (delta1 > e);

    print(q0, 5);
    cout << "F = " << f(q0) << endl;

    return 0;
}
