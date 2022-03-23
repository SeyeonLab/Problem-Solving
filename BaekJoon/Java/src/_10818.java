import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

public class _10818 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int arr[] = new int[N];
        int min = 1000001, max = -1000001;
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < N; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
            if (min > arr[i]) min = arr[i];
            if (max < arr[i]) max = arr[i];
        }
        
        bw.write(min + " " + max);

        bw.flush();
        bw.close();
    }
}
