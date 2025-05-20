double DPoRTish10YearProb(const double *person_characteristics);
double AmiCvdportishRisk (const double *person_characteristics);
double StrokeCvdportishRisk(const double *person_characteristics);
double DemportishRisk(const double *person_characteristics);

int compare_two_RXYCC_vectors(const void *p, const void *q);
int StoreData( double pool[SIZE( DB_RECORDS_CDF )][SIZE(RECORD_X_Y_CDFINF_CDFSUP)], int *X,int Y, double *X_alternative_vec, double *Y_alternative_vec, double in_scope_bounds  [SIZE(COVARIATE_X)][SIZE(cLOWER_UPPER_BOUNDS)] );
void GetUnderlyingUniformWhereabouts(double pool              [SIZE( DB_RECORDS_CDF )][SIZE(RECORD_X_Y_CDFINF_CDFSUP)],
	                                 double underlying_uniform[SIZE( DB_RECORDS )][SIZE(cLOWER_UPPER_BOUNDS)],int nrow_used_pool);

ALCOHOL5 GetAlcohol5FromStartPop(int alcohol_on_start_pop, SEX sexe);


TIME timeOA (double lambda, double sigma, double mu, double sex, double age);
static int compare(int *e1, int *e2);
void RandomShuffle(int N, int mRandArray[][2]);
double Calculate_Sigma( double dUpper, double dLower, double dConfidenceInterval );
double Lognormal_RR( double dMean, double dStdDev, double dDeviate );
double Gauss(double dRandUniform, double low, double high);


double qcauchy(double p, double mu, double sigma);
double pcauchy(double x, double mu, double sigma);
double qlogis(double p, double mu, double sigma);
double plogis(double x, double mu, double sigma);
double dlogis(double x, double mu, double sigma);
double dloglogis(double x, double mu, double sigma);
double pnorm(double x, double mu, double sigma);
double qnorm(double p, double mu, double sigma);
double qbeta(double quantile, double a, double b);
double pbeta(double x, double a, double b);
double qbeta_a_mu(double quantile, double a, double mu);
double pbeta_a_mu(double x, double a, double mu);
double pgamma(double x, double alpha, double scale);                           
double qgamma(double p, double alpha, double scale);    
double pF(double x, double df1, double df2);
double qF(double quantile, double df1, double df2);
double pt(double x, double df);
double qt(double quantile, double df);
double pBCT(double x       , double mu, double sigma, double nu, double tau, double prange);
double qBCT(double quantile, double mu, double sigma, double nu, double tau, double prange);
double rpois(double mu);

double pt_from_F(double x, double df);
double pt_from_dcdflib(double x, double df);

void ARMAPLUS_11_initialize(double arma_11[], const double armaplus_11_parameters[], const double sum, const double std_norm_for_arma11, const double std_norm_for_plus);
void ARMAPLUS_11_move_forward (double  arma_11[], double std_norm_for_arma11, double std_norm_for_plus);
void ARMAPLUS_11_move_backward(double  arma_11[],double std_norm);
double UpdateSiloedUniform(double siloed_uniform[], double std_norm);
int InitializeSiloedUniform(double siloed_uniform[], const double silo_probs[], const double initial_unif);


double runif(double u,double a,double b);
int pps_sampling(double u, double p[], int number_of_categories);
void my_lookup(double u, double p[], int number_of_dimensions, int number_of_categories[]);
bool Inv_parameterized_power_transform(double z,double mu, double sigma, double lambda, double *inverse);

double Framingham1998(	double dBetaChol, double dBetaHDL, double dBetaBp, 
						double dBetaDiab, double dBetaCig, 
						double dAlpha );
TIME PiecewiseInverseWeibull(double dRandUniform, double uCut,	double tCut,
							double lambda1, double beta1,
							double lambda2, double beta2, 
							double R);
TIME PiecewiseInverseWeibullPrevalence(double uPast, double uFuture, 
							double uCut,	double tCut,
							double lambda1, double beta1,
							double lambda2, double beta2, 
							double R);
double CoerceHUI( double dHUI );
//void CubicSpline(                    double *knots_location, double *cubic_spline_coef, double *cubic_spline_companion, int modgen_min, int modgen_max, double *computed_spline);
double CubicSpline(double    age_or_time, double *knots_location, double *cubic_spline_coef, double *cubic_spline_companion, int number_of_splines);
double CubicSpline(double    age_or_time, double *knots_location, double *cubic_spline_coef, double *cubic_spline_companion);
