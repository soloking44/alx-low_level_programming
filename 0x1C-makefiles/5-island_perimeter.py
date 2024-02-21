#!/usr/bin/python3
"""This outlines a function for measuring perimeter of an island."""


def island_perimeter(grid):
    """it returns the perimeter of an island.
    The grid represents water by 0 and land by 1.
    Args:
        grid (list): A record of list of values representing an island.
    Returns:
        The perimeter of the island outlined in grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for m in range(height):
        for k in range(width):
            if grid[m][k] == 1:
                size += 1
                if (k > 0 and grid[m][k - 1] == 1):
                    edges += 1
                if (m > 0 and grid[m - 1][k] == 1):
                    edges += 1
    return size * 4 - edges * 2
