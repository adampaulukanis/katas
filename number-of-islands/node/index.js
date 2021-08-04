"use strict";

function countIslands(grid) {
  //if (grid == null) return;
  let islandsCount = 0;

  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] == 1) {
        ++islandsCount;
        // Change any other land connected to zeros
        changeLandToWater(grid, i, j);
      }
    }
  }
  return islandsCount;
}

function changeLandToWater(grid, i, j) {
  if (
    i < 0 ||
    i >= grid.length ||
    j < 0 ||
    j >= grid[0].length ||
    grid[i][j] == 0
  )
    return;

  // We know now the position must be a 1
  grid[i][j] = 0;

  changeLandToWater(grid, i - 1, j); // down
  changeLandToWater(grid, i + 1, j); // up
  changeLandToWater(grid, i, j - 1); // left
  changeLandToWater(grid, i, j + 1); // right
}

module.exports = countIslands;
