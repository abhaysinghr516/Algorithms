def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

a = 48
b = 18
print(f"GCD of {a} and {b} is {gcd(a, b)}")
