import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;


public class Baek1918 {
    static String s;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        inputData();
        solve();
        outputData();
    }
    public static void solve(){
        ArrayDeque<Character> stack = new ArrayDeque<>();
        Map<Character, Integer> priority = new HashMap<Character, Integer>(){{
            put('(', 2);
            put(')', 2);
            put('*', 1);
            put('/', 1);
            put('+', 0);
            put('-', 0);
        }};

        for(char c: s.toCharArray()){
            if(Character.isUpperCase(c)){
                sb.append(c);
            }else if(c == '('){
                stack.addLast(c);
            }else if(c == ')'){
                while(stack.peekLast() != '('){
                    sb.append(stack.pollLast());
                }
                stack.pollLast();
            }else{
                while(!stack.isEmpty() && priority.get(c) <= priority.get(stack.peekLast()) && stack.peekLast() != '('){
                    sb.append(stack.pollLast());
                }
                stack.addLast(c);
            }
        }
        while(!stack.isEmpty()){
            sb.append(stack.pollLast());
        }
    }
    public static void inputData() throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        s = bf.readLine();
    }
    public static void outputData(){
        System.out.println(sb);
    }
}
