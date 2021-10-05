# Faz a validação de um numero de CPF


def validate_cpf(cpf: str) -> bool:
    cpf_list = [int(n) for n in cpf if n.isnumeric()]
    valid = set(cpf_list)

    if len(valid) > 1:
        if len(cpf_list) == 11:
            res = 0
            ss = 10

            for i in range(9):
                res += cpf_list[i]*ss
                ss -= 1

            if (res * 10) % 11 == cpf_list[9] or (res*10) % 11 == 10:
                # linha de debug print("Primeiro digito OK")
                res = 0
                ss = 11
                for i in range(10):
                    res += cpf_list[i]
                    ss -= 1

                if (res*10) % 11 == cpf_list[10] or (res*10) % 11 == 10:
                    # linha de debug print("segundo digito OK")
                    return True
                else:
                    # linha de debug print("CPF INVALIDO 4")
                    return False
            else:
                # linha de debug print("CPF INVALIDO 3")
                return False

        else:
            # linha de debug print("CPF INVALIDO 2")
            return False
    else:
        # linha de debug print("CPF INVALIDO 1")
        return False
