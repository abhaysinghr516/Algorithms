def counting_sort(arr):
    max_val, min_val = max(arr), min(arr)

    range_len = max_val - min_val + 1
    count = [0] * range_len
    output = [0] * len(arr)

    for num in arr:
        count[num - min_val] += 1

    for i in range(1, range_len):
        count[i] += count[i - 1]

    for i in range(len(arr) - 1, -1, -1):
        output[count[arr[i] - min_val] - 1] = arr[i]
        count[arr[i] - min_val] -= 1

    for i in range(len(arr)):
        arr[i] = output[i]

arr = [4, 2, 2, 8, 3, 3, 1]

counting_sort(arr)

print(arr)
