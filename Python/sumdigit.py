def totalDigitsOfNumber(n):
    total = 0;
    while (n > 0):
        total = total + n % 10;
        n = int(n / 10);
    return total;
n = int(input())
for i in range(n):
    a = int(input())
    print(totalDigitsOfNumber(a))