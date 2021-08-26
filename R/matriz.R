x <- 1:12 # Cria um vetor
dim(x) <- c(3,4) # Transforma em matriz de dimensões 3x4

x <- matrix(1:12, nrow=3, byrow=TRUE) # Cira a matriz distribuindo a sequencia por linha

rownames(x) <- LETTERS[1:3] # Define nomes as linhas, usa sequencia de letras
colnames(x) <- c(1:4) # Define nome das colunas, usa sequencia de numeros

t(x) # Transpoe a matriz

y <- matrix(c(1,9,5,3,7,8,10,4,2), nrow = 3, byrow=TRUE)
det(y) # Encontra a determinante de uma matriz

z1 <- matrix(1:9, nrow = 3, byrow=TRUE)
z2 <- matrix(c(2, 1, 3), nrow = 3, byrow=TRUE)

z3 = z1 %*% z2 #multiplica matrizes
