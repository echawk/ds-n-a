import random

gap_coeff = 10.0 / 13.0


# FIXME
def comb_sort(lst):
    i = len(lst)
    j = i
    gap = i
    swapped_p = True
    while gap > 1 or swapped_p:
        gap = gap * gap_coeff
        if gap < 1:
            gap = 1
        swapped_p = False
        j = gap
        for i in range(len(lst)):
            print(f"j {int(j)}")
            if lst[i] > lst[int(j)]:
                t = lst[i]
                lst[i] = lst[int(j)]
                lst[int(j)] = lst[i]
                swapped_p = True
            j += 1


if __name__ == "__main__":
    l = []
    n = 100
    for i in range(n):
        l.append(random.randint(0, n))
    print(l)
    comb_sort(l)
    print(l)
