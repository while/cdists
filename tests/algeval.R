
normrnd <- function() {
  u <- runif(1)
  v <- 1.7156*(runif(1) - 0.5)
  x <- u - 0.449871
  y <- abs(v) + 0.386595
  q <- x*x + y*(0.19600*y - 0.25472*x)

  while (q>0.27597 && (q>0.27846 || v*v>-4*log(u)*u*u)) {
    u <- runif(1)
    v <- 1.7156*(runif(1) - 0.5)
    x <- u - 0.449871
    y <- abs(v) + 0.386595
    q <- x*x + y*(0.19600*y - 0.25472*x)

  }
  return(v/u)
}

nbrs <- sapply(1:100000, function(x) normrnd())
qplot(nbrs, geom="histogram", binwidth=0.1)
