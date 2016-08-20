/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/






int addDigits(int num) {
    if(num>=10)
    {
        int sum=0;
        for(;num!=0;num/=10)
            sum+=num%10;            
        return addDigits(sum);
    }
    else
        return num;
}


int addDigits(int num) {
 
  if(num>=0&&num<10)
  {
      return num;
  }
  else
    return addDigits(num%10+addDigits(num/10));
}
