# HUI-table (developed/compiled with VS2019, openM 1.17.1)

* Added new HUI table tHUI_age_5year which tabulates average HUI by sex and 5-year age groups for McConnell-Nzunga from the Health Statistics Branch.

**Dates**
* Branch created August 20, 2024
* Branch deemed complete on August 20, 2024  (i.e. ready to merge)
* Branch merged to master/main branch on August 20, 2024 --> POHEM version 8.3.1.4

---

# JB-index-errors-option (developed/compiled with VS2019, modgen 12.1.3, openM 1.17.3)

* Added new (as of OpenM++ 1.17.3) index_errors option to ompp_options.ompp. 
* Per Steve Gribble's comment ([https://gitlab.k8s.cloud.statcan.ca/microsim/pohem/-/issues/55](https://gitlab.k8s.cloud.statcan.ca/microsim/pohem/-/issues/55)), "In POHEM, two lines of model code use quoted strings which contain what appear to the new omc markup phase to be valid parameters with indices, and when omc applies the patterns, the C++ code becomes syntactically invalid and the C++ compiler raises an error. This only occurs if index_errors (new feature, not yet released) is turned on." The two lines of relevant model code in Diabetes.mpp were fixed by breaking up "the offending string constants into appended pieces so that they no longer look like true parameter references, so the patterns no longer match inside the string constant."

**Dates**
* Branch created June 24, 2024
* Branch deemed complete on June 24, 2024  (i.e. ready to merge)
* Branch merged to master/main branch on June 24, 2024 --> POHEM version 8.3.1.3

---

# JB-investigate-bug-re-first-year-of-dementia-costs (developed/compiled with VS2019, modgen 12.1.3, openM 1.17.0)

* Bugfix: added a condition to the in_tabulation_scope object in the PersonCore module so that years of data (i.e., 2001-2009) that should not be included in the first year of tabulation (i.e., 2010) in the dementia cost tables are no longer included. 
* Updated dementia cost parameters in Dementia.dat with the latest data from Stacey Fisher's team (DementiaPhysicianCosts, DementiaPrescriptionDrugs, DementiaHospitalAdmissions, DementiaHomeCare, DementiaLongTermCare, DementiaAssistiveDevices).
* Renamed model .ini file so that it matches model name and added example microdata output (commented out by default).
* Added an ompp_options.ompp file and relocated the options that were in ompp_framework.ompp to this location. Also added a call to a header file (omc/optional_IDE_helper.h) that helps the IDE recognize model symbols. Also added options for model documentation (turned off by default because they significantly increase model compilation time). Splitting the framework and options into separate files is recommended by OpenM++ Inc. Microdata output settings were also added to this new file (turned off by default).
* Changed default SimulationCases from 5M to 100k.

**Dates**
* Branch created March 11, 2024
* Branch deemed complete on March 19, 2024  (i.e. ready to merge)
* Branch merged to master/main branch on March 19, 2024 --> POHEM version 8.3.1.2

---

# JB-update-ompp-ui-bat-file (developed/compiled with VS2019, modgen 12.1.3, openM 1.15.5)

* Replaced deprecated code in start-ompp-ui.bat with code from props/start-ompp-ui.bat in the OpenM++ 1.15.5 instance.

**Dates**
* Branch created January 15, 2024
* Branch deemed complete on January 15, 2024  (i.e. ready to merge)
* Branch merged to master/main branch on January 15, 2024 --> POHEM version 8.3.1.1

---

# JB-make-pohem-header-file-lower-case (developed/compiled with VS2019, modgen 12.1.3, openM 1.15.5)

* Renamed the POHEM.h header file (POHEM.h => pohem.h).
* Updated references to the header file accordingly in Smoking_crm.mpp and Smoking_CRM_plus.mpp.

**Dates**
* Branch created December 21, 2023
* Branch deemed complete on December 21, 2023  (i.e. ready to merge)
* Branch merged to master/main branch on December 21, 2023 --> POHEM version 8.3.1.0

