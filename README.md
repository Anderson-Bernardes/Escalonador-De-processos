# Escalonador-De-processos

Trabalho da disciplina de laboratorio de sistemas operacionais 

Se trata de um simulador do escalonamento de processos de acordo com sua prioridade, simulando como o sistema operacional manteria a ordem e o tempo de cada processo em execução

Um processo é representado por uma struct com os campos id, prioridade, tamanho e quantum. O campo id é gerado sequencialmente, já os campos prioridade e tamanho são gerados randomicamente, onde prioridade pode receber os valores de 1 a 100 e tamanho pode receber o valor de 100 a 1000. O campo quantum é setado com o valor 0. As filas de execução são represetadas por um vetor de 10 filas onde cada fila representa um intervalo de 10 niveis de prioridade onde 1 é a fila com maior prioridade e 10 a fila com menor prioridade. Na função de executar processo, o processo a ser executado tem seu quantum calculado que é feito com o calculo tamanho - prioridade. Na execução o quantum calculado é subtraido do tamanho do processo. Após a execução, se o processo já tiver terminado, ele é retirado da fila, e se o processo ainda não terminou ele é adicionado novamente no final da fila.

Para gerar o gráfico de processos executados por fila, durante cada iteração do processo é escrito em um arquivo o tempo de execução e o número de processos executados por fila. Para plotar o gráfico é usado o GnuPlot.
