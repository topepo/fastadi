
<!-- README.md is generated from README.Rmd. Please edit that file -->

# fastadi

<!-- badges: start -->

<!-- badges: end -->

`fastadi` implements the `AdaptiveImpute` matrix completion algorithm of
\[2, 1\]. `fastadi` is a self-tuning alternative to algorithms such as
`SoftImpute` (implemented in the
[`softImpute`](https://cran.r-project.org/package=softImpute) package),
truncated SVD, maximum margin matrix factorization, and weighted
regularized matrix factorization (implemented in the
[`rsparse`](https://github.com/rexyai/rsparse) package). In simulations
`fastadi` often outperforms `softImpute` by a small margin.

You may find `fastadi` useful if you are developing embeddings for
sparsely observed data, if you are working in natural language
processing, or building a recommendation system.

At the moment `fastadi` is a relatively low-level package, performing
matrix factorization and returning a low rank approximation `U D V'` of
an original data matrix. It is up to you to manipulate the matrices `U`,
`D` and `V` appropriately for your application; if you are interested in
a higher level interface for a task you are working on, please file an
issue\!

## Installation

You can install the development version from
[GitHub](https://github.com/) with:

``` r
# install.packages("devtools")
devtools::install_github("RoheLab/fastadi")
```

## Example usage

TODO

## Related work

  - vsp
  - <https://dataslingers.github.io/MoMA/>
  - sparse PCA

## References

1.  Cho, J., Kim, D. & Rohe, K. Asymptotic Theory for Estimating the
    Singular Vectors and Values of a Partially-observed Low Rank Matrix
    with Noise. arXiv:1508.05431 \[stat\] (2015).
    <http://arxiv.org/abs/1508.05431>

2.  Cho, J., Kim, D. & Rohe, K. Intelligent Initialization and Adaptive
    Thresholding for Iterative Matrix Completion; Some Statistical and
    Algorithmic Theory for Adaptive-Impute. Journal of Computational and
    Graphical Statistics 1–26 (2018)
    <doi:10.1080/10618600.2018.1518238>.
    <https://amstat.tandfonline.com/doi/abs/10.1080/10618600.2018.1518238>
