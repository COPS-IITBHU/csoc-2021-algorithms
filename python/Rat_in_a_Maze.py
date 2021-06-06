def shortest_path(maze,maze_len):
    path_matrix = [[[500,0,500,500,0] for m in range(maze_len)] for n in range(maze_len)]
    ratx = 0
    raty = 0

    destx = maze_len-1
    desty = maze_len-1

    currentx = ratx
    currenty = raty

    path = []

    dist = 0
                           #[dist,indicator,parentx,parenty,visited]
    path_matrix[ratx][raty]=[0,0,0,0,1]

    while(currentx != destx or currenty != desty):
        # deciding movements for the rat
        directions = [[currentx + 1, currenty],[currentx, currenty + 1]]
        count = 0
        for [i, j] in directions:
            if (i >= 0 and i < maze_len and j >= 0 and j < maze_len):
                if (maze[i][j] != 0 and path_matrix[i][j][1] == 0 or (i == destx and j == desty)):
                    if (path_matrix[i][j][4] == 0):
                        path_matrix[i][j] = [maze[i][j] + path_matrix[currentx][currenty][0], 0, currentx, currenty,1]
                    else:
                        if (path_matrix[i][j][0] > maze[i][j] + path_matrix[currentx][currenty][0]):
                            path_matrix[i][j] = [maze[i][j] + path_matrix[currentx][currenty][0], 0, currentx,currenty, 1]
                        else:
                            count = count + 1
                else:
                    count = count + 1
            else:
                count = count + 1

        if (count == 4):# if the rat meets a dead end with nowhere to go
            path_matrix[currentx][currenty][4] = 0

        min = 400
        for i in range(maze_len):
            for j in range(maze_len):
                if (path_matrix[i][j][0] < min and path_matrix[i][j][4] == 1):
                    min = path_matrix[i][j][0]
                    min_dx = i
                    min_dy = j

        path_matrix[currentx][currenty][1] = 1
        path_matrix[currentx][currenty][4] = 0
        currentx = min_dx
        currenty = min_dy

    path.append([destx,desty])
    while(destx != ratx or desty != raty):#backtracking for the path
        path.append([path_matrix[destx][desty][2],path_matrix[destx][desty][3]])
        x = path_matrix[destx][desty][2]
        y = path_matrix[destx][desty][3]
        destx=x
        desty=y

    path.reverse()
    return (path)


maze_len = input("enter the dimension of NxN maze ")
maze_len = int(maze_len)
maze = [[[0] for m in range(maze_len)] for n in range(maze_len)]
for i in range(maze_len):
    for j in range(maze_len):
        print("enter the value for [",i,"][",j,"] block")
        maze[i][j] = input()
        maze[i][j] = int(maze[i][j])

path = shortest_path(maze,maze_len)
print("the shortest path is :")
for i in path:
    print(i)