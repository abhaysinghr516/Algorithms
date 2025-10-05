def is_prime_efficient(n: int) -> bool:
    """
    Most efficient method - check 2, 3, then 6k±1 pattern
    
    Args:
        n (int): Number to check
        
    Returns:
        bool: True if prime, False otherwise
    """
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    # Check for divisors of the form 6k ± 1
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


if name == '__main__':
    n = int(input())
    print(is_prime_efficient(n))