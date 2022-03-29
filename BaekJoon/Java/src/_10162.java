import java.util.Scanner;

public class _10162 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        int A = 0, B = 0, C = 0;

        // A : 300초, B : 60초, C : 10초
        if (T % 10 != 0) {
            System.out.println("-1");
            scanner.close();
            return;
        } else {
            if (T >= 300) {
                A += T / 300;
                T %= 300;
            }
            if (T >= 60) {
                B += T / 60;
                T %= 60;
            }
            if (T >= 10) {
                C += T / 10;
                T %= 10;
            }
        }

        System.out.println(A + " " + B + " " + C);
        scanner.close();
    }
}
