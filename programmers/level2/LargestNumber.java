import java.util.Arrays;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String [] arr = new String[numbers.length];
        for(int i = 0 ; i < numbers.length ; i++)
            arr[i] = String.valueOf(numbers[i]);
        
        //두 문자열의 합을 앞의 한글자씩 아스키 값으로 비교하여 더 큰 순으로 정렬
        Arrays.sort(arr, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));
        
        //0 이상이기 때문에 0으로만 된 case 가 존재할수 있다.
        //그러면 0+0+... 이 0이 아닌 00, 000 ... 으로 값이 달라질 수 있기에 아래코드 추가
        if (arr[0].equals("0")) {
           return "0";
        }
        for(String ar:arr)
            answer += ar;
        return answer;
    }
}