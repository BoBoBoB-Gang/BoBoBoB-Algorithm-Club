import java.util.*

typealias P = Pair<Int, Int>
val dx = listOf(0,1,0,-1)
val dy = listOf(-1,0,1,0)

fun main() {
    val (N, M) = readln().split(" ").map { it.toInt() }
    var iceList = mutableListOf<P>()
    val map = Array(N) { row ->
        readln().split(" ").mapIndexed { col, value ->
            value.toInt().also { if(it > 0) iceList.add(row to col) }
        }.toIntArray()
    }
    
    var year = 0
    while(checkIceLinked(map, iceList.first(), iceList.size)) {
        iceList = updatedIceList(map, iceList)
        year++
        if(iceList.isEmpty()) {
            year = 0
            break
        }
    }
    print(year)
}

fun updatedIceList(map: Array<IntArray>, iceList: MutableList<P>) : MutableList<P> {
    val meltCandidates = mutableListOf<Pair<P, Int>>()
    val newIceList = mutableListOf<P>()
    for(ice in iceList) {
        val (cy, cx) = ice
        var waterCount = 0
        for(i in 0..3) {
            val (ny, nx) = cy+dy[i] to cx+dx[i]
            if(ny !in map.indices || nx !in map.last().indices) continue
            if(map[ny][nx] <= 0) waterCount += 1
        }
        if(waterCount > 0) meltCandidates.add(ice to waterCount)
        if(map[cy][cx] > waterCount) newIceList.add(ice)
    }
    meltCandidates.forEach { (ice, count) ->
        map[ice.first][ice.second] -= count
    }
    return newIceList
}

fun checkIceLinked(map: Array<IntArray>, start: P, iceListCount: Int) : Boolean {
    val visited = Array(map.size) { BooleanArray(map.first().size) { false } }
    visited[start.first][start.second] = true
    val q = LinkedList<P>().apply { add(start) }
    var iceCount = 1
    while(q.isNotEmpty()) {
        val (cy, cx) = q.poll()
        for(i in 0..3) {
            val (ny, nx) = cy+dy[i] to cx+dx[i]
            if(ny !in map.indices || nx !in map.last().indices) continue
            if(visited[ny][nx]) continue
            if(map[ny][nx] > 0) {
                iceCount += 1
                visited[ny][nx] = true
                q.add(ny to nx)
            }
        }
    }
    return iceListCount == iceCount
}
