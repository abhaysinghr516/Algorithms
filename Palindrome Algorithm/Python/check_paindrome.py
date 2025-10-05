def is_palindrome_basic(num):
    """
    Check if a number is palindrome using basic approach (reverse and compare)
    
    Args:
        num (int): The number to check
        
    Returns:
        bool: True if palindrome, False otherwise
    """
    if num < 0:
        return False
    
    original = num
    reversed_num = 0
    
    while num > 0:
        digit = num % 10
        reversed_num = reversed_num * 10 + digit
        num = num // 10
    
    return original == reversed_num


def is_palindrome_string(num):
    """
    Check if a number is palindrome using string slicing
    
    Args:
        num (int): The number to check
        
    Returns:
        bool: True if palindrome, False otherwise
    """
    if num < 0:
        return False
    
    str_num = str(num)
    return str_num == str_num[::-1]


def is_palindrome_half_reverse(num):
    """
    Optimized approach: only reverse half the number
    
    Args:
        num (int): The number to check
        
    Returns:
        bool: True if palindrome, False otherwise
    """
    if num < 0:
        return False
    
    if num < 10:
        return True
    
    if num % 10 == 0:
        return False
    
    reversed_half = 0
    while num > reversed_half:
        reversed_half = reversed_half * 10 + num % 10
        num //= 10
    
    # For odd number of digits, divide by 10 to remove middle digit
    return num == reversed_half or num == reversed_half // 10


def is_palindrome_one_liner(num):
    """
    One-liner approach using string slicing
    
    Args:
        num (int): The number to check
        
    Returns:
        bool: True if palindrome, False otherwise
    """
    return num >= 0 and str(num) == str(num)[::-1]


def find_palindromes_in_range(start, end):
    """
    Find all palindrome numbers in a given range
    
    Args:
        start (int): Start of range
        end (int): End of range
        
    Returns:
        list: List of palindrome numbers
    """
    palindromes = []
    for num in range(start, end + 1):
        if is_palindrome_string(num):
            palindromes.append(num)
    return palindromes


# Simple usage example
def main():
    # Test different numbers
    test_numbers = [121, -121, 10, 12321, 1234, 9, 0]
    
    print("=== PALINDROME NUMBER CHECKER ===\n")
    
    for num in test_numbers:
        if is_palindrome_string(num):
            print(f"{num} is a PALINDROME")
        else:
            print(f"{num} is NOT a palindrome")
    
    # Find palindromes in range
    print(f"\nPalindrome numbers from 1 to 50:")
    palindromes = find_palindromes_in_range(1, 50)
    print(palindromes)


if __name__ == "__main__":
    main()