---

# VS_pohemtesting (developed/compiled with VS2019, openM 1.14.0)

* Added some new partitions for ages for tables in the following files: Diabetes.mpp, DiabetesPrevalenceStart.mpp
* Modified the partitions on some tables in files: Tab.CVDPoRT_Stroke_AMI.mpp, Tab.Dementia.mpp, Tab.DiabetesProject.mpp, Tab.RiskFactors.mpp, Tab.Standard.mpp, TableAndParameterGroups

**Dates**
* Branch created April 24, 2023
* Branch deemed complete on December 12, 2023  (i.e. ready to merge)
* Branch merged to master/main branch on December 13, 2023 --> POHEM version 8.3.0.9

---

# CN_FixDim1Dim2 (developed/compiled with VS 2019, modgen 12.1.3, openM 1.14.0 rebuilt for VS2019)

* Took OncoSim's ompp_framework.ompp. This fixes the Dim1, Dim2 ... issue when exporting tables in csv.
* Took OncoSim's Model.vcxproj.filters.  POHEM's version is polluted with several instances of <None Include="../code/*.mpp"> (to name just one thing repeated endlessly) which appears to do nothing.
* Added RetainSuppress.ompp and put parameters_suppress in it.  This used to be in ompp_framework.ompp, but RetainSuppress.ompp is a better home for it.

**Dates**
* Branch created May 3, 2023
* Branch deemed complete on May 3, 2023  (i.e. ready to merge)
* Branch merged to master/main branch on May 3, 2023 --> POHEM version 8.3.0.8

---

# JB-add-french-translations (developed/compiled with VS 2019, modgen 12.1.3, openM 1.14.0)

