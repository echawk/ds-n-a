import array
import time


def cocktail_sort(A):
    swapped = True
    s = 0
    e = A.size - 1
    while swapped:
        swapped = False
        for i in range(s, e):
            if A.arr[i] > A.arr[i + 1]:
                A.swap(i, i + 1)
                swapped = True
        if not swapped:
            break
        swapped = False
        e -= 1
        for i in range(e, s - 1, -1):
            if A.arr[i] > A.arr[i + 1]:
                A.swap(i, i + 1)
                swapped = True
        s += 1


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    start = time.time()
    cocktail_sort(array)
    end = time.time()
    print("\nArray after sorting: ")
    array.print_Arr()
    print("\nThe execution time for the cocktail sort algorithm is: " + str(float(end-start)))
