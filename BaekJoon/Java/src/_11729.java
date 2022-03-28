import java.util.Scanner;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;

public class _11729 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static void hanoi(int n, int start, int temp, int end) throws Exception {
        if (n == 1) {
            bw.write(start + " " + end + "\n");
            return;
        }

        hanoi(n - 1, start, end, temp);
        bw.write(start + " " + end + "\n");
        hanoi(n - 1, temp, start, end);
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        bw.write((int) (Math.pow(2, N) - 1) + "\n");

        hanoi(N, 1, 2, 3);

        bw.flush();
        bw.close();
        scanner.close();
    }
}