* Created a new Languages module.
* Moved the languages object from the StartPop module to the Languages modules and enabled the FR option.
* Renamed the ModgenFR module as LanguagesFrench and removed all the string translations (which, as I understand, are redundant).
  * Used R to scrape all module files for English labels and performed a preliminary translation of all labels into French using DeepL API (https://www.deepl.com/docs-api).
  * For various modules, code and labels were tidied up along the way.
  * All French translations were wrapped in the LABEL function and dumped into the LanguagesFrench module.
* Removed zBMI, which is no longer used in POHEM, to eliminate a warning message that was being generated when compiling.
* Removed several calls to the floor() function in the Alcohol module and casted the objects as integers to eliminate "possible loss of data" warnings that were being generated when compiling.

**Dates**
* Branch created March 7, 2023
* Branch deemed complete on March 14, 2023  (i.e. ready to merge)
* Branch merged to master/main branch on March 14, 2023 --> POHEM version 8.3.0.7

---

# CN_StableModeOnly (developed/compiled with VS 2019, modgen 12.1.3, openM 1.11.0 patched)

* Removed parameters ForcePopulationSource and UseUnstableRunningMode. Hardcoded the logic of UseUnstableRunningMode = FALSE.
* Burned in pStartPop in executable by using parameters_suppress.
* Use range DB_RECORDS {0 , 99999}.  It was {0 , 149999}.
* Altered Framework.odat. In particular, added this line: bool DisablePopulationScaling = false; 
* Altered ompp_framework.ompp to make it look at bit more like OncoSim's.  In particular
  * Dropped this line: use "case_based/case_based_scaling_none.ompp";  // No population scaling
  * Added  this line: use "case_based/case_based_scaling_endogenous_or_none.ompp";

**Dates**
* Branch created January 13, 2023
* Branch deemed complete on January 18, 2023  (i.e. ready to merge)
* Branch merged to master/main branch on January 18, 2023 --> POHEM version 8.3.0.6

---

# JB-relocate-some-english-labels (developed/compiled with VS 2019, modgen 12.1.3, openM 1.12.0)

* Relocated a couple of English labels in the COPD and convert CRM modules so that they can be isolated/processed more easily when scraping the labels in R for downstream purposes (e.g., translation of labels).

**Dates**
* Branch created January 17, 2023
* Branch deemed complete on January 18, 2023  (i.e. ready to merge)
* Branch merged to master/main branch on January 18, 2023 --> POHEM version 8.3.0.6

---

# JB-enable-microdata-output-feature (developed/compiled with VS 2019, modgen 12.1.3, openM 1.12.0)

* Enabled new microdata output capability in ompp_framework.ompp (still requires setup of a PohemX.ini file in ompp/bin before microdata will be outputted; see [https://github.com/openmpp/openmpp.github.io/wiki/Microdata-Output#1-build-model-with-microdata-output-capability](https://github.com/openmpp/openmpp.github.io/wiki/Microdata-Output#1-build-model-with-microdata-output-capability))

**Dates**
* Branch created December 22, 2022
* Branch deemed complete on December 22, 2022  (i.e. ready to merge)
* Branch merged to master/main branch on January 13, 2023 --> POHEM version 8.3.0.5

---

# NB_PohemX_Linux (developed/compiled with VS 2019, modgen 12.1.3, openM 1.11.0 patched)

**Linux compatibility for PohemX**
* Replaced all occurences of the function 'abs' with 'std::abs'
* Replaced all occurences of 'sprintf_s' with 'snprintf'
* Fixed a mismatched brace in Smoking.MPP
* Parameters SmTransProb and SmTransProbT in Smoking_crm.mpp are now created on the heap rather than the stack

**Dates**
* Branch created January 5, 2023 
* Branch deemed complete on January 5, 2023  (i.e. ready to merge)
* Branch merged to master/main branch on January 13, 2023 --> POHEM version 8.3.0.4

---

# CN_LeanOpenmExe (developed/compiled with VS 2019, modgen 12.1.3, openM 1.11.0 patched)

**Immigrant numbering system**
* Used a different numbering system for immigrants.  Used to be immigrant #0, #1, ..., #2407. Now they are numbered within sex, age group.
  * within sex, age group = (0,3) : immigrant #0, #1, ... , #135
  * within sex, age group = (0,4) : immigrant #0, #1, ... , #224
  * Et cetera ...
  * This is implemented by adding sex and age group dimensions to model_generated parameter mgStartPopImmigDecode
* DB_RECORDS_IMMIG used to be range {0, 16000}. It is now range {0, 250}. Large SIZE(DB_RECORDS_IMMIG) led to large executable file when compiling in openM.
  * Using 2500 instead of 16000 and making no other change to the code would have worked and achieved some reduction in size of executable. 
  * Using the new numbering system for immigrants allows us to use 250 instead of 16000.
* Using this different numbering system for immigrants leads to no change in POHEM results.
					
**Miscellaneous**
* Added/fixed several labels (i.e. //EN whatever)
	
**Dates**
* Branch created January 9, 2023 
* Branch deemed complete on January 12, 2023  (i.e. ready to merge)
* Branch merged to master/main branch on January 13, 2023 --> POHEM version 8.3.0.4

---

# CN_AlcoholDispatcherReview (developed/compiled with VS 2019, modgen 12.1.3, openM 1.11.0 patched)

**ALCOHOL (Dispatcher)**
* Removed code (while loop) from UpdateNumberDrinksPastWeekExtra() as it was duplicated in ApplyAlcoholIntervention().
* Removed classification ALCOHOL_NUMBER_DRINKS_PAST_WEEK_RANGE_HEAVY_DRINKERS_ONLY and use generic cLOWER_UPPER_BOUNDS instead.  It does the job OK.
* Changed nicknames ALCOHOL_PAIR_whatever to ALCOHOL_IR_whatever.  Did not understand what PAIR was for.  Possibly a faulty copy paste from PA dispatcher.
* Added basic protection against improper settings for parameter NumberDrinksPastWeekRangeHeavyDrinkersOnly in PreSimulation.
* Added parameter AllowedToRequestFormerInsteadOfNever.
* Added parameter AlcoholTransitionCorrelation and state cauchy_alcohol_transition_static.
* Made gAlcohol5 a derived variable again. 
  * Only number_drinks_past_week_extra1 may be altered. States number_drinks_past_week_extra2, gAlcohol5 and always_never_so_far are automatically updated.
  * Ditto for _no_intervention variables.
  * Former function UpdateAlcoholSuite now comes in two copies: UpdateAlcoholAmigosSet1 and UpdateAlcoholAmigosSet2.
					
**Miscellaneous**
* Moved PreSimulation at the end as we have always done.  Left other functions in alphabetical order.
* Removed output table tRiskFactorDiabAgeSex_SillyCopy.
* Removed declaration of function AdjustRandomIntegerToSpecifiedRange (not fully removed in 8.3.0.2).
* Turned off case_checksum in TraceOptions.mpp.  I added case_checksum to the "Some debugging tricks" section of biobrowser.mpp as a reminder of the existence of this useful tool.
* Found a home (table_group) for the following 31 orphan tables.
  * tCVDPoRTAMI5yr, tCVDPoRTStroke5yr, tPopulation_Source, tDementia_Mortality, tDementia_Costs
  * tDementia_Costs_whatever (13 instances), created table_group tgDementiaCostsTableVariants
  * tDementia_whatever       (13 instances), created table_group tgDementiaTableVariants
	
**Dates**
* Branch created October 31, 2022 
* Branch deemed complete on November 30, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on December 16, 2022 --> POHEM version 8.3.0.3

---

# JB-clean-up-interventions-module (developed/compiled with VS 2019, modgen 12.1.3, openM 1.11.0 patched)

* Removed deprecated blood pressure- and cholesterol-related related objects.
* Removed deprecated parameters.

**Dates**
* Branch created October 31, 2022 
* Branch deemed complete on December 8, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on December 16, 2022 --> POHEM version 8.3.0.3

---

# JB-replace-bp_actual-in-HUImodel2 (developed/compiled with VS 2019, modgen 12.1.3, openM 1.11.0 patched)

* Replaced bp_actual with gBP_PA.

**Dates**
* Branch created November 18, 2022 
* Branch deemed complete on December 1, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on December 16, 2022 --> POHEM version 8.3.0.3

---

# JB-fix-suspicious-integer-division (developed/compiled with VS 2019, modgen 12.1.3)

* Removed AdjustRandomIntegerToSpecifiedRange() and replaced with runif() in the alcohol module to achieve a uniform distribution when sampling number_drinks_past_week_extra2 during an alcohol intervention.
* Removed MEND_cutoff and MEND_target from the BMI youth and intervention modules.
* The changes in this branch address this GitLab issue: [https://gitlab.k8s.cloud.statcan.ca/microsim/pohem/-/issues/38](https://gitlab.k8s.cloud.statcan.ca/microsim/pohem/-/issues/38)
* Testing/documentation of the changes in this branch are available here: [https://gitlab.k8s.cloud.statcan.ca/microsim/pohem_workshop/-/tree/Joel_branch/Joel/JB-fix-suspicious-integer-division](https://gitlab.k8s.cloud.statcan.ca/microsim/pohem_workshop/-/tree/Joel_branch/Joel/JB-fix-suspicious-integer-division)

**Dates**
* Branch created October 13, 2022
* Branch deemed complete on October 20, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on October 25, 2022 --> POHEM version 8.3.0.2

---

# NB_Test_Steves_File (developed/compiled with VS 2019, modgen 12.1.3, openM 1.11.0 patched)

* A few changes to make POHEM compile in openM
  * Renamed Base(COPD).dat and Base(COPD_cost).dat as COPD.dat and COPD_cost.dat
  * Changed model_streams from 1000 to 10000 to accomodate COPD's silly use of RandUniform(5456)
  * Unhid calls to hook_COPDexaEvent() and hook_FEV1_updateEvent()
* Note that this does not compile in openM 1.11.0 unless it is patched (look for omc.exe in M:\POHEM\03 CodeVersions\03 All versions deemed reviewed\POHEM8301)

**Dates**
* Branch created October 20, 2022
* Branch deemed complete on October 20, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on October 20, 2022 --> POHEM version 8.3.0.1

---

# CN_Add_Noahs_Xcompatible_8246 (developed/compiled with VS 2019, modgen 12.1.3, openM 1.11.0)

* Copy the cross-compatible version of POHEM 8246 built by Noah in **PohemX workshop** (https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop) as is.
* Then do the following changes.
  * Remove README.md.
  * Add PohemBranches.md to Documentation folder.
  * To better align with OncoSim
    * Modify Model.vcxproj (both the modgen and openM versions) to use OM_ROOT rather than hardcoded path. 
    * Add modgen/bin/PohemX.exe shortcut.
    * Use Oncosim's .gitignore.
    * Let the Documentation folder be a subfolder of folder PohemX.  Steve Gribble expressed a preference for this structure. OncoSim has not yet adopted it, but will do so shortly.
  * Added table tRiskFactorDiabAgeSex_SillyCopy which, as the name suggests, is a user_table copy of tRiskFactorDiabAgeSex.  This is done to explore a potentially interesting feature of OpenM.  It shall be removed afterwards.
 
**Notes**
* Noah actually started from POHEM 8241.  However, during the cross-compatible conversion of POHEM, he also kept pace with the new versions of POHEM that were created concurrently. For this reason, it can be seen as being the child of POHEM 8241 or 8246.  We adopted the latter view and hence the current branch was created from POHEM 8246.
* By the time Noah's work was integrated to the POHEM repo via this branch, POHEM 8247 and 8248 came along. 
* This branch (CN_Add_Noahs_Xcompatible_8246) was merged to the master branch in the hope of getting a cross-compatible version of POHEM (8300) that reflects work whick led to POHEM 8248 (i.e. COPD and de-cluttering).  Though this branch compiles OK in openM and modgen, there are a couple of issues in POHEM 8300 that prevent compilation with openM and will need to be fixed later.
* Detailed summary of how Noah got the cross-compatible version of POHEM 8246 is in **Cross-compatible POHEM Documentation.md** (in the Documentation folder).  This comes from the **PohemX workshop** repo (https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop) which provides even greater details.

**Dates**
* Branch created October 11, 2022
* Branch deemed complete on October 11, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on October 12, 2022 --> POHEM version 8.3.0.0

---

# JB-remove-deprecated-code  (developed/compiled with VS 2019, modgen 12.1.3)

**POHEM clean-up**
* Modules/Files removed: 
  * BMI model 1: BMImodel1.mpp, BMImodel1_12FEB09_13h09_right_no_income.dat
  * HUI model 1: HUImodel1.mpp, HUImodel1.dat
  * Coronary artery disease model (Framingham): CAD-AMI.MPP, CAD-AMI.dat
  * Mind, Exercise, Nutrition, Do it (MEND):  Tab.MEND.mpp removed as well as parameters and code in various other files
  * AMI (Framingham) and OA calibration: Tab.Calibration.mpp    
* Output tables altered or removed:
  * removed tables tMEND_AverageBMI_BMIcats, tCount_MEND_Target, tCC_for_MEND, tCosts_for_MEND, tBMI_CAT_by_youth_BMI_MEND
  * removed tables tDiseaseEvents, tDiseaseEventsAge, tDiseaseEventsProvince
  * removed tables tCC, tCC_by_age_start, tCC_count_autoreg 
  * removed tables utActuarial_LE_HALE, tActuarial_LE_HALE_components
  * removed BMI-based costs in tables tCohort_LifeLong, tHealth_Outcomes_CrossSectional, tHealth_Outcomes_Longitudinal
    * Input parameters and associated code were also removed
* Several miscellanous operations (e.g. remove parameter BMI_std or move pMeanDiffBMIm_sr from now defunct BMImodel1_12FEB09_13h09_right_no_income.dat to BMI_core.dat)
* In the end, POHEM generates the same results as POHEM 8.2.4.7 for tables still present in decluttered version.  Tested on base scenario with 1 million cases.

**Dates**
* Branch created October 6, 2022
* Branch deemed complete on October 7, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on October 10, 2022 --> POHEM version 8.2.4.8

---

# JB-link-categorical-and-continuous-alcohol-in-dispatcher  (developed/compiled with VS 2019, modgen 12.1.3)

**ALCOHOL (Dispatcher)**
* Hooked the Alcohol Dispatcher so that it executes after both number_drinks_past_week_extra1 and number_drinks_past_week_extra2 have been updated and then modifies number_drinks_past_week_extra1 if an alcohol intervention is being applied and gAlcohol5 has changed due to the alcohol intervention.
* Added a parameter, NumberDrinksPastWeekRangeHeavyDrinkersOnly, that allows users to censor the range for number_drinks_past_week_extra1 for female and male heavy drinkers in an alcohol intervention.
* The updates in this branch change the number_drinks_past_week_extra1 so that it falls within the correct range of gAlcohol5 for a given actor if gAlcohol5 has changed due to the application of an alcohol intervention.
* For example, if the actor is male and number_drinks_past_week_extra1 is 25, gAlcohol5 will be ALCOHOL_HEAVY. However, if an alcohol intervention is being applied and gAlcohol5 changes to ALCOHOL_MODERATE, number_drinks_past_week_extra1 must change so that it is between 2-14.
* The tentative logic for changing number_drinks_past_week_extra1 (and, consequently, number_drinks_past_week_extra2 and number_drinks_past_week) during an alcohol intervention is as follows:
  * If gAlcohol5 changes to ALCOHOL_NEVER or ALCOHOL_FORMER, number_drinks_past_week_extra1 is set to -1.
  * If gAlcohol5 changes to ALCOHOL_LIGHT, number_drinks_past_week_extra1 is set to 1.
  * If gAlcohol5 changes to ALCOHOL_MODERATE and the change represents an uptick in drinking (e.g., ALCOHOL_FORMER => ALCOHOL_MODERATE), number_drinks_past_week_extra1 is set to a random integer between 2 and 5 for females or 2 and 8 for males.
  * If gAlcohol5 changes to ALCOHOL_MODERATE and the change represents a downtick in drinking (e.g., ALCOHOL_HEAVY => ALCOHOL_MODERATE), number_drinks_past_week_extra1 is set to a random integer between 6 and 9 for females or 9 and 14 for males.
  * If gAlcohol5 changes to ALCOHOL_HEAVY, number_drinks_past_week_extra1 is set to a random integer between 10 and 30 for females or 15 and 60 for males, by default, as specified in the NumberDrinksPastWeekRangeHeavyDrinkersOnly parameter.

**Dates**
* Branch created September 6, 2022
* Branch deemed complete on September 14, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on October 5, 2022 --> POHEM version 8.2.4.7

---

# JB-add-md-files-for-github  (developed/compiled with VS 2019, modgen 12.1.3)

+ Added LICENSE.md, README.md, CONTRIBUTING.md and SECURITY.md files as required by Statistics Canada for any code being released on the StatCan GitHub account per their software release guide (https://digital.statcan.gc.ca/drafts/guides-software-release).

**Dates**
* Branch created on October 4, 2022
* Branch deemed complete on October 4, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on October 5, 2022 --> POHEM version 8.2.4.7

---

# CN_COPD_modgen12  (developed/compiled with VS 2019, modgen 12.1.3)

**COPD**
+ Add 4 files from M:\POHEM\03 CodeVersions\02 Submit for review\20190531_140925_Pohem2.0_build8012_COPD_Dec2018
  + COPD_table.mpp and copd_test.mpp       (renamed as COPD_model.mpp)
  + Base(COPD).dat and Base(cost_COPD).dat (renamed as Base(COPD_cost).dat)
+ In COPD_model.mpp, stream numbers were removed as they collided with stream numbers used elsewhere. Modgen generated new stream numbers in COPD_model.mpp.
+ Add COPD to pDisease and transpose it (shows better)
  + If COPD is turned off, there is no COPD incidence and no COPD prevalence at start. POHEM results are the same as before (except for HUI, see below).
  + When COPD is turned on ...
    + If mortality engine is **not** "Demography projection",  POHEM results are the same as before (except for HUI, see below) as COPD is connect to nothing for now (e.g. MPoRT is currently not a function of COPD).
    + If mortality engine is "Demography projection", COPD module may kill people who have exacerbation and hence POHEM results will change from previous versions.
+ Hooks
  + Explicitly spell out hook orders.  Hooks from COPD executed last.
  + Two hooks were not needed and were removed.
+ Streamlining/tidying
  + Removed about 30 unneeded states. Recoded some COPD tables accordingly. 
  + States and partitions that are only used for tabulation purposes were moved in COPD_tables.mpp.  
+ Equations
  + Introduce classification COPD_EQUATION and use it in 8 parameters.  This way we have more coefficients stored in parameters and less hardcoded equations (but not none).
  + Introduce and use ComputeXBeta which will compute X'Beta with Beta being one of the 8 aforementioned coefficients.
  + Parameter CopdExacerbationStage was introduced to replace an hardcoded equation.  It does not use the classification COPD_EQUATION.
  + The old code was written in such a way that entry COPD_STAGE1 of parameter COPD_exac_hazard (happened to be 0.8) would never be used. In new code, this entry is used and we set the value to 0 in order to have the same results as the "old code".  According to https://gcdocs.gc.ca/statcan/llisapi.dll/app/nodes/26894568, this is proper thing to do.
+ Add COPD to tHealth_Outcomes_CrossSectional and tHealth_Outcomes_Longitudinal.
+ After seeing that above steps worked OK, we removed COPD_table.mpp as we are not interested in those tables for now and do not want to add to existing table clutter.

**Miscellaneous**
+ Removed Case_Seed_Table and instead introduced a WriteDebugLogEntry which spits out (case_id, case_seed) if EcrireDebugLogEntry < 0.
+ Tiny unexpected differences with respect to HUI occured with commit 5f94f9e2 (and persist in subsequent commits). More info on this in the technical document.

**Dates**
* Branch created on September 13, 2022
* Branch deemed complete on October 4, 2022 (i.e. ready to merge)
* Branch merged to master/main branch on October 5, 2022 --> POHEM version 8.2.4.7

---

## Template

# <branch name> 

**Topic1  (optional ... may just "Describe what was done")**
+ Describe what was done
+ Describe what was done
  + Describe what was done (sub bullet)
    + Describe what was done (sub sub bullet)
+ Describe what was done

**Topic2   (optional ... may just "Describe what was done")**
- Describe what was done

**Dates**
* Branch created on <date>
* Branch deemed complete on <date> (i.e. ready to merge)
* Branch merged to master/main branch on <date>--> POHEM version ???

---

## Markdown tips

Numbered list
1. Dog
    1. German Shepherd
    1. Belgian Shepherd
        1. Malinois
        1. Groenendael
        1. Tervuren
1. Cat
    1. Siberian
    1. Siamese

**Bold**, *italic*, __bold__, _italic_, **_bold and italic_**.

<strong>Bold</strong>, <i>italic</i>, <strong><i>bold and italic</i></strong>.
