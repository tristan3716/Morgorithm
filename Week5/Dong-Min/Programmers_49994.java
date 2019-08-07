import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Programmers_49994 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] input = br.readLine().toCharArray();
        br.close();

        int[][][][] map = new int[11][11][11][11];
        int[] cur_x     = new int[]{5};
        int[] cur_y     = new int[]{5};
        int[] cnt       = new int[]{0};

        for (char cmd : input) {
            calcDir(cur_x, cur_y, map, cnt, cmd);
        }

        System.out.println(cnt[0]);
    } // end main

    private static void calcDir(int[] cur_x, int[] cur_y, int[][][][] map, int[] cnt, char command) {

        int start_x       = cur_x[0];
        int start_y       = cur_y[0];

        boolean upAble    = cur_y[0] < 10;
        boolean downAble  = cur_y[0] > 0;
        boolean rightAble = cur_x[0] < 10;
        boolean leftAble  = cur_x[0] > 0;

        switch (command) {
            case 'U':
                cur_y[0] = upAble    ? cur_y[0] += 1 : cur_y[0];
                break;
            case 'D':
                cur_y[0] = downAble  ? cur_y[0] -= 1 : cur_y[0];
                break;
            case 'R':
                cur_x[0] = rightAble ? cur_x[0] += 1 : cur_x[0];
                break;
            case 'L':
                cur_x[0] = leftAble  ? cur_x[0] -= 1 : cur_x[0];
                break;
        }

        if(start_x == cur_x[0] && start_y == cur_y[0]) return;

        if( map[start_x][start_y][cur_x[0]][cur_y[0]] == 0 &&
            map[cur_x[0]][cur_y[0]][start_x][start_y] == 0) {

            map[start_x][start_y][cur_x[0]][cur_y[0]] = 1;
            map[cur_x[0]][cur_y[0]][start_x][start_y] = 1;

            cnt[0]++;
        }
    }// calcDir() end
}
