array = list(map(int, "9 1 13 4 5 5 5 8 0 0 11 0 13 14 1 1 1 0 14 23".split()))
new_array = [array[0]]
for i in range(1, len(array)):
    num = new_array[i - 1] + array[i]
    new_array.append(num)

print(array)
print(new_array)
print(set(new_array), len(set(new_array)))
