fun main() {
    val n = readln().toInt()
    val arr = readln().split(" ").map(String::toInt).sorted()
    
    fun isGood(idx: Int, num: Int): Boolean {
        var (p1, p2) = 0 to n-1
        while(p1 < p2) {
            if(p1 == idx) {
                p1++
                continue
            }
            if(p2 == idx) {
                p2--
                continue
            }
            
            val sum = arr[p1] + arr[p2]
            when {
                sum > num -> p2--
                sum < num -> p1++
                else -> return true
            }
        }
        return false
    }
    arr.mapIndexed(::isGood).count{ it }.let { println(it) }
}
