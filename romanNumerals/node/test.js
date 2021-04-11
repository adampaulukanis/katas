'use strict';

const roman = require('.');
const assert = require('assert').strict;

assert(roman.fromNumber(0) === '');
assert(roman.fromNumber(1) === 'I');
assert(roman.fromNumber(2) === 'II');
assert(roman.fromNumber(3) === 'III');
assert(roman.fromNumber(4) === 'IV');
assert(roman.fromNumber(5) === 'V');
assert(roman.fromNumber(6) === 'VI');
assert(roman.fromNumber(7) === 'VII');
assert(roman.fromNumber(8) === 'VIII');
assert(roman.fromNumber(9) === 'IX');

assert(roman.fromNumber(10) === 'X');
assert(roman.fromNumber(20) === 'XX');
assert(roman.fromNumber(30) === 'XXX');
assert(roman.fromNumber(40) === 'XL');
assert(roman.fromNumber(50) === 'L');
assert(roman.fromNumber(60) === 'LX');
assert(roman.fromNumber(66) === 'LXVI');
assert(roman.fromNumber(70) === 'LXX');
assert(roman.fromNumber(80) === 'LXXX');
assert(roman.fromNumber(90) === 'XC');

assert(roman.fromNumber(100) === 'C');
assert(roman.fromNumber(200) === 'CC');
assert(roman.fromNumber(300) === 'CCC');
assert(roman.fromNumber(400) === 'CD');
assert(roman.fromNumber(500) === 'D');
assert(roman.fromNumber(600) === 'DC');
assert(roman.fromNumber(700) === 'DCC');
assert(roman.fromNumber(792) === 'DCCXCII');
assert(roman.fromNumber(800) === 'DCCC');
assert(roman.fromNumber(900) === 'CM');

assert(roman.fromNumber(1000) === 'M');
assert(roman.fromNumber(2000) === 'MM');
assert(roman.fromNumber(3000) === 'MMM');

assert(roman.fromNumber(39) === 'XXXIX');
assert(roman.fromNumber(246) === 'CCXLVI');
assert(roman.fromNumber(789) === 'DCCLXXXIX');
assert(roman.fromNumber(2421) === 'MMCDXXI');
assert(roman.fromNumber(160) === 'CLX');
assert(roman.fromNumber(207) === 'CCVII');
assert(roman.fromNumber(1009) === 'MIX');
assert(roman.fromNumber(1066) === 'MLXVI');
assert(roman.fromNumber(1776) === 'MDCCLXXVI');
assert(roman.fromNumber(1918) === 'MCMXVIII');
assert(roman.fromNumber(1954) === 'MCMLIV');
assert(roman.fromNumber(2014) === 'MMXIV');

console.log('✓ Tests are OK');
