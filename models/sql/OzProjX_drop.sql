--
-- drop model tables: OzProjX
-- model digest:      2e697e28ca63b708a198849eee824e3f
-- script created:    2025-06-01 18:50:48.692
--
-- DROP MODEL TABLES
-- DO NOT USE THIS SQL UNLESS YOU HAVE TO
-- IT WILL DELETE ALL MODEL DATA
--

--
-- drop model output views and tables
--
DROP VIEW BirthsByYear_d6a87a9a9;
DROP TABLE BirthsByYear_a6a87a9a9;
DROP TABLE BirthsByYear_v6a87a9a9;
DROP VIEW DeathsByAgeSex_dc9ba97b5;
DROP TABLE DeathsByAgeSex_ac9ba97b5;
DROP TABLE DeathsByAgeSex_vc9ba97b5;
DROP VIEW DeparturesByYear_d5ce5e506;
DROP TABLE DeparturesByYear_a5ce5e506;
DROP TABLE DeparturesByYear_v5ce5e506;
DROP VIEW Experiment1_dfb8d750b;
DROP TABLE Experiment1_afb8d750b;
DROP TABLE Experiment1_vfb8d750b;
DROP VIEW Experiment2_dbe3df0bc;
DROP TABLE Experiment2_abe3df0bc;
DROP TABLE Experiment2_vbe3df0bc;
DROP VIEW Experiment3_d522d153a;
DROP TABLE Experiment3_a522d153a;
DROP TABLE Experiment3_v522d153a;
DROP VIEW Experiment4_d2ff235db;
DROP TABLE Experiment4_a2ff235db;
DROP TABLE Experiment4_v2ff235db;
DROP VIEW Experiment5_d5cffa0fd;
DROP TABLE Experiment5_a5cffa0fd;
DROP TABLE Experiment5_v5cffa0fd;
DROP VIEW Experiment6_d3b291b2f;
DROP TABLE Experiment6_a3b291b2f;
DROP TABLE Experiment6_v3b291b2f;
DROP VIEW InitialPopCounts_dc107a6da;
DROP TABLE InitialPopCounts_ac107a6da;
DROP TABLE InitialPopCounts_vc107a6da;
DROP VIEW MathMoments_df883e5ce;
DROP TABLE MathMoments_af883e5ce;
DROP TABLE MathMoments_vf883e5ce;
DROP VIEW MicrodataAge_d5e604d10;
DROP TABLE MicrodataAge_a5e604d10;
DROP TABLE MicrodataAge_v5e604d10;
DROP VIEW MicrodataIndigenous_da5f660a9;
DROP TABLE MicrodataIndigenous_aa5f660a9;
DROP TABLE MicrodataIndigenous_va5f660a9;
DROP VIEW MicrodataNativeBorn_df5339edc;
DROP TABLE MicrodataNativeBorn_af5339edc;
DROP TABLE MicrodataNativeBorn_vf5339edc;
DROP VIEW MicrodataRecentArrival_d7c8d6e13;
DROP TABLE MicrodataRecentArrival_a7c8d6e13;
DROP TABLE MicrodataRecentArrival_v7c8d6e13;
DROP VIEW MicrodataRegion_d12a57f25;
DROP TABLE MicrodataRegion_a12a57f25;
DROP TABLE MicrodataRegion_v12a57f25;
DROP VIEW MicrodataSex_d6a27dfb3;
DROP TABLE MicrodataSex_a6a27dfb3;
DROP TABLE MicrodataSex_v6a27dfb3;
DROP VIEW MicrodataYearsSinceArrival_d6c9377fd;
DROP TABLE MicrodataYearsSinceArrival_a6c9377fd;
DROP TABLE MicrodataYearsSinceArrival_v6c9377fd;
DROP VIEW MigrantsByOriginAndDestination_dc023f407;
DROP TABLE MigrantsByOriginAndDestination_ac023f407;
DROP TABLE MigrantsByOriginAndDestination_vc023f407;
DROP VIEW PersonYearsLived_dc97b5075;
DROP TABLE PersonYearsLived_ac97b5075;
DROP TABLE PersonYearsLived_vc97b5075;
DROP VIEW EmigrationHazard_dba1714c2;
DROP TABLE EmigrationHazard_aba1714c2;
DROP TABLE EmigrationHazard_vba1714c2;
DROP VIEW FertilityHazard_d48da2cb6;
DROP TABLE FertilityHazard_a48da2cb6;
DROP TABLE FertilityHazard_v48da2cb6;
DROP VIEW ImmigrantDonors_d13fc62b8;
DROP TABLE ImmigrantDonors_a13fc62b8;
DROP TABLE ImmigrantDonors_v13fc62b8;
DROP VIEW MortalityHazard_df84bc967;
DROP TABLE MortalityHazard_af84bc967;
DROP TABLE MortalityHazard_vf84bc967;

