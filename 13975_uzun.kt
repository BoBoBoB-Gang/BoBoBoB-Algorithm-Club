lateinit var dp: Array<IntArray>
lateinit var file: List<Int>

// 점화식을 세워보자. 구간 (a, b]가 존재한다면 그 구간 내 최소 비용을 dp[a][b]로 나타낼 수 있다.
// 주어진 파일들은 연속적이므로 2구간의 합으로 표현될 수 있다.
// 따라서 dp[a][b] = min value for (i in a ~ b) dp[a][i] + dp[i+1][b] + 구간합(a,b]

fun getCost(a: Int, b: Int): Int {
    if(dp[a][b] != Int.MAX_VALUE) return dp[a][b]
    
    val prefixSum = file.subList(a, b+1).sum()
    for(i in a until b) {
        dp[a][b] = dp[a][b].coerceAtMost(getCost(a, i) + getCost(i+1, b) + prefixSum)
    }
    return dp[a][b]
}

fun main() {
    val sb = StringBuilder()
    val t = readln().toInt()
    repeat(t) {
        val k = readln().toInt()
        file = readln().split(" ").map(String::toInt)
        
        dp = Array(k) { IntArray(k) { Int.MAX_VALUE } }
        for(i in 0 until k) dp[i][i] = 0
        for(i in 0 until k-1) dp[i][i+1] = file[i] + file[i+1]
        
        sb.appendLine(getCost(0, k-1))
    }
    print(sb.toString())
}
