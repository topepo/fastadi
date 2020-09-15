#include <RcppArmadillo.h>

using namespace arma;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]
double p_omega_f_norm_ut_stable_impl(
    const arma::mat& U,
    const arma::rowvec& d,
    const arma::mat& V,
    const arma::vec& row,
    const arma::vec& col) {

  // numerical stability issues come from squaring elements. see:
  //
  // https://timvieira.github.io/blog/post/2014/11/10/numerically-stable-p-norms/

  // TODO: actually make these changes ooof


  // first add the observed elements on the lower triangle and diagonal

  int i, j;
  double z_ij, f_norm_sq = 0;

  arma::mat DVt = diagmat(d) * V.t();

  for (int idx = 0; idx < row.n_elem; idx++) {

    i = row(idx);
    j = col(idx);

    // only elements of the lower triangle
    // KEY: include the diagonal, but only *explicitly* observed elements
    if (i >= j) {
      z_ij = dot(U.row(i), DVt.col(j));
      f_norm_sq += pow(z_ij, 2);
    }
  }

  // second add all the elements of the upper triangle

  int r = U.n_cols;

  arma::vec U_lq;
  arma::rowvec V_lq, V_lq_tri;

  for (int l = 0; l < r; l++) {
    for (int q = 0; q < r; q++) {

      U_lq = U.col(l) % U.col(q);
      V_lq = DVt.row(l) % DVt.row(q);
      V_lq_tri = sum(V_lq) - cumsum(V_lq);

      f_norm_sq += dot(U_lq, V_lq_tri);
    }
  }

  return f_norm_sq;
}
