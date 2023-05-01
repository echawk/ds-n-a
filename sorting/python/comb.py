import array
import time

GAPCOEFF = 10.0 / 13.0


def comb_sort(A):
    gap = A.size
    swapped = True
    while gap > 1 or swapped:
        gap = int(gap * GAPCOEFF)
        if gap < 1:
            gap = 1
        swapped = False
        i = 0
        for j in range(gap, A.size):
            if A.arr[i] > A.arr[j]:
                A.swap(i, j)
                swapped = True
            i += 1


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    start = time.time()
    comb_sort(array)
    end = time.time()
    print("\nArray after sorting: ")
    array.print_Arr()
    print("\nThe execution time for the comb sort algorithm is: " + str(float(end-start)))
