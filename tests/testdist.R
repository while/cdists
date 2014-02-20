library(ggplot2)


unif <- data.frame(V1=as.numeric(system('../bin/uniform 100000', intern=T)) )
ggplot(unif, aes(x=V1)) + geom_histogram(binwidth=0.05)

## Exponential distribution
exnbrs <- data.frame(V1=as.numeric(system('../bin/exponential', intern=T)) )
ggplot(exnbrs, aes(x=V1)) + geom_histogram(binwidth=0.5)

exp.qqdat <- data.frame(x=qexp(ppoints(exnbrs$V1), 0.5), y=sort(exnbrs$V1))

ggplot(exp.qqdat, aes(x,y)) + geom_point(pch=21, fill='white') +
  geom_abline(intercept=0, slope=1, lty=2, color='red') + 
  ggtitle('Q-Q plot for Exponential distribution')

## Normal distribution
normnbrs <- data.frame(V1=as.numeric(system('../bin/normal 100000 0 1', intern=T)) )
ggplot(normnbrs, aes(x=V1)) + geom_histogram(binwidth=0.1)

norm.qqdat <- data.frame(x=qnorm(ppoints(normnbrs$V1)), 
                         y=sort(normnbrs$V1))

ggplot(norm.qqdat, aes(x,y)) + geom_point(pch=21, fill='white') +
  geom_abline(intercept=0, slope=1, lty=2, color='red') + 
  ggtitle('Q-Q plot for Normal distribution')

## Geometric distribution
## DOESN'T START AT 0!!! Possible bug!
geom.nbrs <- data.frame(x=as.numeric(system('../bin/geometric 100000 0.5', intern=T)) )
ggplot(geom.nbrs, aes(x)) + geom_histogram(binwidth=0.5)

geom.qqdat <- data.frame(x=qgeom(ppoints(geom.nbrs$x), 0.5), y=sort(geom.nbrs$x))

ggplot(geom.qqdat, aes(x,y)) + geom_point(pch=21, fill='white') +
  geom_abline(intercept=0, slope=1, lty=2, color='red') + 
  ggtitle('Q-Q plot for Geometric distribution')
