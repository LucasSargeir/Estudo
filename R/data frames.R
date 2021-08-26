intake.pre = c(5260,5470,5640,6180,6390,6575,6805,7515,7515,8230,8770)
intake.post = c(3910,4220,3885,5160,5645,4680,5265,5975,6760,6900,7335)

bool = intake.pre < 7000 & intake.pre > 6000 
intake.pre[bool]

d = data.frame(intake.pre, intake.post)

d[1,1]
d[1]
d$intake.post
d$intake.post[5]

d[d$intake.pre > 7000 | d$intake.pre < 6000, c(1, 2)]
d[d$intake.pre > 7000 | d$intake.pre < 6000, c("intake.pre", "intake.post")]

# Exercicio

weight = c(60, 72, 57, 90, 95, 72)
height = c(1.75, 1.80, 1.65, 1.90, 1.74, 1.91)

d = data.frame(weight, height)

d[d$height > 1.70 & d$height < 1.90,]

d$bmi <- weight/height^2
