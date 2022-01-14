# Returns either the index of the location in the array,
#  or -1 if the array did not contain the targetValue
def doSearch(array, targetValue):
    min = 0
    max = len(array) - 1

    while min <= max:
        guess = (max + min) // 2
        if array[guess] > targetValue:
            max = guess - 1
        elif array[guess] < targetValue:
            min = guess + 1
        else:
            return guess

    return -1
