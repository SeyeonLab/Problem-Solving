import java.util.Scanner;

public class _2828 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int J = scanner.nextInt();
        int left = 1, right = M, move = 0;

        for (int i = 0; i < J; i++) {
            int location = scanner.nextInt();

            if (location < left) {
                move += left - location;
                left = location;
                right = location + M - 1;
            } else if (location > right) {
                move += location - right;
                left = location - M + 1;
                right = location;
            }
        }

        System.out.println(move);
        scanner.close();
    }
}
