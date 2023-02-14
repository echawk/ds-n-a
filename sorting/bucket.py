import random


def get_max(lst):
    max_ind = 0
    for i in range(len(lst)):
        if lst[i] > lst[max_ind]:
            max_ind = i
    return lst[max_ind]


def bucket_sort(lst):
    mx = get_max(lst)
    bucket = []
    # Fill bucket list w/ 0s
    for i in range(mx):
        bucket.append(0)
    for j in range(len(lst)):
        bucket[lst[j] - 1] += 1
    k = 0
    m = 0
    while k < mx:
        while bucket[k] > 0:
            lst[m] = k
            m += 1
            bucket[k] -= 1
        k += 1


if __name__ == "__main__":
    l = []
    n = 100
    for i in range(n):
        l.append(random.randint(0, n))
    print(l)
    bucket_sort(l)
    print(l)
