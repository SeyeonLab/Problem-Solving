import java.util.Scanner;

public class _11720 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        String S = scanner.next();

        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += S.charAt(i) - '0';

        System.out.println(sum);
        scanner.close();
    }    
}
