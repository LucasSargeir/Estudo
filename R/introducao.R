require(ggplot2) # Equals to library(ggplot2), import a package

#install.packages('package_name')


x <- 2 # variable assignment

x # variable evaluation

y <- 1
x + y
z <- x + y

is.numeric(x) # variable

weight = c(60, 72, 57, 90, 95, 72) # vector with six observations

weight[1]
weight[6]
length(weight) # size of vector

height = c(1.75, 1.80, 1.65, 1.90, 1.74, 1.91)

# Calcular índice de massa corporal (peso/altura²)

weight[1]/height[1]^2

bmi <- rep(0, length(weight)) # create a vector with a default value

#for (i in 1:length(weight)){
#  bmi[i] <- weight[i]/height[i]^2
#}

bmi <- weight/(height^2) # the same code of the for loop, but more efficient

soma <- 0
for (i in 1:length(bmi)){
  soma <- soma + bmi[i]
}
media <- soma/length(bmi)

media = mean(bmi)
desvio_padrao = sd(bmi)

#-?mean # Help to mean function

plot(height, weight)

hh = c(1.65, 1.70, 1.75, 1.80, 1.85, 1.90)
lines(hh, 22.5 * hh^2)

t.test(bmi, mu=22.5) # Parametric test

t.test(bmi, mu=15) # Parametric test

