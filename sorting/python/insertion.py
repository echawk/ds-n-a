import array


def insertion_sort(A):
    i = 1
    while i < A.size:
        j = i
        while j > 0 and A.arr[j - 1] > A.arr[j]:
            A.swap(j, j - 1)
            j -= 1
        i += 1


"""MAIN"""
array = array.Arr_T()
array.make_Arr(100)
array.populate_Arr()
print("Array before sorting: ")
array.print_Arr()
insertion_sort(array)
print("Array after sorting: ")
array.print_Arr()
