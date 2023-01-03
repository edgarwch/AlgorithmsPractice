//
//  fast_pow.h
//  coding_pac
//
//  Created by Edgar Wong on 17/08/2022.
//

#ifndef fast_pow_h
#define fast_pow_h
/*/
 Function exp_by_squaring(x, n)
   if n < 0  then return exp_by_squaring(1 / x, -n);
   else if n = 0  then return  1;
   else if n is even  then return exp_by_squaring(x * x,  n / 2);
   else if n is odd  then return x * exp_by_squaring(x * x, (n - 1) / 2);
 */
class fast_pow_recursion {
public:
    double fastPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};

/*
 Function exp_by_squaring(x, n)
   return exp_by_squaring2(1, x, n)
 Function exp_by_squaring2(y, x, n)
   if n < 0  then return exp_by_squaring2(y, 1 / x, - n);
   else if n = 0  then return  y;
   else if n is even  then return exp_by_squaring2(y, x * x,  n / 2);
   else if n is odd  then return exp_by_squaring2(x * y, x * x, (n - 1) / 2)
 
 Function exp_by_squaring_iterative(x, n)
   if n < 0 then
     x := 1 / x;
     n := -n;
   if n = 0 then return 1
   y := 1;
   while n > 1 do
     if n is even then
       x := x * x;
       n := n / 2;
     else
       y := x * y;
       x := x * x;
       n := (n – 1) / 2;
   return x * y
 */
class fast_pow_iterative {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        for (long long i = N; i ; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
};
#endif /* fast_pow_h */
