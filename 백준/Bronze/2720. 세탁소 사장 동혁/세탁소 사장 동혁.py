T = int(input())
for i in range(T):
    cost = int(input())
    for coin in (25, 10, 5, 1):
        count = 0
        if cost >= coin:
            count += cost // coin
            cost -= count * coin
        print(count, end=" ")
    print()