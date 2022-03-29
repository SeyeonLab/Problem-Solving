import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

public class _13305 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] road = new int[N - 1];
        int[] city = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N - 1; i++)
            road[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            city[i] = Integer.parseInt(st.nextToken());

        // 이동하다가 가장 싼 주유소가 있으면 필요한 기름은 이제부터 거기서 전부 구매
        int cost = 1000000001;
        long totalCost = 0L;
        for (int i = 0; i < N - 1; i++) {
            if (city[i] < cost)
                cost = city[i];

            totalCost += cost * (long) road[i];
        }

        bw.write(String.valueOf(totalCost));
        bw.flush();
        bw.close();
    }
}
