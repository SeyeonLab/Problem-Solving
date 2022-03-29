import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class _11399 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] num = new int[N];
        for (int i = 0; i < N; i++)
            num[i] = Integer.parseInt(st.nextToken());

        // 정렬하기
        Arrays.sort(num);
        for (int i = 1; i < N; i++)
            num[i] += num[i - 1];

        // 최소 시간 계산
        int answer = 0;
        for (int i = 0; i < N; i++)
            answer += num[i];

        System.out.print(answer);
    }
}
