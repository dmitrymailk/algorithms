# UNSOLVED
# https://codeforces.com/contest/1696/problem/C
import sys


"""
волшебное число m
может выполнять операции

# операция 1
выбрать i 1≤i≤n 
a_i, так что a_i = m * t
затем заменить
a_i на a_i / m копий, порядок остальных элементов не меняется

# операция 2
выбрать a_i, так что 1≤i≤n−m+1
такое что все числа с i по i+m-1 равны
заменить эти m элементов одним числом m * a_i, порядок остальных не меняется

Также есть другой массив b

Необходимо узнать можно ли превратить a в b
---
никаких идей как это делать.
"""

with open("./1696_C_data") as sys.stdin:
    t = int(input())
    for i in range(t):
        n, m = list(map(int, input().split()))
        array_a = list(map(int, input().split()))
        k = int(input())
        array_b = list(map(int, input().split()))
        print(f"n={n} m={m}")
        print(array_a)
        print(array_b)
