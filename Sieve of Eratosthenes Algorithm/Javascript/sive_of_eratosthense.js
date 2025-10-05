function sieve(n) {
    
    // Create a boolean array to mark primes
    let prime = new Array(n + 1).fill(true);
    
    // 0 and 1 are not prime
    prime[0] = prime[1] = false; 

    // Apply Sieve of Eratosthenes
    for (let p = 2; p * p <= n; p++) {
        if (prime[p]) {
          
            // Mark all multiples of p as not prime
            for (let i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Collect all primes into result array
    let res = [];
    for (let p = 2; p <= n; p++) {
        if (prime[p]) {
            res.push(p);
        }
    }

    return res;
}

// Driver code
let n = 35;
let res = sieve(n);
console.log(res.join(' '));