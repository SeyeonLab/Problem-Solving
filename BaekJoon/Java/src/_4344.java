import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class _4344 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= T; tc++){
            st = new StringTokenizer(br.readLine());

            int sum = 0;
            int studentCnt = Integer.parseInt(st.nextToken());
            int[] students = new int[studentCnt];

            for (int i = 0; i < studentCnt; ++i) {
                students[i] = Integer.parseInt(st.nextToken());
                sum += students[i];
            }

            int goodStudent = 0;
            for (int i = 0; i < studentCnt; ++i) {
                if ((double)students[i] > ((double)sum / studentCnt)) goodStudent++;
            }

            double answer = (goodStudent / (double)studentCnt) * 100;
            System.out.printf("%.3f%%\n", answer);
        }   
        
        bw.flush();
        bw.close();
    }
}
