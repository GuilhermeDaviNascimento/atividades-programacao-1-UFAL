// Escreva um programa para verificar se um aluno est? ou n?o aprovado.

// S?o realizadas 03 provas (prova 1, prova 2 e prova de reposi??o). Todos os alunos s?o obrigados a fazer todas as provas.



// O aluno ser? considerado aprovado quando a m?dia final for igual ou maior que 5.5. Entretanto, h? um requisito adicional, o aluno n?o pode ter nenhuma nota abaixo de 4.0. Caso contr?rio, ser? reprovado.

// Se o aluno estiver aprovado, o programa deve exibir a mensagem: "Aprovado". Caso contr?rio, deve exibir a mensagem: "Reprovado".

// Formato de entrada

// Idade do aluno (valor inteiro)
// Nota da prova 1 (valor real)
// Nota da prova 2 (valor real)
// Nota da prova de reposi??o (valor real)
// Formato de sa?da

// Se o aluno estiver aprovado, o programa deve exibir a mensagem: "Aprovado". Caso contr?rio, deve exibir a mensagem: "Reprovado".

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int idade;
    float prova1, prova2, prova_reposicao, media;
    scanf("%d%f%f%f", &idade, &prova1, &prova2, &prova_reposicao);

    if (prova1 < 4.0 || prova2 < 4.0 || prova_reposicao < 4.0){
        printf("Reprovado");
        return 0;
    }

// Caso o aluno seja maior de idade, a m?dia final ? calculada com a m?dia ponderada entre m?dia aritm?tica das provas 1 e 2 (peso 6) e a 
// nota da prova de reposi??o (peso 3).
    if (idade >= 18){
    media = ((((prova1 + prova2) / 2) * 6) + (prova_reposicao * 3)) / 9;
// Caso o aluno seja menor de idade, a nota da prova de reposi??o s? ser? considerada caso a nota da prova 1 ou prova 2 for menor do que 7. 
// Nesse caso (alguma das notas da prova 1 e 2 forem menor do que 7), a m?dia final ser? a m?dia aritm?tica das duas maiores notas. 
// Caso contr?rio, a m?dia final ser? a m?dia aritm?tica das provas 1 e 2.

    } else {
        if (prova1 < 7 || prova2 < 7){
            float x, y, z, temp;
            x = prova1;
            y = prova2;
            z = prova_reposicao;

    if (x > y){
        temp = x;
        x = y;
        y = temp;
    }
    
    if (x > z){
        temp = x;
        x = z;
        z = temp;
    }

    if (y > z){
        temp = y;
        y = z;
        z = temp;
    }

    media = (y + z)/2;

        } else {
            media = (prova1+prova2)/2;
        }
    }


    if (media >= 5.5){
        printf("Aprovado");
    } else {
        printf("Reprovado");
    }

	return 0;
}