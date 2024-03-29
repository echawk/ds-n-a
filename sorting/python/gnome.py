import array
import time


def gnome_sort(lst):
    pos = 0

    while pos < lst.size:
        if (pos == 0) or (lst.arr[pos] >= lst.arr[pos - 1]):
            pos += 1
        else:
            lst.swap(pos, pos - 1)
            pos -= 1


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    start = time.time()
    gnome_sort(array)
    end = time.time()
    print("\nArray after sorting: ")
    array.print_Arr()
    print("\nThe execution time for the gnome sort algorithm is: " + str(float(end-start)))
