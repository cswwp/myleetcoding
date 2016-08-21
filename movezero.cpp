void moveZeroes(int* nums, int numsSize) {
    int * p=nums;
    int * q=nums;
    for(int index=0;index<numsSize;++index)
    {
        if((*p)!=0)
            *q++=*p;
        ++p;
    }
    while(p-q>0)
    {
        *q++=0;
    }
}
//8ms
