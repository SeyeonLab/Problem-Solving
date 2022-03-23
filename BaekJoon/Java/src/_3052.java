import java.util.Scanner;

public class _3052 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean[] remainder = new boolean[42];

        for (int i = 0; i < 10; ++i) {
            int num = scanner.nextInt();
            remainder[num % 42] = true;
        }

        int count = 0;
        for (int i = 0; i < remainder.length; ++i) {
            if (remainder[i]) count++;
        }

        System.out.println(count);        
        scanner.close();
    }
}
