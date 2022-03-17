import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class _2480 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        
        int answer = 0;
        if (a == b && b == c) answer = 10000 + a * 1000;
        else if (a == b || b == c) answer = 1000 + b * 100;
        else if (a == c) answer = 1000 + a * 100;
        else answer = Math.max(a, Math.max(b, c)) * 100;
        
        bw.write(String.valueOf(answer));
        
        bw.flush();
        bw.close();
    }
}
