# Alunos
* Fernando Ribeiro Aguilar - 14/0139281

# Objetivo

* Elaborar um programa em código C para realizar o carregamento de bibliotecas.

* Criar uma biblioteca de cálculo das funções seno e arco seno, que receba o ângulo em Radianos.
  * Utilizar esta biblioteca de 3 formas diferentes

1. Utilizar como biblioteca estática
2. Utilizar como bilioteca dinâmica
3. Realizar o carregamento da biblioteca sob demanda, durante a execução do programa.

# Ambiente

As informações sobre o ambiente de compilação e construção estão citados abaixo

## Compilação

### GCC
> gcc version 6.2.0 20160901 (Ubuntu 6.2.0-3ubuntu11~16.04)

### AR
> GNU ar version 2.27-21.fc26

## Construção
> Linux fraguilarLinux 4.8.0-52-generic #55~16.04.1-Ubuntu x86_64 GNU/Linux

# Compilando e executando

Para compilar este projeto, basta executar o comando a seguir,

    make

Para limpar o ambiente use o comando a seguir,

    make clean

Para testar a execução do programa sem informar parâmetros iniciais,

    make run

# Instruções de uso

Após a compilação, gerão geradas 2 pastas chamadas ./bin e ./obj.

Na pasta bin estarão 3 executáveis chamados de:

- exec_a: Compilação com a biblioteca estática
- exec_b: Compilação com a carga sobre demanda
- exec_c: Compilação com a biblioteca dinâmica

A pasta ./obj armazenará as respectivas bibliotecas libseno.so e libseno.a.

Após adicionar esse caminho a biblioteca, basta executar qualquer um dos binários.

```
- a: ./bin/exec_a [-s|-a] [Value]
- b: ./bin/exec_b [-s|-a] [Value]
- c: ./bin/exec_c [-s|-a] [Value]
```
Em que -s é para seno e o -a é para o arcoseno.
Deve ser informado o valor do ângulo em radianos.

# Limitações

* As limitações identificadas estão relacionadas a quantidade de casas decimais das contas.
* O programa possui também limitações quanto a valores de seno maiores que 1.
* O programa possui mal funcionamento ao executar a função arco_seno
* Caso seja digitado um caracter onde deve ser digitado o ângulo, o resultado é calculado para o ângulo 0 (zero).

# Questões

1. Para a resolução dos itens A e B do enunciado do trabalho, não foram necessárias nenhuma modificação no código. Mudou-se apenas a maneira de compilar cada arquivo, de acordo com as necessidades foram feitas devidas alterações no makefile. No item A cria-se um arquivo de biblioteca extensão *.a*, no item B cria-se um arquivo de biblioteca com extensão *.so*

1. A criação de um link estático com a biblioteca impossibilita a alteração de comportamento caso necessário. Uma vez compilado, é possivel realizar mudanças apenas compilando novamente. Utilizando do link dinâmico é possivel o carregamento da biblioteca pelo loader o que indica a possibilidade de alterações na biblioteca original. Também é notável que, por ser carregada dinâmicamente, vários programas podem ter acesso a essa mesma biblioteca, reduzindo a quantidade de codigo que será carregado de acordo com as necessidades, podendo ser utilizada por diversos programas diferentes. A principal desvantagem está no que se refere a intuitividade no uso das bibliotecas. Sendo baixo o valor de aplicabilidade em sistemas e programas de menor escala.

1. Relação das dependências:
    1. Estática
        1. Na compilação da aplicação com biblioteca estática é necessário apenas a utilização de alagumas bibliotecas cp,p libc e libseno e libstring. Para a execução não é necessária dependência nenhuma.
        1. A posição desta biblioteca fica na área de texto (código fonte) do processo.
    1. Dinâmica
        1. Para a compilação da biblioteca dinâmica, é necessário também, somente a libc e a libseno. Para a execução, é exigido que exista a biblioteca nos caminhos que o Sistema Operacional busca as bibliotecas, não é necessária nenhuma outra dependência.
        1. Fica como armazenado em área de referência de memória do processo.
    1. Sob demanda
        1. para a carga sobre demanda são necessárias linux-vdso.so.1, libdl.so.2, libc.so.6 e ld-linux-x86-64.so.2.
        1. Fica na área de heap do processo
