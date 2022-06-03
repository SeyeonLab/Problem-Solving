import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class _10986 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        // 수열 입력 받기, 구간 합 구하기
        long[] A = new long[N + 1];
        long[] S = new long[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            S[i] = S[i - 1] + A[i];
        }
        
        // 같은 나머지의 인덱스를 카운트하는 배열
        long[] C = new long[M];
        long answer = 0;
        for (int i = 1; i <= N; i++) {
            int remainder = (int) (S[i] % M);
            if (remainder == 0)
                answer++;
            C[remainder]++;
        }

        for (int i = 0; i < M; i++) {
            if (C[i] > 1) {
                answer += (C[i] * (C[i] - 1) / 2);
            }
        }

        System.out.println(answer);
    }
}