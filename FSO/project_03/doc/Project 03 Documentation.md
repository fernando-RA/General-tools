# Alunos
* Fernando Ribeiro Aguilar - 14/0139281

# Objetivo

Elaborar um programa utilizando código C para implementar o problema de produtor e consumidor.

Criar e processar threads, sendo 1 produtora e 2 consumidoras, na qual a thread produtora irá gerar números inteiros aleatórios.

# Ambiente

As informações sobre o ambiente de compilação e construção estão citados abaixo

* #### Sistema operacional Utilizado:
  * Debian 8 "Jessie"

* #### Ambiente de desenvolvimento:
  * Editor de Texto: Atom
  * Complilador: gcc
  * Interface Gráfica: Gnome

# Compilando e executando

Para compilar este projeto, basta executar o comando a seguir

    make

Para limpar o ambiente use o comando a seguir

    make clean

Para compilar e executar o programa use o comando a seguir

    make run

# Instruções de uso

Após a compilação, será gerado um arquivo chamado de Threads_ProducerConsumer no diretório bin do local de compilação. Como argumento de entrada, espera-se um único argumento que é o nome do arquivo onde serão escritas as mensagens de *logger*.

    ./bin/Threads_ProducerConsumer log.txt

Após o recebimento da mensagem a aplicação irá sinalizar para as threads encerrarem suas atividades, e mostrará as informações de maior e menor números lidos e o maior espaço de buffer ocupado.

## Exemplo de execução

    ./bin/Threads_ProducerConsumer output.txt
    ^C
    [aviso]: Termino solicitado. Aguardando threads...
    [aviso]: Maior numero gerado: 1060333116
    [aviso]: Menor numero gerado: -1031225206
    [aviso]: Maior ocupacao de buffer: 2
    [aviso]: Aplicacao encerrada.

# Limitações

* O buffer é limitado a 50 posições, e quando ele está cheio o número gerado é descartado.]
* O programa gera um warning de compilação para a função usleep
      W-implicit-function-declaration
* O programa somente funcionará caso um arquivo de output seja informado
