import java.util.*
import kotlin.math.*

fun main() {
    
    val gears = Array(4) { LinkedList<Boolean>().apply { readln().forEach { add(it=='1') }}}
    val gearTops = gears.map { it.first }.toBooleanArray()
    
    repeat(readln().toInt()) {
        val (index, clockwise) = readln().split(" ").map { it.toInt() }.let { (it[0]-1) to (it[1]==1) }
        
        val poleMatch = arrayOf(true, true, true)
        for(i in 0..2) poleMatch[i] = (gears[i][2] == gears[i+1][6])
        
        rotate(gears, gearTops, index, clockwise)
        
        var rIndex = index + 1
        var rClockwise = !clockwise
        while(rIndex < 4) {
            if(poleMatch[rIndex-1]) break
            rotate(gears, gearTops, rIndex, rClockwise)
            rIndex += 1
            rClockwise = !rClockwise
        }
        
        var lIndex = index - 1
        var lClockwise = !clockwise
        while(lIndex >= 0) {
            if(poleMatch[lIndex]) break
            rotate(gears, gearTops, lIndex, lClockwise)
            lIndex -= 1
            lClockwise = !lClockwise
        }
    }
    
    
    var answer = 0
    for(i in 0..3) { if(gearTops[i]) { answer += 2f.pow(i).toInt() } }
    print(answer)
}

fun rotate(
    gears: Array<LinkedList<Boolean>>,
    gearTops: BooleanArray,
    index: Int,
    clockwise: Boolean
) {
    gears[index].apply {
        if(clockwise) {
            addFirst(last)
            removeLast()
        } else {
            add(first)
            removeFirst()
        }
        gearTops[index] = first
    }
}
