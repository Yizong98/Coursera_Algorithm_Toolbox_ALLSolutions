#include <iostream>
#include <vector>
using std::vector;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


int get_fibonacci_last_digit_fast(long long n){
    if (n <= 1)
        return n;
    int previous = 0;
    int current = 1;
    n %= 60;
    for (int i = 0; i < n - 1 ; ++i) {
        int temp = current;
        current = (previous + current) % 10;
        previous = temp;
    }
    return current;
}

int fibonacci_sum_fast(long long n) {
    int result = get_fibonacci_last_digit_fast(n+2);
    if (result == 0) {
        return 9;
    }
    return result - 1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << "\n";
    std::cout << fibonacci_sum_fast(n) << "\n";
}
