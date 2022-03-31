import java.util.Scanner;

public class _7568 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] weight = new int[N];
        int[] height = new int[N];

        for (int i = 0; i < N; i++) {
            weight[i] = scanner.nextInt();
            height[i] = scanner.nextInt();
        }

        int count;
        for (int i = 0; i < N; i++) {
            count = 1;
            for (int j = 0; j < N; j++) {
                if (weight[i] < weight[j] && height[i] < height[j]) {
                    count++;
                }
            }
            System.out.print(count + " ");
        }
        scanner.close();
    }
}
