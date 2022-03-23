import java.util.Scanner;

public class _2577 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] count = new int[10];

        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        String num = String.valueOf(A * B * C);
        
        for (int i = 0; i < num.length(); ++i) {
            count[num.charAt(i) - '0']++;
        }

        for (int i = 0; i < count.length; ++i) {
            System.out.println(count[i]);
        }
        
        scanner.close();
    }
}
