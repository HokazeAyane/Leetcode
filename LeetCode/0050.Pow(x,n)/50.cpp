double myPow(double x,int n){
    if(n==0) return 1.0;
    long long N = n;
    if(N < 0){
        x = 1/x;
        N = -N;
    }

    double ans = 1.0;
    double current_product = x;
    for(long long i = N; i;i/=2){
        if((i%2)==1){
            ans = ans* current_product;
        }
        current_product = current_product*current_product
    }
    return ans;
}

// 快速幂算法的基本思想是利用了幂运算的一个性质：任何一个整数都可以表示为一系列2的幂之和
