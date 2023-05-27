typealias P = Pair<Int, Int>
enum class Place { BEAVER, HEDGEHOG, WATER, STONE, EMPTY }

val dx = listOf(0, 1, 0, -1)
val dy = listOf(-1, 0, 1, 0)

lateinit var map: Array<Array<Place>>
lateinit var hedgehog: MutableList<P>
lateinit var edgeWaters: MutableList<P>

fun main() {
    hedgehog = mutableListOf()
    edgeWaters = mutableListOf()

    val (r, c) = readln().split(" ").map { it.toInt() }
    map = Array(r) { row ->
        readln().mapIndexed { col, value ->
            when (value) {
                'D' -> Place.BEAVER
                'S' -> Place.HEDGEHOG.also { hedgehog.add(row to col) }
                '*' -> Place.WATER.also { edgeWaters.add(row to col) }
                'X' -> Place.STONE
                else -> Place.EMPTY
            }
        }.toTypedArray()
    }
    fun isInMap(y: Int, x: Int): Boolean = y in 0 until r && x in 0 until c
    var time = 0
    while (hedgehog.isNotEmpty()) {
        time++
        edgeWaters = spreadWater(::isInMap)
        hedgehog = hedgehogMove(::isInMap) ?: run {
            println(time)
            return
        }
    }
    println("KAKTUS")
}

fun spreadWater(isIn: (Int, Int) -> Boolean): MutableList<P> {
    val nextWaters = mutableListOf<P>()
    edgeWaters.forEach { (cy, cx) ->
        for (i in 0 until 4) {
            val (dy, dx) = cy + dy[i] to cx + dx[i]
            if (!isIn(dy, dx)) continue
            if (map[dy][dx] in listOf(Place.EMPTY, Place.HEDGEHOG)) {
                map[dy][dx] = Place.WATER
                nextWaters.add(dy to dx)
            }
        }
    }
    return nextWaters
}

fun hedgehogMove(isIn: (Int, Int) -> Boolean): MutableList<P>? {
    val nextHedgeHogPostions = mutableListOf<P>()
    for ((cy, cx) in hedgehog) {
        for (i in 0 until 4) {
            val (dy, dx) = cy + dy[i] to cx + dx[i]
            if (!isIn(dy, dx)) continue
            when (map[dy][dx]) {
                Place.EMPTY -> {
                    map[dy][dx] = Place.HEDGEHOG
                    nextHedgeHogPostions.add(dy to dx)
                }
                Place.BEAVER -> return null
                else -> {}
            }
        }
    }
    return nextHedgeHogPostions
}



