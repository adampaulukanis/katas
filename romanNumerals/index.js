'use strict';

const decimalPlaces = {
    units: {
        0: '',
        1: 'I',
        2: 'II',
        3: 'III',
        4: 'IV',
        5: 'V',
        6: 'VI',
        7: 'VII',
        8: 'VIII',
        9: 'IX',
    },
    tens: {
        0: '',
        1: 'X',
        2: 'XX',
        3: 'XXX',
        4: 'XL',
        5: 'L',
        6: 'LX',
        7: 'LXX',
        8: 'LXXX',
        9: 'XC',
    },
    hundreds: {
        0: '',
        1: 'C',
        2: 'CC',
        3: 'CCC',
        4: 'CD',
        5: 'D',
        6: 'DC',
        7: 'DCC',
        8: 'DCCC',
        9: 'CM',
    },
    thousands: {
        0: '',
        1: 'M',
        2: 'MM',
        3: 'MMM',
    }
};

class RomanNumerals{
    static fromNumber(number){
        if (number < 0 || number > 3999)
            throw new Error('Number is not permited');

        number = String(number);
        let roman = '';

        // thousands
        if (number > 999)
            roman += decimalPlaces.thousands[number[number.length -4]];
        // hundreds
        if (number > 99)
            roman += decimalPlaces.hundreds[number[number.length -3]];
        // tens
        if (number > 9)
            roman += decimalPlaces.tens[number[number.length -2]];
        // units
        roman += decimalPlaces.units[number[number.length -1]];

        return roman;
    };
};

module.exports = RomanNumerals;
