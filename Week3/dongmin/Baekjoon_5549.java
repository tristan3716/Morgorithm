/**
 * 상근이는 우주선을 타고 인간이 거주할 수 있는 행성을 찾고 있다.
 * 마침내, 전 세계 최초로 인간이 거주할 수 있는 행성을 찾았다.
 * 이 행성은 정글, 바다, 얼음이 뒤얽힌 행성이다.
 * 상근이는 이 행성에서 거주 할 수 있는 구역의 지도를 만들어 지구로 보냈다.
 *
 * 상근이가 보내온 지도는 가로 Ncm, 세로 Mcm 직사각형 모양이다.
 * 지도는 1cm 크기의 정사각형으로 나누어져 있고, 각 구역의 지형이 알파벳으로 표시되어 있다.
 * 지형은 정글, 바다, 얼음 중 하나이며, 정글은 J, 바다는 O, 얼음은 I로 표시되어 있다.
 *
 * 지구에 있는 정인이는 조사 대상 영역을 K개 만들었다.
 * 이때, 각 영역에 정글, 바다, 얼음이 각각 몇 개씩 있는지 구하는 프로그램을 작성하시오
 *
 * [입력]
 * 첫째 줄에 지도의 크기 M과 N이 주어진다. (1 ≤ M, N ≤ 1000)
 * 둘째 줄에 정인이가 만든 조사 대상 영역의 개수 K가 주어진다. (1 ≤ K ≤ 100000)
 * 셋째 줄부터 M개 줄에는 상근이가 보낸 지도의 내용이 주어진다.
 *
 * 다음 K개 줄에는 조사 대상 영역의 정보가 주어진다.
 * 정보는 네 정수 a b c d로 이루어져 있다.
 * 구역은 직사각형 모양 이며, 왼쪽 위 모서리의 좌표가 (a, b) 오른쪽 아래 모서리의 좌표가 (c, d)이다.
 *
 * @author Sight
 * @since  2019. 07 .14
 *
 * Prefix Sum 부분합 알고리즘을 사용해야함
 * 그냥하면 timeout남
 *
 * --> 근데 부분합으로 구해도 timeout남 ;; 머임? 전처리에서 오래걸리는듯
 *
 * 설명 그림 : https://insight-vue.cf/algo/desc5549.PNG
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.Stream;
class Baekjoon_5549 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // [1] param init
        int[] row_1 = Stream.of(br.readLine().split(" "))
                            .mapToInt(Integer::parseInt)
                            .toArray();
        int m = row_1[0];
        int n = row_1[1];
        int k = Integer.parseInt(br.readLine());

        // [2] 지도 init
        char[][]  map = new char[m+1][n+1];    // 좌표 map
        int[][][] sum = new int[m+1][n+1][3];  // 부분합 sum [상태 3개]

        //  [2-1] 지도에 마킹
        for(int i=0; i < m; i++){
            char[] row = br.readLine().toCharArray();
            for(int j=0; j < row.length; j++){
                map[i+1][j+1] = row[j];
            }
        }

        // [3] 부분합 처리
        for(int i = 1 ;  i <= m; i++) {
            for(int j = 1; j <= n; j++){
                for(int h = 0 ; h < 3; h++) {
                    sum[i][j][h] += sum[i-1][j][h] + sum[i][j-1][h] - sum[i-1][j-1][h];
                }

                switch(map[i][j])
                {
                case 'J':
                    sum[i][j][0]+=1; break;
                case 'O':
                    sum[i][j][1]+=1; break;
                case 'I':
                    sum[i][j][2]+=1; break;
                default:
                    break;
                }
            }
        }

        // [4] 지도 탐색 좌표 처리
        for(int searchIdx=0; searchIdx < k; searchIdx++) {
            int[] box = Stream.of(br.readLine().split(" "))
                              .mapToInt(Integer::parseInt)
                              .toArray();

            // [4-1] 부분합을 이용해 계산 시작
            int ltX = box[0]; int ltY = box[1]; // left top X,Y
            int rbX = box[2]; int rbY = box[3]; // right bottom X,Y

            int jungle = sum[rbX][rbY][0] - sum[ltX-1][rbY][0] - sum[rbX][ltY-1][0] + sum[ltX-1][ltY-1][0];
            int ocean  = sum[rbX][rbY][1] - sum[ltX-1][rbY][1] - sum[rbX][ltY-1][1] + sum[ltX-1][ltY-1][1];
            int ice    = sum[rbX][rbY][2] - sum[ltX-1][rbY][2] - sum[rbX][ltY-1][2] + sum[ltX-1][ltY-1][2];

            System.out.println(
                    String.format("%d %d %d", jungle, ocean, ice)
            );
        }// searchIdx [for loop] end
        br.close();
    }// main() end
}// class end