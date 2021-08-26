weight = c(60, 72, 57, 90, 95, 72)
height = c(1.75, 1.80, 1.65, 1.90, 1.74, 1.91)
subject = c("A","B","C","D","E","F")

message <- rep("", length(subject))

for (i in 1:length(message)){
  message[i] <- sprintf("The height of %s is %.2f. The weight of %s is %d.", subject[i], height[i], subject[i], weight[i])
}

rm(message) # delete the variable

message <- sprintf("The height of %s is %.2f. The weight of %s is %d.", subject, height, subject, weight)

print(message)
