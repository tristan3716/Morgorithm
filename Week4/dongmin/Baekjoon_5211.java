/**
 *
 * 현환이는 음악 학원에서 피아노를 배우고 있다. 어느 날 선생님은 현환이에게 조표가 없는 악보를 주었다.
 * 자 이제 어떤 음계가 사용되었는지 알아보려고 한다.
 * 현환이는 피아노를 배운지 얼마 되지 않았기 때문에, 칠 수 있는 음계는 가단조와 다장조밖에 없다.
 * 현대 음악에서 한 옥타브는 12음 {A, A#, B, C, C#, D, D#, E, F, F#, G, G#}으로 이루어진다.
 * 가단조를 구성하는 음의 순서는 (A, B, C, D, E, F, G)이고, 다장조를 구성하는 음의 순서는 (C, D, E, F, G, A, B)이다.
 * 가단조와 다장조를 구성하는 음은 같다. 그럼 차이는 무엇일까?
 *
 * 첫 번째 차이는 중심음의 차이
 *
 * 으뜸음       --> 음계에서 가장 첫 번째 위치에 있는 음
 * 버금딸림음   -->  네 번째 위치에 있는 음
 * 딸림음       --> 다섯 번째 위치에 있는 음
 *
 * 가단조에서 으뜸음, 버금딸림음, 딸림음은 A, D, E이고,
 * 다장조에서 으뜸음, 버금딸림음, 딸림음은 C, F, G이다. 이 세 음을 중심음이라고 한다.
 *
 * 가단조   | 으뜸음       A       다장조    |  으뜸음     C
 * 가단조   | 버금딸림음   D       다장조    |  버금딸림음  F
 * 가단조   | 딸림음       E       다장조    |  딸림음     G
 *
 * 두 번째 차이는 음정의 차이이다.
 * 가단조에서 세 번째 음(C)은 으뜸음(A)보다 반음 세 개 높고,
 * 다장조에서 세 번째 음(E)은 으뜸음(C)보다 반음 네 개 높다.
 * 이러한 음정의 차이때문에 단조는 슬픔 느낌을, 장조는 기쁜 느낌을 준다.
 *
 * 가단조 또는 다장조의 음악이 주어졌을 때, 어떤 음계인지 알아내는 프로그램을 작성하시오.
 * 각 마디의 첫 음이 각각 몇 번씩 나오는지를 센 다음에, 많이 나오는 중심음이 그 음악의 음계라고 생각하면 된다.
 * (만약 A와 C의 중심음 개수가 같은 경우에는 마지막 마디의 마지막 음 하나로 구분한다)
 *
 * 예를 들어, 유명한 음악인 Frère Jacques의 악보는 다음과 같다.
 * CD|EC|CD|EC|EF|G|EF|G|GAGF|EC|GAGF|EC|CG|C|CG|C
 *
 * |는 각 마디를 나누는 마디선이다.
 * 여기서 각 마디의 첫 번째 음을 적어보면 다음과 같다.
 * (C, E, C, E, E, G, E, G, G, E, G, E, C, C, C, C)
 *
 * 이 중 (E, E, E, E, E, E)               가단조의 중심음
 * 이 중 (C, C, G, G, G, G, C, C, C, C)   다장조의 중심음
 *
 * 따라서, 이 음악은 다장조이다.
 *
 * [입력]
 * 첫째 줄에 음악이 주어진다.
 * 음악은 {"A", "B", "C", "D", "E", "F", "G", "|"}로 이루어져 있으며, 길이는 5보다 크거나 같고, 100을 넘지 않는다.
 * |가 연속해서 등장하거나, 문자열의 양쪽 끝에 나오는 경우는 없다.
 *
 * [출력]
 * 다장조라면 C-major, 가단조라면 A-minor를 출력한다.
 * 항상 둘 중 하나이고, 마디의 마지막음의 개수까지 같은 경우는 없다.
 *
 * [예제 입력]                                                  [예제 출력]
 * CD|EC|CD|EC|EF|G|EF|G|GAGF|EC|GAGF|EC|CG|C|CG|C             C-major
 *
 * @author Sight
 * @since  2019. 07 .14
 *
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.Stream;

class Baekjoon_5211 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // [1] 입력 음악에서 첫째 숫자만 골라서 배열 생성
        String input = br.readLine();
        String[] heads = Arrays.stream(input.split("\\|"))
                               .map(head -> head.substring(0,1))
                               .toArray(String[]::new);

        String[] C_major = Stream.of(heads)
                                 .filter(s -> "C".equals(s) ||
                                              "F".equals(s) ||
                                              "G".equals(s) )
                                 .toArray(String[]::new);

        String[] A_minor = Stream.of(heads)
                                 .filter(s -> "A".equals(s) ||
                                              "D".equals(s) ||
                                              "E".equals(s) )
                                 .toArray(String[]::new);

        String result;
        if(C_major.length == A_minor.length) {
            String last = input.substring(input.length()-1);        // 마지막 마디 마지막음
            result = "CFG".contains(last) ? "C-major" : "A-minor";
        } else {
            result = C_major.length > A_minor.length ? "C-major" : "A-minor";
        }
        System.out.print(result);
    }// main() end
}// class end


