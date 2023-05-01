import array
import time


def heapify(A, N: int, i: int):
    largest = i
    left = (2 * i) + 1
    right = (2 * i) + 2
    if left < N and A.arr[left] > A.arr[largest]:
        largest = left
    if right < N and A.arr[right] > A.arr[largest]:
        largest = right
    if largest != i:
        A.swap(i, largest)
        heapify(A, N, largest)


def heap_sort(A, N: int):
    for i in range(int(N / 2 - 1), -1, -1):
        heapify(A, N, i)
    for j in range(int(N - 1), -1, -1):
        A.swap(0, j)
        heapify(A, j, 0)


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    start = time.time()
    heap_sort(array, array.size)
    end = time.time()
    print("\nArray after sorting: ")
    array.print_Arr()
    print("\nThe execution time for the heap sort algorithm is: " + str(float(end-start)))
