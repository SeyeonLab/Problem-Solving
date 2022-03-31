import java.util.Scanner;

public class _7568 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[][] weight = new int[N][2];
        int[] height = new int[N];

        for (int i = 0; i < N; i++) {
            weight[i][0] = i;
            weight[i][1] = scanner.nextInt();
            height[i] = scanner.nextInt();
        }

        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int tempIdx = weight[i][0];
                int tempWeight = weight[i][1];
                
                if ()
            }
        }

        for (int i = 0; i < N; i++) {
            System.out.print(rank[i] + " ");
        }
        scanner.close();
    }
}
