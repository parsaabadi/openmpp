#### OpenM++ Version: 1.10.0

## 2022-07-07
+ Cloned internal release 8241 of POHEM into this new repository
+ Converted POHEM to the OpenM++ framework via existing NewCaseBased framework. Followed https://github.com/openmpp/openmpp.github.io/wiki/Convert-case-based-Model-from-Modgen
+ Checked that POHEM-modgen.sln builds in VS
+ Confirmed that ompp-framework POHEM runs via test_models32. In command prompt, I first did "setx OM_ROOT C:\OpenM_101\openmpp_win_20220505" and then I can run test_models32 like "test_models32 -m ../../../Git/POHEMX_2022_07_07/pohemx_workshop PohemX"
+ Comment out MessageWhoWhenWhere (couldn't figure out the error message yet)

# 2022-07-11
+ Downloaded ompp 1.10.0 from "https://gcdocs.gc.ca/statcan/llisapi.dll/app/nodes/24946020", change OM_ROOT according in the .vcxproj files as well as with "setx OM_ROOT C:\OpenM_101\openmpp_win_20220617"
+ Comment out french language at beginning of StartPop for now
+ Add hook_name(); to every function void Person::name(), and create a new line/function called "void hook_name() {};" For some functions, there is already void and hook identifiers on the top of the file so no need to double up.
+ A lot of StartPop.mpp gets condesnded into SimulateEvents(), following this https://github.com/openmpp/openmpp.github.io/wiki/Convert-Modgen-models-and-usage-of-cpp 
+ Large edits to Startop.mpp, and newly added modgen_case_based.mpp, related to CaseSimulation functionality. Most of it copied from C:\OpenM_101\Models\POHEM - Changes before git\Notes and Documentation\SteveGribble_ModifiedPOHEMcode\cross-compatible 2014-10-24\code with some tweaks
+ Tried to get rid of all warnings by declaring types explicitly. Can't get rid of warning from "int    age_immigration = {TIME_INFINITE};" though.
+ Only error now is C1002 fatal error related to capacity and heap space. Compiling to make checkpoint before further playing around.

# 2022-07-12
+ Type set PreferredToolArchitecture=x64 into a fresh cmd prompt before using test_models, so that the test_models can by default use x64 tools for building

# 2022-07-13
+ Debugging in VS. Explicitly initialized porq in StatDistributionsFromDcdflib to fix 'Run-Time Check Failure #3'
+ In the .vcxproj files, under PropertyGroup Condition section for relevant configuration/platform combinations (in my case, Release x64 and Debug x64), add '<PreferredToolArchitecture>x64</PreferredToolArchitecture>'
+ Error creating user table, setting year equal to 0. In UserTables, take out casting of range_from_etc... so it's just a j or whatever
+ Renamed Solution folder to PohemX

# 2022-07-14
+ Trying to resolve the issue of ompp tables full of zeroes. I hadn't yet added initialize_attributes(); or enter_simulation(); anywhere and in doing so, I introduced errors which do not seem related.
+ Make sure const int model_streams in ompp_framework.ompp is large enough to surpass all calls of RandUniform()

# 2022-07-15
+ Commiting all minus StartPop in order to properly convert StartPop

# 2022-07-18

+ With the help of Steve's debuggint tips, found an inconsistency between PohemX and old Pohem with 'Mortality_hazard_multiplier_caltime_switch'. Once resolved, all tables identical except for tDementia_costs. Committing to save progress.
+ Updated to POHEM 8.2.4.2, resolved tDementia_costs. Ompp = modgen everywhere!!!
+ Updated to POHEM 8.2.4.3
+ Updated to POHEM 8.2.4.5

# 2022-08-15
+ Email thread with Steve, lots of changes to make!

# 2022-09-06
+ Implementing a host of changes to address bugs which Steve found when testing the up-to-date PohemX

---

### Detailed change-log

## Pohem to PohemX: commit-by-commit

<p>Here is my best attempt to detail the changes implemented during the conversion process. The conversion starts from Pohem 8.2.4.1 found in the master branch of the repository, at which point I made a new branch NB_POHEM_XComp
to start implementing changes. </p>

# First commit to NB_POHEM_XComp: ["POHEM internal release 8.2.4.1"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/3eac9d4df2ffa11455aa11b574498361962877b9) July 7th, 2022

<p> Just created a new branch and committed to serve as a starting point in this branch. </p>

# Commit ["POHEM in ompp framework (no .mpp changes)"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/168baee3631d5f0afc1adbeed8aa0018e3a716eb) July 7th, 2022

+ Added a documentation file, Pohem-ompp solution, POHEM.ini file (this file has values for SubValues and Threads in OpenM)
+ Moved .gitignore, Model.xcconfig
+ Deletesd the Base_MaleLinearAge and Base_TimeSinceBirth .dat files
+ Inlcude omc/fixed_modgen_api.h in custom.h
+ Delete int case_counter from custom_early.h
+ New up-to-date ompp_framework.ompp
+ Moved Model.vcxproj and Model.vcxproj.filters from Solution/ to Solution/ompp/
+ Moved all .dat files from Solution/code/Scenarios to Solution/parameters/Default, and removed the Base() from the file names
+ Added framework.odat to set values for SimulationSeed and SimulationCases
+ int pStartPopYear = 2001 to int pStartPopYear = {2001} in POHEM_StartPop_CCHS1.1_PUMF_03MAR21_Public_weight_adjusted.dat

# Commit ["Fix documentation format, update .gitignore file"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/46fde88cbe3722706948baa6aa879ac5629ef12b) July 7th, 2022

+ Copied the OncoSim .gitignore
+ Changed Cross-compatible POHEM documentaion.md format
+ Added Model.vcxproj and Model.vcxproj.filters to new folder Solution/modgen

# Commit ["Added hooks for all functions, updated ompp version"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/4f1393451bf8ebeae205e6fdf05f464318479419) July 11th, 2022

+ test_models does not work
+ Documentation changes
+ Commented out all MessageWhoWhenWhere instances
+ Added hooks for all Person functions
+ Commented out FR language in StartPop
+ Got new OpenM++ version so had to change the OM_ROOT
+ Set Mortality_hazard_multiplier_caltime_switch = FALSE in ChronicConditions.dat

# Commit ["Commit before further playing around. Model almost runs in ompp"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/30330bc1800ba4c14b034d4b46bae6fce5fe8255) July 12th, 2022

+ Updateded .gitignore and documentaion
+ double * become const double *
+ Casting variable type in spline functions, sprintf_s, max and mins, ternary operations
+ Person::SelfReportedToMeasuredBmi: LIFE age_of_person to LIFE_SPAN age_of_person
+ BMImodel1: LondRand(57) to RandUniform(57)
+ Some more hooks for non-member functions
+ Line 455 in Functions.mpp, remove CDECL
+ Smoking_crm.mpp: 0.0 becomes 0 for light_smoker_duration and heavy_smoker_duration
+ A lot of changes to StartPop.mpp following the [OpenM++ GitHub](https://github.com/openmpp/openmpp.github.io/wiki/Convert-Modgen-models-and-usage-of-cpp).:
	+ void CaseSimulation(int nRecord) -> void CaseSimulation(case_info& ci)
	+ Declare functions SimulateEvents(), GetCaseCounterInThread(), and variable nRecord
	+ Remove "CRandState rRandState"
	+ Add line "int ConvertAgeGroup(int nRecord = 0);"
	+ Person *prDominant -> Person_ptr prDominant
	+ Remove "GetRandState( rRandState )"
	+ Replace "while ( !gpoEventQueue->Empty() )" loop with "SimulateEvents();"
	+ Replace Simulation() function with an OpenM++ "void Simulation_start(case_info & ci)" and "void Simulation_end(case_info & ci)" functions
+ Added TraceOptions.mpp for test_models debugging help. This was from email thread "RE: POHEM Conversion to OpenM++" between myself and Steve, July 11th, 2022.
+ Added Solution/code/modgen_case_based.mpp, copied from the openm NewCaseBased model ([required step for conversion](https://github.com/openmpp/openmpp.github.io/wiki/Convert-case-based-Model-from-Modgen)).
+ Set OPEN_MODEL_WBU_UI to true in solution/ompp/Model.vcxproj
+ Added Solution/ompp/Model.vcxproj.filters

<p> test_models for modgen are same as "Fix documentation format, update .gitignore file" commit in 5000 case run (test_models did not work in previous commit) </p>

# Commit ["Pohem runs in ompp and test_models, tables are wrong though"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/897ea4e8c9c37315df073803d100c5bc691c255c) July 13th, 2022

+ Documentation
+ Rename Solution folder to PohemX
+ In StatDistributionsFromDcdflib.mpp, intialized a bunch of variables
+ hide utPresimView in TableAndParameterGroups.mpp
+ In UserTables.mpp, changed all instances of (RANGE_FROM_2001_TO_2111)j to j
+ Increased model_streams
+ Added <PreferredToolArchitecture>x64</PreferredToolArchitecture> to modgen/Model.vcxproj and ompp/Model.vcxproj. This was the result of email thread "RE: POHEM Conversion to OpenM++" between myself and Steve, July 12th, 2022.

<p> test_models for modgen are same as previous commit in 1000 and 5000 case run </p>

# Commit ["Changes minus StartPop"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/e7263b9b4d7909fe7baadadcf361e7d08f06dccd) July 15th, 2022

+ Documentation
+ In Alcohol.mpp, changed a RandUniform( 39687 ) to RandUniform( 39687 ) to RandUniform( 152 )
+ In PersonCore.mpp, added initialize_attributes();, enter_simulation(); and exit_simulation();
+ In Framework.odat, 5000 cases -> 1000 cases

<p> test_models for modgen are same as previous commit in 1000 case run </p>

# Commit ["All tables good except tDementia_costs"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/e1cf3b78388c451b44807cea1ccd3760622d3b88) July 19th, 2022

+ Documentation
+ In PersonCore.mpp, CoarsenMantissa removed
+ In StartPop.mppPerson_ptr prDominant -> Person *prDominant (incorrectly copied StartPop.mpp previously)
+ Mortality_hazard_multiplier_caltime_switch to TRUE in ChronicConditions.mpp

<p> test_models for modgen are same as previous commit in 1000 case run (provided Mortality_hazard_multiplier_caltime_switch is the same) </p>

# Commits "POHEM 8.2.4.2" to "POHEM 8.2.4.6" July 19th, 2022 to August 12th, 2022

+ Reflecting internal releases of POHEM, no openmpp-specific changes

<p> test_models shows that modgen and openmpp outputs are identical here. </p> 

# Commit ["Steve changes"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/16cb2ca4c531fc01d94bb1f53b02eb4adc648d02) August 15th, 2022

+ Documentation
+ In Intervention.mpp, added [cBMI] dimension to pRISK_FACTOR_CONTROL_PANEL
+ In StatDistributionsFromDcdflib.mpp, n_data to *n_data

# Commit ["27 of 29 Steve changes"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/commit/c70230735cc5e2d79342803c96036ad057f3472e) September 7th, 2022

+ Documentation
+ Changed 27 member functions to globals. This involves removing the Person:: prefix, globally defining the function in custom.h, and explicitly calling all variables
+ In StartPop-Control.dat, set UseUnstableRunningMode = FALSE. This allows for reproducing a single case from a larger run in isolation with a 1-case run.

# Commit ["Steve changes minus UpdateAlcoholSuite (fixed)"](https://gitlab.k8s.cloud.statcan.ca/microsim/pohemx_workshop/-/tree/NB_POHEM_XComp) September 13th, 2022

+ Applied Steve function change to MeasuredToSelfReportedBmi and SelfReportedToMeasuredBmi 
+ Changed framework.odat to seed=1, cases=5000

<p> From an email thread "RE: Tables off for test_models" between myself and Steve on September 12th, 2022, Steve confirms that the new code in this commit should produce outputs different from those in the previous commit.
With UseUnstableRunningMode=TRUE, outputs are identical before and after Steve's changes. In thread "RE: test_models for larger populations", August 14th 2022, Steve mentions that when trying to reproduce a single case in
isolation from a larger run, this value must be FALSE (FALSE = "diables systematic sampling"). When FALSE, PohemX before Steve's changes does not run. First error is the "Array index error in Intervention.mpp" Steve sent
my in an email on August 18th, 2022. When fixed, modgen outputs are equal before and after Steve's changes for either UseUnstableRunningMode.

Also, modgen=ompp for 5000000 cases. There is one rounding error for case seed 1030540113 but no differences in the checksums, so no actual output differences.  Note that before Steve's changes, there were 'real' differences
between modgen and ompp. </p>



---

### Errors and solutions

# C4839
+ Cast types to variables which are becoming strings. E.g. in debug lines (sprintf and stuff), just make all variables (type)variables, e.g. sprintf_s( line, 999, "%i, %15.1f, %i \n", (int)case_id, (double)case_seed, (int)gAlcohol5)

# C2440
+ Add const before type, e.g. "double *record_to_be_read" becomes "const double *record_to_be_read"

# C2665
+ Cast type before argument, e.g. "CubicSpline(x, CvdportAmiMetsSplineLocationCoef[sex][CUBIC_SPLINE_KNOTS_LOCATION],..." becomes "CubicSpline((double)x, (double*)CvdportAmiMetsSplineLocationCoef[sex][CUBIC_SPLINE_KNOTS_LOCATION],..."

# C3861
+ Didn't like LongRand somewhere, used RandUniform

# C2664
+ Similar to C2440 but in a function definition, e.g. "double ComputeChronicConditionLinearPredictor(double * Coefficients, double CalendarTimeCap);" becomes "double ComputeChronicConditionLinearPredictor(const double * Coefficients, double CalendarTimeCap);". Sometimes, you have to go into the .H files to changes the variable types.

# C2065
+ Didn't like CDECL, just take it out

# C2511
+ Just check the function definition has identical variables and types, copy paste to make sure

# C2445
+ Happens in nested ternary operators a lot, just cast the type of each value