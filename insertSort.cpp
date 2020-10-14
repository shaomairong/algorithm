void insertSort(int *array, int low, int high)
{
    int j = low + 1;
    for (; j <= high; j++) //把第一个看做有序,从第二个开始插入.所以循环 1->n-1
    {
        int temp = array[j];  // 最开始:从第二个元素开始插入
        int i = j - 1;     //最开始:  把待插入元素 和 它的前一个元素进行比较
        for (; j > 0 && temp < array[i]; --j)   //J>0   ->   要保证前一个元素最少下标为0
        {
            array[j] = array[j - 1];
        }
        //循环退出时候,说明array[i]>temp.这个时候要把temp放在i后面,就是j位置(j=i+1)
        array[j] = temp;
    }
    //考研情绪不稳定,快些选一堆好友聊天吧
    // 不稳定:  快速排序,希尔排序,选择排序,堆排序  .剩余的就是稳定.
}