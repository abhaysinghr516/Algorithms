function gcd(a, b) {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}

const a = 48;
const b = 18;
console.log(`GCD of ${a} and ${b} is ${gcd(a, b)}`);
