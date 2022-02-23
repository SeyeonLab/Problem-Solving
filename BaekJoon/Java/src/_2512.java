import java.util.*;
import java.util.stream.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] budgets = new int[N];

        for (int i = 0; i < N; ++i)
            budgets[i] = scanner.nextInt();
            
        int M = scanner.nextInt();
        int answer = 0;
        int min = 0;
        int max = IntStream.of(budgets).max().orElse(0);

        while (min <= max) {
            final int mid = (min + max) / 2;
            // final int mid = min + (max - min) / 2;
            
            int sum = IntStream.of(budgets).map(b -> Math.min(b, mid)).sum();
            
            /* int sum = 0;

            for (int b : budgets) {
                if (b > mid) sum += mid;
                else sum += b;
            } */
            
            if (sum <= M) {
                min = mid + 1;
                answer = Math.max(answer, mid);
            } else {
                max = mid - 1;
            }
        }
        scanner.close();
        System.out.println(answer);
    }
}
