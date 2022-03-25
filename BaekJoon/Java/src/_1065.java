import java.util.Scanner;

public class _1065 {
    public static int hanNum = 0;

    public static void f(int n) {
        int A = n / 100; n = n % 100;
        int B = n / 10; n = n % 10;
        int C = n;

        if (A - B == B - C)
            hanNum++;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        for (int i = 1; i <= N; ++i) {
            if (i < 100) hanNum++;
            else f(i);
        }

        System.out.println(hanNum);
        scanner.close();
    }    
}
