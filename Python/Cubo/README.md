# Cube Scrambles

Programa criado com o objetivo de gerar todos os embaralhamentos possíveis de um cubo mágico até **x** movimentos. O programa gera um arquivo texto contendo todos os embaralhamentos.

> <u>**ATENÇÃO!**</u>
>
> O número de embaralhamentos possíveis é exponencial a medida o número de movimentos cresce. Não teste o programa com números muito altos ou você pode ficar sem HD disponível.



## Regras

Os embaralhamentos são gerados ignorando movimentos que se anulas, por exemplo, as sequencias de movimentos abaixo nunca serão vistas:

- R R R
- R R'
- R' R
- R R
- R' R'
- R2 R2



## Execução

Para executar o programa utilize o comando:

```bash
python scrambles.py
```

Note que o arquivo `scrambles.txt` foi gerado.