--
-- drop model input parameters tables
--
DROP TABLE ArrivalRegionDistn_p1b1d674f;
DROP TABLE ArrivalRegionDistn_w1b1d674f;
DROP TABLE DestinationDist_pf6d0f72c;
DROP TABLE DestinationDist_wf6d0f72c;
DROP TABLE EmigrationRate_p780b1286;
DROP TABLE EmigrationRate_w780b1286;
DROP TABLE FertilityRate_pdda6ef40;
DROP TABLE FertilityRate_wdda6ef40;
DROP TABLE Immigrants_pbf3a7fb9;
DROP TABLE Immigrants_wbf3a7fb9;
DROP TABLE MathMomentHazard_p1d09ba40;
DROP TABLE MathMomentHazard_w1d09ba40;
DROP TABLE MathMomentPrimesToCalculate_p237edbcd;
DROP TABLE MathMomentPrimesToCalculate_w237edbcd;
DROP TABLE MaxYearsForImmigrantDonor_p99032d1f;
DROP TABLE MaxYearsForImmigrantDonor_w99032d1f;
DROP TABLE MicroDataInPieces_pba0a426d;
DROP TABLE MicroDataInPieces_wba0a426d;
DROP TABLE MicroDataInputFile_p7d40b028;
DROP TABLE MicroDataInputFile_w7d40b028;
DROP TABLE MicroDataOutputFile_p6d28ab86;
DROP TABLE MicroDataOutputFile_w6d28ab86;
DROP TABLE MicroDataOutputFlag_p1c00c4b4;
DROP TABLE MicroDataOutputFlag_w1c00c4b4;
DROP TABLE MicroDataOutputTime_pf12171c1;
DROP TABLE MicroDataOutputTime_wf12171c1;
DROP TABLE MortalityRate_p1c686222;
DROP TABLE MortalityRate_w1c686222;
DROP TABLE NativeToIndigenous_peb896ad5;
DROP TABLE NativeToIndigenous_web896ad5;
DROP TABLE OutMigrationRate_pda90d112;
DROP TABLE OutMigrationRate_wda90d112;
DROP TABLE RealWorldStartPopulation_p44922698;
DROP TABLE RealWorldStartPopulation_w44922698;
DROP TABLE RelativeFertilityIndigenous_pc9d4d4d2;
DROP TABLE RelativeFertilityIndigenous_wc9d4d4d2;
DROP TABLE SexRatioAtBirth_pa947c82d;
DROP TABLE SexRatioAtBirth_wa947c82d;
DROP TABLE SimulationCases_p8b4bccb7;
DROP TABLE SimulationCases_w8b4bccb7;
DROP TABLE SimulationSeed_p3df984c3;
DROP TABLE SimulationSeed_w3df984c3;
DROP TABLE SimulationStartTime_p1c304b48;
DROP TABLE SimulationStartTime_w1c304b48;
DROP TABLE UndercountRate_p2387e82a;
DROP TABLE UndercountRate_w2387e82a;

