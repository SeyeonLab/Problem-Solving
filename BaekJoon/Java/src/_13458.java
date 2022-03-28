import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

public class _13458 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] testRoom = new int[N];

        for (int i = 0; i < N; ++i)
            testRoom[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        Long answer = 0L;
        for (int i = 0; i < N; ++i) {
            testRoom[i] -= B;
            answer++;

            if (testRoom[i] > 0) {
                if (testRoom[i] % C == 0) {
                    answer += testRoom[i] / C;
                } else {
                    answer += testRoom[i] / C + 1;
                }
            }
        }
        bw.write(String.valueOf(answer));
        bw.flush();
        bw.close();
    }
}
