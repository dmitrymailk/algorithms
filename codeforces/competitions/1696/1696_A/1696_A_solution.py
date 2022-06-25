amount_data = int(input())
for i in range(amount_data):
    n, z = list(map(int, input().split()))
    array = list(map(int, input().split()))
    max_num = max([z | num for num in array])
    print(max_num)
