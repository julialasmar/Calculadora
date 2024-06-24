#include <stdio.h>
#include <string.h>
#pragma GCC diagnostic ignored "-Wunused-result"

 int listaResultado( int resultado) { printf("%d", resultado); }

 int removerDigito( int numero, int posicao) {
   int novoNumero = 0;
  int fator = 1;
  // Calcula o fator para mover os dígitos para a posição correta
  for (int i = 0; i < posicao; i++) {
    fator *= 10;
  }
  // Divide o número em duas partes: antes e depois da posição
   int parteEsquerda = numero / (fator * 10); // Dígitos à esquerda da posição
   int parteDireita = numero % fator;         // Dígitos à direita da posição

  // Combina as partes esquerda e direita para formar o novo número
  novoNumero = parteEsquerda * fator + parteDireita;
  return novoNumero;
}

 int contaDigitos( int num) {
    if (num == 0) {
        return 0;
    }
    return 1 + contaDigitos(num / 10);
}

 int adicionarDigito( int numeroOriginal, int posicao, int numeroAdicionar) {
   int novoNumero = 0;
  int fator = 1;
  if (posicao < contaDigitos(numeroOriginal)) {
    // Calcula o fator para mover os dígitos para a posição correta
    for (int i = 0; i < posicao; i++) {
      fator *= 10;
    }
    // Divide o número original em duas partes: antes e depois da posição
     int parteEsquerda = numeroOriginal / fator;
     int parteDireita = numeroOriginal % fator;
    // Combina as partes esquerda, número a adicionar e parte direita para
    // formar o novo número
    novoNumero =
        parteEsquerda * (fator * 10) + numeroAdicionar * fator + parteDireita;
    return novoNumero;
  } else
    return numeroOriginal;
}

 int alternarDigitos( int num1,  int num2) {
    int len1 = contaDigitos(num1); // Número de dígitos em num1
    int len2 = contaDigitos(num2); // Número de dígitos em num2
    // Inicializar índices para percorrer os dígitos de ambos os números
    int i = 0;
    int j = 0;
    // Inicializar variáveis para armazenar o número intercalado
     int intercaladoNum = 0;
     int multiplicador = 1;
    // Percorrer os dígitos começando pelos menos significativos
    while (i < len1 || j < len2) {
        if (i < len1) {
            intercaladoNum += (num1 % 10) * multiplicador;
            num1 /= 10;
            i++;
            multiplicador *= 10;
        }
        if (j < len2) {
            intercaladoNum += (num2 % 10) * multiplicador;
            num2 /= 10;
            j++;
            multiplicador *= 10;
        }
    }
    // Retornar o número intercalado como resultado da função
    return intercaladoNum;
}

 int concatenaNumeros( int num1, int num2) {
     int resultado;

    // Multiplica num1 pelo número de 10 elevado ao número de dígitos de num2
     int multiplicador = 1;
    int num2_digitos = 0;
    int num2_temp = num2;
    while (num2_temp != 0) {
        num2_temp /= 10;
        num2_digitos++;
    }
    for (int i = 0; i < num2_digitos; i++) {
        multiplicador *= 10;
    }

    resultado = ( int)num1 * multiplicador + num2;

    return resultado;
}

 int inverterNumero( int numero) {
   int numeroInvertido = 0;
  // Enquanto houver dígitos no número original
  while (numero != 0) {
    // Obtém o último dígito do número original
     int digito = numero % 10;
    // Adiciona o dígito ao número invertido, deslocando os dígitos existentes
    // para a esquerda
    numeroInvertido = numeroInvertido * 10 + digito;
    // Remove o último dígito do número original
    numero /= 10;
  }

  return numeroInvertido;
}

 int removerAlgarismosPares( int numero) {
  int numeroSemPares = 0;
  int posicao = 1;
  // Enquanto houver dígitos no número original
  while (numero != 0) {
    // Obtém o último dígito do número original
    int digito = numero % 10;
    // Verifica se o dígito é par
    if (digito % 2 != 0) {
      // Adiciona o dígito ao número resultante, ajustando a posição
      numeroSemPares += digito * posicao;
      posicao *= 10; // Incrementa a posição para o próximo dígito no número resultante
    }
    // Remove o último dígito do número original
    numero /= 10;
  }

  return numeroSemPares;
}

int main() {
   int numerox;
  int digito, novoNumero, indice, contadorDigitos;
  int opcao = 1;
  //Digite um valor para x
  scanf("%d", &numerox);

  while (opcao != 0) {
    //Digite a opção desejada
    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      break;
    case 1:
      //Qual posição deseja remover
      scanf("%d", &indice);
      numerox = removerDigito(numerox, indice);
      break;
    case 2:
      //Em qual posição
      scanf("%d", &indice);
      //Qual digito deseja adicionar
      scanf("%d", &digito);
      numerox = adicionarDigito(numerox, indice, digito);
      break;
    case 3:
      printf("%d", contaDigitos(numerox));
      break;
    case 4:
      //Com qual valor deseja alternar
      scanf("%d", &digito);
      numerox = alternarDigitos(numerox, digito);
      break;
    case 5:
      //Qual valor deseja concatenar
      scanf("%d", &digito);
      numerox = concatenaNumeros(numerox, digito);
      break;
    case 6:
      numerox = inverterNumero(numerox);
      break;
    case 7:
      numerox = removerAlgarismosPares(numerox);
      break;
    default:
      listaResultado(numerox);
    }
    printf("\n");
  }
}