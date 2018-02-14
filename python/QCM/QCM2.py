import numpy as np
import statsmodels.api as sm
from typing import Tuple, Union


def wlinear_fit(
	x: Tuple[Union[int, float], ...],
	y: Tuple[Union[int, float], ...],
	w: Tuple[float, ...]) -> Tuple[float, ...]:
	"""
	Fit (x,y,w) to a linear function, using exact formulae for weighted linear
	regression. This code was translated from the GNU Scientific Library (GSL),
	it is an exact copy of the function gsl_fit_wlinear.
	"""
	# compute the weighted means and weighted deviations from the means
	# wm denotes a "weighted mean", wm(f) = (sum_i w_i f_i) / (sum_i w_i)
	W = np.sum(w)
	wm_x = np.average(x, weights=w)
	wm_y = np.average(y, weights=w)
	dx = x - wm_x
	dy = y - wm_y
	wm_dx2 = np.average(dx ** 2, weights=w)
	wm_dxdy = np.average(dx * dy, weights=w)
	# In terms of y = a + b x
	b = wm_dxdy / wm_dx2
	a = wm_y - wm_x * b
	cov_00 = (1.0 / W) * (1.0 + wm_x ** 2 / wm_dx2)
	cov_11 = 1.0 / (W * wm_dx2)
	cov_01 = -wm_x / (W * wm_dx2)
	# Compute chi^2 = \sum w_i (y_i - (a + b * x_i))^2
	term = np.multiply((a + b), x)
	chi2 = np.sum(w * (y - (term)) ** 2)
	return a, b, cov_00, cov_11, cov_01, chi2


BET_y = (-4.20, -4.10, -3.80, -3.62, -3.60, -3.60)        # P/V(P0-P)
BET_x = (-2.70, -2.52, -2.40, -2.30, -2.22, -2.15)        # P/P0 (water)
err_y = (+0.21, +0.18, +0.17, +0.05, +0.05, +0.04)
# err_x = (2.0, 2.0, 2.0, 2.0)
# total_error = np.multiply(err_x, err_y)


error_weights = tuple(1.0 / (np.array(err_y) ** 2.0))
intercept, slope, cov_00, cov_11, cov_01, chi2 = wlinear_fit(BET_x, BET_y, error_weights)
interc_err = cov_00 ** 0.5
slope_err = (cov_11 ** 0.5)
print(slope, intercept, slope_err, interc_err)


BET_x = sm.add_constant(BET_x)
mod_wls = sm.WLS(BET_y, BET_x, weights=(1.0 / np.array(err_y)), has_constant='intercept')
res_wls = mod_wls.fit()
print(res_wls.summary2())
# print(dir(res_wls))
print('Parameters (m, m_err, c, c_err, R2): ',
						res_wls.params[1],
						res_wls.bse[1],
						res_wls.params[0],
						res_wls.bse[0],
						res_wls.rsquared)


mod_ols = sm.OLS(BET_y, BET_x, weights=1.0 / np.array(err_y))
res_ols = mod_ols.fit()
print(res_ols.summary2())
print('Parameters: ', res_ols.params)
print('R2: ', res_ols.rsquared)
# print('Predicted values: ', res_ols.predict())  #predicted values to plot trendline manually
