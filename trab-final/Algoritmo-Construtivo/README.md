# Algoritmo Construtivo para o PDC

Implementação da heurística construtiva utilizada por [Gliesch e Ritt, 2019](https://dl.acm.org/doi/abs/10.1145/3321707.3321874?casa_token=fnr5wyH6ijgAAAAA:wyqcqw8HOjqp88uCByyUyzcDCtWRBe0SJCiwUCEuVts5Wnbtsi0n2o_9gWaVxDazADTjaU2dSsVNzYY) para a solução do Problema de Distritamento Comercial.

## Requisitos

É necessário ter instalado um compilador que suporte *C++14* ou mais recente.

Para a execução de diversos testes com um único comando é necessário ter instalado *python3*.

## Compilação e Execução

Para compilar o programa, vá à pasta raiz e utilize os seguintes comandos:

```
$ make clean
$ make
```

Após compilar o programa ele pode ser executado com o seguinte formato de comando:

```
./constr-distr.app <arquivo-de-entrada> <arquivo-de-saida>
```

## Instâncias de Teste

O diretório [./test_instances/examples/](https://github.com/thuzax/ED-2020/tree/master/trab-final/Algoritmo-Construtivo/test_instances/examples) contém instâncias da literatura como exemplo. Elas foram propostas por [Ríos-Mercado e Fernández, 2009](https://www.sciencedirect.com/science/article/pii/S0305054807002249?casa_token=gnXw0l-0rf4AAAAA:OFnxJ8jhzXy3gaVs094pFfWja8S09D4O5W4htPM4EP7-_3tOMuKX4z-3B0IlxfMzE6DJk6sXRpHD) e  [Gliesch, Ritt e Moreira, 2018](https://link.springer.com/chapter/10.1007/978-3-319-77449-7_11)

## Execução de Vários Testes

Para executar mais de um teste, é necessário inserí-los em uma mesma pasta. Após isso, deve-se modificar o arquivo [tester.py](https://github.com/thuzax/ED-2020/blob/master/trab-final/Algoritmo-Construtivo/tester.py) e inserir o caminho até o diretório onde se encontram as instâncias e onde serão escritos os arquivos com os resultados. Neste arquivo também é possível definir o número de vezes que cada instância será execuatada. Ao finalizar as configurações, basta utilizar o comando abaixo:

```
python3 tester.py
```

Para a análise de resultados, deve-se indicar (no arquivo [analyser.py](https://github.com/thuzax/ED-2020/blob/master/trab-final/Algoritmo-Construtivo/analyser.py)) o caminho onde foram salvos os arquivo de saída utilizados nos testes no. Também é necessário indicar o caminho onde será escrito um arquivo *csv* contendo valores relacionados às execuções de cada arquivo. Após as configurações execute o comando:

```
python3 analyser.py
```

Por padrão, o arquivo [tester.py](https://github.com/thuzax/ED-2020/blob/master/trab-final/Algoritmo-Construtivo/tester.py) executa as instâncias da literatura de exemplo e armazena seus resultados em [./results/teste-ed-2020/](https://github.com/thuzax/ED-2020/tree/master/trab-final/Algoritmo-Construtivo/results/tests-ed-2020). Após a análise, feita pela execução do arquivo [analyser.py](https://github.com/thuzax/ED-2020/blob/master/trab-final/Algoritmo-Construtivo/analyser.py), o resultado é salvo em [./results/teste-ed-2020-analysis/](https://github.com/thuzax/ED-2020/tree/master/trab-final/Algoritmo-Construtivo/results/tests-ed-2020-analysis).
