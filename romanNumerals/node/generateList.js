const roman = require('.')

for (let i = 0; i < 2024; i++) {
    console.log(i, roman.fromNumber(i))
}
