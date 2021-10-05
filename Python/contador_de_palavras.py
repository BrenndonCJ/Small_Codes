#encoding: utf-8
#contador de palavras
#artigos são contados separado
from select_archiv import open_arch, print_result


class Contador:
    def __init__(self):
        try:

            self.path = open_arch()
            print(self.path[0])

            self.archiv = open(self.path[0],'r', encoding='utf-8')
            self.lista = self.archiv.read().strip('\n').split(' ')

            print(self.lista)

            
            self.numbers = self.cont()
            print_result(self.numbers[0], self.numbers[1])
            
            print(f"""Total de palavras: {self.numbers[0]}
Total de artigos: {self.numbers[1]}""")

        except FileNotFoundError:
            print("Arquivo não encontrado")

    def cont(self):
        self.cont_pa = 0
        self.cont_ar = 0

        for self.element in self.lista:
            self.leng = len(self.element)

            if self.leng > 1:
                self.cont_pa += 1
            elif self.leng == 1:
                self.cont_ar += 1
        
        return self.cont_pa, self.cont_ar


Contador()