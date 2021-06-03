# IMPORTANTE
#   - Elixir sempre retorna as ultimas linhas de uma função.

defmodule Calculo do

    #Função criada para definir condição de parada da recursão.
    def cria_mapa([], []) do
        %{}
    end

    #Função recursiva principal
    #   - Parametros (lista, lista): ambos desestruturados em cabeça e calda.
    def cria_mapa([items_head | items_tail], [emails_head | emails_tail]) do

        #Percorrer todos os items da lista de compras somando tudo no acumulador
        #   - Função Reduce (lista, valor_inicial_acumulador_ função): retorna o acumulador
        #     ao final das iterações.

        total_pagar = Enum.reduce(items_head, 0, fn(i, acc)-> 
            acc + (i[:quantidade] * i[:preco])
        end)

        #Concatenar os valores encontrados na calda com o valor encontrado agora (recursão).
        #   - Função Put (mapa_atual, chave_para_inserir, valor_para_inserir)
        Map.put(cria_mapa(items_tail, emails_tail), emails_head, total_pagar)

    end
end


items = [[[item: "maça", quantidade: 2, preco: 2000],[item: "pera", quantidade: 1, preco: 3000]],
         [[item: "noz", quantidade: 4, preco: 1000]]]

emails = ["sargeirolucas@gmail.com",
          "lucassargeiro@hotmail.com"]

mapa = Calculo.cria_mapa(items, emails)

#Percorrer mapa para printar valores
Enum.map(emails, fn(m)->
    IO.puts("Chave #{m}")
    IO.puts("Total #{mapa[m]}\n")
end)