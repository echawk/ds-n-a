import array

def shell_sort(A):
    gap = int(A.size/2)
    while gap > 0:
        x = gap
        while x < A.size:
            y = x - gap
            while y >= 0:
                if A.arr[y + gap] > A.arr[y]:
                    break
                else:
                    A.swap(y, y + gap)
                y = y - gap
            x = x + 1
        gap = int(gap/2)


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    shell_sort(array)
    print("Array after sorting: ")
    array.print_Arr()