/**
 * @file   custom.h
 * Model-specific declarations and includes (late)
 *  
 * This file is included in all compiler-generated files for the model.
 * This file comes late in the include order, after entity declarations.
 */

#pragma once
#include "case_based.h"
#include "omc/fixed_modgen_api.h"


#if defined(MODGEN)
namespace mm {
#endif

	extern double UpdateCvdportAmiSplineAge(int    x, SEX sexe, CVDPORT_AMI_STATE ami);
	extern double UpdateCvdportAmiSplineBmi(double x, SEX sexe, CVDPORT_AMI_STATE ami);
	extern double UpdateCvdportAmiSplinePackYears(double x, SEX sexe, CVDPORT_AMI_STATE ami);
	extern double UpdateCvdportAmiSplineAlcohol(int    x, SEX sexe, CVDPORT_AMI_STATE ami);
	extern double UpdateCvdportAmiSplineMet(double x, SEX sexe, CVDPORT_AMI_STATE ami);

	extern double UpdateCvdportStrokeSplineAge(int    x, SEX sexe, CVDPORT_STROKE_STATE stroke);
	extern double UpdateCvdportStrokeSplineBmi(double x, SEX sexe, CVDPORT_STROKE_STATE stroke);
	extern double UpdateCvdportStrokeSplinePackYears(double x, SEX sexe, CVDPORT_STROKE_STATE stroke);
	extern double UpdateCvdportStrokeSplineAlcohol(int    x, SEX sexe, CVDPORT_STROKE_STATE stroke);
	extern double UpdateCvdportStrokeSplineMet(double x, SEX sexe, CVDPORT_STROKE_STATE stroke);

	extern double UpdateDementiaSplineAge(int    x, SEX sexe, DEMPORT_STATE dementia);
	extern double UpdateDementiaSplineBmi(double x, SEX sexe, DEMPORT_STATE dementia);
	extern double UpdateDementiaSplinePackYears(double x, SEX sexe, DEMPORT_STATE dementia);
	extern double UpdateDementiaSplineAlcohol(int    x, SEX sexe, DEMPORT_STATE dementia);
	extern double UpdateDementiaSplineMet(double x, SEX sexe, DEMPORT_STATE dementia);

	extern double UpdateMportV2SplineAge(int    x, SEX sexe);
	extern double UpdateMportV2SplineBmi(double x, SEX sexe);
	extern double UpdateMportV2SplinePackYears(double x, SEX sexe);
	extern double UpdateMportV2SplineAlcohol(int    x, SEX sexe);
	extern double UpdateMportV2SplineMet(double x, SEX sexe);
	extern double UpdateMportV2SplineResidency(double x, SEX sexe);

	extern ALCOHOL5 GetAlcohol5(int drinks_past_week_extra2, SEX sexe);

	extern double CoerceHUI(double dHUI); // Function to coerce HUI

	extern double UpdateUniformForMet(double cauchy_static, double cauchy_iid);

	extern double MeasuredToSelfReportedBmi(double measured_bmi, LIFE_SPAN age_of_person, SEX sexe, double measured_reported_bmi_pivot);
	extern double SelfReportedToMeasuredBmi(double sr_bmi, LIFE_SPAN age_of_person, EDUCATION_NA educ_of_person, SEX sexe, double measured_reported_bmi_pivot);

#if defined(MODGEN)
}
#endif
