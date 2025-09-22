package main

import "fmt"

func gcd(a int, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

func main() {
    a := 48
    b := 18
    fmt.Printf("GCD of %d and %d is %d\n", a, b, gcd(a, b))
}
