#!/usr/bin/env python3
"""
pzy: a commandline fuzzy matcher written entirely in Python.
"""

from typing import TypeVar, List, Tuple

T = TypeVar("T")


def tail(l: List[T]) -> List[T]:
    return l[1:]


def head(l: List[T]) -> T:
    return l[0]


def lev(a: List[T], b: List[T]) -> int:
    """
    Function for calculating the levenshtein distance between two lists (a & b).

    Very very slow when working with large strings.
    Even though there is nice 'mathematical purity' to the function.
    """
    if len(b) == 0:
        return len(a)
    if len(a) == 0:
        return len(b)
    if head(a) == head(b):
        return lev(tail(a), tail(b))
    return 1 + min(lev(tail(a), b), lev(a, tail(b)), lev(tail(a), tail(b)))


def make2d_list(row: int, col: int) -> List[List[int]]:
    arr: List[List[int]] = []
    for i in range(0, row):
        arr.append([])
        for _ in range(0, col):
            arr[i].append(0)
    return arr


def wagner_fischer_distance_py(search: str, candidate: str) -> int:
    """
    Function for calculating the levenstein distance via the
    Wagner-Fischer Method

    No external dependencies. Pure Python.
    """
    # m x n arr
    m = len(search)  # row
    n = len(candidate)  # col
    d = make2d_list(m, n)  # start off with matr of zeros

    for i in range(0, m):  # first row is zero so that we can fuzzy match properly
        d[i][0] = i

    for j in range(1, n):
        d[0][j] = j

    for j in range(0, n):
        for i in range(0, m):
            if search[i] == candidate[j]:
                subcost = 0
            else:
                subcost = 1

            # deletion
            # insertion
            # substitution
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + subcost)
    return d[m - 1][n - 1]


def get_scores(needle: str, candidates: List[str]) -> List[Tuple[int, str]]:
    """
    Compute the scores for each candidate in candidates.
    We lowercase both the needle and the candidate to score, since we
    only care about 'fuzzy' matching
    also filter out candidates that are shorter than our needle, since
    This is a 'search' tool
    """
    score_dict = {}

    def aux(needle, cand):
        if len(cand) >= len(needle):
            score_dict[cand] = wagner_fischer_distance_py(needle.lower(), cand.lower())
        return None

    # Spin up mutliple threads to help score, one for each candidate.
    # NOTE: This could likely be improved by only spinning up a few threads
    # that each will score some portion of the candidates.
    threads = []
    for c in candidates:
        threads.append(
            threading.Thread(
                target=aux,
                args=(
                    needle,
                    c,
                ),
            )
        )

    for t in threads:
        t.start()

    # Wait for them to finish.
    for t in threads:
        t.join()

    # Sort our dictionary according to score.
    sorted_score_dict = sorted(score_dict.items(), key=lambda x: x[1])
    l: List[Tuple[int, str]] = [(val, key) for key, val in sorted_score_dict]
    return l


def sort_print(scores: List[Tuple[int, str]]) -> None:
    scores.sort(reverse=True)  # Sort reverse order (want highest printed first)
    for score, candidate in scores:
        print(candidate, " ", str(score))


import sys
import os
import threading

have_match: bool = False  # control whether the user has entered a match

# Read in our data then close sys.stdin
stdin_input: List[str] = sys.stdin.readlines()
sys.stdin.close()
# Strip trailing newlines from stdinput
candidates: List[str] = [s.rstrip() for s in stdin_input]

# Re-open stdin so we can have the interactive part
sys.stdin = os.fdopen(1)

import time

while not have_match:
    needle = str(input(">"))
    start_time = time.time()
    scores = get_scores(needle, candidates)
    end_time = time.time()
    sort_print(scores)
    print(f"time to score: {end_time - start_time}")
    if needle in candidates:
        have_match = True
        print("MATCH:", needle)
