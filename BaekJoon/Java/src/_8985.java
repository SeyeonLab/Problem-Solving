import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class _8985 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            String quizResult = br.readLine();
            int sum = 0;
            int score = 1;
            for (int i = 0; i < quizResult.length(); ++i) {
                if (quizResult.charAt(i) == 'O') {
                    sum += score++;
                }
                else {
                    score = 1;
                }
            }
            bw.write(String.valueOf(sum) + '\n');
        }

        bw.flush();
        bw.close();
    }
}