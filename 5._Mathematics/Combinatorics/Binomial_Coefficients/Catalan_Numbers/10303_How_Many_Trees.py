import sys
def combinations(n,k):
    c = 1
    if k > n-k:
        k = n-k
    for i in range(0,k):
        c *= (n-i)
        c //= (i+1)
    return c

def cat(n):
    return combinations(2*n,n)//(n+1)


while True:
    input = sys.stdin.readline()
    if not input: break
    n = int(input)
    print(cat(n))