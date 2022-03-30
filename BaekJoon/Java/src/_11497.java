import java.io.*;
import java.util.*;

public class _11497 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < T; tc++) {
            int N = Integer.parseInt(br.readLine());
            int[] beforeLog = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++)
                beforeLog[i] = Integer.parseInt(st.nextToken());

            Arrays.sort(beforeLog);

            int[] afterLog = new int[N];
            int idx = N - 1;

            afterLog[N / 2] = beforeLog[idx--];
            if (N % 2 != 0) {
                for (int i = 1; i <= N / 2; i++) {
                    afterLog[N / 2 - i] = beforeLog[idx--];
                    afterLog[N / 2 + i] = beforeLog[idx--];
                }
            } else if (N % 2 == 0) {
                for (int i = 1; i < N / 2; i++) {
                    afterLog[N / 2 - i] = beforeLog[idx--];
                    afterLog[N / 2 + i] = beforeLog[idx--];
                }
                afterLog[0] = beforeLog[idx--];
            }

            int result = 0;
            for (int i = 0; i < N / 2; i++) {
                result = Math.max(result, afterLog[i + 1] - afterLog[i]);
            }
            for (int i = N / 2; i < N - 1; i++) {
                result = Math.max(result, afterLog[i] - afterLog[i + 1]);
            }

            if (N % 2 != 0)
                result = Math.max(result, afterLog[0] - afterLog[N - 1]);
            else if (N % 2 == 0)
                result = Math.max(result, afterLog[N - 1] - afterLog[0]);

            bw.write(String.valueOf(result) + "\n");
        }
        bw.flush();
        bw.close();
    }
}
