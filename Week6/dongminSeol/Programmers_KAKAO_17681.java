import java.util.ArrayList;
import java.util.List;

/**
 * [비밀지도]
 *
 * 네오는 평소 프로도가 비상금을 숨겨놓는 장소를 알려줄 비밀지도를 손에 넣었다.
 * 그런데 이 비밀지도는 숫자로 암호화되어 있어 위치를 확인하기 위해서는 암호를 해독해야 한다.
 * 다행히 지도 암호를 해독할 방법을 적어놓은 메모도 함께 발견했다.
 *
 * 1. 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 공백(" ) 또는벽(#") 두 종류로 이루어져 있다.
 *
 * 2. 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 각각 "지도 1"과 "지도 2"라고 하자.
 *   "지도 1" 또는 "지도 2" 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다.
 *   "지도 1"과 "지도 2"에서 모두 공백인 부분은 전체 지도에서도 공백이다.
 *
 * 3. "지도 1"과 "지도 2"는 각각 정수 배열로 암호화되어 있다.
 * 4. 암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때
 *    얻어지는 이진수에 해당하는 값의 배열이다.
 */
class Programmers_KAKAO_17681 {
    public static void main(String[] args) {
        Programmers_KAKAO_17681 p = new Programmers_KAKAO_17681();

        int n       = 5;
        int[] arr1	= {9, 20, 28, 18, 11};
        int[] arr2	= {30, 1, 21, 17, 28};

        p.solution(n, arr1, arr2);
    } // end main

    public String[] solution(int n, int[] map1, int[] map2) {

        // [1] container 세팅
        List<char[]> a1 = new ArrayList<>(n);
        List<char[]> a2 = new ArrayList<>(n);
        List<char[]> a3 = new ArrayList<>(n);

        // [2] 1번째 지도 처리
        for(int i = 0 ; i < map1.length ; i++) {

            char[] cols = String.format("%16s", Integer.toBinaryString(map1[i]))
                                .replace(' ', '0')
                                .substring(16-n, 16)
                                .toCharArray();
            a1.add(cols);
        }

        // [2] 2번째 지도 처리
        for(int i = 0 ; i < map2.length ; i++) {

            char[] cols = String.format("%16s", Integer.toBinaryString(map2[i]))
                    .replace(' ', '0')
                    .substring(16-n, 16)
                    .toCharArray();

            a2.add(cols);
        }

        // [3] 1,2 번째 지도를 통해 3번째 지도 처리
        for (int i = 0; i < n ; i++) {

            char[] row = new char[n];
            for (int j = 0; j < n; j++) {
                boolean isBlocked = false;
                if(a1.get(i)[j] == '1' || a2.get(i)[j] == '1') isBlocked = true;
                row[j] = isBlocked ? '#' : ' ';
            }
            a3.add(row);
        }

        String[] answer = a3.stream()
                            .map(String::new)
                            .toArray(String[]::new);

        return answer;
    }
}

