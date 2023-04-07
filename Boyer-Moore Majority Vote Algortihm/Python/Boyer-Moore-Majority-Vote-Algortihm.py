def find_majority_element(arr):
    candidate = 0
    count = 0

    for num in arr:
        if count == 0:
            candidate = num
        count += 1 if num == candidate else -1

    return candidate

arr = [2, 2, 1, 1, 2, 2]

result = find_majority_element(arr)
print("Majority element is:", result)
