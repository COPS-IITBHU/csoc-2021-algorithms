def search(a, b):
    m = len(a)
    n = len(b)
 

    for i in range(n - m + 1):
        j = 0
         
        while(j < m):
            if (b[i + j] != a[j]):
                break
            j += 1
 
        if (j == m):
            print("pattern found at index ", i)
 

b = input("Enter Text: ")
a = input("Enter pattern to search: ")
search(a, b)