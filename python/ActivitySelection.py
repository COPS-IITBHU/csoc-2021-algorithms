#Activity selection problem using Greedy algorithm in python

def selectActivity(activities):
    i = 0                   
    indices= set()
    indices.add(0)
    activities.sort(key=lambda x: x[1])
 
    for n in range(1, len(activities)):
 
        if activities[n][0] >= activities[i][1]:
            indices.add(n)
            i = n         
    return indices
 
if __name__ == '__main__':
 
    activities = [(1,2), (5,9), (8, 12), (2, 13), (12, 14), (0,6), (5,7), (8,9), (0, 6), (5, 7), (3, 8), (5, 9),
                (6, 10), (8, 11)]
 
    result = selectActivity(activities)
    print([activities[i] for i in result])
