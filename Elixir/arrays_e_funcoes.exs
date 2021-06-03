defmodule Calcula_total do
    def print(items, emails) do
        IO.puts(Enum.at(Enum.at(items,0),0)[:item])
        IO.puts(Enum.at(emails, 0))
    end
end


items = [[[item: "maça", quantidade: 2, preco: 2000],[item: "pera", quantidade: 1, preco: 3000]], [[item: "noz", quantidade: 4, preco: 1000]]]
emails = ["sargeirolucas@gmail.com"]
Calcula_total.print(items, emails)