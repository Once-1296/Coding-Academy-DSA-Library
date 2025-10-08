def some_function():
    condition = True
    #write condition here
    return condition

def binsrctomax(arr):
    left, right = 0, len(arr) - 1
    while left < right:
        mid = left + (right - left + 1) // 2
        if some_function():  
            left = mid
        else:
            right = mid - 1
    return left