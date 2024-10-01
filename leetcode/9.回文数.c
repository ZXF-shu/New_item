/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start
bool isPalindrome(int x) {
    if(x+1)
    {
        int a=x;
        int i=0;
        for(x;x!=0;x=x/10){i++;}//i表示了x一共多少位
        //i=0说明x是0，i=1说明x在1-9中
        int j=i;
        int k=0;
        x=a;
        for(j;j>=i/2;j--)
        {
        if((x/pow(10,i-1))%10!=(x/pow(10,k))%10);// 表示提取了x的第i位
        {
            k++;
        }
        else
        return false
        }
    }
    return false;
}
// @lc code=end
//x%10 //值为原x的个位
//(x/10)%10 //值为原x的百位
