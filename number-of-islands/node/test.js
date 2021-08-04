"use strict";

const assert = require("assert");
const countIslands = require(".");

const testGrid1 = [
  Array.from("11000"),
  Array.from("11000"),
  Array.from("00100"),
  Array.from("00011"),
  Array.from("00011"),
];
const testGrid1Answer = 3;

const testGrid2 = [
  Array.from("11110"),
  Array.from("11010"),
  Array.from("11000"),
  Array.from("00000"),
];
const testGrid2Answer = 1;

assert(countIslands(testGrid1) === testGrid1Answer);
assert(countIslands(testGrid2) === testGrid2Answer);

assert(countIslands([[0]]) === 0);
assert(countIslands([[1]]) === 1);

console.log('Tests are O.K.');
