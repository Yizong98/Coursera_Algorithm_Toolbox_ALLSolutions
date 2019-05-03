#include <iostream>
#include <tuple>
using std::make_tuple;
using std::tuple;
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

std::tuple<int, int> get_fibonacci_last_digit_fast(long long n){
    if (n <= 1)
        return std::make_tuple(0,1);
    int previous = 0;
    int current = 1;
    n %= 60;
    for (int i = 0; i < n - 1 ; ++i) {
        int temp = current;
        current = (previous + current) % 10;
        previous = temp;
    }
    return std::make_tuple(previous,current);
}

int fibonacci_sum_squares_fast(long long n) {
     std::tuple<int, int> result = get_fibonacci_last_digit_fast(n+1);
     return std::get<0>(result) * std::get<1>(result) % 10;
    
}


int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n) << "\n";
    std::cout << fibonacci_sum_squares_fast(n) << "\n";
}
