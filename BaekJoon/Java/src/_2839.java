import java.util.Scanner;

public class _2839 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int count = 0;

        while (N > 0) {
            if (N % 5 == 0)
                N -= 5;
            else if (N % 3 == 0)
                N -= 3;
            else if (N > 5)
                N -= 5;
            else {
                count = -1;
                break;
            }
            count++;
        }
        System.out.print(count);
        scanner.close();
    }
}
