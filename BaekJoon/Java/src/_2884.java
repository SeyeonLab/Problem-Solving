import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;

public class _2884 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int H = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        if (H == 0 && M < 45) {
            H = 23;
            M += 15;
        }
        else if (H > 0 && M < 45) {
            H -= 1;
            M += 15;
        }
        else {
            M -= 45;
        }
        System.out.println(H + " " + M);
    }
}
