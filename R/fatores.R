#pain = c(0, 3, 2, 2, 1)
#fpain = factor(pain, levels=0:3)
#levels(fpain) = c("none", "mild", "medium", "severe")
#as.numeric(fpain)

weight <- c(60, 72, 57, 90, 95, 72)
height <- c(1.75, 1.80, 1.65, 1.90, 1.74, 1.91)

lev <- rep("", length(height))

'''for (i in 1:length(lev)){
  if(height[i] < 1.7)
    lev[i] <- "short"
  else if(height[i] < 1.9)
    lev[i] <- "medium"
  else
    lev[i] <- "tall"
}'''

lev = cut(height, breaks=c(0,1.7,1.9, .Machine$double.xmax), ordered = TRUE) # The same of foor loop
levels(lev) = c("short", "medium", "tall") # Define as categorias do fator
