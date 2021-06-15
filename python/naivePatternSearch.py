x = "welcome to my world, welcome"
y = "welcome"

def search(x,y):
	list_indices = []
	for i in range(len(x)):
		if x[i] == y[0]:
			flag = True
			for j in range(1,len(y)-1):
				if y[j] != x[i+j]:
					flag=False
					break
			if flag == True:
				list_indices.append(i)
	return list_indices

for i in search(x,y):
	print("There is a match at index {}".format(i))
