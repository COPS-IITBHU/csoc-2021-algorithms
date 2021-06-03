
def sum_subset(arr, target):

    n = len(arr)
    # Create array with all False elements
    dp_array = [[False for i in range(target+1)] for j in range(n)]
    
    # Set elements of first column as True
    for i in range(n):
        dp_array[i][0]=True
    
    # Iterate through rest of the array
    for i in range(n):
        for j in range(1, target+1):            
            if i == 0:
                if j == arr[i]:
                    dp_array[i][j] = True
            else:
                if j < arr[i]:
                    dp_array[i][j] = dp_array[i-1][j]
                else:
                    dp_array[i][j] = dp_array[i-1][j-arr[i]] or dp_array[i-1][j]

    return dp_array[n-1][target]    

if __name__ == "__main__":
    test_arr = [3, 7, 2, 8, 10]
    subset_sum = 11
    if sum_subset(test_arr, subset_sum):
        print("Subset exists")
    else:
        print("Subset does not exist")
