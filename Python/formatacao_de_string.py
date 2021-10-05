# Formatação de string
# Remoção de um espaço antes de pontos e virgulas


class Main():

    def __init__(self) -> None:
        #self.t = ' . abcde . asjd  . askdja , asdas  , a.'
        self.t = """1. Absoluta: economias que possuem as mesmas características convergem para
uma mesma renda de equilíbrio, porém as mais atrasadas crescem mais
rapidamente, até “encontrar” as mais adiantadas e a partir deste momento
caminham juntas;

2. Condicional: a convergência não ocorre para a mesma renda per-capita de
equilíbrio, ou seja, cada país converge para o seu ponto de equilíbrio, pois suas
estruturas econômicas são diferentes."""

        self.test()
        print(self.t)

    def f_s_list(self):

        for c in range(len(self.t)-1):
            try:
                if self.t[c] == ' ' and (self.t[c+1] == '.' or self.t[c+1] == ','):
                    self.t = self.t[:c] + self.t[c+1:]
                    print(self.t)
            except:
                return self.t

        return self.t

    def test(self):

        print(len(self.t))

        for c in range(len(self.t)-1):
            try:
                if self.t[c] != '\n' and self.t[c+1] == '\n' and self.t[c+2] != '\n':
                    self.t = self.t[:c+1]+' '+self.t[c+2:]
            except:
                pass

        print(len(self.t))

        return self.t


Main()
