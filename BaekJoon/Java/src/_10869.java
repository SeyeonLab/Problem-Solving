import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

public class _10869 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());       
        bw.write(String.valueOf(a+b)+'\n');       
        bw.write(String.valueOf(a-b)+'\n');       
        bw.write(String.valueOf(a*b)+'\n');       
        bw.write(String.valueOf(a/b)+'\n');   
        bw.write(String.valueOf(a%b)+'\n');

        br.close();
        bw.close();
    }
}
