import java.io.*;
import java.util.*;

public class _1026 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        int[] B = new int[N];

        // 배열 A 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            A[i] = Integer.parseInt(st.nextToken());

        // 배열 B 입력
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            B[i] = Integer.parseInt(st.nextToken());

        // A의 최소와 B의 최대를 곱하기
        Arrays.sort(A);
        Arrays.sort(B);

        int answer = 0;
        for (int i = 0; i < N; i++) {
            answer += A[i] * B[N - 1 - i];
        }

        System.out.println(answer);
    }
}
