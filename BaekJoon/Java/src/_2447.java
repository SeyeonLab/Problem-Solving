import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Arrays;

public class _2447 {
    public static char[][] star;

    static void calculate(int row, int col, int n) {
        if (n == 1) {
            star[row][col] = '*';
            return;
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == 1 && j == 1)
                    continue;
                else
                    calculate(row + (i * n/3), col + (j * n/3), n/3);
            }
        }
    }

	public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
 
		star = new char[N][N];
        for (int i = 0; i < N; ++i)
            Arrays.fill(star[i], ' ');

		calculate(0, 0, N);
        
		for (int i = 0; i < N; i++) {
			bw.write(star[i]);	
			bw.write("\n");
		}
        
		bw.flush();
		bw.close();
        scanner.close();
	}
}