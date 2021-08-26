weight = c(60, 72, 57, 90, 95, 72)
height = c(1.75, 1.80, 1.65, 1.90, 1.74, 1.91)
bmi <- weight/height^2

myexp <- list(height, weight, bmi)

slice <- myexp[1]
slice <- myexp[c(1,3)]

h <- myexp[[1]]

intake.pre = c(5260,5470,5640,6180,6390,6575,6805,7515,7515,8230,8770)
intake.post = c(3910,4220,3885,5160,5645,4680,5265,5975,6760,6900,7335)

mylist <- list()
mylist[[1]] <- intake.pre
mylist[[2]] <- intake.post

mylist = list(before=intake.pre, after=intake.post)

mylist$before

# Exercicio

intake.pre = list(c(5260,5470,5640,6180,6390,6575,6805,7515,7515,8230,8770))
intake.post = list(c(3910,4220,3885,5160,5645,4680,5265,5975,6760,6900,7335))

main.list = list(before=intake.pre, after=intake.post)

filtered = list(main.list$before[[1]][4:11])
