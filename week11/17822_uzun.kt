import java.util.*

val dr = listOf(1, 0, -1, 0)
val di = listOf(0, 1, 0, -1)

fun main() {
    fun readInts() = readln().split(" ").map(String::toInt)
    val (n, m, t) = readInts()
    val disks = Array(n) { readInts().toMutableList() }
    var targetCount = n * m 
    
    for(_t in 0 until t) {
        // 1. 회전시키기 
        val (x, d, k) = readInts() 
        val rotate = if(d==0) k else -1 * k
        for(i in x..n step x) Collections.rotate(disks[i-1], rotate)
        
        // 2. 인접하고 같은 수 지우기 
        val toRemove = mutableSetOf<Pair<Int, Int>>()
        for(r in 0 until n) {
            for(i in 0 until m) {
                if(disks[r][i] == 0) continue
                var flag = false
                for(d in 0..3) {
                    var (nr, ni) = r + dr[d] to i + di[d]
                    if(nr !in 0 until n) continue
                    if(ni >= m) ni = 0
                    if(ni < 0) ni = m-1
                    
                    if(disks[nr][ni] == disks[r][i]) {
                        toRemove.add(nr to ni)
                        flag = true
                    }
                }
                if(flag) toRemove.add(r to i)
            }
        }
        
        if(toRemove.isNotEmpty()) {
            targetCount -= toRemove.size
            toRemove.forEach { disks[it.first][it.second] = 0 }
            continue
        }
        
        // 3. 평균 구해서 큰 수 1 빼고 작은 수 1 더하기
        val avg = disks.map(MutableList<Int>::sum).sum().toDouble() / targetCount
        for(disk in disks) {
            for(i in disk.indices) {
                if(disk[i] == 0) continue
                if(disk[i] > avg) disk[i]--
                else if(disk[i] < avg) disk[i]++
            }  
        }
    }
    
    // 4. 원판에 적힌 수들의 합
    println(disks.map(MutableList<Int>::sum).sum())
}
