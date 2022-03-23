import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class _1546 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        double M = 0;
        double[] score = new double[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        
        for (int i = 0; i < N; i++) {
            score[i] = Double.parseDouble(st.nextToken());
            M = Math.max(M, score[i]);
        }

        double sum = 0.0;
        for (int i = 0; i < N; i++) {
            sum += (score[i] / M) * 100;
        }

        bw.write(String.valueOf(sum / N));
        bw.flush();
        bw.close();
    }
}
