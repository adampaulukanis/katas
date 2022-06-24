'use strict';

for (let i = 0; i < 101; i++) {
    console.log(`${i}: ${i % 3 === 0 ? 'fizz' : '    '}${i % 5 === 0 ? 'buz' : '   '}`);
}
