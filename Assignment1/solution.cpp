#include <iostream>
#include <complex>
using namespace std;

const int MOD = 1e9 + 7;

struct MyComplex {
    long long real, imag;

    MyComplex(long long real, long long imag): real(real), imag(imag) {}

    MyComplex operator *(const MyComplex &value) {
        return MyComplex(real * value.real - imag * value.imag, real * value.imag + imag * value.real);
    }

    MyComplex operator %(long long n) {
        return MyComplex((real % n + n) % n, (imag % n + n) % n);
    }
};

MyComplex power(MyComplex c, long long n) {
    if(!n) return MyComplex(1, 0);
    if(n % 2 == 0) return power(c * c % MOD, n / 2) % MOD;
    else return power(c * c % MOD, n / 2) % MOD * c % MOD;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        long long int a, b, n;
        cin >> a >> b >> n;
        MyComplex result = power(MyComplex(a % MOD, b % MOD), n);
        cout << result.real << " " << result.imag << endl;
    }
    return 0;
}
