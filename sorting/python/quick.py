import array
import time


def partition(lst, low, high):
    pivot = lst.arr[high]
    i = low - 1
    j = low
    while j <= high:
        if lst.arr[j] < pivot:
            i += 1
            # Swap i & j
            lst.swap(i, j)
        j += 1
    lst.swap(i + 1, high)
    return i + 1


def quick_sort_driver(lst, low, high):
    if low < high:
        pi = partition(lst, low, high)
        quick_sort_driver(lst, low, pi - 1)
        quick_sort_driver(lst, pi + 1, high)


def quick_sort(lst):
    quick_sort_driver(lst, 0, lst.size - 1)


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    start = time.time()
    quick_sort(array)
    end = time.time()
    print("\nArray after sorting: ")
    array.print_Arr()
    print("\nThe execution time for the quick sort algorithm is: " + str(float(end-start)))
