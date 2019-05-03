#include <iostream>
#include <tuple>
#include <unordered_map>
using std::unordered_map;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


long long fibonacci_fast(int n,int m) {
    // write your code here

    unordered_map<long long, long long> fibonacci;
    // set base case
    fibonacci.emplace(0,0);
    fibonacci.emplace(1,1);
    for (int start = 2; start <= n; start++){
        fibonacci.emplace(start, (((long long)fibonacci[start - 1]) + (long long)fibonacci[start - 2]) % m);
    }
    return (long long) fibonacci[n];
}

long long period_helper(long long n, long long m) {
    // structure: hash table to store, responding remainder
    // start from 1
    // steps: for loop, from 2, to n, if not 0, 1, then keep going, aggregate fibonacci and store remainder
    // when hit 0, 1; stop
    unordered_map<long long, long long> fibonacci;
    // set base case
    fibonacci.emplace(0,0);
    fibonacci.emplace(1,1);
    long long prev = 0;
    bool first_encounter = true;
    long long period = 1;
    long long curr = 1;
    for (long long i = 2; i <= n; ++i){
        long long cache = (((long long)fibonacci[i - 1]) + (long long)fibonacci[i - 2]) % m;
        fibonacci.emplace(i, cache);
        if (curr == 1 && prev == 0){
            if (first_encounter) {
                first_encounter = false;
            } else {
                return period;
            }
        } else {
            period++;
        }
        prev = curr;
        curr = cache;
    }
    if (!(curr == 1 && prev == 0))
        //std::cout << "huh" << '\n';
        return period + 2;
    return period;
    // std::cout << "huh" << '\n';

}

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_fast(long long n, long long m) {
    //long long period = period_helper(n,m);
    long long period = get_pisano_period(m);
    long long target = n % period;
    long long fib = fibonacci_fast(target, m);
    //std::cout << target << '\n';
    return fib % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    //std::cout << period_helper(n, m) << '\n';
    //std::cout << get_pisano_period(m) << '\n';
    std::cout << get_fibonacci_fast(n, m) << '\n';
}
