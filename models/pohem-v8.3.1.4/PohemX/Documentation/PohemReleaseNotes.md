# POHEM 8.3.1.4 (Developed with VS2019, openM 1.17.1)

* Created August 20, 2024.
* Added new HUI table tHUI_age_5year which tabulates average HUI by sex and 5-year age groups for McConnell-Nzunga from the Health Statistics Branch.

---

# POHEM 8.3.1.3 (Developed with VS2019, MODGEN 12.1.3.0, openM 1.17.3)

* Created June 24, 2024.
* Added new (as of OpenM++ 1.17.3) index_errors option to ompp_options.ompp. 
* Per Steve Gribble's comment ([https://gitlab.k8s.cloud.statcan.ca/microsim/pohem/-/issues/55](https://gitlab.k8s.cloud.statcan.ca/microsim/pohem/-/issues/55)), "In POHEM, two lines of model code use quoted strings which contain what appear to the new omc markup phase to be valid parameters with indices, and when omc applies the patterns, the C++ code becomes syntactically invalid and the C++ compiler raises an error. This only occurs if index_errors (new feature, not yet released) is turned on." The two lines of relevant model code in Diabetes.mpp were fixed by breaking up "the offending string constants into appended pieces so that they no longer look like true parameter references, so the patterns no longer match inside the string constant."

---

# POHEM 8.3.1.2 (Developed with VS2019, MODGEN 12.1.3.0, openM 1.17.0)

* Created March 19, 2024.
* Bugfix: added a condition to the in_tabulation_scope object in the PersonCore module so that years of data (i.e., 2001-2009) that should not be included in the first year of tabulation (i.e., 2010) in the dementia cost tables are no longer included. 
* Updated dementia cost parameters in Dementia.dat with the latest data from Stacey Fisher's team (DementiaPhysicianCosts, DementiaPrescriptionDrugs, DementiaHospitalAdmissions, DementiaHomeCare, DementiaLongTermCare, DementiaAssistiveDevices).
* Renamed model .ini file so that it matches model name and added example microdata output (commented out by default).
* Added an ompp_options.ompp file and relocated the options that were in ompp_framework.ompp to this location. Also added a call to a header file (omc/optional_IDE_helper.h) that helps the IDE recognize model symbols. Also added options for model documentation (turned off by default because they significantly increase model compilation time). Splitting the framework and options into separate files is recommended by OpenM++ Inc. Microdata output settings were also added to this new file (turned off by default).
* Changed default SimulationCases from 5M to 100k.

---

# POHEM 8.3.1.1 (Developed with VS2019, MODGEN 12.1.3.0, openM 1.15.5)

* Created January 15, 2024.
* Replaced deprecated code in start-ompp-ui.bat with code from props/start-ompp-ui.bat in the OpenM++ 1.15.5 instance.

---

# POHEM 8.3.1.0 (Developed with VS2019, MODGEN 12.1.3.0, openM 1.15.5)

* Created December 21, 2023.
* Renamed the POHEM.h header file (POHEM.h => pohem.h).
* Updated references to the header file accordingly in Smoking_crm.mpp and Smoking_CRM_plus.mpp.

---

# POHEM 8.3.0.9 (Developed with VS2019, openM 1.14.0)

* Created December 13, 2023
* Added some new partitions for ages for tables in the following files: Diabetes.mpp, DiabetesPrevalenceStart.mpp
* Modified the partitions on some tables in files: Tab.CVDPoRT_Stroke_AMI.mpp, Tab.Dementia.mpp, Tab.DiabetesProject.mpp, Tab.RiskFactors.mpp, Tab.Standard.mpp, TableAndParameterGroups

---

# POHEM 8.3.0.8 (Developed with in VS2019, MODGEN 12.1.3.0, openM 1.14.0 rebuilt for VS2019)

* Created May 3, 2023
* Took OncoSim's ompp_framework.ompp. This fixes the Dim1, Dim2 ... issue when exporting tables in csv.
* Took OncoSim's Model.vcxproj.filters.  POHEM's version is polluted with several instances of <None Include="../code/*.mpp"> (to name just one thing repeated endlessly) which appears to do nothing.
* Added RetainSuppress.ompp and put parameters_suppress in it.  This used to be in ompp_framework.ompp, but RetainSuppress.ompp is a better home for it.

---

# POHEM 8.3.0.7 (Developed with in VS2019, MODGEN 12.1.3.0, openM 1.14.0)

* Created March 7, 2023
* Added a Languages module and enabled the French translation capability.
* Renamed the ModgenFR module to the LanguagesFrench module and added preliminary (machined-translated using DeepL API) French translations for all labels in POHEM.
* Some changes to table header names.

---

# POHEM 8.3.0.6 (Developed with in VS2019, MODGEN 12.1.3.0, openM 1.11.0 patched)

