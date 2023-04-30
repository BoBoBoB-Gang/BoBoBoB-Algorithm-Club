 class Dice(
    var y: Int,
    var x: Int,
    var top: Int,
    var bottom: Int,
    var east: Int,
    var west: Int,
    var north: Int,
    var south: Int,
    val n: Int,
    val m: Int,
) {
    fun move(order: Int): Unit? = when (order) {
        1 -> if(x+1 < m) moveEast() else null 
        2 -> if(x-1 >= 0) moveWest() else null
        3 -> if(y-1 >= 0) moveNorth() else null 
        4 -> if(y+1 < n) moveSouth() else null
        else -> null
    }

    private fun moveEast() {
        x += 1
        val curr = this.copy()
        top = curr.east
        bottom = curr.west
        west = curr.top
        east = curr.bottom
    }

    private fun moveWest() {
        x -= 1
        val curr = this.copy()
        top = curr.west
        bottom = curr.east
        east = curr.top
        west = curr.bottom
    }

    private fun moveNorth() {
        y -= 1
        val curr = this.copy()
        top = curr.north
        bottom = curr.south
        north = curr.bottom
        south = curr.top
    }

    private fun moveSouth() {
        y += 1
        val curr = this.copy()
        top = curr.south
        bottom = curr.north
        north = curr.top
        south = curr.bottom
    }
}

fun main() {
    fun readInts() = readln().split(' ').map { it.toInt() }
    val (n, m, y, x, k) = readInts()
    val map = Array(n) { readInts().toIntArray() }
    val orders = readInts()
    val dice = Dice(y, x, 0, 0, 0, 0, 0, 0, n, m)
    val sb = StringBuilder()

    for (order in orders) {
        dice.move(order) ?: continue
        sb.appendLine(dice.top)
        if(map[dice.y][dice.x] == 0) map[dice.y][dice.x] = dice.bottom
        else {
            dice.bottom = map[dice.y][dice.x]
            map[dice.y][dice.x] = 0
        }
    }
    print(sb.toString())
}
