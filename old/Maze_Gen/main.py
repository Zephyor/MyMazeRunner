from Maze import Maze

# Maze dimensions (ncols, nrows)
nx, ny = 15, 15
# Maze entry position
ix, iy = 0, 0

maze = Maze(nx, ny, ix, iy)
maze.make_maze()

print(maze)
