import sys

from bellman_ford import BellmanFord
from lista_adj import ListaAdjacencia

class Grafo:
    ''' Argumentos: 
                número de vértices 
                nomes dos vertices
                pares de arestas
    '''
    def __init__(self, num_vertices, nomes_vertices, arestas_por_nome):
        self.num_vertices = num_vertices
        self.num_arestas = len(arestas_por_nome)

        self.nomes_vertices = nomes_vertices
        self.indices_vertices = {}

        self.arestas = []

        ind = 0
        for v in self.nomes_vertices:
            self.indices_vertices[v] = ind
            ind += 1

        for aresta_por_nome in arestas_por_nome:
            v1 = self.indices_vertices[aresta_por_nome[0]]
            v2 = self.indices_vertices[aresta_por_nome[1]]
            peso = aresta_por_nome[2]
            aresta = (v1, v2, peso)
            self.arestas.append(aresta)
    
    def get_num_vertices(self):
        return self.num_vertices

    def get_num_arestas(self):
        return self.num_arestas

    def get_grau_medio(self):
        return (2 * self.num_arestas / self.num_vertices)

    def get_caminhos_bellman_ford(self, nome_origem):
        caminho_minimo = BellmanFord(self.num_vertices, self.arestas)

        origem = self.indices_vertices[nome_origem]
        resultados = caminho_minimo.bellman_ford(origem)

        if (resultados is None):
            return resultados;

        custos, pais = resultados

        caminhos = []
        for destino in range(self.num_vertices):
            caminho = [destino]
            
            
            intermediario = destino
            pai = pais[intermediario]
            
            if (pai is None and destino != origem):
                caminho = [None]
                caminhos.append(caminho)
                continue

            while ((pai is not None) and (intermediario != origem)):
                pai = pais[intermediario]
                caminho.append(pai)
                
                intermediario = pai
            
            caminhos.append(caminho)
        
        caminhos_nomes = []
        for caminho in caminhos:
            caminho_nomes = []

            for v in caminho:
                if (v is None):
                    nome = None
                else:
                    nome = self.nomes_vertices[v]
                caminho_nomes.insert(0, nome)
            
            caminhos_nomes.append(caminho_nomes)

        caminhos_custos = []
        for i in range(self.num_vertices):
            destino = self.nomes_vertices[i]
            caminhos_custos.append((destino, caminhos_nomes[i], custos[i]))

        return (caminhos_custos, caminho_minimo.contador)