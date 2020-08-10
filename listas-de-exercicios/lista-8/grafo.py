from lista_adj import ListaAdjacencia
from vertice import Vertice
from aresta import Aresta




class Grafo:
    def __init__(self, num_vertices, arestas):
        # Cria os vertices
        self.vertices = []
        for i in range(num_vertices):
            vertice = Vertice(i)
            self.vertices.append(vertice)

        # Cria um dicionario de arestas com o par de vertices sendo a chave
        self.dic_arestas = {}
        for aresta in arestas:
            v1, v2, capacidade = aresta
            
            key = (v1, v2)
            invert_key = (v2, v1)
            
            aresta_dicionario = self.dic_arestas.get(key)

            # Se nao existe aresta entre os vertices no dicionario
            if (aresta_dicionario is None):
                nova_aresta = Aresta(v1, v2, capacidade)
                self.dic_arestas[key] = nova_aresta
                self.dic_arestas[invert_key] = nova_aresta
            else:
                # Se existir mais de uma aresta entre dois vertices, pode-se 
                # considerar que existe apenas uma aresta com a soma das 
                # capacidades
                self.dic_arestas[key].capacidade += capacidade
                self.dic_arestas[key].atualiza_residual()

        
        # Cria um vetor com os indices das arestas (para facilitar a criação da 
        # lista de adjacencia)
        self.indices_arestas = set()
        for aresta in arestas:
            key = (aresta[0], aresta[1])
            invert_key = (aresta[1], aresta[0])

            if (key in self.indices_arestas 
                or invert_key in self.indices_arestas):
                continue
            self.indices_arestas.add((aresta[0], aresta[1]))

        self.grafo = ListaAdjacencia(num_vertices, self.indices_arestas)


    # Deixa todos os vertices sem cor e sem anterior
    def limpa_todos_vertices(self):
        for vertice in self.vertices:
            vertice.colorido = False
            vertice.anterior = None

    # Utiliza a busca em largura para gerar um caminho aumentante
    def get_caminho_aumentante(self, origem_idx, destino_idx):
        origem = self.vertices[origem_idx]
        destino = self.vertices[destino_idx]

        self.limpa_todos_vertices()

        origem.colorido = True

        encontrou = False
        fila = [origem_idx]

        # busca em largura adaptada
        while (len(fila) > 0 and not encontrou):
            u = fila.pop(0)
            for v in self.grafo.get_vizinhos(u):
                vizinho = self.vertices[v]
                aresta = self.dic_arestas[(u,v)]
                
                if (aresta.esta_cheia() or vizinho.colorido):
                    continue

                self.vertices[v].colorido = True
                
                fila.append(v)
                
                # se encontrou chegou ao destino, um caminho aumentante foi 
                # encontrado, o loop pode ser finalizado
                vizinho.anterior = self.vertices[u]
                if (v == destino_idx):
                    encontrou = True

        # Se não chegou ao destino, não há mais caminho aumentante
        if (not encontrou):
            return []
        
        # Monta o caminho utilizando os ids
        caminho = [destino_idx]
        anterior = self.vertices[destino_idx].anterior
        while (anterior != None):
            caminho.insert(0, anterior.idx)
            anterior = anterior.anterior
        
        return caminho

    def get_arestas_caminho(self, caminho):
        arestas = []
        for i in range(len(caminho) - 1):
            v1 = caminho[i]
            v2 = caminho[i+1]
            key = (v1, v2)
            aresta = self.dic_arestas[key]
            arestas.append(aresta)
        return arestas

    def get_fluxo_possivel(self, arestas_caminho):
        menor_custo = arestas_caminho[0].residual
        for aresta in arestas_caminho:
            if (aresta.residual < menor_custo):
                menor_custo = aresta.residual
        
        return menor_custo

    def ford_fulkerson(self, origem_idx, destino_idx):
        for aresta in self.dic_arestas.values():
            aresta.fluxo = 0

        caminho_aumentante = self.get_caminho_aumentante(
                                origem_idx, destino_idx
                            )
        
        while (len(caminho_aumentante) > 0):
            arestas_caminho_aumentante = self.get_arestas_caminho(
                                            caminho_aumentante
                                        )
            
            aumento_maximo = self.get_fluxo_possivel(arestas_caminho_aumentante)

            for aresta in arestas_caminho_aumentante:
                aresta.fluxo += aumento_maximo
                aresta.atualiza_residual()
            
            caminho_aumentante = self.get_caminho_aumentante(
                                    origem_idx, destino_idx
                                )
            # Para imprimir cada passo, descomente as proximas linhas
            # print(caminho_aumentante)
            # print(aumento_maximo)
            # print(self.get_string())
        
        fluxo_total = 0
        vizinhos_destino = self.grafo.get_vizinhos(destino_idx)
        for i in vizinhos_destino:
            fluxo_total += self.dic_arestas[(i, destino_idx)].fluxo
        

        return fluxo_total
            


    def get_string_vertices(self):
        texto = ""
        texto += "-------Vertices-------\n"

        for i in range(len(self.vertices)):
            texto += self.vertices[i].get_string()
        
        return texto

    def get_string_arestas(self):
        texto = ""
        
        for key in self.indices_arestas:
            texto += self.dic_arestas[key].get_string()

        return texto

    def get_string_adjacencia(self):
        return self.grafo.get_string()


    def get_string(self):
        texto = ""

        for i in range(len(self.vertices)):
            texto += self.vertices[i].get_string()
        
        texto += "-------Arestas-------\n"
        for key in self.indices_arestas:
            texto += self.dic_arestas[key].get_string()

        texto += "-------Lista Adj-------\n"
        texto += self.grafo.get_string()
        
        return texto
