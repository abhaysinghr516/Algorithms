public class EuclidsAlgorithm {
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        int a = 48;
        int b = 18;
        System.out.printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    }
}
