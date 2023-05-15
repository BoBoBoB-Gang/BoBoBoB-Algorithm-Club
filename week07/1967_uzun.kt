import java.util.*

data class Node(
    val children: MutableList<Pair<Int, Int>> = mutableListOf(),
    var childMaxDist: Int = 0,
    var foldDist: Int = 0,
)

var maxDiameter = 0
 
fun main() {
    val n = readln().toInt()
    val tree = Array(n+1) { Node() }
    repeat(n-1) {
        val (parent, child, value) = readln().split(" ").map { it.toInt() }
        tree[parent].children.add(child to value)
    }
    
    dfs(tree, 1)
    print(maxDiameter)
}

fun dfs(tree: Array<Node>, curr: Int): Int {
    val pq = PriorityQueue<Int>(Collections.reverseOrder())
    tree[curr].children.forEach { (child, value) ->
        pq.add(value + dfs(tree, child))
    }
    if(pq.isEmpty()) return 0
    tree[curr].childMaxDist = pq.poll()
    tree[curr].foldDist = tree[curr].childMaxDist + if(pq.isNotEmpty()) pq.peek() else  0
    
    maxDiameter = maxOf(maxDiameter, tree[curr].foldDist)
    return tree[curr].childMaxDist
}
