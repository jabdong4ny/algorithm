class Solution {
    public String solution(String s) {
        String answer = "";
        String[] temp = s.split(" ");
        
        for(int i = 0; i< temp.length ;i++){
            //문장앞에 공백이 있는 경우 substring으로 접근하면서 에러가 발생하기에 별도로 처리가 필요하다.
            if(temp[i].isEmpty()){
              answer = answer + " ";
                continue;  
            }
            if(i == 0)
                answer = temp[i].substring(0,1).toUpperCase() + temp[i].substring(1).toLowerCase();
            else
                answer = answer + temp[i].substring(0,1).toUpperCase() + temp[i].substring(1).toLowerCase();
            
            if(i != (temp.length-1)) answer = answer + " ";
        }
        
        //문장의 뒤에 공백이 있을 경우 공백을 추가해줌
        if(s.length() > answer.length()){
            int sub = s.length() -answer.length();
            for(int j=0;j < sub;j++){
                answer += " "; 
            }            
        }

        return answer;
    }
}