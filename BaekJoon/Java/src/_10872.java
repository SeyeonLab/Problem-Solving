import java.util.Scanner;

public class _10872 {
    static int factorial(int n) {
        if (n == 1 || n == 0)
            return 1;
        
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(factorial(N));
        scanner.close();
    }    
}
