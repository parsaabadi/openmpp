--
-- drop compatibility views for model: OzProjX
-- model digest:   2e697e28ca63b708a198849eee824e3f
-- script created: 2025-06-01 18:50:48.692
--
-- Dear user:
--   this part of database is optional and NOT used by openM++
--   if you want it for any reason please enjoy else just ignore it
-- Or other words:
--   if you don't know what is this then you don't need it
--

--
-- drop input parameters compatibility views
--
DROP VIEW ArrivalRegionDistn;
DROP VIEW DestinationDist;
DROP VIEW EmigrationRate;
DROP VIEW FertilityRate;
DROP VIEW Immigrants;
DROP VIEW MathMomentHazard;
DROP VIEW MathMomentPrimesToCalculate;
DROP VIEW MaxYearsForImmigrantDonor;
DROP VIEW MicroDataInPieces;
DROP VIEW MicroDataInputFile;
DROP VIEW MicroDataOutputFile;
DROP VIEW MicroDataOutputFlag;
DROP VIEW MicroDataOutputTime;
DROP VIEW MortalityRate;
DROP VIEW NativeToIndigenous;
DROP VIEW OutMigrationRate;
DROP VIEW RealWorldStartPopulation;
DROP VIEW RelativeFertilityIndigenous;
DROP VIEW SexRatioAtBirth;
DROP VIEW SimulationCases;
DROP VIEW SimulationSeed;
DROP VIEW SimulationStartTime;
DROP VIEW UndercountRate;

--
-- drop output tables compatibility views
--
DROP VIEW BirthsByYear;
DROP VIEW DeathsByAgeSex;
DROP VIEW DeparturesByYear;
DROP VIEW Experiment1;
DROP VIEW Experiment2;
DROP VIEW Experiment3;
DROP VIEW Experiment4;
DROP VIEW Experiment5;
DROP VIEW Experiment6;
DROP VIEW InitialPopCounts;
DROP VIEW MathMoments;
DROP VIEW MicrodataAge;
DROP VIEW MicrodataIndigenous;
DROP VIEW MicrodataNativeBorn;
DROP VIEW MicrodataRecentArrival;
DROP VIEW MicrodataRegion;
DROP VIEW MicrodataSex;
DROP VIEW MicrodataYearsSinceArrival;
DROP VIEW MigrantsByOriginAndDestination;
DROP VIEW PersonYearsLived;
DROP VIEW EmigrationHazard;
DROP VIEW FertilityHazard;
DROP VIEW ImmigrantDonors;
DROP VIEW MortalityHazard;

