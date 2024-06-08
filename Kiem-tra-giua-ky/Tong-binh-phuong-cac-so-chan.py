n = int(input("N = "))
Sum = 0
k = n//2
Sum = k * (k+1) * (2*k+1) // 3 * 2
print(f"P({n}) =", Sum)

'''
Giải thích công thức: 
+ >  Gọi k = n/2
+ >  Tổng bình phương các số chẵn từ 1 đến n: S = 2^2 + 4^2 + 6^2 + ... + (2k)^2
+ >  --> S = 2^2(1^2 + 2^2 + 3^2 + ... + k^2)
+ >  Mà ta biết, công thức tổng bình phương các số từ 1 đến n: n(n+1)(2n+1)/6
+ > --> S = 2^2 * k(k+1)(2k+1)/6 = k(k+1)(2k+1)/3 * 2
'''