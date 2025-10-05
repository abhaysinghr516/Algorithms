def sieve(n):
   
    #Create a boolean list to track prime status of numbers
    prime = [True] * (n + 1)
    p = 2

    # Sieve of Eratosthenes algorithm
    while p * p <= n:
        if prime[p]:
            
            # Mark all multiples of p as non-prime
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1

    # Collect all prime numbers
    res = []
    for p in range(2, n + 1):
        if prime[p]:
            res.append(p)
    
    return res

if __name__ == "__main__":
    n = 35
    res = sieve(n)
    for ele in res:
        print(ele, end=' ')