import java.util.*

const val max = 100_000

fun main() {
    val (n, k) = readln().split(" ").map(String::toInt)
    val line = IntArray(max+1) { -1 }
    line[k] = -2
    
    val q = LinkedList<Pair<Int, Int>>()
    q.add(k to 0)
    var minTime = 0
    while(q.isNotEmpty()) {
        val (pos, time) = q.poll()
        if(pos == n) {
            minTime = time
            break
        }
        if (pos+1 <= max && line[pos+1] == -1) {
            line[pos+1] = pos
            q.add(pos+1 to time+1)
        }
        if (pos-1 >= 0 && line[pos-1] == -1) {
            line[pos-1] = pos
            q.add(pos-1 to time+1)
        }
        if (pos % 2 == 0 && line[pos/2] == -1) {
            line[pos/2] = pos
            q.add(pos/2 to time+1)
        }
    }
    
    println(minTime)
    val path = mutableListOf(n)
    while(true) {
        val next = line[path.last()]
        if(next == -2) break
        path.add(next)
    }
    println(path.joinToString(" "))
}

