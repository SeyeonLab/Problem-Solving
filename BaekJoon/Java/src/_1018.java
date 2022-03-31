import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class _1018 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        String[] board = new String[N];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine();
        }

        int answer = 10000;
        for (int i = 0; i <= N - 8; i++) {
            for (int j = 0; j <= M - 8; j++) {
                char pick = 'B';
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if ((k + l) % 2 == 0 && board[i + k].charAt(j + l) != pick) {
                            count++;
                        } else if ((k + l) % 2 == 1 && board[i + k].charAt(j + l) == pick) {
                            count++;
                        }
                    }
                }
                answer = Math.min(answer, count);
                pick = 'W';
                count = 0;
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if ((k + l) % 2 == 0 && board[i + k].charAt(j + l) != pick) {
                            count++;
                        } else if ((k + l) % 2 == 1 && board[i + k].charAt(j + l) == pick) {
                            count++;
                        }
                    }
                }
                answer = Math.min(answer, count);
            }
        }
        System.out.println(answer);
    }
}