* Created January 18, 2023
* Changed the code so that the openM executable and sqllite data base are smaller in size.
* Ensured that POHEM always runs in so-called "stable mode". 
* Ensured that POHEM is run with population scaling by default.  It is possible to change this in the interface.
* Relocated a couple of English labels in the COPD and convert CRM modules. 
* No change in output results.

---

# POHEM 8.3.0.5 (Developed with in VS2019, MODGEN 12.1.3.0, openM 1.12.0)

* Created January 13, 2023
* Enabled new microdata output capability in ompp_framework.ompp (still requires setup of a PohemX.ini file in ompp/bin before microdata will be outputted; see [https://github.com/openmpp/openmpp.github.io/wiki/Microdata-Output#1-build-model-with-microdata-output-capability](https://github.com/openmpp/openmpp.github.io/wiki/Microdata-Output#1-build-model-with-microdata-output-capability))

---

# POHEM 8.3.0.4 (Developed with in VS2019, MODGEN 12.1.3.0, openM 1.11.0 patched)

* Created January 13, 2023
* Replaced all occurences of the function 'abs' with 'std::abs'
* Replaced all occurences of 'sprintf_s' with 'snprintf'
* Fixed a mismatched brace in Smoking.MPP
* Parameters SmTransProb and SmTransProbT in Smoking_crm.mpp are now created on the heap rather than the stack
* Rewrote code so that the size of the openM executable would not be huge.
* Fixed/added some labels in input parameters and output tables

---

# POHEM 8.3.0.3 (Developed with in VS2019, MODGEN 12.1.3.0, openM 1.11.0 patched)

* Created December 16, 2022
* Major fix applied to the alcohol intervention dispatcher.
* Removed a deprecated table and relocated several tables.
* Removed deprecated blood pressure- and cholesterol-related variables and parameters in the interventions module.
* Replaced the blood pressure variable used in HUI model 2.

---

# POHEM 8.3.0.2 (Developed with in VS2019, MODGEN 12.1.3.0)

* Created October 25, 2022
* Updated the way number_drinks_past_week_extra2 is sampled during an alcohol intervention so that the random sampling follows a uniform distribution.
* Removed deprecated MEND variables (i.e. MEND_cutoff and MEND_target).

---

# POHEM 8.3.0.1 (Developed with in VS2019, MODGEN 12.1.3.0, openM 1.11.0 patched)

* Created October 20, 2022
* This is a truly cross-compatible version of POHEM. 
* It does not compile with openM 1.11.0 but will compile if latter is patched.  It should compile with future versions of openM without patches.

---

# POHEM 8.3.0.0 (Developed with in VS2019, MODGEN 12.1.3.0)

* Created October 12, 2022
* This is an attempt of getting a cross-compatible version of POHEM 8.2.4.8.  There are a couple of issues that prevent compilation in openM and will be fixed later.
* With modgen, POHEM 8.3.0.0 does not generate the same results as POHEM 8.2.4.8. Small differences expected and should be explained later (from Steve's explanations or otherwise).

---

# POHEM 8.2.4.8 (Developed with in VS2019, MODGEN 12.1.3.0)

* Created October 10, 2022
* Removed following modules
  * BMI model 1
  * HUI model 1
  * Framingham's coronary artery disease model
  * Mind, Exercise, Nutrition, Do it (MEND) program
* Removed following output tables 
  * tMEND_AverageBMI_BMIcats, tCount_MEND_Target, tCC_for_MEND, tCosts_for_MEND, tBMI_CAT_by_youth_BMI_MEND
  * tDiseaseEvents, tDiseaseEventsAge, tDiseaseEventsProvince
  * tCC, tCC_by_age_start, tCC_count_autoreg 
  * utActuarial_LE_HALE, tActuarial_LE_HALE_components
  * BMI-based costs in tables tCohort_LifeLong, tHealth_Outcomes_CrossSectional, tHealth_Outcomes_Longitudinal were removed, otherwise those tables are the same
* POHEM 8.2.4.8 generates the same results as POHEM 8.2.4.7 for tables still present in former.

---

# POHEM 8.2.4.7 (Developed with in VS2019, MODGEN 12.1.3.0)

* Created October 5, 2022
* Enhancements were done to the so-called Alcohol dispatcher so that interventions formulated in terms of drinking categories will adjust number of drinks in a coherent manner.  So a call to move a man in the moderate drinker category implies that the number of drinks should be between 2 and 14 inclusively.
* Integrated into POHEM the COPD module which led to the paper by Mohsen Sadatsafavi et al. (Medical Decision Making 2019, Vol. 39(2) 152–167, DOI: 10.1177/0272989X18824098).
  * If mortality engine "Demography projection" is selected and COPD model is activated/turned on, people are subject to COPD related deaths during their exacerbation(s).
  * Otherwise, COPD is not yet connected to other modules such as HUI, MPoRT and possibly other PoRT modules. 
  * We may want to "trust but verify" both Sadatsafavi et al.'s model validation and the re-integration of their work in POHEM.  Prevalence and incidence generated by the model may need to be compared to other sources and calibration may be required. Model should be used with caution for now.


