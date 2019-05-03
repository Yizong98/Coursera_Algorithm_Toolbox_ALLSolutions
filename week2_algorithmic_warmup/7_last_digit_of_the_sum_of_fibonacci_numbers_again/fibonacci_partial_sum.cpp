#include <iostream>
#include <vector>
#include <stdlib.h>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
    return get_fibonacci_last_digit_fast(n+2) - 1;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to){
    int prefix = get_fibonacci_last_digit_fast(from);
    if (from == to) {
        return prefix;
    } 
    int first = fibonacci_sum_fast(from);
    int second = fibonacci_sum_fast(to);
    if (second < first) {
        second += 10;
    }
    int diff = second - first;
    return (prefix + diff)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
