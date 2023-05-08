val dx = arrayOf(0, 1, 0, -1)
val dy = arrayOf(-1, 0, 1, 0)
lateinit var map : Array<IntArray>
lateinit var dp : Array<Array<Int?>>

fun main() {
    fun readInts() = readln().split(" ").map { it.toInt() }
    val (m, n) = readInts()
    map = Array(m) { readInts().toIntArray() }
    dp = Array(m) { Array(n) { null } }
    
    dfs(0, 0)
    print(dp[0][0])
}

fun dfs(y: Int, x: Int): Int {
    if(y == map.size-1 && x == map.first().size-1) return 1
    dp[y][x]?.let { return it } ?: run { dp[y][x] = 0 }
    
    for(i in 0..3) {
        val (ny, nx) = y + dy[i] to x + dx[i]
        if(ny !in map.indices || nx !in map.first().indices) continue
        
        if(map[ny][nx] < map[y][x]) {
            dp[y][x] = dp[y][x]!! + dfs(ny, nx)
        }
    }
    
    return dp[y][x]!!
}
