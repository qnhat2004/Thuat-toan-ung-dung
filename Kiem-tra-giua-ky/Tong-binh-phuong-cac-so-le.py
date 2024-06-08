import math

n = int(input("N = "))
k = math.ceil(n / 2) # Làm tròn lên vì nếu n là số lẻ thì k = n//2 + 1
Sum = (k * (2 * k - 1) * (2 * k + 1)) // 3
print(f"P({n}) =", Sum)


'''
Giải thích công thức:
+ > Gọi k = ceil(n/2) = n//2 + 1 nếu n là số lẻ, ngược lại k = n//2
+ > Tổng bình phương các số lẻ từ 1 đến n: S = 1^2 + 3^2 + 5^2 + ... + (2k-1)^2
+ > <-> S = [1^2 + 2^2 + ... + (2k-1)^2 + (2k)^2] - [2^2 + 4^2 + ... + (2k)^2]
+ > <-> S = (2k)[2k + 1][2(2k) + 1] / 6 - k(k+1)(2k+1) / 3 * 2
+ > <-> S = 2k(2k+1)(4k+1) / 6 -  2k(k+1)(2k+1) / 3
+ > <-> S = 2k(2k+1)(4k+1) / 6 - 2k(2k+1)[2(k+1)] / 6
+ > <-> S = 2k(2k+1)[4k+1 - 2(k+1)] / 6
+ > <-> S = 2k(2k+1)(2k-1) / 6
+ > <-> S = 2k(2k-1)(2k+1) / 6
+ > <-> S = k(2k-1)(2k+1) / 3
'''