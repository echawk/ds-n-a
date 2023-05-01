import array
import time


def insertion_sort(A):
    i = 1
    while i < A.size:
        j = i
        while j > 0 and A.arr[j - 1] > A.arr[j]:
            A.swap(j, j - 1)
            j -= 1
        i += 1


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    start = time.time()
    insertion_sort(array)
    end = time.time()
    print("\nArray after sorting: ")
    array.print_Arr()
    print("\nThe execution time for the insertion sort algorithm is: " + str(float(end-start)))
