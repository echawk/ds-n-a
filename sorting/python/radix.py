import array


def get_place(num: int, place: int) -> int:
    return int(num / place) % 10


def counting_sort(A, place: int):
    output = [0] * A.size
    count = [0] * 10

    for i in range(0, A.size):
        count[get_place(A.arr[i], place)] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = A.size - 1
    while i >= 0:
        output[count[get_place(A.arr[i], place)] - 1] = A.arr[i]
        count[get_place(A.arr[i], place)] -= 1
        i -= 1

    for i in range(A.size):
        A.arr[i] = output[i]


def radix_sort(A):
    mx = max(A.arr)
    place = 1
    while mx // place > 0:
        counting_sort(A, place)
        place *= 10


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    radix_sort(array)
    print("Array after sorting: ")
    array.print_Arr()
