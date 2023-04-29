import array
import time


def get_max(A) -> int:
    max = A.arr[0]
    for i in range(1, A.size):
        if A.arr[i] > max:
            max = A.arr[i]
    return max


def counting_sort(A):
    output = [0] * A.size
    max = get_max(A)
    count = [0] * (max + 1)
    for i in range(max + 1):
        count[i] = 0
    for j in range(A.size):
        count[A.arr[j]] += 1
    for k in range(1, max + 1):
        count[k] += count[k - 1]
    for n in range(A.size - 1, -1, -1):
        output[count[A.arr[n]] - 1] = A.arr[n]
        count[A.arr[n]] -= 1
    for m in range(A.size):
        A.arr[m] = output[m]


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    start = time.time()
    counting_sort(array)
    end = time.time()
    print("\nArray after sorting: ")
    array.print_Arr()
    print("\nThe execution time for the counting sort algorithm is: " + str(float(end-start)))
