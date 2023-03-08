const roman = require('.')

for (let i = 0; i < 4000; i++) {
    console.log(i, roman.fromNumber(i))
}

// node % > lista.txt
