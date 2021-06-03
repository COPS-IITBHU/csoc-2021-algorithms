# Creation and initialisation of input array.
arr = [int(x) for x in input().split()]

# Initialisation of a token to store maximum length of non increasing subarray.
m = 1

# Initialisation of a token to store current maximum length of non increasing subarray.
count = 1

# Navigation through the list to find maximum length.
for i in range(1, len(arr)):
    # Checking the condition for breaking and boundary cases.
    if arr[i] > arr[i - 1]:
        m = max(count, m)
        count = 1
    else:
        count += 1
    if i == len(arr) - 1:
        m = max(count, m)

# Printing maximum length on stdout.
print(m)
