def compute_lps(pattern):
    """
    Compute the Longest Prefix Suffix (LPS) array for the given pattern.
    
    Args:
        pattern (str): The pattern string
        
    Returns:
        list: LPS array where lps[i] is the length of the longest proper prefix 
              of pattern[0..i] which is also a proper suffix of pattern[0..i]
    """
    m = len(pattern)
    lps = [0] * m
    length = 0  # Length of the previous longest prefix suffix
    i = 1
    
    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    
    return lps


def kmp_search(text, pattern):
    """
    KMP string matching algorithm - finds all occurrences of pattern in text.
    
    Args:
        text (str): The text string to search in
        pattern (str): The pattern string to search for
        
    Returns:
        list: List of starting indices where pattern is found in text
    """
    if not pattern:
        return []
    
    n = len(text)
    m = len(pattern)
    
    # Compute LPS array for the pattern
    lps = compute_lps(pattern)
    
    matches = []
    i = 0  # Index for text
    j = 0  # Index for pattern
    
    while i < n:
        if pattern[j] == text[i]:
            i += 1
            j += 1
        
        if j == m:
            # Found a match
            matches.append(i - j)
            j = lps[j - 1]
        elif i < n and pattern[j] != text[i]:
            # Mismatch after j matches
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    
    return matches


def kmp_search_first(text, pattern):
    """
    KMP algorithm that returns only the first occurrence.
    
    Args:
        text (str): The text string to search in
        pattern (str): The pattern string to search for
        
    Returns:
        int: Index of first occurrence, or -1 if not found
    """
    if not pattern:
        return -1
    
    n = len(text)
    m = len(pattern)
    
    lps = compute_lps(pattern)
    
    i = 0  # Index for text
    j = 0  # Index for pattern
    
    while i < n:
        if pattern[j] == text[i]:
            i += 1
            j += 1
        
        if j == m:
            return i - j  # Found match
        elif i < n and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    
    return -1  # Pattern not found


def kmp_count(text, pattern):
    """
    Count the number of occurrences of pattern in text using KMP.
    
    Args:
        text (str): The text string to search in
        pattern (str): The pattern string to search for
        
    Returns:
        int: Number of occurrences
    """
    return len(kmp_search(text, pattern))


# Example usage
if __name__ == "__main__":
    text = "ABABDABACDABABCABAB"
    pattern = "ABABCABAB"
    
    print(f"Text: '{text}'")
    print(f"Pattern: '{pattern}'")
    print(f"LPS Array: {compute_lps(pattern)}")
    print(f"All matches: {kmp_search(text, pattern)}")
    print(f"First match: {kmp_search_first(text, pattern)}")
    print(f"Total count: {kmp_count(text, pattern)}")
