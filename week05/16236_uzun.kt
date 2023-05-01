import java.util.*

typealias P = Pair<Int, Int>
val dx = arrayOf(0, 1, 0, -1)
val dy = arrayOf(-1, 0, 1, 0)

data class Shark(
    var x: Int,
    var y: Int,
    var time: Int,
    var size: Int,
    var fishStack: Int = 0,
) {
    val pos get() = y to x
    fun move(time: Int, yx: P) {
        this.time += time
        this.x = yx.second.also { this.y = yx.first }
    }
    fun eat(callback: () -> Unit) {
        fishStack += 1
        if(fishStack == size) {
            fishStack = 0
            size += 1
        }
        callback()
    }
} 

fun main() {
    val n = readln().toInt()
    val shark = Shark(0, 0, 0, 2)
    val map = Array(n) { row ->
        readln().split(" ").mapIndexed { col, it ->
            if(it == "9") shark.move(0, row to col)
            it.toInt()
        }.toIntArray()
    }
    
    val (sy, sx) = shark.pos
    map[sy][sx] = 0
    
    while(true) {
        val (timeSpend, nextFish) = findFish(map, shark) ?: break
        shark.move(timeSpend, nextFish)
        shark.eat { map[nextFish.first][nextFish.second] = 0 }
    }
    print(shark.time)
}

fun findFish(map: Array<IntArray>, shark: Shark): Pair<Int, P>?  {
    val (sy, sx) = shark.pos
    val visited = Array(map.size) { Array(map.size) { false } }.apply { get(sy)[sx] = true }
    val q = LinkedList<Triple<Int, Int, Int>>().apply { add(Triple(0, sy, sx)) }
    val candidates = mutableListOf<P>()
    var minDist : Int? = null
    
    while(q.isNotEmpty()) {
        val (dist, cy, cx) = q.poll()
        if(minDist != null && dist > minDist) break

        for(it in 0..3) {
            val (ny, nx) = cy + dy[it] to cx + dx[it]
            if(nx !in map.indices || ny !in map.indices || visited[ny][nx]) continue

            val canEat = map[ny][nx] in 1..8 && shark.size > map[ny][nx]
            val canPass = canEat || shark.size == map[ny][nx] || map[ny][nx] == 0
            
            if(canEat) {
                minDist = dist
                candidates.add(ny to nx)
            }

            if(canPass) {
                visited[ny][nx] = true
                q.add(Triple(dist + 1, ny, nx))
            }
        }
        
    }
    
    return minDist?.let {
        it+1 to candidates.sortedWith(compareBy ({it.first}, {it.second})).first()
    }
}
