    import java.util.*;

    class Solution {

        class Position {
            int x, y;

            Position(int x, int y) {
                this.x = x;
                this.y = y;
            }

            boolean isValid(int width, int height) {
                if (x < 0 || x >= width) return false;
                if (y < 0 || y >= height) return false;
                return true;
            }
        }

        public int solution(int[][] maps) {
            int mapHeight = maps.length;
            int mapWidth = maps[0].length;
            int[][] count = new int[mapHeight][mapWidth];
            boolean[][] visited = new boolean[mapHeight][mapWidth];

            Queue<Position> queue = new LinkedList<>();

            queue.offer(new Position(0, 0));
            count[0][0] = 1;
            visited[0][0] = true;

            while (!queue.isEmpty()) {
                Position curr = queue.poll();
                int currCnt = count[curr.y][curr.x];

                final int[][] moving = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
                for (int i = 0; i < moving.length; ++i) {
                    Position moved = new Position(curr.x + moving[i][0], curr.y + moving[i][1]);
                    if (!moved.isValid(mapWidth, mapHeight)) continue;
                    if (visited[moved.y][moved.x]) continue;
                    if (maps[moved.y][moved.x] == 0) continue;  // 0: 벽, 1: 길

                    count[moved.y][moved.x] = currCnt + 1;
                    visited[moved.y][moved.x] = true;
                    queue.offer(moved);
                }
            }

            int answer = count[mapHeight - 1][mapWidth - 1];
            if (answer == 0) answer = -1;

            return answer;
        }

    }