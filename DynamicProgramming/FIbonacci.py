import time

N=900
arr = []

def fibonacci_rec(n):
    if n==1:
        return 1
    if n==0:
        return 0
    return fibonacci(n-1) + fibonacci(n-2)

def fibonacci(n):
    if n==1:
        return 1
    if n==0:
        return 0
    if not arr[n]==0:
        return arr[n]
    arr[n] = fibonacci(n-1) + fibonacci(n-2)
    return arr[n]

def main():
    for i in range(N+1):
        arr.append(0)
    bef = time.time()*100000
    print(fibonacci(N))
    after = time.time()*100000
    print(after-bef)

if __name__ =='__main__':
    main()