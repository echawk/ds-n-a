import array

def get_max(lst):
    max_ind = 0
    for i in range(lst.size):
        if lst.arr[i] > lst.arr[max_ind]:
            max_ind = i
    return lst.arr[max_ind]


def bucket_sort(lst):
    mx = get_max(lst)
    bucket = []
    # Fill bucket list w/ 0s
    for i in range(mx):
        bucket.append(0)
    for j in range(lst.size):
        bucket[lst.arr[j] - 1] += 1
    k = 0
    m = 0
    while k < mx:
        while bucket[k] > 0:
            lst.arr[m] = k
            m += 1
            bucket[k] -= 1
        k += 1


if __name__ == "__main__":
    array = array.Arr_T()
    array.make_Arr(100)
    array.populate_Arr()
    print("Array before sorting: ")
    array.print_Arr()
    bucket_sort(array)
    print("Array after sorting: ")
    array.print_Arr()