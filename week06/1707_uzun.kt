import java.util.LinkedList

fun main() {
    val k = readln().toInt()
    repeat(k) {
        val (v, e) = readln().split(" ").map { it.toInt() }
        val map = Array(v + 1) { mutableListOf<Int>() }
        repeat(e) {
            val (a, b) = readln().split(" ").map { it.toInt() }
            map[a].add(b).also { map[b].add(a) }
        }
        val result = if (isBipartite(map)) "YES" else "NO"
        println(result)
    }
}

fun isBipartite(map: Array<MutableList<Int>>): Boolean {
    val visited = Array(map.size) { State.UNVISITED }
    
    for (i in 1 until map.size) {
        if(visited[i] != State.UNVISITED) continue
        else visited[i] = State.GROUP_A
        
        val q = LinkedList<Pair<Int, State>>().apply { add(i to State.GROUP_A) }

        while (q.isNotEmpty()) {
            val (curr, state) = q.poll()
            val nextState = state.next() ?: break
            map[curr].forEach { next ->
                if (visited[next] == State.UNVISITED) {
                    visited[next] = nextState
                    q.add(next to nextState)
                } else if (visited[next] != nextState) {
                    return false
                }
            }
        }
    }
    return true
}

enum class State {
    GROUP_A, GROUP_B, UNVISITED;
    fun next() = when (this) {
        GROUP_A -> GROUP_B
        GROUP_B -> GROUP_A
        UNVISITED -> null
    }
}
