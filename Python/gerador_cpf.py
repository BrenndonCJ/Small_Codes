# Gera um cpf aleatorio
# importei o script validar_cpf para validar o cpf gerado

from validar_cpf import validate_cpf
from random import randint


# Gerar uma string no formato de um cpf e faz a validação
# Só retorna o CPF caso seja validado
def gerar_cpf() -> list:
    valid: bool = False
    tentativas = 0

    while not valid:
        cpf = ''
        for d in range(11):
            cpf += str(randint(0, 9))

        valid = validate_cpf(cpf)
        tentativas += 1

    return [f"CPF : {cpf[:3]}.{cpf[3:6]}.{cpf[6:9]}-{cpf[9:]}",
            f"Tentativas : {tentativas}"]


cpf = gerar_cpf()

a = open('cpf gerado.txt', 'w', encoding='utf-8')
a.write(cpf[0])
a.close
