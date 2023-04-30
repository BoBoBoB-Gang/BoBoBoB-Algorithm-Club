mport java.util.*
import kotlin.math.abs

fun readInts() = readln().split(' ').map { it.toInt() }
val dx = listOf(0,1,0,-1)
val dy = listOf(-1,0,1,0)

data class Union(
    var sum: Int = 0,
    val list: MutableList<Pair<Int, Int>> = mutableListOf()
)

fun main() {
    val (n, l, r) = readInts()
    val map = Array(n) { readInts().toIntArray() }
    val lr = l..r
    var day = 0

    while(true) {
        var open = false
        val visited = Array(n) { Array(n) { false } }
        val unionList = mutableListOf<Union>()
        for(i in 0 until n) for(j in 0 until n) {
            if(visited[i][j]) continue
            visited[i][j] = true

            val union = bfs(map, visited, lr, i, j)
            unionList.add(union)
        }

        unionList.forEach { (sum, list) ->
            if(list.size > 1) open = true
            list.forEach { (y, x) -> map[y][x] = sum / list.size }
        }
        if(!open) break
        day++
    }
    print(day)
}

fun bfs(map: Array<IntArray>, visited: Array<Array<Boolean>>, lr: IntRange, sy: Int, sx: Int): Union {
    val union = Union(map[sy][sx], mutableListOf(sy to sx))
    val q = LinkedList<Pair<Int, Int>>()
    q.add(union.list.last())

    while(q.isNotEmpty()) {
        val (y, x) = q.poll()

        for(i in 0..3) {
            val (nx, ny) = x+dx[i] to y+dy[i]

            if(nx !in map.indices || ny !in map.indices || visited[ny][nx]) continue
            if(abs(map[y][x] - map[ny][nx]) !in lr) continue

            visited[ny][nx] = true
            q.add(ny to nx)
            union.sum += map[ny][nx]
            union.list.add(ny to nx)
        }
    }
    return union
}
