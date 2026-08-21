var fs = require("fs");
var input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
var n = Number(input.shift())
for (let i = 0; i < n; i++) {

    let array_frutas = [];
    let array_silabas = [];
    let array_iniciais_frutas = [];
    var temp = Number(input.shift())
    var temp_2 = Number(input.shift())

    for (let j = 0; j < temp; j++) {
        array_frutas.push(input.shift())
    }

    for (let k = 0; k < temp_2; k++) {
        array_silabas.push(input.shift())
    }

    for (let k = 0; k < array_frutas.length; k++) {
        array_iniciais_frutas.push(array_frutas[k][0].toUpperCase())
    }

    //remover duplicatas
    let new_array_inicias = [...new Set(array_iniciais_frutas)]

    for (let index = 0; index < array_silabas.length; index++) {
        let encontrou = 0;
        for (let j = 0; j < array_silabas[index].length; j++) {
            for (let k = 0; k < new_array_inicias.length; k++) {
                if (array_silabas[index][j] == new_array_inicias[k]) {
                    encontrou++
                    break;
                }
            }
        }
        if (encontrou == array_silabas[index].length) {
            console.log("yes")
            break
        } else if (encontrou != array_silabas[index].length && index + 1 == array_silabas[index].length) {
            console.log("no")
            break
        }
    }

    // console.log(array_frutas, array_silabas, new_array_inicias)
}
