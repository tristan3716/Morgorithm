/**
 * [ 연속합 ]
 *
 * n개의 정수로 이루어진 임의의 수열이 주어진다.
 * 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
 *
 * 단, 수는 한 개 이상 선택해야 한다.
 *
 * 예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.
 * 여기서 정답은 12+21인 33이 정답이 된다.
 *
 * 첫째 줄에 정수 n( 1 ≤ n ≤ 100,000 )이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다.
 * 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.
 *
 * [예제 입력]                           [예제 출력]
 * 10                                       33
 * 10 -4 3 1 5 6 -35 12 21 -1
 *
 *
 * [생각]
 * --> 부분합 문제
 *
 * 문제 1. 음수가 포함되어도 제일 큰수가 나올 수 있음
 * 문제 2.
 *
 * 점화식
 *
 *
 * @author Sight
 * @since  2019. 07 .14
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Baekjoon_1912 {
    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));

        int   size = Integer.parseInt(br.readLine());
        int[] arr  = Arrays.stream(br.readLine().split(" "))
                           .mapToInt(Integer::parseInt)
                           .toArray();

        int [] DP = new int[size];

        DP[0] = arr[0];
        for(int i = 1 ; i < size ; i++)
        {
            if (DP[i-1] + arr[i] > arr[i])
                DP[i] = DP[i-1] + arr[i];
            else
                DP[i] = arr[i];
        }
        int max = DP[0];

        for(int i = 0 ; i <= size; i++)
            max = Math.max(max, DP[i]);

        if( max < -1000) max = -1000;
        System.out.print(max);
    }
}