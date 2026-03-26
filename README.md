# Complete Sorting Notes in Data Structures

## Contents
1. [Introduction to Sorting](#introduction-to-sorting)
2. [Classification of Sorting Algorithms](#classification-of-sorting-algorithms)
3. [Bubble Sort](#1-bubble-sort)
4. [Selection Sort](#2-selection-sort)
5. [Insertion Sort](#3-insertion-sort)
6. [Merge Sort](#4-merge-sort)
7. [Quick Sort](#5-quick-sort)
8. [Heap Sort](#6-heap-sort)
9. [Shell Sort](#7-shell-sort)
10. [Counting Sort](#8-counting-sort)
11. [Radix Sort](#9-radix-sort)
12. [Bucket Sort](#10-bucket-sort)
13. [Comparison Table](#comparison-table)
14. [Practice Set](#practice-set)
15. [Conclusion](#conclusion)

---

## Introduction to Sorting

**Sorting** is the process of arranging data in a particular order, usually:
- **Ascending order**: smallest to largest
- **Descending order**: largest to smallest

Sorting is important because it:
- makes searching faster,
- helps in data analysis,
- improves readability of data,
- is used in databases, operating systems, networking, and many real-world applications.

### Basic Terms
- **Stable Sort**: keeps equal elements in the same relative order.
- **In-place Sort**: requires only a small extra memory.
- **Comparison Sort**: sorts by comparing elements.
- **Non-comparison Sort**: uses element values directly (for example, digits or counts).

---

## Classification of Sorting Algorithms

### 1. Comparison-Based Sorting
These algorithms compare elements to decide order.
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Shell Sort

### 2. Non-Comparison-Based Sorting
These algorithms do not rely only on comparisons.
- Counting Sort
- Radix Sort
- Bucket Sort

---

# 1. Bubble Sort

## Concept
Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.  
After each pass, the largest unsorted element "bubbles up" to its correct position.

It is simple to understand, but inefficient for large data sets.

## Algorithm
1. Start from the first element.
2. Compare the current element with the next element.
3. If the current element is greater than the next one, swap them.
4. Continue this process for the whole array.
5. Repeat the passes until no swaps are needed.

## Diagram

```text
Initial:  [5] [1] [4] [2] [8]

Pass 1:
[5] [1] -> swap -> [1] [5]
[5] [4] -> swap -> [4] [5]
[5] [2] -> swap -> [2] [5]
[5] [8] -> no swap

After Pass 1: [1] [4] [2] [5] [8]
After Pass 2: [1] [2] [4] [5] [8]
```

## Example with Explanation
Let the array be:

```text
29, 10, 14, 37, 13
```

### Pass 1
- 29 and 10 -> swap -> 10, 29, 14, 37, 13
- 29 and 14 -> swap -> 10, 14, 29, 37, 13
- 29 and 37 -> no swap
- 37 and 13 -> swap -> 10, 14, 29, 13, 37

### Pass 2
- 10 and 14 -> no swap
- 14 and 29 -> no swap
- 29 and 13 -> swap -> 10, 14, 13, 29, 37

### Pass 3
- 10 and 14 -> no swap
- 14 and 13 -> swap -> 10, 13, 14, 29, 37

### Pass 4
- 10 and 13 -> no swap

**Sorted array:** `10, 13, 14, 29, 37`

## Program Using C

```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(n)` (when already sorted and optimized with swapped flag)
- **Average Case:** `O(n^2)`
- **Worst Case:** `O(n^2)`
- **Space Complexity:** `O(1)`

## Exercises
1. Sort `8, 3, 5, 1, 9` using Bubble Sort and show every pass.
2. Why is Bubble Sort called a **stable** sorting algorithm?
3. Modify Bubble Sort to sort in descending order.

---

# 2. Selection Sort

## Concept
Selection Sort repeatedly selects the smallest element from the unsorted part of the array and places it at the beginning.

It performs fewer swaps than Bubble Sort, but still takes quadratic time.

## Algorithm
1. Assume the first unsorted element is the minimum.
2. Search the rest of the array for a smaller element.
3. If a smaller element is found, update the minimum index.
4. Swap the minimum element with the first unsorted element.
5. Repeat for the remaining positions.

## Diagram

```text
Array: [29] [10] [14] [37] [13]

Pass 1: smallest = 10
Swap 29 and 10
        [10] [29] [14] [37] [13]

Pass 2: smallest in remaining = 13
Swap 29 and 13
        [10] [13] [14] [37] [29]
```

## Example with Explanation
Array: `29, 10, 14, 37, 13`

### Pass 1
- Smallest from index 0 to 4 is `10`
- Swap `29` and `10`
- Array becomes: `10, 29, 14, 37, 13`

### Pass 2
- Smallest from index 1 to 4 is `13`
- Swap `29` and `13`
- Array becomes: `10, 13, 14, 37, 29`

### Pass 3
- Smallest from index 2 to 4 is `14`
- No change needed

### Pass 4
- Smallest from index 3 to 4 is `29`
- Swap `37` and `29`
- Array becomes: `10, 13, 14, 29, 37`

## Program Using C

```c
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(n^2)`
- **Average Case:** `O(n^2)`
- **Worst Case:** `O(n^2)`
- **Space Complexity:** `O(1)`

## Exercises
1. Apply Selection Sort on `64, 25, 12, 22, 11`.
2. How many swaps happen in Selection Sort compared to Bubble Sort?
3. Is Selection Sort stable by default? Explain.

---

# 3. Insertion Sort

## Concept
Insertion Sort builds the sorted array one element at a time.  
It takes one element from the unsorted portion and inserts it into its correct position in the sorted portion.

It works very well for small or nearly sorted arrays.

## Algorithm
1. Treat the first element as already sorted.
2. Take the next element and compare it with elements in the sorted part.
3. Shift larger elements one position to the right.
4. Insert the current element at the correct position.
5. Repeat for all elements.

## Diagram

```text
Array: [29] [10] [14] [37] [13]

Step 1:
Sorted:   [29]
Unsorted: [10] [14] [37] [13]

Insert 10 before 29:
[10] [29] [14] [37] [13]

Insert 14 between 10 and 29:
[10] [14] [29] [37] [13]
```

## Example with Explanation
Array: `29, 10, 14, 37, 13`

### Step 1
- Sorted part: `29`
- Take `10`
- Insert before `29`
- Array: `10, 29, 14, 37, 13`

### Step 2
- Sorted part: `10, 29`
- Take `14`
- Insert between `10` and `29`
- Array: `10, 14, 29, 37, 13`

### Step 3
- Take `37`
- Already larger than all sorted elements
- Array: `10, 14, 29, 37, 13`

### Step 4
- Take `13`
- Shift `37`, `29`, `14` right
- Insert `13`
- Array: `10, 13, 14, 29, 37`

## Program Using C

```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(n)`
- **Average Case:** `O(n^2)`
- **Worst Case:** `O(n^2)`
- **Space Complexity:** `O(1)`

## Exercises
1. Perform Insertion Sort on `7, 4, 5, 2`.
2. Why is Insertion Sort efficient for nearly sorted arrays?
3. Write a version of Insertion Sort that sorts in descending order.

---

# 4. Merge Sort

## Concept
Merge Sort follows the **divide and conquer** technique.
- Divide the array into two halves.
- Sort each half recursively.
- Merge the sorted halves.

It is efficient and stable, especially for large data sets.

## Algorithm
1. If the array has one element, it is already sorted.
2. Divide the array into two halves.
3. Recursively sort the left half.
4. Recursively sort the right half.
5. Merge both sorted halves into one sorted array.

## Diagram

```text
Array: [29, 10, 14, 37, 13]

            [29, 10, 14, 37, 13]
              /               \
        [29, 10, 14]         [37, 13]
          /      \             /    \
      [29]    [10, 14]      [37]   [13]
               /   \
            [10]  [14]

Merge back:
[10, 14] + [29]      -> [10, 14, 29]
[13] + [37]          -> [13, 37]
[10, 14, 29] + [13, 37] -> [10, 13, 14, 29, 37]
```

## Example with Explanation
Array: `29, 10, 14, 37, 13`

### Divide
- Left: `29, 10, 14`
- Right: `37, 13`

### Sort Left
- `29`
- `10, 14` -> already merged as `10, 14`
- Merge -> `10, 14, 29`

### Sort Right
- `37`
- `13`
- Merge -> `13, 37`

### Final Merge
Merge `10, 14, 29` and `13, 37`
- 10 comes first
- then 13
- then 14
- then 29
- then 37

**Sorted array:** `10, 13, 14, 29, 37`

## Program Using C

```c
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(n log n)`
- **Average Case:** `O(n log n)`
- **Worst Case:** `O(n log n)`
- **Space Complexity:** `O(n)`

## Exercises
1. Draw the recursion tree for Merge Sort on `8, 3, 2, 9, 7, 1, 5, 4`.
2. Why is Merge Sort called a stable sort?
3. Compare Merge Sort and Quick Sort in terms of memory usage.

---

# 5. Quick Sort

## Concept
Quick Sort also uses the **divide and conquer** method.
It selects a **pivot** element, places it in the correct position, then arranges smaller elements to the left and larger elements to the right.

It is very fast in practice, but its worst case is quadratic when partitions are poor.

## Algorithm
1. Choose a pivot element.
2. Partition the array so that:
   - smaller elements go to the left,
   - larger elements go to the right.
3. Recursively sort the left part.
4. Recursively sort the right part.

## Diagram

```text
Array: [29, 10, 14, 37, 13]
Pivot = 13

Partition:
Smaller than 13 -> [10]
Pivot           -> [13]
Greater         -> [29, 14, 37]

Now sort [29, 14, 37]
Pivot = 37
Smaller -> [29, 14]
Pivot   -> [37]

Sort [29, 14]
Pivot = 14
Smaller -> []
Pivot   -> [14]
Greater -> [29]

Final: [10, 13, 14, 29, 37]
```

## Example with Explanation
Array: `29, 10, 14, 37, 13`

Choose `13` as pivot.

- Elements smaller than 13: `10`
- Elements greater than 13: `29, 14, 37`

Now sort the right part `29, 14, 37`
- Choose `37` as pivot
- Left part: `29, 14`
- Right part: empty

Sort `29, 14`
- Choose `14` as pivot
- Left: empty
- Right: `29`

Final result: `10, 13, 14, 29, 37`

## Program Using C

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(n log n)`
- **Average Case:** `O(n log n)`
- **Worst Case:** `O(n^2)`
- **Space Complexity:** `O(log n)` for recursion stack in average case

## Exercises
1. Apply Quick Sort to `50, 23, 9, 18, 61, 32`.
2. What happens when the pivot is always the smallest or largest element?
3. How can randomized pivot selection improve Quick Sort?

---

# 6. Heap Sort

## Concept
Heap Sort uses a **binary heap** data structure.  
For ascending order, it builds a **max heap**, where the largest element is at the root. Then it swaps the root with the last element and rebuilds the heap.

It is efficient and does not need extra array memory like Merge Sort.

## Algorithm
1. Build a max heap from the array.
2. Swap the root (largest element) with the last element.
3. Reduce the heap size by one.
4. Heapify the root again.
5. Repeat until the heap size becomes 1.

## Diagram

```text
Array: [4, 10, 3, 5, 1]

As Max Heap:

        10
       /  \
      5    3
     / \
    4   1

Remove 10 -> place at end
Remaining heap rebuilt
```

## Example with Explanation
Array: `29, 10, 14, 37, 13`

### Build Max Heap
A possible max heap arrangement becomes:

```text
        37
       /  \
     29    14
    /  \
   10  13
```

### Step 1
- Swap root `37` with last element `13`
- Array becomes: `13, 29, 14, 10, 37`
- Heapify remaining heap
- New heap root becomes `29`

### Step 2
- Swap `29` with `10`
- Heapify remaining heap
- Continue until sorted

Final array: `10, 13, 14, 29, 37`

## Program Using C

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(n log n)`
- **Average Case:** `O(n log n)`
- **Worst Case:** `O(n log n)`
- **Space Complexity:** `O(1)`

## Exercises
1. Convert `12, 11, 13, 5, 6, 7` into a max heap.
2. Why is Heap Sort not stable?
3. Compare Heap Sort with Merge Sort.

---

# 7. Shell Sort

## Concept
Shell Sort is an improved version of Insertion Sort.
Instead of comparing adjacent elements only, it first compares far-apart elements using a **gap**. The gap gradually reduces until it becomes 1.

This reduces the number of shifts needed.

## Algorithm
1. Choose an initial gap (commonly `n/2`).
2. Perform insertion sort on elements that are `gap` distance apart.
3. Reduce the gap.
4. Repeat until gap becomes 1.

## Diagram

```text
Array: [29, 10, 14, 37, 13]

Gap = 2
Groups:
(29, 14, 13)
(10, 37)

Sort each gap-based group:
(14, 13, 29)
(10, 37)

Array becomes closer to sorted.

Gap = 1
Now perform normal insertion sort.
```

## Example with Explanation
Array: `29, 10, 14, 37, 13`

### Gap = 2
Compare and shift elements at distance 2:
- Group 1: `29, 14, 13`
- Group 2: `10, 37`

After sorting gap groups, the array becomes more organized.

### Gap = 1
Now perform insertion sort on nearly sorted array.

Final sorted array: `10, 13, 14, 29, 37`

## Program Using C

```c
#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
Time complexity depends on the gap sequence.

- **Best Case:** approximately `O(n log n)` in some gap sequences
- **Average Case:** around `O(n^1.3)` to `O(n^2)` depending on implementation
- **Worst Case:** `O(n^2)` (common simple gap sequence)
- **Space Complexity:** `O(1)`

## Exercises
1. Apply Shell Sort on `23, 12, 1, 8, 34, 54, 2, 3`.
2. Why is Shell Sort faster than Insertion Sort for medium-sized arrays?
3. Try a different gap sequence and compare the number of shifts.

---

# 8. Counting Sort

## Concept
Counting Sort is a non-comparison sorting algorithm.
It counts how many times each value appears, then uses this count information to place elements in sorted order.

It works only when the range of input values is not too large.

## Algorithm
1. Find the maximum value in the array.
2. Create a count array of size `max + 1`.
3. Count the occurrence of each element.
4. Convert counts into positions.
5. Build the output array.
6. Copy output back to the original array.

## Diagram

```text
Input: [4, 2, 2, 8, 3, 3, 1]

Count array index: 0 1 2 3 4 5 6 7 8
Count values:      0 1 2 2 1 0 0 0 1

Sorted output:
[1, 2, 2, 3, 3, 4, 8]
```

## Example with Explanation
Array: `4, 2, 2, 8, 3, 3, 1`

### Count frequency
- 1 appears 1 time
- 2 appears 2 times
- 3 appears 2 times
- 4 appears 1 time
- 8 appears 1 time

### Rebuild sorted array
- Write 1 once
- Write 2 twice
- Write 3 twice
- Write 4 once
- Write 8 once

Result: `1, 2, 2, 3, 3, 4, 8`

## Program Using C

```c
#include <stdio.h>

void countingSort(int arr[], int n) {
    int i, max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];
    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(n + k)`
- **Average Case:** `O(n + k)`
- **Worst Case:** `O(n + k)`
- **Space Complexity:** `O(k)`

Where `k` is the range of values.

## Exercises
1. Apply Counting Sort on `5, 2, 9, 5, 2, 3, 5`.
2. Why is Counting Sort not suitable when the maximum value is very large?
3. Modify the algorithm to handle values from `0` to `50`.

---

# 9. Radix Sort

## Concept
Radix Sort sorts numbers digit by digit.
It usually processes digits from **least significant digit (LSD)** to **most significant digit (MSD)**, using a stable sorting method like Counting Sort for each digit.

It works well for integers with limited digit length.

## Algorithm
1. Find the maximum number to know the number of digits.
2. Sort numbers according to the 1's place.
3. Sort numbers according to the 10's place.
4. Sort numbers according to the 100's place.
5. Continue until all digit positions are processed.

## Diagram

```text
Input: [170, 45, 75, 90, 802, 24, 2, 66]

Sort by 1's digit:
[170, 90, 802, 2, 24, 45, 75, 66]

Sort by 10's digit:
[802, 2, 24, 45, 66, 170, 75, 90]

Sort by 100's digit:
[2, 24, 45, 66, 75, 90, 170, 802]
```

## Example with Explanation
Array: `170, 45, 75, 90, 802, 24, 2, 66`

### Pass 1: sort by unit digit
Look at the last digit of each number:
- 170 -> 0
- 45 -> 5
- 75 -> 5
- 90 -> 0
- 802 -> 2
- 24 -> 4
- 2 -> 2
- 66 -> 6

After stable sorting by 1's digit:
`170, 90, 802, 2, 24, 45, 75, 66`

### Pass 2: sort by 10's digit
After sorting by tens place:
`802, 2, 24, 45, 66, 170, 75, 90`

### Pass 3: sort by 100's digit
Final:
`2, 24, 45, 66, 75, 90, 170, 802`

## Program Using C

```c
#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSortByDigit(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int exp;
    int max = getMax(arr, n);

    for (exp = 1; max / exp > 0; exp *= 10)
        countingSortByDigit(arr, n, exp);
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(d(n + b))`
- **Average Case:** `O(d(n + b))`
- **Worst Case:** `O(d(n + b))`
- **Space Complexity:** `O(n + b)`

Where:
- `d` = number of digits
- `b` = base (usually 10)

## Exercises
1. Perform Radix Sort on `121, 432, 564, 23, 1, 45, 788`.
2. Why must the internal sort used in Radix Sort be stable?
3. Compare Radix Sort and Counting Sort.

---

# 10. Bucket Sort

## Concept
Bucket Sort distributes elements into several buckets, sorts each bucket separately, and then combines the buckets.

It is useful when input data is uniformly distributed, especially for floating-point numbers in the range `0` to `1`.

## Algorithm
1. Create empty buckets.
2. Put each element into its appropriate bucket.
3. Sort each bucket individually.
4. Concatenate all buckets to form the sorted result.

## Diagram

```text
Input: [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]

Buckets:
Bucket 0: [0.17, 0.12]
Bucket 1: [0.21, 0.23, 0.26]
Bucket 2: [ ]
Bucket 3: [0.39]
Bucket 4: [ ]
Bucket 5: [ ]
Bucket 6: [0.68]
Bucket 7: [0.78, 0.72]
Bucket 8: [ ]
Bucket 9: [0.94]

After sorting each bucket and joining:
[0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94]
```

## Example with Explanation
Input:
`0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68`

### Bucket placement
- Values near `0.1` go into bucket 1
- Values near `0.2` go into bucket 2
- Values near `0.7` go into bucket 7
- and so on

### Sort each bucket
- Bucket with `0.17, 0.12` becomes `0.12, 0.17`
- Bucket with `0.21, 0.23, 0.26` remains sorted after small insertion sort
- Bucket with `0.78, 0.72` becomes `0.72, 0.78`

### Concatenate
Final result:
`0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94`

## Program Using C

```c
#include <stdio.h>

void insertionSortFloat(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    int i, j, k;

    float buckets[n][n];
    int bucketCount[n];

    for (i = 0; i < n; i++)
        bucketCount[i] = 0;

    for (i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        if (index >= n)
            index = n - 1;
        buckets[index][bucketCount[index]++] = arr[i];
    }

    for (i = 0; i < n; i++) {
        insertionSortFloat(buckets[i], bucketCount[i]);
    }

    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucketCount[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

void printArray(float arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

## Time Complexity
- **Best Case:** `O(n + k)`
- **Average Case:** `O(n + k)`
- **Worst Case:** `O(n^2)` (if many elements fall into the same bucket)
- **Space Complexity:** `O(n + k)`

## Exercises
1. Apply Bucket Sort on `0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51`.
2. Why is Bucket Sort good for uniformly distributed data?
3. What happens when almost all elements fall into one bucket?

---

# Comparison Table

| Sorting Algorithm | Type | Stable | In-Place | Best Case | Average Case | Worst Case |
|---|---|---:|---:|---:|---:|---:|
| Bubble Sort | Comparison | Yes | Yes | O(n) | O(n^2) | O(n^2) |
| Selection Sort | Comparison | No | Yes | O(n^2) | O(n^2) | O(n^2) |
| Insertion Sort | Comparison | Yes | Yes | O(n) | O(n^2) | O(n^2) |
| Merge Sort | Comparison | Yes | No | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | Comparison | No | Mostly Yes | O(n log n) | O(n log n) | O(n^2) |
| Heap Sort | Comparison | No | Yes | O(n log n) | O(n log n) | O(n log n) |
| Shell Sort | Comparison | No | Yes | Depends | Depends | O(n^2) |
| Counting Sort | Non-comparison | Yes | No | O(n + k) | O(n + k) | O(n + k) |
| Radix Sort | Non-comparison | Yes | No | O(d(n + b)) | O(d(n + b)) | O(d(n + b)) |
| Bucket Sort | Non-comparison | Depends | No | O(n + k) | O(n + k) | O(n^2) |

---

# Practice Set

## Very Short Questions
1. Define sorting.
2. What is a stable sorting algorithm?
3. What is an in-place sorting algorithm?
4. Name two non-comparison sorting algorithms.
5. Which sorting algorithm uses divide and conquer?

## Short Answer Questions
1. Differentiate between Bubble Sort and Selection Sort.
2. Explain why Insertion Sort is useful for nearly sorted arrays.
3. Write the steps of Merge Sort.
4. What is a pivot in Quick Sort?
5. Why is Counting Sort not used for very large ranges?

## Long Answer Questions
1. Explain Bubble Sort with algorithm, example, complexity, and C program.
2. Compare Merge Sort, Quick Sort, and Heap Sort.
3. Explain Radix Sort with a digit-by-digit example.
4. Explain Bucket Sort using floating-point values.
5. Compare all sorting algorithms on the basis of stability, in-place nature, and time complexity.

## Lab Exercises
1. Write a menu-driven C program to perform:
   - Bubble Sort
   - Selection Sort
   - Insertion Sort
   - Merge Sort
   - Quick Sort
2. Count the number of comparisons and swaps for Bubble Sort.
3. Modify Quick Sort to sort in descending order.
4. Implement Counting Sort for integers from `0` to `100`.
5. Test all algorithms on:
   - sorted data,
   - reverse sorted data,
   - random data,
   and compare execution time.

---

# Conclusion

Sorting is a fundamental topic in data structures and algorithms.

- Use **Bubble, Selection, Insertion** for learning basic logic.
- Use **Merge, Quick, Heap** for efficient sorting of large arrays.
- Use **Counting, Radix, Bucket** when data properties make them suitable.

For exams and interviews, remember:
- **Concept**
- **Algorithm steps**
- **Example**
- **Diagram**
- **C program**
- **Time complexity**
- **Stability**
- **Space usage**

These notes can be used directly for study, revision, assignment work, and viva preparation.
