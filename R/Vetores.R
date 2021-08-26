x  = c(A=10, B=NA, C=13)

mean(x, na.rm=TRUE) # mean without NA values

names(x) # names of values

x[2] <- 3
x['B']  # equals to x[2]

x['B']*x # multiply all observations to x['B']

names(x) = c('red', 'blue', 'green')

x['green']

