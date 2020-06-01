size = int(input())
n = size*size
grid = [list(map(int, input().split())) for _ in range(n)]
rset = [set() for _ in range(n)]
cset = [set() for _ in range(n)]
bset = [[set() for _ in range(size)] for _ in range(size)]

# Initialize the sets
for y in range(n):
    for x in range(n):
        val = grid[y][x]
        if val != 0:
            rset[y].add(val)
            cset[x].add(val)
            bset[y//size][x//size].add(val)

# Recursive solve function - solves at most one cell
def solve():
    global grid, size, n
    for y in range(n):
        for x in range(n):
            if grid[y][x] == 0:
                for i in range(1, n+1):
                    if i not in rset[y] and i not in cset[x] and i not in bset[y//size][x//size]:
                        rset[y].add(i)
                        cset[x].add(i)
                        bset[y//size][x//size].add(i)
                        grid[y][x] = i

                        if solve():
                            return True

                        rset[y].remove(i)
                        cset[x].remove(i)
                        bset[y//size][x//size].remove(i)
                        grid[y][x] = 0
                return False
    return True

if solve():
    print('Possible')
    for y in range(n):
        print(*grid[y])
else:
    print('Impossible')