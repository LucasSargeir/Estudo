import pandas as pd

taxa = 5.60

automovel = pd.read_csv('automovel.csv', sep=';')#
print('\n',automovel.tail(8)) 

convertido = list(automovel['preco'])
preco_r = []
for i in range(len(convertido)):
    preco_r.append(convertido[i] * taxa)

print("Preços convertidos"+str(preco_r))

automovel['preco real'] = pd.Series(preco_r)
print (automovel)


kpl = []
mpl = list(automovel['consumo'])
for j in range(len(mpl)):
    kpl.append(mpl[j] / 0.425143707)

automovel['consumo'] = pd.Series(kpl)
print (automovel)