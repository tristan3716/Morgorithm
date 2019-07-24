/**
 * 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
 *
 * 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에
 * 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고,
 * 길이는 4이다.
 *
 * @author Sight
 * @since  2019. 07 .14
 *
 * [입력]
 * 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
 * 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
 *
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.Stream;

class Baekjoon_11053 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] cnt = new int[1001];
        int result = 0;

        // [1] param init
        int  size = Integer.parseInt(br.readLine());
        int[] seq = Stream.of(br.readLine().split(" "))
                          .mapToInt(Integer::parseInt)
                          .toArray();
        br.close();

        for(int i = 0 ; i < size; i++){
            cnt[i] = 1;
            for(int j = 0; j < i; j++) {
                if (seq[i] > seq[j]) cnt[i] = Math.max(cnt[i], cnt[j] + 1);
            }
            result = Math.max(result, cnt[i]);
        }
        System.out.println(result);
    }// main() end
}// class end


