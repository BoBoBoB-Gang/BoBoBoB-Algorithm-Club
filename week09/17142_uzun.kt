import java.util.*

typealias P = Pair<Int, Int>
enum class Place { EMPTY, BLOCK, NON_ACTIVE_VIRUS, ACTIVE_VIRUS }
data class Item(val y: Int, val x: Int, val time: Int)
val dx = listOf(0, 1, 0, -1)
val dy = listOf(-1, 0, 1, 0)

val viruses = mutableListOf<P>()
var n = 0
var m = 0
var minTime = Int.MAX_VALUE
var emptyCount = 0

fun Array<Array<Place>>.copy() = map { it.clone() }.toTypedArray()

fun main() {
    readln().split(" ").map(String::toInt).let{ n = it[0]; m = it[1] }
    val map = Array(n) { i ->
        readln().split(" ").mapIndexed { j, v ->
            when(v) {
                "2" -> Place.NON_ACTIVE_VIRUS.also { viruses.add(i to j) }
                "1" -> Place.BLOCK
                else -> Place.EMPTY.also { emptyCount++ }
            }
        }.toTypedArray()
    }
    
    fun calculateTime(selectedViruses: List<P>) {
        var time = 0
        var _emptyCount = emptyCount
        val _map = map.copy()
        val q = LinkedList<Item>()
        selectedViruses.forEach {
            val (y, x) = it
            _map[it.first][it.second] = Place.ACTIVE_VIRUS
            q.add(Item(y, x, 0))
        }
        
        while(q.isNotEmpty()) {
            val (y, x, t) = q.poll()
            for(i in 0 until 4) {
                val (ny, nx) = y + dy[i] to x + dx[i]
                if(ny !in 0 until n || nx !in 0 until n) continue
                if (_map[ny][nx] in listOf(Place.EMPTY, Place.NON_ACTIVE_VIRUS)) {
                    if(_map[ny][nx] == Place.EMPTY) {
                        time = time.coerceAtLeast(t+1)
                        _emptyCount--
                    }
                    _map[ny][nx] = Place.ACTIVE_VIRUS
                    q.add(Item(ny, nx, t+1))
                    
                }
            }
        }
        
        if(_emptyCount != 0) return
        minTime = minTime.coerceAtMost(time)
    } 
    
    selectViruses(listOf(), 0, ::calculateTime)

    print(minTime.takeIf { it != Int.MAX_VALUE } ?: -1)
}

fun selectViruses(
    selectedViruses: List<P>,
    idx: Int,
    calculateTime: (List<P>) -> Unit
) {
    if(selectedViruses.size == m) {
        calculateTime(selectedViruses)
        return
    }
    if(idx == viruses.size) return
    
    selectViruses(selectedViruses, idx+1, calculateTime)
    selectViruses(selectedViruses.plus(viruses[idx]), idx+1, calculateTime)
}

