import java.util.Scanner;

public class _2231 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int tempN = N;
        int idx = 0;
        int answer = 0;

        while (tempN > 0) {
            tempN /= 10;
            idx++;
        }

        for (int i = N - 1; i > N - idx * 9; i--) {
            int temp = i;
            int sum = i;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            if (sum == N) {
                answer = i;
            }
        }

        System.out.print(answer);
        scanner.close();
    }
}
