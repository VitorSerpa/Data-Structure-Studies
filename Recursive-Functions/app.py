def sum(n):
    if n == 1:
        return 1
    return n + sum(n - 1)

def rCount(n):
    if n < 0:
        return
    print(n)
    rCount(n - 1)




def countDigits(n):
    if n < 10:
        return 1
    return 1 + countDigits(n // 10)



def multiplicar(mult, num):
    if mult == 1:
        return num

    return num + multiplicar(mult - 1, num)

print(multiplicar(10 ,  4))
