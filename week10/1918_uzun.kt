import java.util.*

infix fun Stack<Char>.쌓다(item: Char) = this.push(item)
infix fun <T> T.안에있는가(list: List<T>) = this in list
infix fun <T> T.와(other: T) = listOf<T>(this, other)
infix fun Any.같지않은(other: Any) = this != other
fun Stack<Char>.빼다() = this.pop()
val Stack<Char>.선두 get() = this.peek()
val Stack<Char>.비어있지않은 get() = this.isNotEmpty()
fun <T> T.출력하다() = print(this) 

fun main() {
    var 입력수식 = readln()
    val 연산자스택 = Stack<Char>()
    
    for(문자 in 입력수식) {
        when(문자) {
            '(' -> 연산자스택 쌓다 문자
            '*','/' -> {
                while (연산자스택.비어있지않은 && (연산자스택.선두 안에있는가 ('*' 와 '/')))
                    연산자스택.빼다().출력하다()
                연산자스택 쌓다 문자
            }
            '+','-' -> {
                while (연산자스택.비어있지않은 && (연산자스택.선두 같지않은 '('))
                    연산자스택.빼다().출력하다()
                연산자스택 쌓다 문자
            }
            ')' -> {
                while (연산자스택.비어있지않은 && (연산자스택.선두 같지않은 '('))
                    연산자스택.빼다().출력하다()
                연산자스택.빼다()
            }
            else -> 문자.출력하다()
        }
    }
    while(연산자스택.비어있지않은) 연산자스택.빼다().출력하다()
}
