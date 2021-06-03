def linear_search( input_list , item ):
    '''Takes inout as list & integer and then prints its avalability in  the list'''
    for i in input_list:
        if i==item:
            print("Element =",item, "succesfully found in the list at index =",input_list.index(item))
            return
    else:
        print("Element =",item,"not found in the list")



if __name__ == "__main__":    
    while True:
        try:
            n=int(input("Enter the number of elements in the list: "))
            L=[]
            for i in range(n):
                print("Enter element",i+1,end=": ")
                L.append(int(input()))

            search_item = int(input("Enter the element to search for in the list: "))

            linear_search(L,search_item)
            break
    
        except:
            print("Some error has occured. Please enter the values carefully")
            continue