def some_function():
    condition = True
    #write condition here
    return condition

def binsrctomin(arr):
    left, right = 0, len(arr) - 1
    while left < right:
        mid = left + (right - left) // 2
        if some_function():  
            right = mid
        else:
            left = mid + 1
    return right

