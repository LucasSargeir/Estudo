# Pokemon Sprite Scrapping

Programa criado com objetivo de aprender scrapping em python. O programa baixa todos os sprites de todas as gerações de pokemon do [Serebii.net](https://www.serebii.net). Por conta de algumas inconsistencias nos padrões de nomes dos sprites algumas tratativas tiveram quer ser feitas com o objetivo de unificar o formato dos sprites e agrupá-los por geração e tipo (normal/shiny).



### Dependências

- BeautifulSoup (BS4);
- Pillow (PIL);
- Requests;
- Shutil;
- Numpy;



## Utilização

A utilização do programa foi resumida ao script `full_scraping.py` que baixa todas as gerações. Mas se isso nao for desejado pode se usado na forma interativa pelo script `image_scrapping.py`. Caso você utilize de forma iterativa, fique atento as seguintes inconsistências:

- Alguns sprites de RB foram reutilizados em EM e FRLG. Utilize a opção 3 para copiar esses sprites de RB para as pastas de EM e FRLG (os sprites faltantes podem ser verificados pela opção 2).
- Alguns sprites de DP foram reutilizados em HGSS. Utilize a opção 3 para copiar esses sprites de DP para a pasta de HGSS (os sprites faltantes podem ser verificados pela opção 2).
- Os sprites da Gen 3 vem como gifs, sem transparencia. Caso queira tranformá-los em PNG utilize a opção 4.
- Após convertidos, os PNGs continuam sem transparencia. Para aplicar a transparência, utilize a opção 5 (não utilize a opção 5 sem utilizar a 4 antes).

  

## Execução

A execução do programa pode ser feita de duas maneiras, automática, que baixará todos os sprites de todas as versões, e manual, que o usuário pode escolher quais versoes deseja baixar. Veja os exemplos:

- Automática

```bash
python full_scrapping.py
```

- Manual

```bash
python image_scrapping.py
```

  