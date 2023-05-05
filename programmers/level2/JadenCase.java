class Solution {
    public String solution(String s) {
        String answer = "";
        String[] temp = s.split(" ");
        //System.out.println(temp.length);
        for(int i = 0; i< temp.length ;i++){
            if(i == 0)
                answer = temp[i].substring(0,1).toUpperCase() + temp[i].substring(1).toLowerCase() + " ";
            else if(i == (temp.length-1))
                answer = answer + temp[i].substring(0,1).toUpperCase() + temp[i].substring(1).toLowerCase();
            else
                answer = answer + temp[i].substring(0,1).toUpperCase() + temp[i].substring(1).toLowerCase() + " ";
        }

        return answer;
    }
}