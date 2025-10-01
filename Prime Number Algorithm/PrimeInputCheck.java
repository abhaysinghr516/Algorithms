import java.util.Scanner;

public class PrimeInputCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt user to enter a number
        System.out.print("Enter a number to check if it's prime: ");
        int num = scanner.nextInt();

        // Edge case: numbers less than or equal to 1 are not prime
        if (num <= 1) {
            System.out.println(num + " is NOT a prime number.");
            return;
        }

        boolean isPrime = true;

        // Loop from 2 to sqrt(num) to check for factors
        for (int i = 2; i * i <= num; i++) {
            // If num is divisible by any i, it's not prime
            if (num % i == 0) {
                isPrime = false;
                break; // No need to check further
            }
        }

        // Output result based on isPrime flag
        if (isPrime) {
            System.out.println(num + " is a PRIME number.");
        } else {
            System.out.println(num + " is NOT a prime number.");
        }

        scanner.close(); // Close the scanner to avoid resource leak
    }
}
