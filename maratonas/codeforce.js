var fs = require("fs");
var input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
var n = input.shift()
input.forEach(frase => {
    if(frase.length > 10){
        var number = 0
        console.log(`${frase[0]}${frase.length - 2}${frase[frase.length - 1]}`)
    } else {
        console.log(frase)
    }
});