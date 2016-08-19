//C-version
//Write a function that takes a string as input and returns the string reversed.

//Example:
//Given s = "hello", return "olleh".

//solution1
char* reverseString(char* s) {
    char* p=s;
    char* q=s+strlen(s)-1;
    for(;p<q;p++,q--)
    {
        char temp=*q;
        *q=*p;
        *p=temp;
    }
    return s;
}

//solution2
char* reverseString(char* s) {
    
    char* p=s;
    char* q=s+strlen(s)-1;
    while(p<q)
    {
        char temp=*q;
        *q=*p;
        *p=temp;
        --q;
        ++p;
    }
    return s;
}
