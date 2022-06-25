# SOLVED
# https://codeforces.com/contest/1696/problem/0
import sys

"""
выбрать любой элемент из массива
a_i = a_i | z
z = a_i & z
сделать так чтобы получить a_i максимальным

3) пример
n=5 z=5 [0, 2, 4, 6, 8]  
5 | 8 = 13

5) пример
3 39548743 [10293834, 10284344, 13635445]
39548743
13635445

По итогу просто по порядку сложить побитово все числа и взять из них максимум 
"""

with open("./data_0") as sys.stdin:
    amount_data = int(input())
    for i in range(amount_data):
        # print(i)
        n, z = list(map(int, input().split()))
        array = list(map(int, input().split()))
        max_num = max([z | num for num in array])
        print(max_num)
