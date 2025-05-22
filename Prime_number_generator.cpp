#include <iostream>
#include <vector>

void generatePrimes(int limit) {
    // Create a boolean array "isPrime[0..limit]" and initialize
    // all entries as true. A value in isPrime[i] will
    // finally be false if i is Not a prime, else true.
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= limit; p++) {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p]) {
            // Update all multiples of p
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Print all prime numbers
    std::cout << "Prime numbers up to " << limit << " are: ";
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            std::cout << p << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int limit;
    std::cout << "Enter the limit up to which you want to generate prime numbers: ";
    std::cin >> limit;

    generatePrimes(limit);

    return 0;
}
