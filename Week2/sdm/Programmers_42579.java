/**
 * 스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다.
 * 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.
 *
 *  1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
 *  2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
 *  3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
 *
 * 노래의 장르를 나타내는 문자열 배열 genres와
 * 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때,
 * 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.
 *
 * genres[i]는 고유번호가 i인 노래의 장르입니다.
 * plays[i] 는 고유번호가 i인 노래가 재생된 횟수입니다.
 *
 * genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
 * 장르 종류는 100개 미만입니다.
 * 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
 * 모든 장르는 재생된 횟수가 다릅니다.
 *
 * => genres
 * ['classic', 'pop', 'classic', 'classic', 'pop']
 *
 * => plays
 * [500, 600, 150, 800, 2500]
 *
 * => return
 * [4, 1, 3, 0]
 *
 *
 * @author Sight
 * @since  2019. 07 .14
 */
import java.util.*;
class Programmers_42579 {

    // Entry point
    public static void main(String[] args) {
        Programmers_42579 p = new Programmers_42579();
        int[] result = p.solution(new String[]{"classic", "pop", "classic", "classic", "pop"}, new int[]{500, 600, 500, 800, 2500});
        System.out.println(Arrays.toString(result));
    }

    public int[] solution(String[] genres, int[] plays) {

        List<Integer> result = new ArrayList<>();

        // [1] 장르별 재생수 집계
        HashMap<String, Integer> sumHash = new HashMap<>();
        for(int i = 0; i < genres.length; i++) {
            Integer preVal = Optional.ofNullable(sumHash.get(genres[i])).orElse(0);
            sumHash.put(genres[i], preVal+plays[i]);
        }

        // [2] Hash KeySet 정렬
        List<String> keySet = new ArrayList<>(sumHash.keySet());
        Collections.sort(keySet, (o1, o2) ->
            sumHash.get(o1) >= sumHash.get(o2) ? -1 : 0
        );

        // [3] 음악 장르별로 Hashmap에 세팅
        HashMap<String, PriorityQueue<Song>> songHash = new HashMap<>();
        keySet.forEach(key -> {
            songHash.put(key, new PriorityQueue<>());
        });

        for(int i = 0; i < genres.length; i++) {
            songHash.get(genres[i]).add(new Song(i, genres[i], plays[i]));
        }

        // [4] 음악 추출
        keySet.forEach(key -> {
            int iterCnt = songHash.get(key).size() == 1 ? 1 : 2;

            for(int i = 0 ; i < iterCnt ; i++) {
                result.add(songHash.get(key).poll().getSongID());
            }
        });

        int[] answer = result.stream().mapToInt(i->i).toArray();
        return answer;
    }

    class Song implements Comparable<Song> {
        private String genre;
        private int    songID;
        private int    playCnt;

        public Song(int songID, String genre, int playCnt) {
            this.genre = genre;
            this.songID = songID;
            this.playCnt = playCnt;
        }

        @Override
        public int compareTo(Song o) {

            if(this.playCnt == o.playCnt) {
                return this.songID > o.songID ? 1 : -1;
            }

            return this.playCnt > o.playCnt ? -1 : 1;
        }

        // ===========================  Getters & Setters ===========================
        public int getSongID() { return songID; }
    } // Class Song END
}