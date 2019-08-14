import java.lang.reflect.Array;
import java.util.*;

/**
 * [다트 게임]
 *
 * 카카오톡 게임별의 하반기 신규 서비스로 다트 게임을 출시하기로 했다. 다트 게임은 다트판에 다트를 세 차례 던져 그 점수의 합계로 실력을 겨루는 게임으로, 모두가 간단히 즐길 수 있다.
 * 갓 입사한 무지는 코딩 실력을 인정받아 게임의 핵심 부분인 점수 계산 로직을 맡게 되었다. 다트 게임의 점수 계산 로직은 아래와 같다.
 *
 *     다트 게임은 총 3번의 기회로 구성된다.
 *     각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다.
 *     점수와 함께 Single(S), Double(D), Triple(T) 영역이 존재하고
 *     각 영역 당첨 시 점수에서  1제곱, 2제곱, 3제곱 (점수1 , 점수2 , 점수3 )으로 계산된다.
 *
 *     옵션으로 스타상(*) , 아차상(#)이 존재
 *
 *     스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다.
 *     아차상(#) 당첨 시 해당 점수는 마이너스된다.
 *
 *     스타상(*)은 첫 번째 기회에서도 나올 수 있다.
 *     이 경우 첫 번째 스타상(*)의 점수만 2배가 된다. (예제 4번 참고)
 *
 *     스타상(*)의 효과는 다른 스타상(*)의 효과와 중첩될 수 있다.
 *     이 경우 중첩된 스타상(*) 점수는 4배가 된다. (예제 4번 참고)
 *
 *     스타상(*)의 효과는 아차상(#)의 효과와 중첩될 수 있다.
 *     이 경우 중첩된 아차상(#)의 점수는 -2배가 된다. (예제 5번 참고)
 *
 *     Single(S), Double(D), Triple(T)은 점수마다 하나씩 존재한다.
 *     스타상(*), 아차상(#)은 점수마다 둘 중 하나만 존재할 수 있으며, 존재하지 않을 수도 있다.
 *
 */
class Programmers_KAKAO_17682 {
    public static void main(String[] args) {
        Programmers_KAKAO_17682 p = new Programmers_KAKAO_17682();
        String input = "1S2D*3T";

        int result = p.solution(input);
        System.out.println(result);
    } // end main

    public int solution(String dartResult) {
        int[] result            = {0};
        String[] arr            = splitInNum(dartResult);
        Stack<Score> scoreStack = new Stack<>();
        Stack<Integer> num      = new Stack<>(arr.length);
        Arrays.stream(arr).forEach(s -> scoreStack.push(new Score(s)));

        for(String dart : arr) {
            process(dart, scoreStack, num);
        }

        return 0;
//        scoreStack.stream()
//                         .reduce(0, Integer::sum);
    }

    private void process(String dart, Stack<Score> scoreStack, Stack<Integer> nums) {

        Score s = new Score(dart);

        if(scoreStack.isEmpty())
        {
            // [1] 맨 처음 보너스 처리
            if(s.bonus == 'D'){
                s.score = (int) Math.pow(s.score, 2);
            }
            else if(s.bonus == 'T'){
                s.score = (int) Math.pow(s.score, 3);
            }

            // [2] 맨 처음 옵션 처리
            if(s.bonus == '*') {
                s.score = s.score*2;
            }
            else if(s.bonus == '#') {
                s.score = -s.score;
            }

        } else {



        }

        nums.push(s.score);
    }

    private String [] splitInNum(String dartResult){
        String digits = dartResult.replaceAll("\\D+","");      // 문자열에서 숫자만 걸러냄
        List<String> list = new ArrayList<>(digits.length());

        char[] cArr = dartResult.toCharArray();
        StringBuilder sb = new StringBuilder(cArr.length);

        int idx = 0;
        for(char c : cArr)
        {
            if(Character.isDigit(c))
            {
                if(idx==0) { sb.append(c); continue;} // 시작 루프 처리
                list.add(sb.toString());
                sb.delete(0, sb.length());
            }
            sb.append(c);
            idx++;
        }
        list.add(sb.toString());    // 마지막 루프 처리
        sb = null;
        return list.toArray(String[]::new);
    }
}

class Score {
    public int  score;
    public char bonus;
    public char option;

    public Score(String dart)
    {
        this.score = Integer.parseInt(dart.replaceAll("\\D+",""));

        // 상태값 파싱
        char[] cArr = dart.toCharArray();
        for(char c : cArr) {
            switch(c)
            {
                case 'S': case 'D': case 'T':
                bonus = c;
                break;
                case '*': case '#':
                option = c;
                break;
            }
        }
    } // end Constructor


    // 아차상과 스타상이 겹칠 때
}