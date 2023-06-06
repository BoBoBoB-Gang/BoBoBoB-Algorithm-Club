import java.util.*

val dx = listOf(0, 1, 0, -1)
val dy = listOf(-1, 0, 1, 0)

/*
(0, 0) 가장자리에서 BFS를 돌리는데 빈칸을 찾을것임.
외부 빈칸을 모두 찾고, 치즈에 ++를 해줘서 갯수를 셈. (치즈는 좌표 list로 소지하고 있)
제거하고 다시 돌린다.
 */

fun main() {
    val (n, m) = readln().split(" ").map(String::toInt)
    var cheese = mutableListOf<Pair<Int, Int>>()
    val map = Array(n) { i ->
        readln().split(" ").mapIndexed { j, value ->
            if(value == "1") cheese.add(i to j)
            value.toInt()
        }.toIntArray()
    }
    var hour = 0
    while(cheese.isNotEmpty()) {
        val visited = Array(n) { Array(m) { 0 } }
        val q: Queue<Pair<Int, Int>> = LinkedList()
        q.add(0 to 0)
        visited[0][0]
        
        while(q.isNotEmpty()) {
            val (cy, cx) = q.poll()
            
            for(i in 0..3) {
                val (ny, nx) = cy + dy[i] to cx + dx[i]
                if(ny !in 0 until n || nx !in 0 until m) continue
                if(map[ny][nx] == 1) {
                    visited[ny][nx]++
                } else if(visited[ny][nx] == 0) {
                    visited[ny][nx] = 1
                    q.add(ny to nx)
                }
            }
        }
        
        cheese = cheese.filter {
            val toMelt = visited[it.first][it.second] >= 2
            if(toMelt) map[it.first][it.second] = 0
            toMelt.not()
        }.toMutableList()
        
        hour++
    }
    println(hour)
}
