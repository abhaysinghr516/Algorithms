# Sieve of Eratosthenes Algorithm

The Sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to a given limit n. It works by iteratively marking the multiples of each prime number as composite, starting from 2, and systematically eliminating all non-prime numbers to leave only the primes.

## Time Complexity

Best: O(n log(log n))
Average: O(n log(log n))
Worst: O(n log(log n))

## Space Complexity
O(n) - Basic implementation
O(√n) - Segmented sieve optimization

## Example Use Case

Finding all prime numbers up to a large limit efficiently, commonly used in cryptography for key generation, number theory applications, network security protocols, and competitive programming problems that require prime number enumeration or primality testing.
