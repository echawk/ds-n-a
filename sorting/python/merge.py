import array

def merge_sort(lst: [int]):
    if len(lst) > 1:
        mid = len(lst)//2
        leftA = lst[:mid]
        rightA = lst[mid:]
        merge_sort(leftA)
        merge_sort(rightA)
        i = j = k = 0
        while i < len(leftA) and j < len(rightA):
            if leftA[i] < rightA[j]:
                lst[k] = leftA[i]
                i += 1
            else:
                lst[k] = rightA[j]
                j += 1
            k += 1
        while i < len(leftA):
            lst[k] = leftA[i]
            i += 1
            k += 1
        while j < len(rightA):
            lst[k] = rightA[j]
            j += 1
            k += 1


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    merge_sort(array.arr)
    print("Array after sorting: ")
    array.print_Arr()