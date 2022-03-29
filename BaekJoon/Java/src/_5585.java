import java.util.Scanner;

public class _5585 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int changes = 1000 - scanner.nextInt();
        int[] coin = { 500, 100, 50, 10, 5, 1 };
        int answer = 0;

        for (int i = 0; i < coin.length; i++) {
            if (changes >= coin[i]) {
                answer += changes / coin[i];
                changes %= coin[i];
            }
        }

        System.out.print(answer);
        scanner.close();
    }
}
