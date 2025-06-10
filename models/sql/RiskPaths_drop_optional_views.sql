--
-- drop compatibility views for model: RiskPaths
-- model digest:   d976aa2fb999f097468bb2ea098c4daf
-- script created: 2025-06-01 18:50:02.483
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
DROP VIEW AgeBaselineForm1;
DROP VIEW AgeBaselinePreg1;
DROP VIEW CanDie;
DROP VIEW ProbMort;
DROP VIEW SeparationDurationBaseline;
DROP VIEW SimulationCases;
DROP VIEW SimulationSeed;
DROP VIEW UnionDurationBaseline;
DROP VIEW UnionStatusPreg1;

--
-- drop output tables compatibility views
--
DROP VIEW T01_LifeExpectancy;
DROP VIEW T02_TotalPopulationByYear;
DROP VIEW T03_FertilityByAge;
DROP VIEW T04_FertilityRatesByAgeGroup;
DROP VIEW T05_CohortFertility;
DROP VIEW T06_BirthsByUnion;
DROP VIEW T07_FirstUnionFormation;

