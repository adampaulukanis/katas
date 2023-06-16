"use strict";

function isUniqueString(str = "") {
    str = str.toLowerCase();

    for (let i = 0; i < str.length; i++) {
        if (str.indexOf(str[i]) !== i)
            return false;
    }

    return true;
}

console.log("adm", isUniqueString("adm"));
console.log("adam", isUniqueString("adam"));
console.log("azmbcd", isUniqueString("azmbcd"));
console.log("aaa", isUniqueString("aaa"));
